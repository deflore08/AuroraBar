[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Stopwatch module. Thanks to vlesun (vlesun@newmail.ru) & balala, it based on their skin.

[Variables]

; --- MEASURES BEGINNING

[formula.COUNTER_STOPWATCH_TIME]
 Measure                          = TIME
 AverageSize                      = 20
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasureGroup #stopwatch#][!UpdateMeterGroup #stopwatch_texts#]

[formula.COUNTER_STOPWATCH]
 Measure                          = CALC
 Formula                          = ( formula.COUNTER_STOPWATCH = 0 ? ( formula.COUNTER_STOPWATCH_TIME - formula.STOPWATCH / 10 ) : formula.COUNTER_STOPWATCH )
 Disabled                         = 1
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH]
 Measure                          = CALC
 Formula                          = ( formula.COUNTER_STOPWATCH = 0 ? formula.STOPWATCH : (formula.COUNTER_STOPWATCH_TIME - formula.COUNTER_STOPWATCH) *10 )
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH_DIGIT_1]
 Measure                          = CALC
 Formula                          = formula.STOPWATCH%10
 MaxValue                         = 3
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH_DIGIT_1-2]
 Measure                          = CALC
 Formula                          = ( formula.STOPWATCH_DIGIT_1 > 9 ? 9 : formula.STOPWATCH_DIGIT_1 )
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH_DIGIT_2]
 Measure                          = CALC
 Formula                          = (FLOOR(formula.STOPWATCH/10))%60
 Substitute                       = "0":"00","1":"01","2":"02","3":"03","4":"04","5":"05","6":"06","7":"07","8":"08","9":"09","0100":"10","0101":"11","0102":"12","0103":"13","0104":"14","0105":"15","0106":"16","0107":"17","0108":"18","0109":"19","0200":"20","0201":"21","0202":"22","0203":"23","0204":"24","0205":"25","0206":"26","0207":"27","0208":"28","0209":"29","0300":"30","0301":"31","0302":"32","0303":"33","0304":"34","0305":"35","0306":"36","0307":"37","0308":"38","0309":"39","0400":"40","0401":"41","0402":"42","0403":"43","0404":"44","0405":"45","0406":"46","0407":"47","0408":"48","0409":"49","0500":"50","0501":"51","0502":"52","0503":"53","0504":"54","0505":"55","0506":"56","0507":"57","0508":"58","0509":"59"
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH_DIGIT_3]
 Measure                          = CALC
 Formula                          = (FLOOR(formula.STOPWATCH/600))%60
 Substitute                       = "0":"00","1":"01","2":"02","3":"03","4":"04","5":"05","6":"06","7":"07","8":"08","9":"09","0100":"10","0101":"11","0102":"12","0103":"13","0104":"14","0105":"15","0106":"16","0107":"17","0108":"18","0109":"19","0200":"20","0201":"21","0202":"22","0203":"23","0204":"24","0205":"25","0206":"26","0207":"27","0208":"28","0209":"29","0300":"30","0301":"31","0302":"32","0303":"33","0304":"34","0305":"35","0306":"36","0307":"37","0308":"38","0309":"39","0400":"40","0401":"41","0402":"42","0403":"43","0404":"44","0405":"45","0406":"46","0407":"47","0408":"48","0409":"49","0500":"50","0501":"51","0502":"52","0503":"53","0504":"54","0505":"55","0506":"56","0507":"57","0508":"58","0509":"59"
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.STOPWATCH_DIGIT_4]
 Measure                          = CALC
 Formula                          = (FLOOR(formula.STOPWATCH/36000))%100
 MaxValue                         = 2
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

[formula.ATTENTION_HOURLY]
 Measure                          = CALC
 Formula                          = ((( formula.STOPWATCH_DIGIT_3=0 ) ? 1 : 0 ) + (( formula.STOPWATCH_DIGIT_4<>0 ) ? 1 : 0 ))
 IfEqualAction                    = [Play #Success_1#]
 IfEqualValue                     = 2
 Group                            = #stopwatch# | #stopwatch_sensors# | #sensors#

; - MEASURES END

; --- TEXTS

[text.static.START]
 Meter                            = STRING
 X                                = 50
 Y                                = (#Pad_Top# + 198)
 W                                = 70
 SolidColor                       = 0, 0, 0, 1
 MeterStyle                       = style.text.Stopwatch_Digits
 Text                             = START
 MouseActionCursor                = 1
 DynamicVariables                 = 1
 Hidden                           = 0
 LeftMouseDownAction              = [!EnableMeasure formula.STOPWATCH][!EnableMeasure formula.COUNTER_STOPWATCH][!HideMeter text.static.START][!ShowMeter text.static.STOP][!HideMeter text.static.RESET]
 Group                            = #stopwatch# | #stopwatch_texts# | #texts#

[text.static.STOP]
 Meter                            = STRING
 MeterStyle                       = style.text.Stopwatch_Digits
 X                                = 50
 Y                                = (#Pad_Top# + 198)
 W                                = 70
 SolidColor                       = 0, 0, 0, 1
 Text                             = STOP
 MouseActionCursor                = 1
 DynamicVariables                 = 1
 Hidden                           = 1
 LeftMouseDownAction              = [!DisableMeasure formula.COUNTER_STOPWATCH][!ShowMeter text.static.START][!HideMeter text.static.STOP][!ShowMeter text.static.RESET]
 Group                            = #stopwatch# | #stopwatch_texts# | #texts#

[text.static.RESET]
 Meter                            = STRING
 MeterStyle                       = style.text.Stopwatch_Digits
 X                                = 158
 Y                                = (#Pad_Top# + 198)
 W                                = 70
 SolidColor                       = 0, 0, 0, 1
 Text                             = RESET
 MouseActionCursor                = 1
 DynamicVariables                 = 1
 LeftMouseDownAction              = [!DisableMeasure formula.STOPWATCH][!HideMeter text.static.RESET]
 Hidden                           = 1
 Group                            = #stopwatch# | #stopwatch_texts# | #texts#

[text.dynamic.STOPWATCH_DIGITS]
 Meter                            = STRING
 MeterStyle                       = style.text.Stopwatch_Digits
 MeasureName                      = formula.STOPWATCH_DIGIT_4
 MeasureName2                     = formula.STOPWATCH_DIGIT_3
 MeasureName3                     = formula.STOPWATCH_DIGIT_2
 MeasureName4                     = formula.STOPWATCH_DIGIT_1-2
 X                                = 102
 Y                                = (#Pad_Top# + 198)
 W                                = 157
 SolidColor                       = 150,0,0,0
 Text                             = %1:%2:%3
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Hidden                           = 0
 Group                            = #stopwatch# | #stopwatch_texts# | #texts#

; - TEXTS END