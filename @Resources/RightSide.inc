[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Right side meters like uptime, idle etc.
 
; --- MEASURES

[sensor.IDLE_TIME]
 Measure                          = PLUGIN
 Plugin                           = SysInfo
 SysInfoType                      = IDLE_TIME
 Group                            = #uptime# | #uptime_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.IDLE_TIME]
 
[sensor.UPTIME]
 Measure                          = UPTIME
 Format                           = "%4!i!d %3!i!h %2!i!m"
 DynamicVariables                 = 1
 Group                            = #uptime# | #uptime_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.UPTIME]

; --- TEXTS

[text.dynamic.IDLE_TIME]
 MeasureName                      = sensor.IDLE_TIME
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 1810
 Y                                = (#Pad_Top# + 198)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = IDLE TIME: %1
 Group                            = #uptime# | #sensors_texts# | #texts#
 DynamicVariables                 = 1

[text.dynamic.UPTIME]
 MeasureName                      = sensor.UPTIME
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 1810
 Y                                = (#Pad_Top# + 10)
 W                                = 157
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = UPTIME: %1
 DynamicVariables                 = 1
 Group                            = #uptime# | #sensors_texts# | #texts#