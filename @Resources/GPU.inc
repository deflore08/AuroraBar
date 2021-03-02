[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = All GPU Meters, measures, bars, graphs, text in section 7
 
; --- MEASURES
 
[sensor.GPU_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 MinValue                         = 0
 MaxValue                         = 100
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_sensors# | #sensors#
     onUpdateAction               = [!UpdateMeter text.dynamic.GPU_LOAD_VALUE][!UpdateMeter bar.GPU_LOAD][!UpdateMeter histogram.GPU_LOAD][!UpdateMeter text.dynamic.GPU_TEMPERATURE_VALUE][!UpdateMeter bar.GPU_TEMPERATURE][!UpdateMeter histogram.GPU_TEMPERATURE]
     
     ifCondition                  = sensor.GPU_LOAD < #GPU_Load_Max#
          ifTrueAction            = [!SetOption text.dynamic.GPU_LOAD_VALUE FontColor "#Font_Value_Color#"]
     ifCondition2                 = (sensor.GPU_LOAD > #GPU_Load_Max#) || (sensor.GPU_LOAD = #GPU_Load_Max#)
          ifTrueAction2           = [!SetOption text.dynamic.GPU_LOAD_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

[sensor.GPU_TEMPERATURE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Temp-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Temp-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Temp-EntryId#
 HWiNFOType                       = CurrentValue
 MinValue                         = 0
 MaxValue                         = 100
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_sensors# | #sensors#
;     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TEMPERATURE_VALUE][!UpdateMeter bar.GPU_TEMPERATURE][!UpdateMeter histogram.GPU_TEMPERATURE]

     ifCondition                  = sensor.GPU_TEMPERATURE < #GPU_Temp_Max#
          ifTrueAction            = [!SetOption text.dynamic.GPU_TEMPERATURE_VALUE FontColor "#Font_Value_Color#"]
     ifCondition2                 = (sensor.GPU_TEMPERATURE > #GPU_Temp_Max#) || (sensor.GPU_TEMPERATURE = #GPU_Temp_Max#)
          ifTrueAction2           = [!SetOption text.dynamic.GPU_TEMPERATURE_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

[sensor.GPU_CLOCK]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Clock-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Clock-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Clock-EntryId#
 HWiNFOType                       = CurrentValue
 Substitute                       = "":"M","k":"G"
 DynamicVariables                 = 1
 Group                            = #gpu# | #clock_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_CLOCK_VALUE]

[sensor.GPU_POWER]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-PowerW-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-PowerW-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-PowerW-EntryId#
 HWiNFOType                       = CurrentValue
 DynamicVariables                 = 1
 Disabled                         = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_POWER_VALUE]

[sensor.GPU_VOLTAGE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Voltage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Voltage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Voltage-EntryId#
 HWiNFOType                       = CurrentValue
 DynamicVariables                 = 1
 Disabled                         = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_VOLTAGE_VALUE]

[sensor.GPU_BUS_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-BusLoad-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-BusLoad-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-BusLoad-EntryId#
 HWiNFOType                       = CurrentValue
 DynamicVariables                 = 1
 Disabled                         = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_BUS_LOAD_VALUE]

[sensor.GPU_MEMORY_CLOCK]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-MemoryClock-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-MemoryClock-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-MemoryClock-EntryId#
 HWiNFOType                       = CurrentValue
 Substitute                       = "":"M","k":"G"
 DynamicVariables                 = 1
 Disabled                         = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_MEMORY_CLOCK_VALUE]
 
[sensor.GPU_NAME]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Usage-SensorInstance#
 HWiNFOType                       = SensorName
 RegExpSubstitute                 = 1
 Substitute                       = "^(.*]: )":"","(: .*)$":""
 Group                            = #gpu# | #gpu_info# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_NAME]
 
; --- TEXTS

[text.static.GPU_LOAD]
 Meter                            = STRING
 X                                = 1460
 Y                                = (#Pad_Top# + 60)
 MeterStyle                       = style.text.Simple_Font_Right_Align
 Text                             = "GPU LOAD"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_texts# | #texts#

[text.static.GPU_TEMPERATURE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1460
 Y                                = (#Pad_Top# + 149)
 Text                             = "GPU TEMP"
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_texts# | #texts#

[text.dynamic.GPU_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_LOAD
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1285
 Y                                = (#Pad_Top# + 60)
 W                                = 90
 H                                = 15
 Text                             = "%1%"
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_values# | #values#

[text.dynamic.GPU_TEMPERATURE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_TEMPERATURE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1285
 Y                                = (#Pad_Top# + 149)
 Text                             = "%1 C"
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_values# | #values#

[text.dynamic.GPU_NAME]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_NAME
 X                                = 1400
 Y                                = (#Pad_Top# + 10)
 W                                = 157
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Center_Align
 ClipString                       = 1
 Text                             = %1
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_info# | #gpu_values# | #values#

[text.dynamic.GPU_POWER_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_POWER
 X                                = 1415
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 ClipString                       = 1
 Text                             = W %1
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_values# | #values#

[text.static.GPU_POWER_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_POWER
 X                                = 0r
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Left_Align
 ClipString                       = 1
 Text                             = "  : Power"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_texts# | #texts#

[text.dynamic.GPU_VOLTAGE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_VOLTAGE
 X                                = 1443
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 ClipString                       = 1
 Text                             = V %1
 NumOfDecimals                    = 2
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_values# | #values#

[text.static.GPU_VOLTAGE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_VOLTAGE
 X                                = 0r
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Left_Align
 ClipString                       = 1
 Text                             = "  : Voltage"
 NumOfDecimals                    = 2
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_texts# | #texts#

[text.dynamic.GPU_MEMORY_CLOCK_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_MEMORY_CLOCK
 X                                = 1471
 Y                                = (#Pad_Top# - 75)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 ClipString                       = 1
 Text                             = %1Hz
 NumOfDecimals                    = 2
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_values# | #values#

[text.static.GPU_MEMORY_CLOCK]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_MEMORY_CLOCK
 X                                = 0r
 Y                                = (#Pad_Top# - 75)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Left_Align
 ClipString                       = 1
 Text                             = "  : Memory"
 NumOfDecimals                    = 2
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_texts# | #texts#

[text.dynamic.GPU_BUS_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_BUS_LOAD
 X                                = 1499
 Y                                = (#Pad_Top# - 103)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 ClipString                       = 1
 Text                             = %1%
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_values# | #values#

[text.static.GPU_BUS_LOAD]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_BUS_LOAD
 X                                = 0r
 Y                                = (#Pad_Top# - 103)
 W                                = 80
 SolidColor                       = 0,0,0,0
 MeterStyle                       = style.text.Simple_Font_Left_Align
 ClipString                       = 1
 Text                             = "  : Bus"
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu# | #gpu_info# | #gpu_texts# | #texts#

[text.static.GPU_LOAD_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontRightAlign
 FontColor                        = #Global_Color#
 X                                = 1455
 Y                                = (#Pad_Top# + 81)
 Text                             = "MIN %"
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_texts# | #texts#

[text.static.GPU_LOAD_AND_TEMPERATURE_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontRightAlign
 FontColor                        = #Global_Color#
 X                                = 1445
 Y                                = (#Pad_Top# + 105)
 Text                             = "MAX C %"
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_texts# | #texts#

[text.static.GPU_TEMPERATURE_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontRightAlign
 FontColor                        = #Global_Color#
 X                                = 1455
 Y                                = (#Pad_Top# + 129)
 Text                             = "MIN C"
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_texts# | #texts#

; --- BARS

[bar.GPU_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.GPU_LOAD
 MeterStyle                       = b.LongBarRightTop
 X                                = (1290 + #Pad_Top#)
 Y                                = (#Pad_Top# + 46)
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_bars# | #bars#

[bar.GPU_TEMPERATURE]
 Meter                            = BAR
 MeasureName                      = sensor.GPU_TEMPERATURE
 MeterStyle                       = b.LongBarRightBottom
 X                                = (1070 - #Pad_Top#)
 Y                                = (#Pad_Top# + 167)
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_bars# | #bars#
 
; --- HISTOGRAMS

[formula_GPU_LOAD_HISTOGRAM_Y]
 Measure                          = CALC
 Formula                          = (#Pad_Top# + 87)
 DynamicVariables                 = 1

[histogram.GPU_LOAD]
 Meter                            = LINE
 MeasureName                      = sensor.GPU_LOAD
 X                                = #GPU_Histogram_X#
 Y                                = (#Pad_Top# + 87)
 W                                = #GPU_Histogram_Width#
 H                                = #GraphHeight#
 LineWidth                        = 0.2
 LineColor                        = #Global_Color#
 SolidColor                       = 0,0,0,0
 AutoScale                        = 0
 AntiAlias                        = 0
 GraphOrientation                 = Vertical
; TransformationMatrix             = 1; 0; -1; 1; [formula_GPU_LOAD_HISTOGRAM_Y]; 0
 Flip                             = 1
 GraphStart                       = Left
 ToolTipIcon                      = Info
 ToolTipTitle                     = GPU Loading Graph
 ToolTipText                      = Left click or drag: set player volume#CRLF#Scroll: change volume#CRLF#Middle click: toggle mute#CRLF#Right click: max volume
 ToolTipHidden                    = #ToolTips_State#
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_histograms# | #histograms#

[formula_GPU_TEMPERATURE_HISTOGRAM_Y]
 Measure                          = CALC
 Formula                          = (#Pad_Top# + 112)
 DynamicVariables                 = 1

[histogram.GPU_TEMPERATURE]
 Meter                            = LINE
 MeasureName                      = sensor.GPU_TEMPERATURE
 X                                = #GPU_Histogram_X#
 Y                                = (#Pad_Top# + 112)
 W                                = #GPU_Histogram_Width#
 H                                = #GraphHeight#
 LineWidth                        = 0.2
 LineColor                        = #Global_Color#
 SolidColor                       = 0,0,0,0
 AutoScale                        = 0
 AntiAlias                        = 0
 GraphOrientation                 = Vertical
; TransformationMatrix             = 1; 0; 1; 1; -[formula_GPU_TEMPERATURE_HISTOGRAM_Y]; 0
 Flip                             = 0
 GraphStart                       = Left
 ToolTipIcon                      = Info
 ToolTipTitle                     = GPU Temp Graph
 ToolTipText                      = Left click or drag: set player volume#CRLF#Scroll: change volume#CRLF#Middle click: toggle mute#CRLF#Right cick: max volume
 ToolTipHidden                    = #ToolTips_State#
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_histograms# | #histograms#

[shape.GPU_HISTOGRAM_MOUSE_SLIDER]
 Meter                            = SHAPE
 X                                = #GPU_Histogram_X#
 Y                                = (#Pad_Top# + 87)
 Shape                            = Rectangle 0,0,#GPU_Histogram_Width#,49 | Extend MyModifiers1
 MyModifiers1                     = Fill Color 0,0,0,1 | StrokeWidth 0 | Stroke Color 46,115,31,255
 DynamicVariables                 = 1
 Group                            = #gpu# | #gpu_histograms# | #histograms#
 MouseActionCursorName            = #Cursor_Slider_X#
 MouseScrollDownAction            = [!CommandMeasure sensor.PLAYER "SetVolume -#Player_Volume_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeter b.Player_Volume][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure sensor.PLAYER "SetVolume +#Player_Volume_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeter b.Player_Volume][!Redraw]
 MiddleMouseUpAction              = [!CommandMeasure sensor.PLAYER "SetVolume 0"][!UpdateMeasure sensor.PLAYER][!UpdateMeter b.Player_Volume][!Redraw]
 RightMouseUpAction               = [!CommandMeasure sensor.PLAYER "SetVolume 100"][!UpdateMeasure sensor.PLAYER][!UpdateMeter b.Player_Volume][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.GPU_Volume_Slider "Start"][!EnableMeasure m.GPU_Volume_Slider_Set][!Redraw]