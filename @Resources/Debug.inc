[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = ALL-IN-ONE combain for PC's monitoring

[Variables]

 Command_Trigger                  = 0
 Command_Input                    = 123  

; --- TEST COMMAND LINE

[sensor.COMMAND_INPUT]
 Measure                          = PLUGIN
 Plugin                           = InputText
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 885
 Y                                = (#Pad_Top# - 17)
 W                                = 150
 H                                = 15
 SolidColor                       = 0,0,0,255
 FontColor                        = 255,255,255,255
 DefaultValue                     = #Command_Input#
 FocusDismiss                     = 1
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

 Command1                         = [!WriteKeyValue Variables Command_Input " $UserInput$" "#@#Debug.inc"][!SetVariable Command_Input [sensor.COMMAND_INPUT]][!UpdateMeter text.dynamic.COMMAND_INPUT]
 Command2                         = [!SetVariable Command_Trigger "1"][!UpdateMeasure formula.COMMAND_INPUT]

[formula.COMMAND_INPUT]
 Measure                          = CALC
 Formula                          = #Command_Trigger#
 DynamicVariables                 = 1
 Disabled                         = #Debug_State#
 Group                            = #debug#
     ifCondition                  = #Command_Trigger# = 1
          ifTrueAction            = [!#Command_Input#] [!Delay 2000][!SetVariable Command_Trigger "0"][!UpdateMeasure #CURRENTSECTION#]
     ifConditionMode              = 0

[text.dynamic.COMMAND_INPUT]
 Meter                            = STRING
 X                                = 885
 Y                                = (#Pad_Top# - 17)
 W                                = 150
 H                                = 15
 SolidColor                       = 0,0,0,150
 ClipString                       = 1
 MeterStyle                       = style.text.Simple_Font_Left_Align
 StringCase                       = Upper
 Prefix                           = "CMD: "
 Text                             = "#Command_Input#"
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

 LeftMouseDownAction              = [!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure "sensor.COMMAND_INPUT" "ExecuteBatch 1-2"]
 RightMouseUpAction               = [!SetClip #Command_Input#]

; --- TEXTS

[text.MAIN_HANDLER]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 60
 X                                = 960
 Y                                = 0
 W                                = 70
 ;H                                = 20
 SolidColor                       = #BG_Color#
 Text                             = [handler.MAIN_CYCLE_DEBUG]
 AntiAlias                        = 1
 ClipString                       = 1
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

[text.2ND_UPDATE_CYCLE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontSize                         = 29
 X                                = 920
 Y                                = 0
 W                                = 70
 ;H                                = 20
 SolidColor                       = #BG_Color#
 Text                             = [handler.2ND_CYCLE_DEBUG] : #2nd_Cycle# 
 AntiAlias                        = 1
 ClipString                       = 1
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

[text.3RD_UPDATE_CYCLE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontSize                         = 29
 X                                = 1000
 Y                                = 0
 W                                = 70
 ;H                                = 20
 SolidColor                       = #BG_Color#
 Text                             = #3rd_Cycle# : [handler.3RD_CYCLE_DEBUG]
 AntiAlias                        = 1
 ClipString                       = 1
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

; --- BUTTONS

[b.TEST_BUTTON_1]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 30, 30 | Strokewidth 0 | Fill Color #BG_COLOR#
 X                                = 1000
 Y                                = (#Pad_Top# - 63)
 DynamicVariables                 = 1
 Hidden                           = #Debug_State#
 Group                            = #debug#

 LeftMouseUpAction                = [!SetVariable Cycle "0"][!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
 RightMouseUpAction               = [!SetVariable Cycle "1"][!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeterGroup #debug#][!Redraw]

[b.TEST_BUTTON_2]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 30, 30 | Strokewidth 0 | Fill Color #BG_Color#
 X                                = 890
 Y                                = (#Pad_Top# - 63)
 DynamicVariables                 = 1
 Group                            = #debug#
 Hidden                           = #Debug_State#

 LeftMouseUpAction                = [!DisableMeasure handler.MAIN_CYCLE][!EnableMeasure handler.MAIN_CYCLE_DEBUG][!UpdateMeasure handler.MAIN_CYCLE_DEBUG]
 RightMouseUpAction               = [!DisableMeasure handler.MAIN_CYCLE_DEBUG][!EnableMeasure handler.MAIN_CYCLE][!UpdateMeasure handler.MAIN_CYCLE]
 MiddleMouseUpAction              = [!RefreshApp]
