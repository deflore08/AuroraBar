[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Volume control measures and meters
 
[Variables]

; --- SLIDERS VARS

 CPU_Volume_Handle                = 0 
 GPU_Volume_Handle                = 0 

; --- DEVICE SWITCHERS

; - Placed at right side

[t.Headphones]
 Meter                            = STRING
 FontColor                        = #Global_Color#
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 1845
 Y                                = (#Pad_Top# + 160)
 FonSize                          = 10
 Text                             = "HEADPHONES"
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.System_Volume "SetOutPutIndex 1"]
 Group                            = #app_volume_controls_static#
 Hidden                           = ( #App_Volume_Control_Static_State# + #Audio_Devices_State# )

[t.Speakers]
 Meter                            = STRING
 FontColor                        = #Global_Color#
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 1845
 Y                                = (#Pad_Top# + 46)
 FonSize                          = 10
 Text                             = "SPEAKERS"
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.System_Volume "SetOutPutIndex 2"]
 Group                            = #app_volume_controls_static#
 Hidden                           = ( #App_Volume_Control_Static_State# + #Audio_Devices_State# )

; --- MEASURES BEGINNING
 
; --- SLIDERS BEGINNING

; - CPU

[m.CPU_Volume_Slider]
 Measure                          = PLUGIN
 Plugin                           = Mouse
 LeftMouseDragAction              = [!SetVariable CPU_Volume_Handle "(clamp($MouseX$,[histogram.CPU_LOAD:X],[histogram.CPU_LOAD:XW]))"][!UpdateMeasure m.CPU_Volume_Slider_Set][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 LeftMouseUpAction                = [!SetVariable CPU_Volume_Handle "(clamp($MouseX$,[histogram.CPU_LOAD:X],[histogram.CPU_LOAD:XW]))"][!CommandMeasure m.CPU_Volume_Slider "Stop"][!Delay 1][!UpdateMeasure m.CPU_Volume_Slider_Set]
 RelativeToSkin                   = 1
 RequireDragging                  = 1
 DynamicVariables                 = 1

[m.CPU_Volume_Slider_Set]
 Measure                          = CALC
 Formula                          = #CPU_Volume_Handle#
 MinValue                         = [histogram.CPU_LOAD:X]
 MaxValue                         = ([histogram.CPU_LOAD:X] + [histogram.CPU_LOAD:W])
 DynamicVariables                 = 1
 OnUpdateAction                   = [!CommandMeasure m.System_Volume "SetVolume [m.CPU_Volume_Slider_Set:%,0]"]
 Disabled                         = 1

; - GPU

[m.GPU_Volume_Slider]
 Measure                          = PLUGIN
 Plugin                           = Mouse
 LeftMouseDragAction              = [!SetVariable GPU_Volume_Handle "(clamp(($MouseX$),[histogram.GPU_LOAD:X],[histogram.GPU_LOAD:XW]))"][!UpdateMeasure m.GPU_Volume_Slider_Set][!UpdateMeasure sensor.PLAYER][!UpdateMeter b.Player_Volume][!Redraw]
 LeftMouseUpAction                = [!SetVariable GPU_Volume_Handle "(clamp(($MouseX$),[histogram.GPU_LOAD:X],[histogram.GPU_LOAD:XW]))"][!CommandMeasure m.GPU_Volume_Slider "Stop"][!Delay 1][!UpdateMeasure m.GPU_Volume_Slider_Set]
 RelativeToSkin                   = 1
 RequireDragging                  = 1
 DynamicVariables                 = 1

[m.GPU_Volume_Slider_Set]
 Measure                          = CALC
 Formula                          = #GPU_Volume_Handle#
 MinValue                         = [histogram.GPU_LOAD:X]
 MaxValue                         = ([histogram.GPU_LOAD:X] + [histogram.GPU_LOAD:W])
 DynamicVariables                 = 1
 InvertMeasure                    = 1
 OnUpdateAction                   = [!CommandMeasure sensor.PLAYER "SetVolume [m.GPU_Volume_Slider_Set:%,0]"]
 Disabled                         = 1

; --- SLIDERS END

; - System volume

[m.System_Volume]
 Measure                          = PLUGIN
 Plugin                           = Win7AudioPlugin
 UpdateDivider                    = 1
        onChangeAction            = [!UpdateMeasure m.Percent_System_Volume][!UpdateMeasure m.Volume_Values_Controller][!UpdateMeter b.System_Volume][!UpdateMeter t.System_Volume]

[m.Percent_System_Volume]
 Measure                          = CALC
 Formula                          = m.System_Volume
 MinValue                         = 0
 MaxValue                         = 100
 DynamicVariables                 = 1

[m.Volume_Values_Controller]
 Measure                          = CALC
 DynamicVariables                 = 1
        IfCondition               = m.System_Volume > -1
        IfTrueAction              = [!SetOption t.System_Volume FontColor "#Font_Value_Color#"]
        ifCondition2              = m.System_Volume < 10
                IfTrueAction2     = [!SetOption t.System_Volume Text "0%1"]
                IfFalseAction2    = [!SetOption t.System_Volume Text "%1"]
        ifCondition3              = sensor.PLAYER < 10
                IfTrueAction3     = [!SetOption t.Player_Volume Text "0%1"]
                IfFalseAction3    = [!SetOption t.Player_Volume Text "%1"]
        IfCondition4              = sensor.PLAYER = 100
                IfTrueAction4     = [!SetOption t.Player_Volume Text "99"]
        IfCondition5              = m.System_Volume > 99
                IfTrueAction5     = [!SetOption t.System_Volume Text "99"]
        IfCondition6              = m.System_Volume = -1
                IfTrueAction6     = [!SetOption t.System_Volume Text "00"][!SetOption t.System_Volume FontColor "#Font_Warning_Color#"]
        IfCondition7              = sensor.PLAYER = 0
                IfTrueAction7     = [!SetOption t.Player_Volume Text "00"][!SetOption t.Player_Volume FontColor "#Font_Warning_Color#"]
                IfFalseAction7    = [!SetOption t.Player_Volume FontColor "#Font_Value_Color#"]
        IfConditionMode           = 1

; - MEASURES END

; --- TEXTS BEGINNING

[t.Player_Volume]
 Meter                            = STRING
 MeasureName                      = sensor.PLAYER
 MeterStyle                       = f.fadedSmallFontRightAlign
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Time_Font_Size_Day#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 X                                = 1055
 Y                                = (#Pad_Top# + 8)
 Text                             = %1
 Percentual                       = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = (1 - #Settings_Color_Temp#)

[t.System_Volume]
 Meter                            = STRING
 MeasureName                      = m.Percent_System_Volume
 MeterStyle                       = f.fadedSmallFontLeftAlign
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Time_Font_Size_Day#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 X                                = 865
 Y                                = (#Pad_Top# + 8)
 Text                             = %1
 Percentual                       = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = (1 - #Settings_Main_Temp#)
; LeftMouseUpAction                = [!CommandMeasure shell.BACKUP_CONFIG_GLOBAL "Run"][!CommandMeasure shell.BACKUP_HARDWARE_GLOBAL "Run"][!CommandMeasure shell.BACKUP_HOTKEYS_GLOBAL "Run"]
; RightMouseUpAction               = [!CommandMeasure shell.RESTORE_CONFIG "Run"][!CommandMeasure shell.RESTORE_HARDWARE "Run"]

; - TEXTS END

; --- BARS BEGINNING

; Thin line between CPU GRAPHS

[b.System_Volume]
 Meter                            = BAR
 MeasureName                      = m.System_Volume
 X                                = #CPU_Histogram_X#
 Y                                = (#Pad_Top# + 110)
 W                                = #CPU_Histogram_Width#
 H                                = 1
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 DynamicVariables                 = 1
 Group                            = #volume_control#

; - Thin line between GPU GRAPHS

[b.Player_Volume]
 Meter                            = BAR
 MeasureName                      = sensor.PLAYER
 X                                = #GPU_Histogram_X#
 Y                                = (#Pad_Top# + 110)
 W                                = #GPU_Histogram_Width#
 H                                = 1
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 Flip                             = 1
 DynamicVariables                 = 1
 Group                            = #volume_control#

; - BARS END