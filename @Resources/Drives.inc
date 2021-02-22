[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.4b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = All HDD meters, measures, bars, text in section 8

; --- MEASURES BEGINNING

[sensor.DRIVE_1_TOTAL_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD1-TotalActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD1-TotalActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD1-TotalActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure sensor.DRIVE_1_READ_ACTIVITY][!UpdateMeasure sensor.DRIVE_1_WRITE_ACTIVITY][!UpdateMeasure sensor.DRIVE_1_READ_RATE][!UpdateMeasure sensor.DRIVE_1_WRITE_RATE][!UpdateMeter text.dynamic.DRIVE_1_LOAD_VALUE][!UpdateMeter bar.DRIVE_1_ACTIVITY]

[sensor.DRIVE_1_READ_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD1-ReadActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD1-ReadActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD1-ReadActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter bar.DRIVE_1_READ_ACTIVITY]

[sensor.DRIVE_1_WRITE_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD1-WriteActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD1-WriteActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD1-WriteActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter bar.DRIVE_1_WRITE_ACTIVITY]

[sensor.DRIVE_1_READ_RATE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD1-ReadRate-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD1-ReadRate-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD1-ReadRate-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.DRIVE_1_READ_RATE_VALUE]

[sensor.DRIVE_1_WRITE_RATE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD1-WriteRate-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD1-WriteRate-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD1-WriteRate-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.DRIVE_1_WRITE_RATE_VALUE]

[sensor.DRIVE_2_TOTAL_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD2-TotalActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD2-TotalActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD2-TotalActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure sensor.DRIVE_2_READ_ACTIVITY][!UpdateMeasure sensor.DRIVE_2_WRITE_ACTIVITY][!UpdateMeasure sensor.DRIVE_2_READ_RATE][!UpdateMeasure sensor.DRIVE_2_WRITE_RATE][!UpdateMeter text.dynamic.DRIVE_2_LOAD_VALUE][!UpdateMeter bar.DRIVE_2_ACTIVITY]

[sensor.DRIVE_2_READ_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD2-ReadActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD2-ReadActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD2-ReadActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter bar.DRIVE_2_READ_ACTIVITY]

[sensor.DRIVE_2_WRITE_ACTIVITY]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD2-WriteActivity-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD2-WriteActivity-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD2-WriteActivity-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter bar.DRIVE_2_WRITE_ACTIVITY]

[sensor.DRIVE_2_READ_RATE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD2-ReadRate-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD2-ReadRate-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD2-ReadRate-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.DRIVE_2_READ_RATE_VALUE]

[sensor.DRIVE_2_WRITE_RATE]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-HDD2-WriteRate-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-HDD2-WriteRate-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-HDD2-WriteRate-EntryId#
 HWiNFOType                       = CurrentValue
 Group                            = #drives# | #drives_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.DRIVE_2_WRITE_RATE_VALUE]

; - MEASURES END

; --- TEXTS BEGINNING

[text.static.DRIVE_1_LOAD]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1608
 Y                                = (#Pad_Top# + 60)
 Text                             = "HDD LOAD"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_1_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_1_TOTAL_ACTIVITY
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1510
 Y                                = (#Pad_Top# + 30)
 Text                             = %1%
 Percentual                       = 1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

[text.static.DRIVE_1_READ_RATE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1530
 Y                                = (#Pad_Top# + 77)
 Text                             = "RD"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_1_READ_RATE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_1_READ_RATE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1500
 Y                                = (#Pad_Top# + 77)
 Text                             = %1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

[text.static.DRIVE_1_WRITE_RATE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1520
 Y                                = (#Pad_Top# + 92)
 Text                             = "WR"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_1_WRITE_RATE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_1_WRITE_RATE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1490
 Y                                = (#Pad_Top# + 92)
 Text                             = %1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

[text.static.DRIVE_2_LOAD]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1610
 Y                                = (#Pad_Top# + 150)
 Text                             = "SSD LOAD"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_2_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_2_TOTAL_ACTIVITY
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1510
 Y                                = (#Pad_Top# + 177)
 Text                             = %1%
 Percentual                       = 1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

[text.static.DRIVE_2_READ_RATE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1530
 Y                                = (#Pad_Top# + 132)
 Text                             = "RD"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_2_READ_RATE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_2_READ_RATE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1500
 Y                                = (#Pad_Top# + 132)
 Text                             = %1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

[text.static.DRIVE_2_WRITE_RATE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 1520
 Y                                = (#Pad_Top# + 117)
 Text                             = "WR"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_texts# | #texts#

[text.dynamic.DRIVE_2_WRITE_RATE_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.DRIVE_2_WRITE_RATE
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 1490
 Y                                = (#Pad_Top# + 117)
 Text                             = %1
 AutoScale                        = 1
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_values# | #values#

; - TEXTS END

; --- BARS BEGINNING

[bar.DRIVE_1_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_1_TOTAL_ACTIVITY
 MeterStyle                       = b.LongBarRightTop
 X                                = (1500 + #Pad_Top#)
 Y                                = (#Pad_Top# + 46)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

[bar.DRIVE_1_READ_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_1_READ_ACTIVITY
 MeterStyle                       = b.ShortBarRightTop
 X                                = (1610 + #Pad_Top#)
 Y                                = (#Pad_Top# + 80)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

[bar.DRIVE_1_WRITE_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_1_WRITE_ACTIVITY
 MeterStyle                       = b.ShortBarRightTop
 X                                = (1610 + #Pad_Top#)
 Y                                = (#Pad_Top# + 95)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

[bar.DRIVE_2_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_2_TOTAL_ACTIVITY
 MeterStyle                       = b.LongBarRightbottom
 X                                = (1280 - #Pad_Top#)
 Y                                = (#Pad_Top# + 167)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

[bar.DRIVE_2_READ_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_2_READ_ACTIVITY
 MeterStyle                       = b.ShortBarRightBottom
 X                                = (1388 - #Pad_Top#)
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

[bar.DRIVE_2_WRITE_ACTIVITY]
 Meter                            = BAR
 MeasureName                      = sensor.DRIVE_2_WRITE_ACTIVITY
 MeterStyle                       = b.ShortBarRightBottom
 X                                = (1388 - #Pad_Top#)
 Y                                = (#Pad_Top# + 120)
 DynamicVariables                 = 1
 Group                            = #drives# | #drives_bars# | #bars#

; - BARS END