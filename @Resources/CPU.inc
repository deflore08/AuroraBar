[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = All CPU meters, measures, bars, graphs, text and other. It's 3, 4, 6 and 7 sections.

; --- MEASURES BEGINNING
 
[sensor.CPU_NAME]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-Usage-SensorInstance#
 HWiNFOType                       = SensorName
 HWiNFOLogHandler                 = 3
 RegExpSubstitute                 = 1
 Substitute                       = "^(.*]: )":"","(: .*)$":""
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_NAME]
 
[sensor.CPU_CLOCK]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-UncoreClock-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-UncoreClock-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-UncoreClock-EntryId#
 HWiNFOType                       = CurrentValue
 Substitute                       = "":"M","k":"G"
 DynamicVariables                 = 1
 Group                            = #cpu# | #clock_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure sensor.CPU_CLOCK_CORE_0][!UpdateMeter text.dynamic.CPU_CLOCK_VALUE]

[sensor.CPU_CLOCK_CORE_0]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-Clock-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-Clock-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-Clock-EntryId#
 HWiNFOType                       = CurrentValue
 Substitute                       = "":"M","k":"G"
 DynamicVariables                 = 1
 Group                            = #cpu# | #clock_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_CLOCK_CORE_0_VALUE]

[sensor.CPU_TEMPERATURE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-CoreMax-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-CoreMax-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-CoreMax-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 1
 MinValue                         = 0
 MaxValue                         = 97
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TEMPERATURE_VALUE][!UpdateMeter bar.CPU_TEMPERATURE][!UpdateMeter histogram.CPU_TEMPERATURE]

     ifCondition                  = sensor.CPU_TEMPERATURE < #CPU_Temp_Max#
          ifTrueAction            = [!SetOption text.dynamic.CPU_TEMPERATURE_VALUE FontColor "#Font_Value_Color#"][!SetVariable CPU_Temp_Health "0"]
     ifCondition2                 = (sensor.CPU_TEMPERATURE > #CPU_Temp_Max#) || (sensor.CPU_TEMPERATURE = #CPU_Temp_Max#)
          ifTrueAction2           = [!SetOption text.dynamic.CPU_TEMPERATURE_VALUE FontColor "#Font_Warning_Color#"][!SetVariable CPU_Temp_Health "1"]
     ifConditionMode              = 1

[sensor.CPU_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_LOAD_VALUE][!UpdateMeter bar.CPU_LOAD][!UpdateMeter histogram.CPU_LOAD][!UpdateMeasureGroup #cpu_cores#]

     ifCondition                  = sensor.CPU_LOAD < #CPU_Load_Max#
          ifTrueAction            = [!SetOption text.dynamic.CPU_LOAD_VALUE FontColor "#Font_Value_Color#"][!SetVariable CPU_Load_Health "0"]
     ifCondition2                 = (sensor.CPU_LOAD > #CPU_Load_Max#) || (sensor.CPU_LOAD = #CPU_Load_Max#)
          ifTrueAction2           = [!SetOption text.dynamic.CPU_LOAD_VALUE FontColor "#Font_Warning_Color#"][!SetVariable CPU_Load_Health "1"]
     ifConditionMode              = 1

[sensor.CPU_BUS_CLOCK]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-BusClock-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-BusClock-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-BusClock-EntryId#
 HWiNFOType                       = CurrentValue
 Substitute                       = "":"M","k":"G"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_info# | #cpu_sensors# | #sensors#
 Disabled                         = #CPU_Info_Measures_State#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_BUS_CLOCK_VALUE]

[sensor.CPU_VOLTAGE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-VID-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-VID-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-VID-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Disabled                         = #CPU_Info_Measures_State#
 Group                            = #cpu# | #cpu_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_VOLTAGE_VALUE]

[sensor.CPU_RATIO]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-UncoreRatio-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-UncoreRatio-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-UncoreRatio-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Disabled                         = #CPU_Info_Measures_State#
 Group                            = #cpu# | #cpu_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_RATIO_VALUE]

[sensor.CPU_POWER]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-Power-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-Power-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-Power-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Disabled                         = #CPU_Info_Measures_State#
 Group                            = #cpu# | #cpu_info# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_POWER_VALUE]

[sensor.CPU_THREADS]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Category                         = System
 Counter                          = Threads
 Index                            = 0
 Group                            = #cpu# | #threads# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_THREADS_VALUE]

[sensor.CPU_PROCESSES]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Category                         = System
 Counter                          = Processes
 Index                            = 0 
 DynamicVariables                 = 1
 Disabled                         = #Threads_Measures_State#
 Group                            = #cpu# | #threads# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_PROCESSES_VALUE]

[sensor.CORE_1_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU1-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU1-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU1-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter bar.CPU_CORE_1_LOAD]
 
[sensor.CORE_2_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU2-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU2-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU2-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_2_LOAD]
 
[sensor.CORE_3_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU3-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU3-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU3-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_3_LOAD]
 
[sensor.CORE_4_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU4-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU4-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU4-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_4_LOAD]
 
[sensor.CORE_5_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU5-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU5-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU5-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_5_LOAD]
 
[sensor.CORE_6_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU6-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU6-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU6-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_6_LOAD]
 
[sensor.CORE_7_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU7-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU7-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU7-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_7_LOAD]
 
[sensor.CORE_8_LOAD]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU8-Usage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU8-Usage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU8-Usage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #cpu# | #cpu_cores# | #cpu_sensors# | #sensors#
    onChangeAction                = [!UpdateMeter bar.CPU_CORE_8_LOAD]
 
; --- TEXTS

[text.static.CPU_LOAD]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 465
 Y                                = (#Pad_Top# + 60)
 Text                             = "CPU LOAD"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_TEMPERATURE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 465
 Y                                = (#Pad_Top# + 149)
 Text                             = "CPU TEMP"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.dynamic.CPU_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_LOAD
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 640
 Y                                = (#Pad_Top# + 60)
 W                                = 90
 H                                = 15
 Text                             = %1%
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_values# | #values#

[text.dynamic.CPU_TEMPERATURE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_TEMPERATURE
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 640
 Y                                = (#Pad_Top# + 149)
 Text                             = "%1 C"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_values# | #values#

[text.static.CPU_CORE_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 700
 Y                                = (#Pad_Top# + 42)
 Text                             = "CORE 1"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 710
 Y                                = (#Pad_Top# + 58)
 Text                             = "CORE 2"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1260
 Y                                = (#Pad_Top# + 42)
 Text                             = "3 CORE"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_4]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1250
 Y                                = (#Pad_Top# + 58)
 Text                             = "4 CORE"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_5]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 710
 Y                                = (#Pad_Top# + 150)
 Text                             = "CORE 5"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_6]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 700
 Y                                = (#Pad_Top# + 167)
 Text                             = "CORE 6"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_7]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1250
 Y                                = (#Pad_Top# + 150)
 Text                             = "7 CORE"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_CORE_8]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 1260
 Y                                = (#Pad_Top# + 167)
 Text                             = "8 CORE"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.dynamic.CPU_CLOCK_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_CLOCK
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 X                                = 1150
 Y                                = (#Pad_Top# + 10)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = %1Hz
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #cpu# | #clock_info# | #cpu_values# | #values#

[text.static.CPU_CLOCK]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 20r
 Y                                = (#Pad_Top# + 10)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " :UNCORE CLOCK"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #cpu# | #clock_info# | #cpu_values# | #values#


[text.dynamic.CPU_CLOCK_CORE_0_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_CLOCK_CORE_0
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 X                                = 1170
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = %1Hz
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #Clock_Info_State#
 Group                            = #cpu# | #clock_info# | #cpu_values# | #values#

[text.static.CPU_CLOCK_CORE_0]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 20r
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = ":CPU"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #Clock_Info_State#
 Group                            = #cpu# | #clock_info# | #cpu_texts# | #texts#

[text.dynamic.GPU_CLOCK_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.GPU_CLOCK
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 X                                = 45r
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = %1Hz
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #Clock_Info_State#
 Group                            = #cpu# | #clock_info# | #cpu_values# | #values#

[text.static.GPU_CLOCK]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 20r
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = ":GPU"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #Clock_Info_State#
 Group                            = #cpu# | #clock_info# | #cpu_texts# | #texts#

[text.dynamic.CPU_NAME]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_NAME
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 528
 Y                                = (#Pad_Top# + 10)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = %1
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_info# | #cpu_values# | #values#

[text.static.CPU_POWER]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 500
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "Power :"
 DynamicVariables                 = 1
 NumOfDecimals                    = 2
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_texts# | #texts#

[text.dynamic.CPU_POWER_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_POWER
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 19)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " %1 W"
 DynamicVariables                 = 1
 NumOfDecimals                    = 2
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_values# | #values#

[text.static.CPU_VOLTAGE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 472
 Y                                = (#Pad_Top# - 47)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "Voltage :"
 DynamicVariables                 = 1
 NumOfDecimals                    = 3
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_texts# | #texts#

[text.dynamic.CPU_VOLTAGE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_VOLTAGE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 47)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " %1 V"
 DynamicVariables                 = 1
 NumOfDecimals                    = 3
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_values# | #values#

[text.static.CPU_RATIO]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 444
 Y                                = (#Pad_Top# - 75)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "Ratio :"
 DynamicVariables                 = 1
 NumOfDecimals                    = 0
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_texts# | #texts#

[text.dynamic.CPU_RATIO_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_RATIO
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 75)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " %1 x"
 DynamicVariables                 = 1
 NumOfDecimals                    = 0
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_values# | #values#

[text.static.CPU_BUS_CLOCK]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 416
 Y                                = (#Pad_Top# - 103)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "Bus :"
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_texts# | #texts#

[text.dynamic.CPU_BUS_CLOCK_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_BUS_CLOCK
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 103)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " %1 MHz"
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu# | #cpu_info# | #cpu_values# | #values#

[text.static.CPU_THREADS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 760
 Y                                = (#Pad_Top# + 10)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "TOTAL THREADS: "
 DynamicVariables                 = 1
 Group                            = #cpu# | #threads# | #cpu_texts# | #texts#

[text.dynamic.CPU_THREADS_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_THREADS
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 5r
 Y                                = (#Pad_Top# + 10)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = [sensor.CPU_THREADS:0]
 DynamicVariables                 = 1
 Group                            = #cpu# | #threads# | #cpu_values# | #values#

[text.static.CPU_PROCESSES]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 700
 Y                                = (#Pad_Top# - 19)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "TOTAL PROCESSES:"
 DynamicVariables                 = 1
 Hidden                           = #Threads_State#
 Group                            = #cpu# | #threads# | #cpu_texts# | #texts#

[text.dynamic.CPU_PROCESSES_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.CPU_THREADS
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 43r
 Y                                = (#Pad_Top# - 19)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = [sensor.CPU_PROCESSES:0]
 DynamicVariables                 = 1
 Hidden                           = #Threads_State#
 Group                            = #cpu# | #threads# | #cpu_values# | #values#

[text.static.CPU_LOAD_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontLeftAlign
 FontColor                        = #Global_Color#
 X                                = 470
 Y                                = (#Pad_Top# + 81)
 Text                             = "MIN %"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_LOAD_AND_TEMPERATURE_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontLeftAlign
 FontColor                        = #Global_Color#
 X                                = 480
 Y                                = (#Pad_Top# + 105)
 Text                             = "MAX C %"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#

[text.static.CPU_TEMPERATURE_HISTOGRAM]
 Meter                            = STRING
 MeterStyle                       = f.fadedSmallFontLeftAlign
 FontColor                        = #Global_Color#
 X                                = 470
 Y                                = (#Pad_Top# + 129)
 Text                             = "MIN C"
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_texts# | #texts#
 
; --- BARS

[bar.CPU_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CPU_LOAD
 MeterStyle                       = b.LongBarLeftTop
 X                                = (375 - #Pad_Top#)
 Y                                = (#Pad_Top# + 46)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_1_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_1_LOAD
 MeterStyle                       = b.MiddleBarLeftTop
 X                                = (630 - #Pad_Top#)
 Y                                = (#Pad_Top# + 44)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_2_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_2_LOAD
 MeterStyle                       = b.MiddleBarLeftTop
 X                                = (629 - #Pad_Top#)
 Y                                = (#Pad_Top# + 62)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_3_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_3_LOAD
 MeterStyle                       = b.MiddleBarRightTop
 X                                = (1112 + #Pad_Top#)
 Y                                = (#Pad_Top# + 44)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_4_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_4_LOAD
 MeterStyle                       = b.MiddleBarRightTop
 X                                = (1113 + #Pad_Top#)
 Y                                = (#Pad_Top# + 62)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_5_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_5_LOAD
 MeterStyle                       = b.MiddleBarLeftBottom
 X                                = (851 + #Pad_Top#)
 Y                                = (#Pad_Top# + 152)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_6_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_6_LOAD
 MeterStyle                       = b.MiddleBarLeftBottom
 X                                = (852 + #Pad_Top#)
 Y                                = (#Pad_Top# + 170)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_7_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_7_LOAD
 MeterStyle                       = b.MiddleBarRightBottom
 X                                = (890 - #Pad_Top#)
 Y                                = (#Pad_Top# + 152)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_CORE_8_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.CORE_8_LOAD
 MeterStyle                       = b.MiddleBarRightBottom
 X                                = (890 - #Pad_Top#)
 Y                                = (#Pad_Top# + 170)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#

[bar.CPU_TEMPERATURE]
 Meter                            = BAR
 MeterStyle                       = b.LongBarLeftBottom
 MeasureName                      = sensor.CPU_TEMPERATURE
 X                                = (595 + #Pad_Top#)
 Y                                = (#Pad_Top# + 167)
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_bars# | #bars#
 
; --- GRAPHS ---

[formula_CPU_TEMPERATURE_HISTOGRAM_Y]
 Measure                          = CALC
 Formula                          = (#Pad_Top# + 112)
 DynamicVariables                 = 1

[histogram.CPU_TEMPERATURE]
 Meter                            = LINE
 MeasureName                      = sensor.CPU_TEMPERATURE
 X                                = #CPU_Histogram_X#
 Y                                = (#Pad_Top# + 112)
 W                                = #CPU_Histogram_Width#
 H                                = #GraphHeight#
 LineWidth                        = 0.2
 LineColor                        = #Global_Color#
 SolidColor                       = 0,0,0,0
 AutoScale                        = 0
 AntiAlias                        = 0
 GraphOrientation                 = Vertical
 ;TransformationMatrix             = 1; 0; -1; 1; [formula_CPU_TEMPERATURE_HISTOGRAM_Y]; 0
 ToolTipIcon                      = Info
 ToolTipTitle                     = CPU Temperature Graph
 ToolTipText                      = Left click or drag: set system volume#CRLF#Scroll: change volume#CRLF#Middle click: toggle mute#CRLF#Right cick: max volume
 ToolTipHidden                    = #ToolTips_State#
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_histograms# | #histograms#

 RightMouseUpAction               = [!CommandMeasure m.System_Volume "SetVolume 100"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.System_Volume "ChangeVolume #Sys_Volume_Down#"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.System_Volume "ChangeVolume #Sys_Volume_Up#"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MiddleMouseUpAction              = [!CommandMeasure m.System_Volume "ToggleMute"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.CPU_Volume_Slider "Start"][!EnableMeasure m.CPU_Volume_Slider_Set][!UpdateMeasure m.System_Volume][!UpdateMeasure m.Percent_System_Volume][!UpdateMeasure m.Volume_Values_Controller][!UpdateMeter b.System_Volume][!UpdateMeter t.System_Volume][!Redraw]

[formula_CPU_LOAD_HISTOGRAM_Y]
 Measure                          = CALC
 Formula                          = (#Pad_Top# + 87)
 DynamicVariables                 = 1

[histogram.CPU_LOAD]
 Meter                            = LINE
 MeasureName                      = sensor.CPU_LOAD
 X                                = #CPU_Histogram_X#
 Y                                = (#Pad_Top# + 87)
 W                                = #CPU_Histogram_Width#
 H                                = #GraphHeight#
 LineWidth                        = 0.2
 LineColor                        = #Global_Color#
 SolidColor                       = 0,0,0,0
 AutoScale                        = 0
 AntiAlias                        = 0
 GraphOrientation                 = Vertical
; TransformationMatrix             = 1; 0; 1; 1; -[formula_CPU_LOAD_HISTOGRAM_Y]; 0
 Flip                             = 1
 ToolTipIcon                      = Info
 ToolTipTitle                     = CPU Loading Graph
 ToolTipText                      = Left click or drag: set system volume#CRLF#Scroll: change volume#CRLF#Middle click: toggle mute#CRLF#Right cick: max volume
 ToolTipHidden                    = #ToolTips_State#
 DynamicVariables                 = 1
 Group                            = #cpu# | #cpu_histograms# | #histograms#

 RightMouseUpAction               = [!CommandMeasure m.System_Volume "SetVolume 100"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MouseScrollDownAction            = [!CommandMeasure m.System_Volume "ChangeVolume #Sys_Volume_Down#"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure m.System_Volume "ChangeVolume #Sys_Volume_Up#"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 MiddleMouseUpAction              = [!CommandMeasure m.System_Volume "ToggleMute"][!UpdateMeasure m.System_Volume][!UpdateMeter b.System_Volume][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure m.CPU_Volume_Slider "Start"][!EnableMeasure m.CPU_Volume_Slider_Set][!Delay 1][!UpdateMeasure m.System_Volume][!Redraw]
