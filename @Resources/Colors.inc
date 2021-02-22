[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Colors variables and pallete
 
[Variables]

 R_Color                          = 
 G_Color                          = 
 B_Color                          = 
 A_Color                          = 

 RGB_Color                        = 162, 94 , 215
 RGB_Font_Color                   = 255, 255, 255
 RGB_Font_Warning_Color           = 
 Global_Color                     = #RGB_Color#, #Global_Alpha#
 Bar_Color                        = #Global_Color#
 Bar_BG_Color                     = #RGB_Color#, #Bar_BG_Alpha#

 BG_Color                         = 0, 0, 0, 160

 Font_Color                       = 73, 214 , 129, 255
 Font_Value_Color                 = 219, 129, 156, 255
 Font_Warning_Color               = 163, 55 , 141, 255 

 Global_Alpha                     = 220
 Font_Alpha                       = 255
 Pallete_Alpha                    = 140
 Bar_BG_Alpha                     = 50

; --- LAST COLORS

; - These vars force Aurora to remember current scheme

; - It needs for returning to your current scheme when mouse left out of a color buttons

 Last_Global_Color                = 162, 94 , 215 
 Last_Bar_Color                   = 
 Last_BG_Color                    = 162, 94 , 215
 Last_RGB_Color                   = 
 Last_RGB_Font_Color              = 73, 214 , 129 
 Last_Font_Color                  = 73, 214 , 129 
 Last_Value_Color                 = 219, 129, 156, 255 
 Last_Warning_Color               = 163, 55 , 141 

; --- COLOR LIBRARY BEGINNING

; - Understanding library variables:

; - CER1 = Color:Element:Red:1 ; CEG1 = Color:Element:Green:1 ; CEB1 = Color:Element:Blue:1
; - CTR2 = Color:Text:Red:2    ; CTG2 = Color:Text:Green:2    ; CTB2 = Color:Text:Blue:2
; - CWR3 = Color:Warning:Red:3 ; CWG3 = Color:Warning:Green:3 ; CWB3 = Color:Warning:Blue:3
; - CVR4 = Color:Value:Red:4   ; CVG4 = Color:Value:Green:4   ; CVG4 = Color:Value:Blue:4

; - Where numbers means a serial numbers of color scheme in pallete.

; - Following codes means which color has used regarding with main color.

; - Example: DSC:D or SCP:A or SQR:B

; - Where left operator means type of color harmony and right tells us a number of a color in this harmony.

; - Color harmony rules:

; - SCP  = Split Complementary
; - DSC  = Double Split Complementary
; - SQR  = Square 
; - TRD  = Triad
; - CPD  = Compound
; - MNL  = Manually - means i didn't find a good color in scheme and took it manually

; - A-E  = Number of color in scheme: A, B, C, D, E.

; - Main color is always equal C. The others is a derivatives. 

; - This tool https://color.adobe.com/create/color-wheel has used in creation of schemes. So you can repeat this expirience and change the pallete as you wish. :)

; --- #1 RED

; - Main #1

 Red                              = #CER1#, #CEG1#, #CEB1#
 CER1                             = 231
 CEG1                             = 47
 CEB1                             = 47
 RedPallete                       = #Red#, #Pallete_Alpha#

; - CPD:D - Text

 Red_Text                         = #CTR1#, #CTG1#, #CTB1#
 CTR1                             = 106
 CTG1                             = 235
 CTB1                             = 106
 Red_Text_Pallete                 = #Red_Text#, #Pallete_Alpha#

; - DSC:D - Value

 Red_Value                        = #CVR1#, #CVG1#, #CVB1#
 CVR1                             = 23
 CVG1                             = 232
 CVB1                             = 201

; - TRD:D - Warning

 Red_Warning                      = #CWR1#, #CWG1#, #CWB1#
 CWR1                             = 23
 CWG1                             = 152
 CWB1                             = 232
 
; --- #2 ORANGE

; - Main #2

 Orange                           = #CER2#, #CEG2# , #CEB2#
 CER2                             = 230
 CEG2                             = 111
 CEB2                             = 11
 OrangePallete                    = #Orange#, #Pallete_Alpha#

; - SQR:D - Text

 Orange_Text                      = #CTR2#, #CTG2# , #CTB2#
 CTR2                             = 34
 CTG2                             = 201
 CTB2                             = 230
 Orange_Text_Pallete              = #Orange_Text#, #Pallete_Alpha#

; - DSC:B - Value

 Orange_Value                     = #CVR2#, #CVG2#, #CVB2#
 CVR2                             = 34
 CVG2                             = 230
 CVB2                             = 150

; - DSC:E - Warning

 Orange_Warning                   = #CWR2#, #CWG2#, #CWB2#
 CWR2                             = 230
 CWG2                             = 36
 CWB2                             = 0
 
; --- #3 YELLOW

; Main #3

 Yellow                           = #CER3#, #CEG3# , #CEB3#
 CER3                             = 247
 CEG3                             = 233
 CEB3                             = 74
 YellowPallete                    = #Yellow#, #Pallete_Alpha#

; - TRD:B - Text

 Yellow_Text                      = #CTR3#, #CTG3# , #CTB3#
 CTR3                             = 99
 CTG3                             = 217
 CTB3                             = 247
 YellowPallete                    = #Yellow_Text#, #Pallete_Alpha#

; - CPD:D - Value

 Yellow_Value                     = #CVR3#, #CVG3#, #CVB3#
 CVR3                             = 137
 CVG3                             = 137
 CVB3                             = 248

; - SQR:E - Warning

 Yellow_Warning                   = #CWR3#, #CWG3# , #CWB3#
 CWR3                             = 247
 CWG3                             = 92
 CWB3                             = 62
 
; --- #4 GREEN

; - Main #4

 Green                            = #CER4#, #CEG4# , #CEB4#
 CER4                             = 142
 CEG4                             = 252
 CEB4                             = 75
 GreenPallete                     = #Green#, #Pallete_Alpha#

; - SQR:B - Text

 Green_Text                       = #CTR4#, #CTG4# , #CTB4#
 CTR4                             = 101
 CTG4                             = 198
 CTB4                             = 252
 Green_Text_Pallete               = #Green_Text#, #Pallete_Alpha#

; - DSC:B - Value

 Green_Value                      = #CVR4#, #CVG4#, #CVB4#
 CVR4                             = 166
 CVG4                             = 101
 CVB4                             = 252

; - SQR:E - Warning

 Green_Warning                    = #CWR4#, #CWG4# , #CWB4#
 CWR4                             = 252
 CWG4                             = 171
 CWB4                             = 63
 
; --- #5 LIGHTBLUE

; - Main #5

 Lightblue                        = #CER5#, #CEG5# , #CEB5#
 CER5                             = 37
 CEG5                             = 221
 CEB5                             = 243 
 LightbluePallete                 = #Lightblue#, #Pallete_Alpha#

; - DCS:E - Text

 Lightblue_Text                   = #CTR5#, #CTG5# , #CTB5#
 CTR5                             = 24
 CTG5                             = 242
 CTB5                             = 142
 Lightblue_Text_Pallete           = #Lightblue_Text#, #Pallete_Alpha#

; - SQR:E - Value

 Lightblue_Value                  = #CVR5#, #CVG5#, #CVB5#
 CVR5                             = 183
 CVG5                             = 242
 CVB5                             = 24

; - SQR:D - Warning

 Lightblue_Warning                = #CWR5#, #CWG5# , #CWB5#
 CWR5                             = 242
 CWG5                             = 110
 CWB5                             = 12
 
; --- #6 BLUE-1

; - Main #6

 Blue1                            = #CER6#, #CEG6# , #CEB6#
 CER6                             = 9
 CEG6                             = 85
 CEB6                             = 238
 Blue1Pallete                     = #Blue1#, #Pallete_Alpha#

; - CPD:D - Text

 Blue1_Text                       = #CTR6#, #CTG6# , #CTB6#
 CTR6                             = 239
 CTG6                             = 170
 CTB6                             = 69
 Blue1_Text_Pallete               = #Blue1_Text#, #Pallete_Alpha#

; - DSC:E - Value

 Blue1_Value                      = #CVR6#, #CVG6#, #CVB6#
 CVR6                             = 21
 CVG6                             = 207
 CVB6                             = 237

; - SQR:B - Warning

 Blue1_Warning                    = #CWR6#, #CWG6# , #CWB6#
 CWR6                             = 237
 CWG6                             = 215
 CWB6                             = 33
 
; --- #7 VIOLET

; - Main #7

 Violet                           = #CER7#, #CEG7# , #CEB7#
 CER7                             = 124
 CEG7                             = 12
 CEB7                             = 239
 VioletPallete                    = #Violet#, #Pallete_Alpha#

; - SQR:E - Text

 Violet_Text                      = #CTR7#, #CTG7# , #CTB7#
 CTR7                             = 0
 CTG7                             = 240
 CTB7                             = 215
 Violet_Text_Pallete              = #Violet_Text#, #Pallete_Alpha#

; - MNL:A - Value

 Violet_Value                     = #CVR7#, #CVG7#, #CVB7#
 CVR7                             = 0
 CVG7                             = 240
 CVB7                             = 117

; - DSC:A - Warning

 Violet_Warning                   = #CWR7#, #CWG7# , #CWB7#
 CWR7                             = 240
 CWG7                             = 24
 CWB7                             = 222
 
; --- #8 MAJENTA

; - Main #8

 Majenta                          = #CER8#, #CEG8# , #CEB8#
 CER8                             = 175
 CEG8                             = 30
 CEB8                             = 222
 MajentaPallete                   = #Majenta#, #Pallete_Alpha#

; - TRD:D - Text

 Majenta_Text                     = #CTR8#, #CTG8# , #CTB8#
 CTR8                             = 9
 CTG8                             = 222
 CTB8                             = 134
 Majenta_Text_Pallete             = #Majenta_Text#, #Pallete_Alpha#

; - SQR:E - Value

 Majenta_Value                    = #CVR8#, #CVG8#, #CVB8#
 CVR8                             = 20
 CVG8                             = 193
 CVB8                             = 222

; - CPD:A - Warning

 Majenta_Warning                  = #CWR8#, #CWG8# , #CWB8#
 CWR8                             = 171
 CWG8                             = 7
 CWB8                             = 82
 
; --- #9 SEA

; - Main #9

 Sea                              = #CER9#, #CEG9# , #CEB9#
 CER9                             = 19
 CEG9                             = 238
 CEB9                             = 199
 SeaPallete                       = #Sea#, #Pallete_Alpha#

; - DSC:E - Text

 Sea_Text                         = #CTR9#, #CTG9# , #CTB9#
 CTR9                             = 7
 CTG9                             = 237
 CTB9                             = 65
 Sea_Text_Pallete                 = #Sea_Text#, #Pallete_Alpha#

; - DSC:A - Value

 Sea_Value                        = #CVR9#, #CVG9#, #CVB9#
 CVR9                             = 31
 CVG9                             = 164
 CVB9                             = 237

; - SQR:B - Warning

 Sea_Warning                      = #CWR9#, #CWG9# , #CWB9#
 CWR9                             = 125
 CWG9                             = 43
 CWB9                             = 237
 
; --- #10 MAJENTA-1

; - Main #10

 Majenta1                         = #CER10#, #CEG10# , #CEB10#
 CER10                            = 245
 CEG10                            = 44
 CEB10                            = 134
 Majenta1Pallete                  = #Majenta1#, #Pallete_Alpha#

; - TRD:D - Text

 Majenta1_Text                    = #CTR10#, #CTG10# , #CTB10#
 CTR10                            = 20
 CTG10                            = 211
 CTB10                            = 245
 Majenta1_Text_Pallete            = #Majenta1_Text#, #Pallete_Alpha#

; - DSC:D - Value

 Majenta1_Value                   = #CVR10#, #CVG10#, #CVB10#
 CVR10                            = 20
 CVG10                            = 245
 CVB10                            = 153

; - DSC:E - Warning

 Majenta1_Warning                 = #CWR10#, #CWG10# , #CWB10#
 CWR10                            = 193
 CWG10                            = 32
 CWB10                            = 245
 
; --- #11 PINK

; - Main #11

 Pink                             = #CER11#, #CEG11# , #CEB11#
 CER11                            = 224
 CEG11                            = 117
 CEB11                            = 203
 PinkPallete                      = #Pink#, #Pallete_Alpha#

; - SQR:B - Text

 Pink_Text                        = #CTR11#, #CTG11# , #CTB11#
 CTR11                            = 224
 CTG11                            = 192
 CTB11                            = 139
 Pink_Text_Pallete                = #Pink_Text#, #Pallete_Alpha#

; - SQR:D - Value

 Pink_Value                       = #CVR11#, #CVG11#, #CVB11#
 CVR11                            = 121
 CVG11                            = 224
 CVB11                            = 94

; - SQR:E - Warning

 Pink_Warning                     = #CWR11#, #CWG11# , #CWB11#
 CWR11                            = 105
 CWG11                            = 166
 CWB11                            = 224
 
; --- #12 VIOLET-1

; - Main #12

 Violet1                          = #CER12#, #CEG12# , #CEB12#
 CER12                            = 162
 CEG12                            = 94
 CEB12                            = 215
 Violet1Pallete                   = #Violet1#, #Pallete_Alpha#

; - TRD:D - Text

 Violet1_Text                     = #CTR12#, #CTG12# , #CTB12#
 CTR12                            = 73
 CTG12                            = 214
 CTB12                            = 129
 Violet1_Text_Pallete             = #Violet1_Text#, #Pallete_Alpha#

; - CPD:D - Value

 Violet1_Value                    = #CVR12#, #CVG12#, #CVB12#
 CVR12                            = 219
 CVG12                            = 129
 CVB12                            = 156

; - CPD:A - Value

 Violet1_Warning                  = #CWR12#, #CWG12# , #CWB12#
 CWR12                            = 163
 CWG12                            = 55
 CWB12                            = 141
 
; --- #13 BROWN

; - Main #13

 Brown                            = #CER13#, #CEG13# , #CEB13#
 CER13                            = 140
 CEG13                            = 86
 CEB13                            = 9
 BrownPallete                     = #Brown#, #Pallete_Alpha#

; - CPD:B - Text

 Brown_Text                       = #CTR13#, #CTG13# , #CTB13#
 CTR13                            = 242
 CTG13                            = 214
 CTB13                            = 111
 Brown_Text_Pallete               = #Brown_Text#, #Pallete_Alpha#

; - SCP:A - Value

 Brown_Value                      = #CVR13#, #CVG13#, #CVB13#
 CVR13                            = 35
 CVG13                            = 217
 CVB13                            = 189

; - MNL:A - Warning

 Brown_Warning                    = #CWR13#, #CWG13# , #CWB13#
 CWR13                            = 22
 CWG13                            = 140
 CWB13                            = 56

; --- #14 LIGHTBLUE-1

; - Main #14

 Lightblue1                       = #CER14#, #CEG14# , #CEB14#
 CER14                            = 178
 CEG14                            = 231
 CEB14                            = 241 
 Lightblue1Pallete                = #Lightblue1#, #Pallete_Alpha#

; - DSC:B - Text

 Lightblue1_Text                  = #CTR14#, #CTG14# , #CTB14#
 CTR14                            = 242
 CTG14                            = 210
 CTB14                            = 203
 Lightblue1_Text_Pallete          = #Lightblue1_Text#, #Pallete_Alpha#

; - SQR:B - Value

 Lightblue1_Value                 = #CVR14#, #CVG14#, #CVB14#
 CVR14                            = 233
 CVG14                            = 203
 CVB14                            = 242

; - SQR:E - Warning

 Lightblue1_Warning               = #CWR14#, #CWG14# , #CWB14#
 CWR14                            = 215
 CWG14                            = 242
 CWB14                            = 167

; --- #15 BLUE

; - Main #15

 Blue                             = #CER15#, #CEG15# , #CEB15#
 CER15                            = 0
 CEG15                            = 24
 CEB15                            = 255
 BluePallete                      = #Blue#, #Pallete_Alpha#

; - SQR:E - Text

 Blue_Text                        = #CTR15#, #CTG15# , #CTB15#
 CTR15                            = 13
 CTG15                            = 255
 CTB15                            = 78
 Blue_Text_Pallete                = #Blue_Text#, #Pallete_Alpha#

; - DSC:E - Value

 Blue_Value                       = #CVR15#, #CVG15#, #CVB15#
 CVR15                            = 13
 CVG15                            = 164
 CVB15                            = 255
 
; - SQR:D - Warning

 Blue_Warning                     = #CWR15#, #CWG15# , #CWB15#
 CWR15                            = 255
 CWG15                            = 205
 CWB15                            = 25

; --- #16 GREEN-1

; - Main #16

 Green1                           = #CER16#, #CEG16# , #CEB16#
 CER16                            = 93
 CEG16                            = 164
 CEB16                            = 62
 Green1Pallete                    = #Green1#, #Pallete_Alpha#

; - CPD:D - Text

 Green1_Text                      = #CTR16#, #CTG16# , #CTB16#
 CTR16                            = 160
 CTG16                            = 110
 CTB16                            = 175
 Green1_Text_Pallete              = #Green1_Text#, #Pallete_Alpha#

; - CPD:A - Value

 Green1_Value                     = #CVR16#, #CVG16#, #CVB16#
 CVR16                            = 60
 CVG16                            = 214
 CVB16                            = 110

; - SQR:D - Warning

 Green1_Warning                   = #CWR16#, #CWG16# , #CWB16#
 CWR16                            = 163
 CWG16                            = 46
 CWB16                            = 155

; - COLOR LIBRARY END

; --- TOP SHAPES BEGINNING

[c.shape_Top_Right_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #OrangePallete# | Fill Color #OrangePallete# | Extend Modifier
 X                                = 970
 Y                                = (#Pad_Top# + 65)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Top_Right_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Orange# | Fill Color #Orange# | Extend Modifier"][!SetVariable  Global_Color "#Orange#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Orange#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Orange#"][!SetVariable  Font_Color "#Orange_Text#"][!SetVariable Font_Warning_Color "#Orange_Warning#"][!SetVariable Font_Value_Color "#Orange_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 MouseLeaveAction                 = [!SetOption c.shape_Top_Right_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #OrangePallete# | Fill Color #OrangePallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Orange#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Orange#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Orange#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Orange_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Orange_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Orange_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Orange_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Orange_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable RGB_Color " #Orange#"][!SetVariable Last_Global_Color " #Orange#"][!SetVariable Last_BG_Color " #Orange#"][!SetVariable Last_RGB_Font_Color " #Orange_Text#"][!SetVariable Last_Font_Color " #Orange_Text#"][!SetVariable Last_Warning_Color " #Orange_Warning#"][!SetVariable Last_Value_Color " #Orange_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Orange_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Orange_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Top_Right_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #BrownPallete# | Fill Color #BrownPallete# | Extend Modifier
 X                                = 990
 Y                                = (#Pad_Top# + 46)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Top_Right_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Brown# | Fill Color #Brown# | Extend Modifier"][!SetVariable  Global_Color "#Brown#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Brown#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Brown#"][!SetVariable  Font_Color "#Brown_Text#"][!SetVariable Font_Warning_Color "#Brown_Warning#"][!SetVariable Font_Value_Color "#Brown_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 MouseLeaveAction                 = [!SetOption c.shape_Top_Right_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #BrownPallete# | Fill Color #BrownPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Brown#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Brown#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Brown#" "#@#Colors.inc"][!SetVariable RGB_Color " #Brown#"][!SetVariable Last_Global_Color " #Brown#"][!SetVariable Last_BG_Color " #Brown#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Brown_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Brown_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Brown_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Brown_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Brown_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Brown_Text#"][!SetVariable Last_Font_Color " #Brown_Text#"][!SetVariable Last_Warning_Color " #Brown_Warning#"][!SetVariable Last_Value_Color " #Brown_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Brown_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Brown_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Top_Left_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #RedPallete# | Fill Color #RedPallete# | Extend Modifier
 X                                = 926
 Y                                = (#Pad_Top# + 65)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Top_Left_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Red# | Fill Color #Red# | Extend Modifier"][!SetVariable  Global_Color "#Red#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Red#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Red#"][!SetVariable  Font_Color "#Red_Text#"][!SetVariable Font_Warning_Color "#Red_Warning#"][!SetVariable Font_Value_Color "#Red_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Top_Left_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #RedPallete# | Fill Color #RedPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Red#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Red#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Red#" "#@#Colors.inc"][!SetVariable RGB_Color " #Red#"][!SetVariable Last_Global_Color " #Red#"][!SetVariable Last_BG_Color " #Red#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Red_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Red_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Red_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Red_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Red_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Red_Text#"][!SetVariable Last_Font_Color " #Red_Text#"][!SetVariable Last_Warning_Color " #Red_Warning#"][!SetVariable Last_Warning_Color " #Red_Warning#"][!SetVariable Last_Value_Color " #Red_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Red_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Red_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Top_Left_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Majenta1Pallete# | Fill Color #Majenta1Pallete# | Extend Modifier
 X                                = 906
 Y                                = (#Pad_Top# + 46)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Top_Left_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Majent1a# | Fill Color #Majenta1# | Extend Modifier"][!SetVariable  Global_Color "#Majenta1#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Majenta1#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Majenta1#"][!SetVariable  Font_Color "#Majenta1_Text#"][!SetVariable Font_Warning_Color "#Majenta1_Warning#"][!SetVariable Font_Value_Color "#Majenta1_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 MouseLeaveAction                 = [!SetOption c.shape_Top_Left_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #Majenta1Pallete# | Fill Color #Majenta1Pallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Majenta1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Majenta1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Majenta1#" "#@#Colors.inc"][!SetVariable RGB_Color " #Majenta1#"][!SetVariable Last_Global_Color " #Majenta1#"][!SetVariable Last_BG_Color " #Majenta1#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Majenta1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Majenta1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Majenta1_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Majenta1_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Majenta1_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Majenta1_Text#"][!SetVariable Last_Font_Color " #Majenta1_Text#"][!SetVariable Last_Warning_Color " #Majenta1_Warning#"][!SetVariable Last_Value_Color " #Majenta1_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Majenta1_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Majenta1_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

; - TOP SHAPES END

; --- RIGHT SHAPES BEGINNING

[c.shape_Right_Top_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #GreenPallete# | Fill Color #GreenPallete# | Extend Modifier
 X                                = 969
 Y                                = (#Pad_Top# + 89)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Right_Top_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Green# | Fill Color #Green# | Extend Modifier"][!SetVariable  Global_Color "#Green#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Green#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Green#"][!SetVariable  Font_Color "#Green_Text#"][!SetVariable Font_Warning_Color "#Green_Warning#"][!SetVariable Font_Value_Color "#Green_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 MouseLeaveAction                 = [!SetOption c.shape_Right_Top_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #GreenPallete# | Fill Color #GreenPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Green#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Green#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Green#" "#@#Colors.inc"][!SetVariable RGB_Color " #Green#"][!SetVariable Last_Global_Color " #Green#"][!SetVariable Last_BG_Color " #Green#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Green_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Green_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Green_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Green_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Green_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Green_Text#"][!SetVariable Last_Font_Color " #Green_Text#"][!SetVariable Last_Warning_Color " #Green_Warning#"][!SetVariable Last_Value_Color " #Green_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Green_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Green_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Right_Top_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #YellowPallete# | Fill Color #YellowPallete# | Extend Modifier
 X                                = 988
 Y                                = (#Pad_Top# + 69)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Right_Top_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Yellow# | Fill Color #Yellow# | Extend Modifier"][!SetVariable  Global_Color "#Yellow#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Yellow#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Yellow#"][!SetVariable  Font_Color "#Yellow_Text#"][!SetVariable Font_Warning_Color "#Yellow_Warning#"][!SetVariable Font_Value_Color "#Yellow_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Right_Top_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #YellowPallete# | Fill Color #YellowPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Yellow#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Yellow#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Yellow#" "#@#Colors.inc"][!SetVariable RGB_Color " #Yellow#"][!SetVariable Last_Global_Color " #Yellow#"][!SetVariable Last_BG_Color " #Yellow#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Yellow_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Yellow_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Yellow_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Yellow_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Yellow_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Yellow_Text#"][!SetVariable Last_Font_Color " #Yellow_Text#"][!SetVariable Last_Warning_Color " #Yellow_Warning#"][!SetVariable Last_Value_Color " #Yellow_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Yellow_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Yellow_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Right_Bottom_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Green1Pallete# | Fill Color #Green1Pallete# | Extend Modifier
 X                                = 993
 Y                                = (#Pad_Top# + 109)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Right_Bottom_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Green1# | Fill Color #Green1# | Extend Modifier"][!SetVariable  Global_Color "#Green1#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Green1#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Green1#"][!SetVariable  Font_Color "#Green1_Text#"][!SetVariable Font_Warning_Color "#Green1_Warning#"][!SetVariable Font_Value_Color "#Green1_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Right_Bottom_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #Green1Pallete# | Fill Color #Green1Pallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Green1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Green1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Green1#" "#@#Colors.inc"][!SetVariable RGB_Color " #Green1#"][!SetVariable Last_Global_Color " #Green1#"][!SetVariable Last_BG_Color " #Green1#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Green1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Green1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Green1_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Green1_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Green1_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Green1_Text#"][!SetVariable Last_Font_Color " #Green1_Text#"][!SetVariable Last_Warning_Color " #Green1_Warning#"][!SetVariable Last_Value_Color " #Green1_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Green1_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Green1_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Right_Bottom_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #SeaPallete# | Fill Color #SeaPallete# | Extend Modifier
 X                                = 1012
 Y                                = (#Pad_Top# + 129)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Right_Bottom_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Sea# | Fill Color #Sea# | Extend Modifier"][!SetVariable  Global_Color "#Sea#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Sea#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Sea#"][!SetVariable  Font_Color "#Sea_Text#"][!SetVariable Font_Warning_Color "#Sea_Warning#"][!SetVariable Font_Value_Color "#Sea_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Right_Bottom_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #SeaPallete# | Fill Color #SeaPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Sea#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Sea#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Sea#" "#@#Colors.inc"][!SetVariable RGB_Color " #Sea#"][!SetVariable Last_Global_Color " #Sea#"][!SetVariable Last_BG_Color " #Sea#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Sea_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Sea_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Sea_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Sea_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Sea_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Sea_Text#"][!SetVariable Last_Font_Color " #Sea_Text#"][!SetVariable Last_Warning_Color " #Sea_Warning#"][!SetVariable Last_Value_Color " #Sea_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Sea_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Sea_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

; - RIGHT SHAPES END

; --- LEFT SHAPES BEGINNING

[c.shape_Left_Top_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #PinkPallete# | Fill Color #PinkPallete# | Extend Modifier
 X                                = 927
 Y                                = (#Pad_Top# + 89)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Left_Top_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Pink# | Fill Color #Pink# | Extend Modifier"][!SetVariable  Global_Color "#Pink#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Pink#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Pink#"][!SetVariable  Font_Color "#Pink_Text#"][!SetVariable Font_Warning_Color "#Pink_Warning#"][!SetVariable Font_Value_Color "#Pink_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Left_Top_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #PinkPallete# | Fill Color #PinkPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Pink#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Pink#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Pink#" "#@#Colors.inc"][!SetVariable RGB_Color " #Pink#"][!SetVariable Last_Global_Color " #Pink#"][!SetVariable Last_BG_Color " #Pink#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Pink_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Pink_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Pink_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Pink_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Pink_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Pink_Text#"][!SetVariable Last_Font_Color " #Pink_Text#"][!SetVariable Last_Warning_Color " #Pink_Warning#"][!SetVariable Last_Value_Color " #Pink_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Pink_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Pink_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Left_Top_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #MajentaPallete# | Fill Color #MajentaPallete# | Extend Modifier
 X                                = 908
 Y                                = (#Pad_Top# + 69)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Left_Top_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Majenta# | Fill Color #Majenta# | Extend Modifier"][!SetVariable  Global_Color "#Majenta#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Majenta#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Majenta#"][!SetVariable  Font_Color "#Majenta_Text#"][!SetVariable Font_Warning_Color "#Majenta_Warning#"][!SetVariable Font_Value_Color "#Majenta_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Left_Top_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #MajentaPallete# | Fill Color #MajentaPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Majenta#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Majenta#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Majenta#" "#@#Colors.inc"][!SetVariable RGB_Color " #Majenta#"][!SetVariable Last_Global_Color " #Majenta#"][!SetVariable Last_BG_Color " #Majenta#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Majenta_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Majenta_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Majenta_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Majenta_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Majenta_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Majenta_Text#"][!SetVariable Last_Font_Color " #Majenta_Text#"][!SetVariable Last_Warning_Color " #Majenta_Warning#"][!SetVariable Last_Value_Color " #Majenta_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Majenta_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Majenta_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Left_Bottom_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Violet1Pallete# | Fill Color #Violet1Pallete# | Extend Modifier
 X                                = 902
 Y                                = (#Pad_Top# + 109)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Left_Bottom_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Violet1# | Fill Color #Violet1# | Extend Modifier"][!SetVariable  Global_Color "#Violet1#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Violet1#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Violet1#"][!SetVariable  Font_Color "#Violet1_Text#"][!SetVariable Font_Warning_Color "#Violet1_Warning#"][!SetVariable Font_Value_Color "#Violet1_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Left_Bottom_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #Violet1Pallete# | Fill Color #Violet1Pallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Violet1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Violet1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Violet1#" "#@#Colors.inc"][!SetVariable RGB_Color " #Violet1#"][!SetVariable Last_Global_Color " #Violet1#"][!SetVariable Last_BG_Color " #Violet1#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Violet1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Violet1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Violet1_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Violet1_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Violet1_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Violet1_Text#"][!SetVariable Last_Font_Color " #Violet1_Text#"][!SetVariable Last_Warning_Color " #Violet1_Warning#"][!SetVariable Last_Value_Color " #Violet1_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Violet1_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Violet1_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Left_Bottom_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #VioletPallete# | Fill Color #VioletPallete# | Extend Modifier
 X                                = 883
 Y                                = (#Pad_Top# + 129)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Left_Bottom_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Violet# | Fill Color #Violet# | Extend Modifier"][!SetVariable  Global_Color "#Violet#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Violet#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Violet#"][!SetVariable  Font_Color "#Violet_Text#"][!SetVariable Font_Warning_Color "#Violet_Warning#"][!SetVariable Font_Value_Color "#Violet_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Left_Bottom_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #VioletPallete# | Fill Color #VioletPallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Violet#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Violet#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Violet#" "#@#Colors.inc"][!SetVariable RGB_Color " #Violet#"][!SetVariable Last_Global_Color " #Violet#"][!SetVariable Last_BG_Color " #Violet#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Violet_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Violet_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Violet_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Violet_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Violet_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Violet_Text#"][!SetVariable Last_Font_Color " #Violet_Text#"][!SetVariable Last_Warning_Color " #Violet_Warning#"][!SetVariable Last_Value_Color " #Violet_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Violet_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Violet_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

; - LEFT SHAPES END

; --- BOTTOM SHAPES BEGINNING

[c.shape_Bottom_Left_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Blue1Pallete# | Fill Color #Blue1Pallete# | Extend Modifier
 X                                = 950
 Y                                = (#Pad_Top# + 132)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1

 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Bottom_Left_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Blue1# | Fill Color #Blue1# | Extend Modifier"][!SetVariable  Global_Color "#Blue1#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Blue1#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Blue1#"][!SetVariable  Font_Color "#Blue1_Text#"][!SetVariable Font_Warning_Color "#Blue1_Warning#"][!SetVariable Font_Value_Color "#Blue1_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 MouseLeaveAction                 = [!SetOption c.shape_Bottom_Left_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #Blue1Pallete# | Fill Color #Blue1Pallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Blue1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Blue1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Blue1#" "#@#Colors.inc"][!SetVariable RGB_Color " #Blue1#"][!SetVariable Last_Global_Color " #Blue1#"][!SetVariable Last_BG_Color " #Blue1#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Blue1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Blue1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Blue1_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Blue1_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Blue1_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Blue1_Text#"][!SetVariable Last_Font_Color " #Blue1_Text#"][!SetVariable Last_Warning_Color " #Blue1_Warning#"][!SetVariable Last_Value_Color " #Blue1_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Blue1_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Blue1_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Bottom_Left_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #BluePallete# | Fill Color #BluePallete# | Extend Modifier
 X                                = 930
 Y                                = (#Pad_Top# + 152)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 0, 24 | LineTo -24, 24
 Modifier                         = Rotate 135
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Bottom_Left_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Blue# | Fill Color #Blue# | Extend Modifier"][!SetVariable  Global_Color "#Blue#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Blue#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Blue#"][!SetVariable  Font_Color "#Blue_Text#"][!SetVariable Font_Warning_Color "#Blue_Warning#"][!SetVariable Font_Value_Color "#Blue_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Bottom_Left_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #BluePallete# | Fill Color #BluePallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Blue#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Blue#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Blue#" "#@#Colors.inc"][!SetVariable RGB_Color " #Blue#"][!SetVariable Last_Global_Color " #Blue#"][!SetVariable Last_BG_Color " #Blue#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Blue_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Blue_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Blue_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Blue_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Blue_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Blue_Text#"][!SetVariable Last_Font_Color " #Blue_Text#"][!SetVariable Last_Warning_Color " #Blue_Warning#"][!SetVariable Last_Value_Color " #Blue_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Blue_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Blue_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Bottom_Right_1_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #LightbluePallete# | Fill Color #LightbluePallete# | Extend Modifier
 X                                = 946
 Y                                = (#Pad_Top# + 132)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Bottom_Right_1_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Lightblue# | Fill Color #Lightblue# | Extend Modifier"][!SetVariable  Global_Color "#Lightblue#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Lightblue#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Lightblue#"][!SetVariable  Font_Color "#Lightblue_Text#"][!SetVariable Font_Warning_Color "#Lightblue_Warning#"][!SetVariable Font_Value_Color "#Lightblue_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Bottom_Right_1_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #LightbluePallete# | Fill Color #LightbluePallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Lightblue#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Lightblue#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Lightblue#" "#@#Colors.inc"][!SetVariable RGB_Color " #Lightblue#"][!SetVariable Last_Global_Color " #Lightblue#"][!SetVariable Last_BG_Color " #Lightblue#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Lightblue_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Lightblue_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Lightblue_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Lightblue_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Lightblue_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Lightblue_Text#"][!SetVariable Last_Font_Color " #Lightblue_Text#"][!SetVariable Last_Warning_Color " #Lightblue_Warning#"][!SetVariable Last_Value_Color " #Lightblue_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Lightblue_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Lightblue_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

[c.shape_Bottom_Right_2_E]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Lightblue1Pallete# | Fill Color #Lightblue1Pallete# | Extend Modifier
 X                                = 966
 Y                                = (#Pad_Top# + 152)
 MyPath                           = 0, 0 | LineTo 24, 0 | LineTo 48, 24 | LineTo 24, 24
 Modifier                         = Rotate 45
 Group                            = #settings_color#
 Hidden                           = #Settings_Color#
 DynamicVariables                 = 1
 
 ; ; MouseActionCursorName            = #Hand#

 MouseOverAction                  = [!SetOption c.shape_Bottom_Right_2_E Shape  "Path MyPath | Strokewidth 0 | Stroke Color #Lightblue1# | Fill Color #Lightblue1# | Extend Modifier"][!SetVariable  Global_Color "#Lightblue1#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Lightblue1#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Lightblue1#"][!SetVariable  Font_Color "#Lightblue1_Text#"][!SetVariable Font_Warning_Color "#Lightblue1_Warning#"][!SetVariable Font_Value_Color "#Lightblue1_Value#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 MouseLeaveAction                 = [!SetOption c.shape_Bottom_Right_2_E Shape "Path MyPath | Strokewidth 0 | Stroke Color #Lightblue1Pallete# | Fill Color #Lightblue1Pallete# | Extend Modifier"][!SetVariable  Global_Color "#Last_Global_Color#, #Global_Alpha#"][!SetVariable  Bar_BG_Color "#Last_BG_Color#, #Bar_BG_Alpha#"][!SetVariable  RGB_Color "#Last_BG_Color#"][!SetVariable  Font_Color "#Last_Font_Color#, #Font_Alpha#"][!SetVariable  Font_Warning_Color "#Last_Warning_Color#"][!SetVariable  Font_Value_Color "#Last_Value_Color#"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]
 
 LeftMouseUpAction                = [!WriteKeyValue "Variables" "RGB_Color" " #Lightblue1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Global_Color" " #Lightblue1#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_BG_Color" " #Lightblue1#" "#@#Colors.inc"][!SetVariable RGB_Color " #Lightblue1#"][!SetVariable Last_Global_Color " #Lightblue1#"][!SetVariable Last_BG_Color " #Lightblue1#"][!WriteKeyValue "Variables" "Last_RGB_Font_Color" " #Lightblue1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Font_Color" " #Lightblue1_Text#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Warning_Color" " #Lightblue1_Warning#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Color" " #Lightblue1_Text#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Font_Warning_Color" " #Lightblue1_Warning#, #Font_Alpha#" "#@#Colors.inc"][!SetVariable Last_RGB_Font_Color " #Lightblue1_Text#"][!SetVariable Last_Font_Color " #Lightblue1_Text#"][!SetVariable Last_Warning_Color " #Lightblue1_Warning#"][!SetVariable Last_Value_Color " #Lightblue1_Value#"][!WriteKeyValue "Variables" "Font_Value_Color" " #Lightblue1_Value#, #Font_Alpha#" "#@#Colors.inc"][!WriteKeyValue "Variables" "Last_Value_Color" " #Lightblue1_Value#, #Font_Alpha#" "#@#Colors.inc"]#Warning_Measures_Update#[!UpdateMeter *][!Redraw]

; - BOTTOM SHAPES END
