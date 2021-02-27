[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Calculator module. Thanks to TGonZo for this.

[Variables]
 Display_Result                   = 0
 Display_Between                  = ""
 Calc_CMD                         = ""
 Calc_Formula                     = ""

;-------------MEASURES------------

[m.Number_7]
 Measure                          = String
 String                           = "#Display_Result#7"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^07":"7"

[m.Number_8]
 Measure                          = String
 String                           = "#Display_Result#8"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^08":"8"

[m.Number_9]
 Measure                          = String
 String                           = "#Display_Result#9"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^09":"9"

[m.Number_4]
 Measure                          = String
 String                           = "#Display_Result#4"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^04":"4"

[m.Number_5]
 Measure                          = String
 String                           = "#Display_Result#5"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^05":"5"

[m.Number_6]
 Measure                          = String
 String                           = "#Display_Result#6"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^06":"6"

[m.Number_1]
 Measure                          = String
 String                           = "#Display_Result#1"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^01":"1"

[m.Number_2]
 Measure                          = String
 String                           = "#Display_Result#2"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^02":"2"

[m.Number_3]
 Measure                          = String
 String                           = "#Display_Result#3"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^03":"3"

[m.Number_0]
 Measure                          = String
 String                           = "#Display_Result#0"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "^00":"0"

[m.Operator_DOT]
 Measure                          = String
 String                           = "#Display_Result#."
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "(.*\..*)(\.)":"\1"

[m.Operator_=]
 Measure                          = CALC
 Formula                          = "#Calc_Formula#"
 DynamicVariables                 = 1


[m.Operator_+]
 Measure                          = String
 String                           = "#Display_Result#+"
 DynamicVariables                 = 1

[m.Operator_-]
 Measure                          = String
 String                           = "#Display_Result#-"
 DynamicVariables                 = 1

[m.Operator_*]
 Measure                          = String
 String                           = "#Display_Result#*"
 DynamicVariables                 = 1

[m.Operator_/]
 Measure                          = String
 String                           = "#Display_Result#/"
 DynamicVariables                 = 1

[m.Operator_+/-]
 Measure                          = String
 String                           = "-#Display_Result#"
 DynamicVariables                 = 1
 RegExpSubstitute                 = 1
 Substitute                       = "(^--)":""

[m.Operator_%]
 Measure                          = CALC
 Formula                          = "#Display_Result#/100"
 DynamicVariables                 = 1

[m.Operator_AC]
 Measure                          = String
 String                           = no
 IfMatch                          = "yes"
 IfMatchAction                    = [!SetVariable Display_Result "0"][!SetOption m.Operator_AC String "no"][!UpdateMeasure m.Operator_AC]
;;UpdateDivider                    = #Divider_Negative_Measure#

;-------------TEXTS---------------

[t.Operator_/]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 85
 Y                                = (#Pad_Top# + 50)
 FonSize                          = 10
 Text                             = "/"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_%]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 125
 Y                                = (#Pad_Top# + 50)
 FonSize                          = 10
 Text                             = "%"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_+/-]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 165
 Y                                = (#Pad_Top# + 50)
 FonSize                          = 10
 Text                             = "+/-"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_AC]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 12
 X                                = 204
 Y                                = (#Pad_Top# + 50)
 FonSize                          = 10
 Text                             = "AC"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_*]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 20
 X                                = 44
 Y                                = (#Pad_Top# + 52)
 FonSize                          = 10
 Text                             = "*"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_-]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 40
 X                                = 82
 Y                                = (#Pad_Top# + 127)
 FonSize                          = 10
 Text                             = "-"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_+]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 20
 X                                = 43
 Y                                = (#Pad_Top# + 144)
 FonSize                          = 10
 Text                             = "+"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Operator_=]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 20
 X                                = 123
 Y                                = (#Pad_Top# + 144)
 FonSize                          = 10
 Text                             = "="
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_7]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 145
 Y                                = (#Pad_Top# + 72)
 FonSize                          = 10
 Text                             = "7"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_8]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 185
 Y                                = (#Pad_Top# + 72)
 FonSize                          = 10
 Text                             = "8"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_9]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 225
 Y                                = (#Pad_Top# + 72)
 FonSize                          = 10
 Text                             = "9"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_4]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 18
 X                                = 164
 Y                                = (#Pad_Top# + 97)
 FonSize                          = 10
 Text                             = "4"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_5]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 18
 X                                = 204
 Y                                = (#Pad_Top# + 97)
 FonSize                          = 10
 Text                             = "5"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_6]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 18
 X                                = 244
 Y                                = (#Pad_Top# + 97)
 FonSize                          = 10
 Text                             = "6"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 144
 Y                                = (#Pad_Top# + 128)
 FonSize                          = 10
 Text                             = "1"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 184
 Y                                = (#Pad_Top# + 128)
 FonSize                          = 10
 Text                             = "2"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 224
 Y                                = (#Pad_Top# + 128)
 FonSize                          = 10
 Text                             = "3"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_.]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 40
 X                                = 161
 Y                                = (#Pad_Top# + 114)
 FonSize                          = 10
 Text                             = "."
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Number_0]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontSize                         = 13
 X                                = 203
 Y                                = (#Pad_Top# + 150)
 FonSize                          = 10
 Text                             = "0"
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Display_Result]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontSize                         = 13
 X                                = 127
 Y                                = (#Pad_Top# + 88)
 FonSize                          = 10
 Text                             = #Display_Result#
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[t.Display_Between]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontSize                         = 13
 X                                = 127
 Y                                = (#Pad_Top# + 112)
 FonSize                          = 10
 Text                             = #Display_Between#
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

;-------------BUTTONS-------------

[shape.Display_Result]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 17
 Y                                = (#Pad_Top# + 88)
 MyPath                           = 0, 0 | LineTo 110, 0 | LineTo 130, 20 | LineTo 20, 20 | LineTo 0, 0
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[shape.Display_Between]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 37
 Y                                = (#Pad_Top# + 112)
 MyPath                           = 0, 0 | LineTo 110, 0 | LineTo 90, 20 | LineTo -20, 20 | LineTo 0, 0
 DynamicVariables                 = 1
 Group                            = #calculator#
 Hidden                           = #Calculator_State#

[shape.Operator_/]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 61
 Y                                = (#Pad_Top# + 51)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 LeftMouseUpAction                = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#/"][!SetOption m.Operator_AC String "yes"][!SetVariable Display_Between "#Display_Between#/"][!Update][!Redraw]
 DynamicVariables                 = 1

[shape.Operator_%]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 101
 Y                                = (#Pad_Top# + 51)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Display_Result [m.Operator_%]][!SetVariable Display_Between "#Display_Between#%"][!Update][!Redraw]

[shape.Operator_+/-]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 141
 Y                                = (#Pad_Top# + 51)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Display_Result [m.Operator_+/-]][!Update][!Redraw]

[shape.Operator_AC]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 181
 Y                                = (#Pad_Top# + 51)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Calc_CMD ""][!SetVariable Display_Result "0"][!SetVariable Display_Between ""][!SetVariable Calc_Formula ""][!Update][!Redraw]

[shape.Operator_*]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 21
 Y                                = (#Pad_Top# + 51)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#*"][!SetVariable Display_Between "#Display_Between#*"][!SetOption m.Operator_AC String "yes"][!Update][!Redraw]

[shape.Number_7]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 121
 Y                                = (#Pad_Top# + 73)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_7]][!SetVariable Display_Between "#Display_Between#7"][!Update][!Redraw]

[shape.Number_8]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 161
 Y                                = (#Pad_Top# + 73)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_8]][!SetVariable Display_Between "#Display_Between#8"][!Update][!Redraw]

[shape.Number_9]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 201
 Y                                = (#Pad_Top# + 73)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 48, 18 | LineTo 18, 18 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_9]][!SetVariable Display_Between "#Display_Between#9"][!Update][!Redraw]

;[shape.Operator_-]
; Meter                            = SHAPE
; MeterStyle                       = s.Calc_Operators
; X                                = 101
; Y                                = 95
; MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 45, 15 | LineTo 30, 30 | LineTo 0, 30 | LineTo 15, 15 | LineTo 0, 0
; Group                            = #calculator#

[shape.Number_4]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 141
 Y                                = (#Pad_Top# + 95)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 45, 15 | LineTo 30, 30 | LineTo 0, 30 | LineTo 15, 15 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_4]][!SetVariable Display_Between "#Display_Between#4"][!Update][!Redraw]

[shape.Number_5]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 181
 Y                                = (#Pad_Top# + 95)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 45, 15 | LineTo 30, 30 | LineTo 0, 30 | LineTo 15, 15 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_5]][!SetVariable Display_Between "#Display_Between#5"][!Update][!Redraw]

[shape.Number_6]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 221
 Y                                = (#Pad_Top# + 95)
 MyPath                           = 0, 0 | LineTo 30, 0 | LineTo 45, 15 | LineTo 30, 30 | LineTo 0, 30 | LineTo 15, 15 | LineTo 0, 0
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_6]][!SetVariable Display_Between "#Display_Between#6"][!Update][!Redraw]

[shape.Operator_+]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 39
 Y                                = (#Pad_Top# + 154)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#+"][!SetOption m.Operator_AC String "yes"][!SetVariable Display_Between "#Display_Between#+"][!Update][!Redraw]

[shape.Number_1]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 138
 Y                                = (#Pad_Top# + 132)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_1]][!SetVariable Display_Between "#Display_Between#1"][!Update][!Redraw]

[shape.Number_2]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 178
 Y                                = (#Pad_Top# + 132)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_2]][!SetVariable Display_Between "#Display_Between#2"][!Update][!Redraw]

[shape.Number_3]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 218
 Y                                = (#Pad_Top# + 132)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_3]][!SetVariable Display_Between "#Display_Between#3"][!Update][!Redraw]

[shape.Operator_-]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 78
 Y                                = (#Pad_Top# + 154)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#-"][!SetOption m.Operator_AC String "yes"][!SetVariable Display_Between "#Display_Between#-"][!Update][!Redraw]

[shape.Operator_=]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 117
 Y                                = (#Pad_Top# + 154)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#"][!update][!SetVariable Display_Result [m.Operator_=]][!SetVariable Calc_CMD ""][!SetVariable Calc_Formula ""][!SetOption m.Operator_AC String "yes"][!Update][!Redraw]

[shape.Operator_DOT]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Operators
 X                                = 157
 Y                                = (#Pad_Top# + 154)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Operator_DOT]][!SetVariable Display_Between "#Display_Between#."][!Update][!Redraw]

[shape.Number_0]
 Meter                            = SHAPE
 MeterStyle                       = s.Calc_Buttons
 X                                = 197
 Y                                = (#Pad_Top# + 154)
 MyPath                           = 0, -3 | LineTo 30, -3 | LineTo 12, 15 | LineTo -18, 15 | LineTo 0, -3
 Group                            = #calculator#
 Hidden                           = #Calculator_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_0]][!SetVariable Display_Between "#Display_Between#0"][!Update][!Redraw]