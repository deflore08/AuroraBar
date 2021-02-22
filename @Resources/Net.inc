[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = All net meters. It requires to set network bandwidth first.
 
; --- MEASURES BEGINNING

; - Net measures uses #Net_Max# & #MaxNetOut# vars to limit the MAX value

; - Set these vars manually depending on your internet speed

[sensor.NET_IN]
 Measure                          = NETIN
 MinValue                         = 0
 MaxValue                         = [formula.NET_MAX]
 DynamicVariables                 = 1
 Group                            = #net# | #net_sensors# | #sensors#
      onChangeAction              = [!UpdateMeter text.dynamic.NET_IN_VALUE][!UpdateMeter bar.NET_IN]

[sensor.NET_OUT]
 Measure                          = NETOUT
 MinValue                         = 0
 MaxValue                         = [formula.NET_MAX]
 DynamicVariables                 = 1
 Group                            = #net# | #net_sensors# | #sensors#
      onChangeAction              = [!UpdateMeter text.dynamic.NET_OUT_VALUE][!UpdateMeter bar.NET_OUT]

[sensor.NET_TOTAL]
 Measure                          = NETTOTAL
 MinValue                         = 0
 MaxValue                         = [formula.NET_MAX]
 DynamicVariables                 = 1
 Group                            = #net# | #net_sensors# | #sensors#
      onChangeAction              = [!UpdateMeasureGroup #net_sensors#][!UpdateMeter text.dynamic.NET_TOTAL_VALUE][!UpdateMeter bar.NET_TOTAL]

[formula.NET_MAX]
 Measure                          = CALC
 Formula                          = ( #Net_Max# * 1250 )
 DynamicVariables                 = 1
 Group                            = #net# | #net_sensors# | #sensors#

; --- PING

; - Set MaxValue to a value you to see as maximum for bar

; - For example: 100 means BAR is full when ping = 100 ms

; - TimeOut means maximum wait time and determines a value when you will see "N/A" text instead of numbers

[sensor.PING]
 Measure                          = PLUGIN
 Plugin                           = PINGPLUGIN
 DestAddress                      = #Ping_Host#
 MaxValue                         = #Ping_Max#
 TimeOut                          = #Ping_Timeout#
 UpdateRate                       = 10
 DynamicVariables                 = 1
 Group                            = #net# | #net_sensors# | #sensors#
      onChangeAction              = [!UpdateMeter text.dynamic.PING_VALUE][!UpdateMeter bar.PING]
      ifCondition                 = (sensor.PING > #Ping_Timeout#) || (#Ping_Timeout# <= 0)
         ifTrueAction             = [!SetOption text.dynamic.PING_VALUE Text "N/A"][!SetOption text.dynamic.PING_VALUE FontColor "#Font_Warning_Color#"]
         ifFalseAction            = [!SetOption text.dynamic.PING_VALUE Text "%1 ms"][!SetOption text.dynamic.PING_VALUE FontColor "#Font_Value_Color#"]
      ifConditionMode             = 1

; - MEASURES END

; --- TEXTS BEGINNING

[text.static.PING]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 380
 Y                                = (#Pad_Top# + 77)
 Text                             = "PG"
 DynamicVariables                 = 1
 Group                            = #net# | #net_texts# | #texts#

[text.static.NET_TOTAL]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 385
 Y                                = (#Pad_Top# + 92)
 Text                             = "NL"
 DynamicVariables                 = 1
 Group                            = #net# | #net_texts# | #texts#

[text.dynamic.PING_VALUE]
 MeasureName                      = sensor.PING
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 FontColor                        = #Font_Value_Color#
 X                                = 410
 Y                                = (#Pad_Top# + 77)
 Text                             = %1 ms
 NumOfDecimals                    = 0
 DynamicVariables                 = 1
 Group                            = #net# | #net_values# | #values#

[text.dynamic.NET_TOTAL_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.NET_TOTAL
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 415
 Y                                = (#Pad_Top# + 92)
 Text                             = %1%
 Percentual                       = 1
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #net# | #net_values# | #values#

[text.static.NET_IN]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 380
 Y                                = (#Pad_Top# + 133)
 Text                             = "IN"
 DynamicVariables                 = 1
 Group                            = #net# | #net_texts# | #texts#

[text.dynamic.NET_IN_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.NET_IN
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 410
 Y                                = (#Pad_Top# + 133)
 Text                             = %1B
 NumOfDecimals                    = 0
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #net# | #net_values# | #values#

[text.static.NET_OUT]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 385
 Y                                = (#Pad_Top# + 118)
 Text                             = "OT"
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #net# | #net_texts# | #texts#

[text.dynamic.NET_OUT_VALUE]
 Meter                            = STRING
 MeasureName                      = sensor.NET_OUT
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 415
 Y                                = (#Pad_Top# + 118)
 Text                             = %1B
 NumOfDecimals                    = 0
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #net# | #net_values# | #values#

; - TEXTS END

; --- BARS BEGINNING

[bar.NET_TOTAL]
 MeasureName                      = sensor.NET_TOTAL
 Meter                            = BAR
 X                                = (150 - #Pad_Top#)
 Y                                = (#Pad_Top# + 95)
 MeterStyle                       = b.ShortBarLeftTop
 DynamicVariables                 = 1
 Group                            = #net# | #net_bars# | #bars#

[bar.NET_IN]
 MeasureName                      = sensor.NET_IN
 Meter                            = BAR
 X                                = (373 + #Pad_Top#)
 Y                                = (#Pad_Top# + 135)
 MeterStyle                       = b.ShortBarLeftBottom
 DynamicVariables                 = 1
 Group                            = #net# | #net_bars# | #bars#

[bar.NET_OUT]
 MeasureName                      = sensor.NET_OUT
 Meter                            = BAR
 X                                = (373 + #Pad_Top#)
 Y                                = (#Pad_Top# + 120)
 MeterStyle                       = b.ShortBarLeftBottom
 DynamicVariables                 = 1
 Group                            = #net# | #net_bars# | #bars#

[bar.PING]
 MeasureName                      = sensor.PING
 Meter                            = BAR
 MeterStyle                       = b.ShortBarLeftTop
 X                                = (150 - #Pad_Top#)
 Y                                = (#Pad_Top# + 80)
 DynamicVariables                 = 1
 Group                            = #net# | #net_bars# | #bars#

; - BARS END