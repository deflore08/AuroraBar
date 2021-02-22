[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.4b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Background

; --- BG ---

[shape.BG_Left_Part]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 0
 Y                                = (#Pad_Top# + 2)
 DynamicVariables                 = 1
 MyPath                           = 0, 0 | LineTo 960, 0 | LineTo 960, 30 | LineTo 856, 30 | LineTo 856, 186 | LineTo 960, 186 | LineTo 960, 216 | LineTo 0, 216 | ClosePath 1

[BG]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 0
 Y                                = (#Pad_Top# + 2)
 DynamicVariables                 = 1
 MyPath                           = 960, 30 | LineTo 856, 30 | LineTo 856, 186 | LineTo 1064, 186 | LineTo 1064, 30 | ClosePath 1
 MouseActionCursor                = 0
 MouseOverAction                  = #Aurora_Config_MouseOver#
 MouseLeaveAction                 = #Aurora_Config_MouseLeave#
 MiddleMouseUpAction              = [!SetWindowPosition "#Window_X#@#Monitor_Num#" "#Window_Y#" "#Anchor_X#%" "#Anchor_Y#%"]

[shape.BG_Right_Part]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 0
 Y                                = (#Pad_Top# + 2)
 DynamicVariables                 = 1
 MyPath                           = 1920, 0 | LineTo 960, 0 | LineTo 960, 30 | LineTo 1064, 30 | LineTo 1064, 186 | LineTo 960, 186 | LineTo 960, 216 | LineTo 1920, 216 | ClosePath 1

