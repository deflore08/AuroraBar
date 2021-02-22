[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Applications volume controls bars in right side

[Variables]



; --- SLIDERS VARS

 App_1_Volume_Static_Handle       = 0 
 App_2_Volume_Static_Handle       = 0 
 App_3_Volume_Static_Handle       = 0 
 App_4_Volume_Static_Handle       = 0 

 App_1_Volume_Dynamic_Handle      = 0 
 App_2_Volume_Dynamic_Handle      = 0 
 App_3_Volume_Dynamic_Handle      = 0 
 App_4_Volume_Dynamic_Handle      = 0 
 App_5_Volume_Dynamic_Handle      = 0 
 App_6_Volume_Dynamic_Handle      = 0 
 App_7_Volume_Dynamic_Handle      = 0 
 App_8_Volume_Dynamic_Handle      = 0 
 App_9_Volume_Dynamic_Handle      = 0 
 App_10_Volume_Dynamic_Handle     = 0 

; --- MEASURES BEGINNING

; - APP VOLUME TERMINATOR

[terminator.APP_VOLUME]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #App_Volume_Process# /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\#Log_App_Terminate#.log

; --- PROCESS CHEKERS BEGINNING

[sensor.PROCESS_APP_1_STATIC]
 Measure                          = PLUGIN
 Plugin                           = Process
 ProcessName                      = #App_Volume_1#
 DynamicVariables                 = 1
 Group                            = #app_volume_static_process# | #app_volume_controls_static# | #app_volume_controls_static_sensors#

     ifCondition                  = sensor.PROCESS_APP_1_STATIC = 1
          ifTrueAction            = [!SetOption t.App_Volume_1_Static FontColor "#*Font_Value_Color*#"][!UpdateMeter t.App_Volume_1_Static]
     ifCondition2                 = sensor.PROCESS_APP_1_STATIC = -1
          ifTrueAction2           = [!SetOption t.App_Volume_1_Static FontColor "#*Font_Color*#"][!UpdateMeter t.App_Volume_1_Static]
     onChangeAction               = [!UpdateMeasure m.App_1_Volume_Static]

[sensor.PROCESS_APP_2_STATIC]
 Measure                          = PLUGIN
 Plugin                           = Process
 ProcessName                      = #App_Volume_2#
 DynamicVariables                 = 1
 Group                            = #app_volume_static_process# | #app_volume_controls_static# | #app_volume_controls_static_sensors#

     ifCondition                  = sensor.PROCESS_APP_2_STATIC = 1
          ifTrueAction            = [!SetOption t.App_Volume_2_Static FontColor "#*Font_Value_Color*#"][!UpdateMeter t.App_Volume_2_Static]
     ifCondition2                 = sensor.PROCESS_APP_2_STATIC = -1
          ifTrueAction2           = [!SetOption t.App_Volume_2_Static FontColor "#*Font_Color*#"][!UpdateMeter t.App_Volume_2_Static]
     onChangeAction               = [!UpdateMeasure m.App_2_Volume_Static]

[sensor.PROCESS_APP_3_STATIC]
 Measure                          = PLUGIN
 Plugin                           = Process
 ProcessName                      = #App_Volume_3#
 DynamicVariables                 = 1
 Group                            = #app_volume_static_process# | #app_volume_controls_static# | #app_volume_controls_static_sensors#

     ifCondition                  = sensor.PROCESS_APP_3_STATIC = 1
          ifTrueAction            = [!SetOption t.App_Volume_3_Static FontColor "#*Font_Value_Color*#"][!UpdateMeter t.App_Volume_3_Static]
     ifCondition2                 = sensor.PROCESS_APP_3_STATIC = -1
          ifTrueAction2           = [!SetOption t.App_Volume_3_Static FontColor "#*Font_Color*#"][!UpdateMeter t.App_Volume_3_Static]
     onChangeAction               = [!UpdateMeasure m.App_3_Volume_Static]

[sensor.PROCESS_APP_4_STATIC]
 Measure                          = PLUGIN
 Plugin                           = Process
 ProcessName                      = #App_Volume_4#
 DynamicVariables                 = 1
 Group                            = #app_volume_static_process# | #app_volume_controls_static# | #app_volume_controls_static_sensors#
 
     ifCondition                  = sensor.PROCESS_APP_4_STATIC = 1
          ifTrueAction            = [!SetOption t.App_Volume_4_Static FontColor "#*Font_Value_Color*#"][!UpdateMeter t.App_Volume_3_Static]
     ifCondition2                 = sensor.PROCESS_APP_4_STATIC = -1
          ifTrueAction2           = [!SetOption t.App_Volume_4_Static FontColor "#*Font_Color*#"][!UpdateMeter t.App_Volume_3_Static]
     onChangeAction               = [!UpdateMeasure m.App_4_Volume_Static]
     

; --- SLIDERS BEGINNING

; --- STATIC SLIDERS BEGINNING

; - #1

[sensor.APP_1_VOLUME_STATIC_SLIDER]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_1_Volume_Static_Handle "(clamp($MouseX$,[b.App_1_Volume_Static:X],[b.App_1_Volume_Static:XW]))"][!UpdateMeasure sensor.APP_1_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_1_Volume_Static_Handle "(clamp($MouseX$,[b.App_1_Volume_Static:X],[b.App_1_Volume_Static:XW]))"][!CommandMeasure sensor.APP_1_VOLUME_STATIC_SLIDER "Stop"][!Delay 1][!UpdateMeasure sensor.APP_1_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[sensor.APP_1_VOLUME_STATIC_SLIDER_SET]
 Measure                            = Calc
 Formula                            = #App_1_Volume_Static_Handle#
 MinValue                           = [b.App_1_Volume_Static:X]
 MaxValue                           = ([b.App_1_Volume_Static:X] + [b.App_1_Volume_Static:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_1_Volume_Static "SetVolume [sensor.APP_1_VOLUME_STATIC_SLIDER_SET:%,0]"]
 Disabled                           = 1

; - #2

[sensor.APP_2_VOLUME_STATIC_SLIDER]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_2_Volume_Static_Handle "(clamp($MouseX$,[b.App_2_Volume_Static:X],[b.App_2_Volume_Static:XW]))"][!UpdateMeasure sensor.APP_2_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_2_Volume_Static_Handle "(clamp($MouseX$,[b.App_2_Volume_Static:X],[b.App_2_Volume_Static:XW]))"][!CommandMeasure sensor.APP_2_VOLUME_STATIC_SLIDER "Stop"][!Delay 1][!UpdateMeasure sensor.APP_2_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[sensor.APP_2_VOLUME_STATIC_SLIDER_SET]
 Measure                            = Calc
 Formula                            = #App_2_Volume_Static_Handle#
 MinValue                           = [b.App_2_Volume_Static:X]
 MaxValue                           = ([b.App_2_Volume_Static:X] + [b.App_2_Volume_Static:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_2_Volume_Static "SetVolume [sensor.APP_2_VOLUME_STATIC_SLIDER_SET:%,0]"]
 Disabled                           = 1

; - #3

[sensor.APP_3_VOLUME_STATIC_SLIDER]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_3_Volume_Static_Handle "(clamp($MouseX$,[b.App_3_Volume_Static:X],[b.App_3_Volume_Static:XW]))"][!UpdateMeasure sensor.APP_3_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_3_Volume_Static_Handle "(clamp($MouseX$,[b.App_3_Volume_Static:X],[b.App_3_Volume_Static:XW]))"][!CommandMeasure sensor.APP_3_VOLUME_STATIC_SLIDER "Stop"][!Delay 1][!UpdateMeasure sensor.APP_3_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[sensor.APP_3_VOLUME_STATIC_SLIDER_SET]
 Measure                            = Calc
 Formula                            = #App_3_Volume_Static_Handle#
 MinValue                           = [b.App_3_Volume_Static:X]
 MaxValue                           = ([b.App_3_Volume_Static:X] + [b.App_3_Volume_Static:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_3_Volume_Static "SetVolume [sensor.APP_3_VOLUME_STATIC_SLIDER_SET:%,0]"]
 Disabled                           = 1

; - #4

[sensor.APP_4_VOLUME_STATIC_SLIDER]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_4_Volume_Static_Handle "(clamp($MouseX$,[b.App_4_Volume_Static:X],[b.App_4_Volume_Static:XW]))"][!UpdateMeasure sensor.APP_4_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_4_Volume_Static_Handle "(clamp($MouseX$,[b.App_4_Volume_Static:X],[b.App_4_Volume_Static:XW]))"][!CommandMeasure sensor.APP_4_VOLUME_STATIC_SLIDER "Stop"][!Delay 1][!UpdateMeasure sensor.APP_4_VOLUME_STATIC_SLIDER_SET][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[sensor.APP_4_VOLUME_STATIC_SLIDER_SET]
 Measure                            = Calc
 Formula                            = #App_4_Volume_Static_Handle#
 MinValue                           = [b.App_4_Volume_Static:X]
 MaxValue                           = ([b.App_4_Volume_Static:X] + [b.App_4_Volume_Static:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_4_Volume_Static "SetVolume [sensor.APP_4_VOLUME_STATIC_SLIDER_SET:%,0]"]
 Disabled                           = 1

; - STATIC SLIDERS END

; --- DYNAMIC SLIDERS

; - #1

[m.App_1_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_1_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_1_Volume_Dynamic:X],[b.App_1_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_1_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_1_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_1_Volume_Dynamic:X],[b.App_1_Volume_Dynamic:XW]))"][!CommandMeasure m.App_1_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_1_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_1_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_1_Volume_Dynamic_Handle#
 MinValue                           = [b.App_1_Volume_Dynamic:X]
 MaxValue                           = ([b.App_1_Volume_Dynamic:X] + [b.App_1_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_1_Volume_Dynamic "SetVolume [m.App_1_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #2

[m.App_2_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_2_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_2_Volume_Dynamic:X],[b.App_2_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_2_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_2_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_2_Volume_Dynamic:X],[b.App_2_Volume_Dynamic:XW]))"][!CommandMeasure m.App_2_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_2_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_2_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_2_Volume_Dynamic_Handle#
 MinValue                           = [b.App_2_Volume_Dynamic:X]
 MaxValue                           = ([b.App_2_Volume_Dynamic:X] + [b.App_2_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_2_Volume_Dynamic "SetVolume [m.App_2_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #3

[m.App_3_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_3_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_3_Volume_Dynamic:X],[b.App_3_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_3_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_3_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_3_Volume_Dynamic:X],[b.App_3_Volume_Dynamic:XW]))"][!CommandMeasure m.App_3_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_3_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_3_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_3_Volume_Dynamic_Handle#
 MinValue                           = [b.App_3_Volume_Dynamic:X]
 MaxValue                           = ([b.App_3_Volume_Dynamic:X] + [b.App_3_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_3_Volume_Dynamic "SetVolume [m.App_3_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #4

[m.App_4_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_4_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_4_Volume_Dynamic:X],[b.App_4_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_4_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_4_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_4_Volume_Dynamic:X],[b.App_4_Volume_Dynamic:XW]))"][!CommandMeasure m.App_4_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_4_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_4_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_4_Volume_Dynamic_Handle#
 MinValue                           = [b.App_4_Volume_Dynamic:X]
 MaxValue                           = ([b.App_4_Volume_Dynamic:X] + [b.App_4_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_4_Volume_Dynamic "SetVolume [m.App_4_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #5

[m.App_5_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_5_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_5_Volume_Dynamic:X],[b.App_5_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_5_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_5_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_5_Volume_Dynamic:X],[b.App_5_Volume_Dynamic:XW]))"][!CommandMeasure m.App_5_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_5_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_5_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_5_Volume_Dynamic_Handle#
 MinValue                           = [b.App_5_Volume_Dynamic:X]
 MaxValue                           = ([b.App_5_Volume_Dynamic:X] + [b.App_5_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_5_Volume_Dynamic "SetVolume [m.App_5_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #6

[m.App_6_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_6_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_6_Volume_Dynamic:X],[b.App_6_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_6_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_6_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_6_Volume_Dynamic:X],[b.App_6_Volume_Dynamic:XW]))"][!CommandMeasure m.App_6_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_6_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_6_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_6_Volume_Dynamic_Handle#
 MinValue                           = [b.App_6_Volume_Dynamic:X]
 MaxValue                           = ([b.App_6_Volume_Dynamic:X] + [b.App_6_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_6_Volume_Dynamic "SetVolume [m.App_6_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #7

[m.App_7_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_7_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_7_Volume_Dynamic:X],[b.App_7_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_7_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_7_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_7_Volume_Dynamic:X],[b.App_7_Volume_Dynamic:XW]))"][!CommandMeasure m.App_7_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_7_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_7_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_7_Volume_Dynamic_Handle#
 MinValue                           = [b.App_7_Volume_Dynamic:X]
 MaxValue                           = ([b.App_7_Volume_Dynamic:X] + [b.App_7_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_7_Volume_Dynamic "SetVolume [m.App_7_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #8

[m.App_8_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_8_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_8_Volume_Dynamic:X],[b.App_8_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_8_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_8_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_8_Volume_Dynamic:X],[b.App_8_Volume_Dynamic:XW]))"][!CommandMeasure m.App_8_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_8_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_8_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_8_Volume_Dynamic_Handle#
 MinValue                           = [b.App_8_Volume_Dynamic:X]
 MaxValue                           = ([b.App_8_Volume_Dynamic:X] + [b.App_8_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_8_Volume_Dynamic "SetVolume [m.App_8_Volume_Dynamic_Slider_Set:%,0]"]
;UpdateDivider                      = -1
 Disabled                           = 1

; - #9

[m.App_9_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_9_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_9_Volume_Dynamic:X],[b.App_9_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_9_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_9_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_9_Volume_Dynamic:X],[b.App_9_Volume_Dynamic:XW]))"][!CommandMeasure m.App_9_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_9_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_9_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_9_Volume_Dynamic_Handle#
 MinValue                           = [b.App_9_Volume_Dynamic:X]
 MaxValue                           = ([b.App_9_Volume_Dynamic:X] + [b.App_9_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_9_Volume_Dynamic "SetVolume [m.App_9_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - #10

[m.App_10_Volume_Dynamic_Slider]
 Measure                            = Plugin
 Plugin                             = Mouse
 LeftMouseDragAction                = [!SetVariable App_10_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_10_Volume_Dynamic:X],[b.App_10_Volume_Dynamic:XW]))"][!UpdateMeasure m.App_10_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]
 LeftMouseUpAction                  = [!SetVariable App_10_Volume_Dynamic_Handle "(clamp($MouseX$,[b.App_10_Volume_Dynamic:X],[b.App_10_Volume_Dynamic:XW]))"][!CommandMeasure m.App_10_Volume_Dynamic_Slider "Stop"][!Delay 1][!UpdateMeasure m.App_10_Volume_Dynamic_Slider_Set][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]
 RelativeToSkin                     = 1
 RequireDragging                    = 1
 DynamicVariables                   = 1

[m.App_10_Volume_Dynamic_Slider_Set]
 Measure                            = Calc
 Formula                            = #App_10_Volume_Dynamic_Handle#
 MinValue                           = [b.App_10_Volume_Dynamic:X]
 MaxValue                           = ([b.App_10_Volume_Dynamic:X] + [b.App_10_Volume_Dynamic:W])
 DynamicVariables                   = 1
 InvertMeasure                      = 1
 OnUpdateAction                     = [!CommandMeasure m.App_10_Volume_Dynamic "SetVolume [m.App_10_Volume_Dynamic_Slider_Set:%,0]"]
 Disabled                           = 1

; - DYNAMIC SLIDERS END

; - SLIDERS END

; --- PARENT MEASURES BEGINNING

[m.App_Volume_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 IgnoreSystemSound                = 1
 ExcludeApp                       = rainmeter.exe; 
 DynamicVariables                 = 1

     onChangeAction               = [!UpdateMeasure m.App_1_Volume_Static][!UpdateMeasure m.App_1_Peaks_Static][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeasure m.App_2_Peaks_Static][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeasure m.App_3_Peaks_Static][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeasure m.App_4_Peaks_Static]

[m.App_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 IgnoreSystemSound                = 1
 ExcludeApp                       = #App_Volume_1#; #App_Volume_2#; #App_Volume_3#; #App_Volume_4#;
 Substitute                       = ".exe":""
 DynamicVariables                 = 1

     onChangeAction               = 

; - PARENT MEASURES END

; --- STATIC MEASURES BEGINNING

; - #1

[m.App_1_Volume_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_1#
 NumberType                       = Volume
 StringType                       = Filepath
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_1_Volume_Static]

[m.App_1_Peaks_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_1#
 NumberType                       = Peak
 StringType                       = Filename
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_1_Peaks_Static]

; - #2

[m.App_2_Volume_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_2#
 NumberType                       = Volume
 StringType                       = Filepath
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_2_Volume_Static]

[m.App_2_Peaks_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_2#
 NumberType                       = Peak
 StringType                       = Filename
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_2_Peaks_Static]

; - #3

[m.App_3_Volume_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_3#
 NumberType                       = Volume
 StringType                       = Filepath
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_3_Volume_Static]

[m.App_3_Peaks_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_3#
 NumberType                       = Peak
 StringType                       = Filename
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_3_Peaks_Static]

; - #4

[m.App_4_Volume_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_4#
 NumberType                       = Volume
 StringType                       = Filepath
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_4_Volume_Static]

[m.App_4_Peaks_Static]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Static
 AppName                          = #App_Volume_4#
 NumberType                       = Peak
 StringType                       = Filename
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static# | #app_volume_controls_static_sensors#
     onChangeAction               = [!UpdateMeter b.App_4_Peaks_Static]

; - STATIC MEASURES END

; --- DYNAMIC MEASURES BEGINNING

; - #1

[m.App_1_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 1
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_1_Volume_Dynamic]

[m.App_1_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 1
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_1_Peaks_Dynamic]

; - #2

[m.App_2_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 2
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_2_Volume_Dynamic]

[m.App_2_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 2
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_2_Peaks_Dynamic]

; - #3

[m.App_3_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 3
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_3_Volume_Dynamic]

[m.App_3_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 3
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_3_Peaks_Dynamic]

; - #4

[m.App_4_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 4
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_4_Volume_Dynamic]

[m.App_4_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 4
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_4_Peaks_Dynamic]

; - #5

[m.App_5_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 5
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_5_Volume_Dynamic]

[m.App_5_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 5
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_5_Peaks_Dynamic]

; - #6

[m.App_6_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 6
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_6_Volume_Dynamic]

[m.App_6_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 6
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_6_Peaks_Dynamic]

; - #7

[m.App_7_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 7
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_7_Volume_Dynamic]

[m.App_7_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 7
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_7_Peaks_Dynamic]

; - #8

[m.App_8_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 8
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_8_Volume_Dynamic]

[m.App_8_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 8
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_8_Peaks_Dynamic]

; - #9

[m.App_9_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 9
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_9_Volume_Dynamic]

[m.App_9_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 9
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_9_Peaks_Dynamic]

; - #10

[m.App_10_Volume_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 10
 NumberType                       = Volume
 StringType                       = Filename
 Substitute                       = ".exe":""
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_10_Volume_Dynamic]

[m.App_10_Peaks_Dynamic]
 Measure                          = PLUGIN
 Plugin                           = AppVolume
 Parent                           = m.App_Volume_Dynamic
 Index                            = 10
 NumberType                       = Peak
 StringType                       = Filename
 Group                            = #app_volume_controls_dynamic# | #app_volume_controls_dynamic_sensors#
     onChangeAction               = [!UpdateMeter b.App_10_Peaks_Dynamic]

; - DYNAMIC MEASURES END

; - MEASURES END

; --- BARS BEGINNING

; --- STATIC BARS BEGINNING

; - #1

[f.b.App_1_Volume_Static_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 70
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#

[b.App_1_Volume_Static]
 Meter                            = BAR
 MeasureName                      = m.App_1_Volume_Static
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_1_Volume_Static_Y]; 0
 W                                = 100
 X                                = 1780
 Y                                = [f.b.App_1_Volume_Static_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#
 MiddleMouseUpAction              = [!SetVariable App_Volume_Process "[m.App_1_Volume_Static:1,0]"][!CommandMeasure terminator.APP_VOLUME "Run"][!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_1_Volume_Static "SetVolume +5"][!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_1_Volume_Static "SetVolume -5"][!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.APP_1_VOLUME_STATIC_SLIDER "Start"][!EnableMeasure sensor.APP_1_VOLUME_STATIC_SLIDER_SET]
 RightMouseUpAction               = [!CommandMeasure m.App_1_Volume_Static "ToggleMute"][[!UpdateMeasure m.App_1_Volume_Static][!UpdateMeter b.App_1_Volume_Static][!Redraw]

[b.App_1_Peaks_Static]
 Meter                            = BAR
 MeasureName                      = m.App_1_Peaks_Static
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 W                                = 98
 H                                = 1
 X                                = (1807 + #Pad_Top#)
 Y                                = (#Pad_Top# + 70)
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; - #2

[f.b.App_2_Volume_Static_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 90
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#

[b.App_2_Volume_Static]
 Meter                            = BAR
 MeasureName                      = m.App_2_Volume_Static
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_2_Volume_Static_Y]; 0
 W                                = 100
 X                                = 1765
 Y                                = [f.b.App_2_Volume_Static_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_2_Volume_Static "ToggleMute"][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_2_Volume_Static "SetVolume +5"][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_2_Volume_Static "SetVolume -5"][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.APP_2_VOLUME_STATIC_SLIDER "Start"][!EnableMeasure sensor.APP_2_VOLUME_STATIC_SLIDER_SET]
 RightMouseUpAction               = [!CommandMeasure m.App_2_Volume_Static "SetVolume 0"][!UpdateMeasure m.App_2_Volume_Static][!UpdateMeter b.App_2_Volume_Static][!Redraw]

[b.App_2_Peaks_Static]
 Meter                            = BAR
 MeasureName                      = m.App_2_Peaks_Static
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 W                                = 98
 H                                = 1
 X                                = (1812 + #Pad_Top#)
 Y                                = (#Pad_Top# + 90)
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

[f.b.App_3_Volume_Static_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 120
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#

; - #3

[b.App_3_Volume_Static]
 Meter                            = BAR
 MeasureName                      = m.App_3_Volume_Static
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_3_Volume_Static_Y]; 0
 W                                = 100
 X                                = 1758
 Y                                = [f.b.App_3_Volume_Static_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_3_Volume_Static "ToggleMute"][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_3_Volume_Static "SetVolume +5"][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_3_Volume_Static "SetVolume -5"][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.APP_3_VOLUME_STATIC_SLIDER "Start"][!EnableMeasure sensor.APP_3_VOLUME_STATIC_SLIDER_SET]
 RightMouseUpAction               = [!CommandMeasure m.App_3_Volume_Static "SetVolume 0"][!UpdateMeasure m.App_3_Volume_Static][!UpdateMeter b.App_3_Volume_Static][!Redraw]

[b.App_3_Peaks_Static]
 Meter                            = BAR
 MeasureName                      = m.App_3_Peaks_Static
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 W                                = 98
 H                                = 1
 X                                = (1849 + #Pad_Top#)
 Y                                = (#Pad_Top# + 127)
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; - #1

[f.b.App_4_Volume_Static_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 140
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#

[b.App_4_Volume_Static]
 Meter                            = BAR
 MeasureName                      = m.App_4_Volume_Static
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_4_Volume_Static_Y]; 0
 W                                = 100
 X                                = 1772
 Y                                = [f.b.App_4_Volume_Static_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_4_Volume_Static "ToggleMute"][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_4_Volume_Static "SetVolume +5"][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_4_Volume_Static "SetVolume -5"][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.APP_4_VOLUME_STATIC_SLIDER "Start"][!EnableMeasure sensor.APP_4_VOLUME_STATIC_SLIDER_SET]
 RightMouseUpAction               = [!CommandMeasure m.App_4_Volume_Static "SetVolume 0"][!UpdateMeasure m.App_4_Volume_Static][!UpdateMeter b.App_4_Volume_Static][!Redraw]

[b.App_4_Peaks_Static]
 Meter                            = BAR
 MeasureName                      = m.App_4_Peaks_Static
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 W                                = 98
 H                                = 1
 X                                = (1883 + #Pad_Top#)
 Y                                = (#Pad_Top# + 147)
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; - STATIC BARS END

; --- DYNAMIC BARS BEGINNING

; - Don't look at numbers in measures. Real order numbers are commented!

; - #1 is top, #10 is bottom

; - #1

[f.b.App_1_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 45
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_1_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_1_Volume_Dynamic
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_1_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1785
 Y                                = [f.b.App_1_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_1_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_1_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_1_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_1_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_1_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_1_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_1_Volume_Dynamic][!UpdateMeter b.App_1_Volume_Dynamic][!Redraw]

[b.App_1_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_1_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 W                                = 98
 H                                = 1
 X                                = (1787 + #Pad_Top#)
 Y                                = (#Pad_Top# + 45)
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #2

[f.b.App_10_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 58
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_10_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_10_Volume_Dynamic
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_10_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1775
 Y                                = [f.b.App_10_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_10_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_10_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_10_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_10_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_10_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_10_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_10_Volume_Dynamic][!UpdateMeter b.App_10_Volume_Dynamic][!Redraw]

[f.b.App_10_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 58
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_10_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_10_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_10_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1777
 Y                                = [f.b.App_10_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #3

[f.b.App_3_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 71
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_3_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_3_Volume_Dynamic
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_3_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1765
 Y                                = [f.b.App_3_Volume_Dynamic_Y]
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 DynamicVariables                 = 1
 MiddleMouseUpAction              = [!CommandMeasure m.App_3_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_3_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_3_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_3_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_3_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_3_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_3_Volume_Dynamic][!UpdateMeter b.App_3_Volume_Dynamic][!Redraw]

[f.b.App_3_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 71
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_3_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_3_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_3_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1767
 Y                                = [f.b.App_3_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #4

[f.b.App_8_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 84
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_8_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_8_Volume_Dynamic
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_8_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1753
 Y                                = [f.b.App_8_Volume_Dynamic_Y]
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 DynamicVariables                 = 1
 MiddleMouseUpAction              = [!CommandMeasure m.App_8_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_8_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_8_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_8_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_8_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_8_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_8_Volume_Dynamic][!UpdateMeter b.App_8_Volume_Dynamic][!Redraw]

[f.b.App_8_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 84
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_8_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_8_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_8_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1755
 Y                                = [f.b.App_8_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #5

[f.b.App_5_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 97
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_5_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_5_Volume_Dynamic
 MeterStyle                       = b.LongBarRightTop
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_5_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1741
 Y                                = [f.b.App_5_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_5_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_5_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_5_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_5_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_5_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_5_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_5_Volume_Dynamic][!UpdateMeter b.App_5_Volume_Dynamic][!Redraw]

[f.b.App_5_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 97
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_5_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_5_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; -1; 1; [f.b.App_5_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1743
 Y                                = [f.b.App_5_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #6

[f.b.App_6_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 116
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_6_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_6_Volume_Dynamic
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_6_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1733
 Y                                = [f.b.App_6_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_6_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_6_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_6_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_6_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_6_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_6_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_6_Volume_Dynamic][!UpdateMeter b.App_6_Volume_Dynamic][!Redraw]

[f.b.App_6_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 123
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_6_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_6_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_BOTTOM_PEAKS
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_6_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1741
 Y                                = [f.b.App_6_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #7

[f.b.App_7_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 129
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_7_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_7_Volume_Dynamic
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_7_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1745
 Y                                = [f.b.App_7_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_7_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_7_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_7_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_7_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_7_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_7_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_7_Volume_Dynamic][!UpdateMeter b.App_7_Volume_Dynamic][!Redraw]

[f.b.App_7_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 136
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_7_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_7_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_7_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1754
 Y                                = [f.b.App_7_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #8

[f.b.App_4_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 142
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_4_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_4_Volume_Dynamic
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_4_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1757
 Y                                = [f.b.App_4_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_4_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_4_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_4_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_4_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_4_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_4_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_4_Volume_Dynamic][!UpdateMeter b.App_4_Volume_Dynamic][!Redraw]

[f.b.App_4_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 149
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_4_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_4_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_4_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1766
 Y                                = [f.b.App_4_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #9

[f.b.App_9_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 155
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_9_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_9_Volume_Dynamic
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_9_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1769
 Y                                = [f.b.App_9_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_9_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_9_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_9_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_9_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_9_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_9_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_9_Volume_Dynamic][!UpdateMeter b.App_9_Volume_Dynamic][!Redraw]

[f.b.App_9_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 162
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_9_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_9_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_9_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1778
 Y                                = [f.b.App_9_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - #10

[f.b.App_2_Volume_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 168
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_2_Volume_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_2_Volume_Dynamic
 MeterStyle                       = b.LongBarRightBottom
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_2_Volume_Dynamic_Y]; 0
 W                                = 100
 X                                = 1781
 Y                                = [f.b.App_2_Volume_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#
 MiddleMouseUpAction              = [!CommandMeasure m.App_2_Volume_Dynamic "ToggleMute"][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.App_2_Volume_Dynamic "SetVolume +5"][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.App_2_Volume_Dynamic "SetVolume -5"][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.App_2_Volume_Dynamic_Slider "Start"][!EnableMeasure m.App_2_Volume_Dynamic_Slider_Set]
 RightMouseUpAction               = [!CommandMeasure m.App_2_Volume_Dynamic "SetVolume 0"][!UpdateMeasure m.App_2_Volume_Dynamic][!UpdateMeter b.App_2_Volume_Dynamic][!Redraw]

[f.b.App_2_Peaks_Dynamic_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 175
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#

[b.App_2_Peaks_Dynamic]
 Meter                            = BAR
 MeasureName                      = m.App_2_Peaks_Dynamic
 MeterStyle                       = style.bar.LONG_BAR_RIGHT_TOP_PEAKS
 TransformationMatrix             = 1; 0; 1; 1; -[f.b.App_2_Peaks_Dynamic_Y]; 0
 W                                = 98
 H                                = 1
 X                                = 1790
 Y                                = [f.b.App_2_Peaks_Dynamic_Y]
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - DYNAMIC BARS END

; - BARS END

; --- TEXTS BEGINNING

; --- STATIC TEXTS BEGINNING

; #1

[t.App_Volume_1_Static]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1750
 Y                                = (#Pad_Top# + 67)
 FonSize                          = 10
 Text                             = #App_Volume_1S#
 StringCase                       = Upper
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; #2

[t.App_Volume_2_Static]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1737
 Y                                = (#Pad_Top# + 85)
 W                                = 60
 FonSize                          = 10
 Text                             = #App_Volume_2S#
 DynamicVariables                 = 1
 StringCase                       = Upper
 ClipString                       = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; #3

[t.App_Volume_3_Static]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1737
 Y                                = (#Pad_Top# + 117)
 FonSize                          = 10
 Text                             = #App_Volume_3S#
 StringCase                       = Upper
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; #4

[t.App_Volume_4_Static]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1750
 Y                                = (#Pad_Top# + 137)
 FonSize                          = 10
 Text                             = #App_Volume_4S#
 StringCase                       = Upper
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_static#
 Hidden                           = #App_Volume_Control_Static_State#

; - STATIC TEXTS END

; --- DYNAMIC TEXTS BEGINNING

; - Don't look at numbers in measures. Real order numbers are commented! Order is confused to prevent usual 1-2-3-etc order in bar's list to make this more interesting 

; - #1 is top, #10 is bottom

; #1

[t.App_Volume_1_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_1_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1765
 Y                                = (#Pad_Top# + 40)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #2

[t.App_Volume_10_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_10_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1755
 Y                                = (#Pad_Top# + 53)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #3

[t.App_Volume_3_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_3_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1745
 Y                                = (#Pad_Top# + 66)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #4

[t.App_Volume_8_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_8_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1735
 Y                                = (#Pad_Top# + 79)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #5

[t.App_Volume_5_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_5_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1725
 Y                                = (#Pad_Top# + 92)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #6

[t.App_Volume_6_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_6_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1725
 Y                                = (#Pad_Top# + 111)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #7

[t.App_Volume_7_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_7_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1735
 Y                                = (#Pad_Top# + 124)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #8

[t.App_Volume_4_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_4_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1745
 Y                                = (#Pad_Top# + 137)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #9

[t.App_Volume_9_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_9_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1755
 Y                                = (#Pad_Top# + 150)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; #10

[t.App_Volume_2_Dynamic]
 Meter                            = STRING
 MeasureName                      = m.App_2_Volume_Dynamic
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1765
 Y                                = (#Pad_Top# + 163)
 FonSize                          = 10
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #app_volume_controls_dynamic#
 Hidden                           = #App_Volume_Control_Dyna_State#

; - DYNAMIC TEXTS END

; - TEXTS END
