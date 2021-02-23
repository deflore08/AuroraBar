[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Styles
 
[Variables]
 Long_Bar_Width                   = 180
 Middle_Bar_Width                 = 89
 Short_Bar_Width                  = 75
 Bar_Height                       = 8
 GraphHeight                      = 24

; --- SHAPE STYLES BEGINNING
 
[s.LineStyle]
 LineColor                        = #Global_Color#

[s.ThinLineStyle]
 LineColor                        = #Bar_BG_Color#
 
[s.Shape_BG]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #BG_Color# | Fill Color #BG_Color#

[s.TriangleEmpty]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100

[s.TriangleFaded_Top]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, #Alpha_Tri_Top#
 
[s.TriangleFaded_Left]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, #Alpha_Tri_Left#
 
[s.TriangleFaded_Right]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, #Alpha_Tri_Right#
 
[s.TriangleFaded_Bottom]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, #Alpha_Tri_Bottom#

[s.TriangleFilled]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, 250
 
[s.ShapeEmpty]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100

[s.Calc_Buttons]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color #Bar_BG_Color#

[s.Calc_Operators]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color #Bar_BG_Color#

[s.Calc_Display]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100

;[s.Color_Elements]
; Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #Bar_BG_Color# | Extend Modifier

[s.Color_Elements]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #RGB_Color#, #Alpha_Crystal_Shapes# | Extend Modifier

[s.Color_Elements_Filled]
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color #Global_Color# | Extend Modifier
 
[s.Color_Text]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Font_Color# | Fill Color #Font_Color# | Extend Modifier

[style.BG]
 Shape                            = Path MyPath | StrokeWidth 0 | Stroke Color 0,0,0,0 | Fill Color #BG_Color# | Extend Modifier

[style.BG_Empty]
 Shape                            = Path MyPath | StrokeWidth 0 | Stroke Color 0,0,0,0 | Fill Color 0, 0, 0, 1 | Extend Modifier

; - SHAPE STYLES END

; --- FONT STYLES BEGINNING

[style.text.Stopwatch_Digits]
 FontColor                        = #Font_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringAlign                      = Center
 StringStyle                      = #T_String_Style#
 AntiAlias                        = 1

[style.text.Simple_Font_Left_Align]
 FontColor                        = #Font_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Left
 AntiAlias                        = 1

[style.text.Simple_Font_Left_Align_Value]
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Left
 AntiAlias                        = 1
 
[style.text.Simple_Font_Center_Align]
 FontColor                        = #Font_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Center
 AntiAlias                        = 1

[style.text.Simple_Font_Center_Align_Value]
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Center
 AntiAlias                        = 1
 
[style.text.Simple_Font_Right_Align]
 FontColor                        = #Font_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Right
 AntiAlias                        = 1

[style.text.Simple_Font_Right_Align_Value]
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Font_Size#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Right
 AntiAlias                        = 1

[style.text.Settings_Menu]
 FontColor                        = #Global_Color#
 FontSize                         = 13
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Center
 AntiAlias                        = 1
 
[f.fadedSmallFontLeftAlign]
 FontSize                         = #Faded_Font_Size_Small#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Left
 AntiAlias                        = 1
 
[f.fadedSmallFontCenterAlign]
 FontSize                         = #Faded_Font_Size_Small#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Center
 AntiAlias                        = 1
 
[f.fadedSmallFontRightAlign]
 FontSize                         = #Faded_Font_Size_Small#
 FontFace                         = #Font#
 StringStyle                      = #T_String_Style#
 StringAlign                      = Right
 AntiAlias                        = 1

; - FONT STYLES END

; --- BAR STYLES BEGINNING

[b.LongBarLeftTopClickable]
 ;W                                = #Long_Bar_Width#
 W = 100
 H                                = #Bar_Height#
 TransformationMatrix             = 1; 0; 1; 1; -110; 0
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 Flip                             = 0

[b.LongBarLeftTopPeaks]
 ;W                                = #Long_Bar_Width#
 W = 100
 H                                = 1
 TransformationMatrix             = 1; 0; 1; 1; -110; 0
 BarColor                         = #Global_Color##
 BarOrientation                   = Horizontal
 Flip                             = 0

[b.LongBarLeftTop]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 TransformationMatrix             = 1; 0; 1; 1; 35; 0
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 Flip                             = 0

[b.LongBarLeftBottom]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 TransformationMatrix             = 1; 0; -1; 1; 35; 0
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 Flip                             = 0

[b.LongBarRightTop]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 1

[style.bar.LONG_BAR_RIGHT_TOP_PEAKS]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Font_Warning_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 1

[style.bar.LONG_BAR_RIGHT_BOTTOM_PEAKS]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Font_Warning_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 1

[b.LongBarRightBottom]
 W                                = #Long_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 1

[b.MiddleBarLeftTop]
 W                                = #Middle_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 0

[b.MiddleBarLeftBottom]
 W                                = #Middle_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 0

[b.MiddleBarRightTop]
 W                                = #Middle_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 1

[b.MiddleBarRightBottom]
 W                                = #Middle_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 1
 
[b.ShortBarLeftTop]
 W                                = #Short_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 0

[b.ShortBarLeftBottom]
 W                                = #Short_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 0

[b.ShortBarRightTop]
 W                                = #Short_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; -1; 1; 45; 0
 Flip                             = 1

[b.ShortBarRightBottom]
 W                                = #Short_Bar_Width#
 H                                = #Bar_Height#
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = Horizontal
 TransformationMatrix             = 1; 0; 1; 1; 45; 0
 Flip                             = 1
 
; - BAR STYLES END
 
