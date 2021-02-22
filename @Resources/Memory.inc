[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Memory meters

; --- MEASURES BEGINNING

[sensor.RAM]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-MEMORY-PhysicalMLoad-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-MEMORY-PhysicalMLoad-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-MEMORY-PhysicalMLoad-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #ram# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.RAM_LOAD_VALUE][!UpdateMeter bar.RAM_LOAD]

[sensor.VRAM]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-MemoryUsage-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-MemoryUsage-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-MemoryUsage-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 MinValue                         = 0
 MaxValue                         = 100
 Group                            = #vram# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.VRAM_LOAD_VALUE][!UpdateMeter bar.VRAM_LOAD]

; - MEASURES END

; --- TEXTS BEGINNING

[text.dynamic.RAM_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.RAM
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 415
 Y                                = (#Pad_Top# + 30)
 Text                             = "%1%"
 Percentual                       = 1
 DynamicVariables                 = 1
 Group                            = #ram# | #ram_values# | #values#

[text.static.RAM_LOAD]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 255
 Y                                = (#Pad_Top# + 58)
 Text                             = "RAM LOAD"
 DynamicVariables                 = 1
 Group                            = #ram# | #ram_texts# | #texts#

[text.dynamic.VRAM_LOAD_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.VRAM
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 415
 Y                                = (#Pad_Top# + 177)
 Text                             = %1%
 Percentual                       = 1
 DynamicVariables                 = 1
 Group                            = #vram# | #vram_values# | #values#

[text.static.VRAM_LOAD]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 255
 Y                                = (#Pad_Top# + 150)
 Text                             = "VRM LOAD"
 DynamicVariables                 = 1
 Group                            = #vram# | #vram_texts# | #texts#

; - TEXTS END

; --- BARS BEGINNING

[bar.RAM_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.RAM
 MeterStyle                       = b.LongBarLeftTop
 X                                = (161 - #Pad_Top#)
 Y                                = (#Pad_Top# + 46)
 DynamicVariables                 = 1
 Group                            = #ram# | #ram_bars# | #bars#

[bar.VRAM_LOAD]
 Meter                            = BAR
 MeasureName                      = sensor.VRAM
 MeterStyle                       = b.LongBarLeftBottom
 X                                = (383 + #Pad_Top#)
 Y                                = (#Pad_Top# + 167)
 DynamicVariables                 = 1
 Group                            = #vram# | #vram_bars# | #bars#

; - BARS END
