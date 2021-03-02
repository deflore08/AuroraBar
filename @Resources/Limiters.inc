[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = Limiters info, such as thermal throttling and power limits.

; --- MEASURES

; - The formula checks if something have thermal throtthling

[formula.THROTTHLING]
 Measure                          = CALC
 Formula                          = sensor.THROTTLING_CPU + sensor.THROTTLING_GPU
 DynamicVariables                 = 1
 Group                            = #throttling# | #limiters# | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.THROTTLING_COMMON_VALUE][!UpdateMeter text.dynamic.THROTTLING_CPU_VALUE][!UpdateMeter text.dynamic.THROTTLING_GPU_VALUE][!Redraw]
     ifCondition                  = formula.THROTTHLING = 0
          ifTrueAction            = [!SetOption text.dynamic.THROTTLING_COMMON_VALUE Text "NO"][!SetOption text.dynamic.THROTTLING_COMMON_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.THROTTLING_CPU_VALUE Text "NO"][!SetOption text.dynamic.THROTTLING_CPU_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.THROTTLING_GPU_VALUE Text "NO"][!SetOption text.dynamic.THROTTLING_GPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.THROTTLING_COMMON_VALUE Text "YES"][!SetOption text.dynamic.THROTTLING_COMMON_VALUE FontColor "#Font_Warning_Color#"]
          ifConditionMode         = 1

[sensor.THROTTLING_CPU]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-Throttling-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-Throttling-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-Throttling-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Group                            = #throttling# | #limiters#  | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.THROTTLING_COMMON_VALUE][!UpdateMeter text.dynamic.THROTTLING_CPU_VALUE][!Redraw]
     ifCondition                  = sensor.THROTTLING_CPU = 0
          ifTrueAction            = [!SetOption text.dynamic.THROTTLING_CPU_VALUE Text "NO"][!SetOption text.dynamic.THROTTLING_CPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.THROTTLING_CPU_VALUE Text "YES"][!SetOption text.dynamic.THROTTLING_CPU_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

[sensor.THROTTLING_GPU]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Throttling-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Throttling-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Throttling-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Group                            = #throttling# | #limiters#  | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.THROTTLING_COMMON_VALUE][!UpdateMeter text.dynamic.THROTTLING_GPU_VALUE][!Redraw]
     ifCondition                  = sensor.THROTTLING_GPU < 2
          ifTrueAction            = [!SetOption text.dynamic.THROTTLING_GPU_VALUE Text "NO"][!SetOption text.dynamic.THROTTLING_GPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.THROTTLING_GPU_VALUE Text "YES"][!SetOption text.dynamic.THROTTLING_GPU_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

; - The formula checks if someething reached a power limit

[formula.POWER_LIMIT]
 Measure                          = CALC
 Formula                          = sensor.POWER_LIMIT_CPU + sensor.POWER_LIMIT_GPU
 DynamicVariables                 = 1
 Group                            = #power_limit# | #limiters#  | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.POWER_LIMIT_VALUE][!UpdateMeter text.dynamic.POWER_LIMIT_CPU_VALUE][!UpdateMeter text.dynamic.POWER_LIMIT_GPU_VALUE][!Redraw]
     ifCondition                  = formula.POWER_LIMIT = 0
          ifTrueAction            = [!SetOption text.dynamic.POWER_LIMIT_VALUE Text "NO"][!SetOption text.dynamic.POWER_LIMIT_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE Text "NO"][!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE Text "NO"][!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.POWER_LIMIT_VALUE Text "YES"][!SetOption text.dynamic.POWER_LIMIT_VALUE FontColor "#Font_Warning_Color#"]
          ifConditionMode         = 1

[sensor.POWER_LIMIT_CPU]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-CPU0-PowerLimit-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-CPU0-PowerLimit-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-CPU0-PowerLimit-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Group                            = #power_limit# | #limiters#  | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.POWER_LIMIT_VALUE][!UpdateMeter text.dynamic.POWER_LIMIT_CPU_VALUE][!Redraw]
     ifCondition                  = sensor.POWER_LIMIT_CPU = 0
          ifTrueAction            = [!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE Text "NO"][!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE Text "YES"][!SetOption text.dynamic.POWER_LIMIT_CPU_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

[sensor.POWER_LIMIT_GPU]
 Measure                          = PLUGIN
 Plugin                           = HWiNFO.dll
 HWiNFOSensorId                   = #HWiNFO-GPU1-Power-Limit-SensorId#
 HWiNFOSensorInstance             = #HWiNFO-GPU1-Power-Limit-SensorInstance#
 HWiNFOEntryId                    = #HWiNFO-GPU1-Power-Limit-EntryId#
 HWiNFOType                       = CurrentValue
 HWiNFOLogHandler                 = 2
 DynamicVariables                 = 1
 Group                            = #power_limit# | #limiters#  | #limiters_sensors# | #sensors#

     onChangeAction               = [!UpdateMeter text.dynamic.POWER_LIMIT_VALUE][!UpdateMeter text.dynamic.POWER_LIMIT_GPU_VALUE][!Redraw]
     ifCondition                  = sensor.POWER_LIMIT_GPU = 0
          ifTrueAction            = [!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE Text "NO"][!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE FontColor "#Font_Value_Color#"]
               ifFalseAction      = [!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE Text "YES"][!SetOption text.dynamic.POWER_LIMIT_GPU_VALUE FontColor "#Font_Warning_Color#"]
     ifConditionMode              = 1

; --- TEXTS

; - Throttling

[text.static.THROTTLING_COMMON]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 750
 Y                                = (#Pad_Top# + 198)
 W                                = 100
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = "THROTTLING:"
 DynamicVariables                 = 1
 Group                            = #throttling# | #limiters# | #limiters_texts# | #texts#

[text.dynamic.THROTTLING_COMMON_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 15r
 Y                                = (#Pad_Top# + 198)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = 
 DynamicVariables                 = 1
 Group                            = #throttling# | #limiters# | #limiters_values# | #values#

[text.static.THROTTLING_CPU]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 660
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Throttling#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "CPU:"
 DynamicVariables                 = 1
 Hidden                           = #Throttling_State#
 Group                            = #throttling# | #limiters# | #limiters_texts# | #texts#

[text.dynamic.THROTTLING_CPU_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 40r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Throttling#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = 
 DynamicVariables                 = 1
 Hidden                           = #Throttling_State#
 Group                            = #throttling# | #limiters# | #limiters_values# | #values#

[text.static.THROTTLING_GPU]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 720
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Throttling#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "GPU:"
 DynamicVariables                 = 1
 Hidden                           = #Throttling_State#
 Group                            = #throttling# | #limiters# | #limiters_texts# | #texts#

[text.dynamic.THROTTLING_GPU_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 40r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Throttling#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = 234
 DynamicVariables                 = 1
 Hidden                           = #Throttling_State#
 Group                            = #throttling# | #limiters# | #limiters_values# | #values#

; - Power Limit

[text.dynamic.POWER_LIMIT_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 FontColor                        = #Font_Value_Color#
 X                                = 1150
 Y                                = (#Pad_Top# + 198)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = 
 DynamicVariables                 = 1
 Group                            = #power_limit# | #limiters# | #limiters_values# | #values#

[text.static.POWER_LIMIT]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 50r
 Y                                = (#Pad_Top# + 198)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = ":POWER LIMIT"
 DynamicVariables                 = 1
 Group                            = #power_limit# | #limiters# | #limiters_texts# | #texts#

[text.dynamic.POWER_LIMIT_CPU_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 FontColor                        = #Font_Value_Color#
 X                                = 1170
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Power_Limit#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = 
 DynamicVariables                 = 1
 Hidden                           = #Power_Limit_State#
 Group                            = #power_limit# | #limiters# | #limiters_values# | #values#

[text.static.POWER_LIMIT_CPU]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 25r
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Power_Limit#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = ":CPU"
 DynamicVariables                 = 1
 Hidden                           = #Power_Limit_State#
 Group                            = #power_limit# | #limiters# | #limiters_texts# | #texts#

[text.dynamic.POWER_LIMIT_GPU_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align_Value
 FontColor                        = #Font_Value_Color#
 X                                = 1225
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Power_Limit#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = 
 DynamicVariables                 = 1
 Hidden                           = #Power_Limit_State#
 Group                            = #power_limit# | #limiters# | #limiters_values# | #values#

[text.static.POWER_LIMIT_GPU]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 25r
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Power_Limit#)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = ":GPU"
 DynamicVariables                 = 1
 Hidden                           = #Power_Limit_State#
 Group                            = #power_limit# | #limiters# | #limiters_texts# | #texts#