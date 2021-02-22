[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.4b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = It contains all (almost all..) lines and shapes

; --- TRIANGLE TOP

[shape.Triangle_Top-Shape]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleEmpty
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 DynamicVariables                 = 1
 MyPath                           = 960, 30 | LineTo 930, 2 | LineTo 990, 2 | LineTo 960, 30

 MouseOverAction                  = [!CommandMeasure animation.fader.TRIANGLES "Stop 1"][!CommandMeasure animation.fader.TRIANGLES "Execute 2"][Play #MouseOver_1#]
; MouseOverAction                  = [!CommandMeasure animation.fader.TRIANGLES "Stop 1"][!CommandMeasure animation.fader.TRIANGLES "Execute 2"][!CommandMeasure "sound.test.TRIANGLE_TOP" "Run"]
 MouseLeaveAction                 = [!CommandMeasure animation.fader.TRIANGLES "Stop 2"][!CommandMeasure animation.fader.TRIANGLES "Execute 1"][!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFaded_Top"]

[shape.Triangle_Top-Shape_Faded]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleFaded_Top
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 MyPath                           = 960, 30 | LineTo 930, 2 | LineTo 990, 2 | LineTo 960, 30
 DynamicVariables                 = 1

 LeftMouseDownAction              = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFilled"][!EnableMeasure f.Height_Top_Check][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 LeftMouseUpAction                = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFaded_Top"][!SetVariable Triangle_Top_Mechanic "(1 - #Triangle_Top_Mechanic#)"][!WriteKeyValue Variables Triangle_Top_Mechanic " (1 - #Triangle_Top_Mechanic#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.TRIANGLE_TOP][!UpdateMeasure sound.TRIANGLE_TOP][!EnableMeasure f.Triangle_Top_Mechanic][!UpdateMeasure f.Triangle_Top_Mechanic]
 
 RightMouseDownAction             = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 RightMouseUpAction               = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFaded_Top"][!SetVariable Debug_State "(1 - #Debug_State#)"][!WriteKeyValue Variables Debug_State "(1 - #Debug_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.DEBUG][!UpdateMeasure sound.DEBUG][!UpdateMeter #CURRENTSECTION#][!UpdateMeasureGroup #debug#][!UpdateMeterGroup #debug#][!Redraw]
 MiddleMouseDownAction            = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFilled"]
 MiddleMouseUpAction              = [!SetOption shape.Triangle_Top-Shape_Faded MeterStyle "s.TriangleFaded_Top"]
 MouseScrollUpAction              = [!SetVariable Power_Plan_Current "(#Power_Plan_Current# + 1)"][!UpdateMeasure formula.POWER_PLAN_SWITCHER][!UpdateMeasure sensor.POWER_PLAN_ACTIVE_POWER][!UpdateMeter #CURRENTSECTION#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Power_Plan_Current "(#Power_Plan_Current# - 1)"][!UpdateMeasure formula.POWER_PLAN_SWITCHER][!UpdateMeasure sensor.POWER_PLAN_ACTIVE_POWER][!UpdateMeter #CURRENTSECTION#][!Redraw]
 MouseLeaveAction                 = 

; --- TRIANGLE BOTTOM

[shape.Triangle_Bottom-Shape]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleEmpty
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 DynamicVariables                 = 1
 MyPath                           = 960, 188 | LineTo 930, 219 | LineTo 990, 219 | LineTo 960, 188
 MouseOverAction                  = [!CommandMeasure animation.fader.TRIANGLES "Stop 7"][!CommandMeasure animation.fader.TRIANGLES "Execute 8"][Play #MouseOver_1#]
 MouseLeaveAction                 = [!CommandMeasure animation.fader.TRIANGLES "Stop 8"][!CommandMeasure animation.fader.TRIANGLES "Execute 7"][!SetOption shape.Triangle_Bottom-Shape_Faded MeterStyle "s.TriangleFaded_Bottom"]

[shape.Triangle_Bottom-Shape_Faded]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleFaded_Bottom
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 MyPath                           = 960, 188 | LineTo 930, 219 | LineTo 990, 219 | LineTo 960, 188
 DynamicVariables                 = 1
 LeftMouseDownAction              = [!SetOption shape.Triangle_Bottom-Shape_Faded MeterStyle "s.TriangleFilled"][!EnableMeasure f.Height_Bottom_Check][!UpdateMeter #CURRENTSECTION#][!Redraw]
 LeftMouseUpAction                = [!SetOption shape.Triangle_Bottom-Shape_Faded MeterStyle "s.TriangleFaded_Bottom"][!SetVariable Triangle_Bottom_Mechanic "(1 - #Triangle_Bottom_Mechanic#)"][!WriteKeyValue Variables Triangle_Bottom_Mechanic " (1 - #Triangle_Bottom_Mechanic#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.TRIANGLE_BOTTOM][!UpdateMeasure sound.TRIANGLE_BOTTOM][!EnableMeasure f.Triangle_Bottom_Mechanic][!UpdateMeasure f.Triangle_Bottom_Mechanic][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 RightMouseDownAction             = [!SetOption shape.Triangle_Bottom-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 RightMouseUpAction               = [!SetOption shape.Triangle_Bottom-Shape_Faded MeterStyle "s.TriangleFaded_Bottom"][!SetVariable Logs_Bottom_State "(1 - #Logs_Bottom_State#)"][!WriteKeyValue Variables Logs_Bottom_State " (1 - #Logs_Bottom_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.LOGS_BOTTOM][!UpdateMeasure sound.LOGS_BOTTOM][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #logs_bottom_shapes#][!UpdateMeterGroup #logs_bottom#][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 MouseScrollUpAction              = [!SetVariable Power_Plan_Current "(#Power_Plan_Current# + 1)"][!UpdateMeasure formula.POWER_PLAN_SWITCHER][!UpdateMeasure sensor.POWER_PLAN_ACTIVE_POWER][!UpdateMeter #CURRENTSECTION#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Power_Plan_Current "(#Power_Plan_Current# - 1)"][!UpdateMeasure formula.POWER_PLAN_SWITCHER][!UpdateMeasure sensor.POWER_PLAN_ACTIVE_POWER][!UpdateMeter #CURRENTSECTION#][!Redraw]

; --- TRIANGLE LEFT

[shape.Triangle_Left-Shape]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleEmpty
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 DynamicVariables                 = 1
 MyPath                           = 31, 110 | LineTo 1, 140 | LineTo 1, 80 | LineTo 31, 110
 MouseOverAction                  = [!CommandMeasure animation.fader.TRIANGLES "Stop 3"][!CommandMeasure animation.fader.TRIANGLES "Execute 4"][Play #MouseOver_1#]
 MouseLeaveAction                 = [!CommandMeasure animation.fader.TRIANGLES "Stop 4"][!CommandMeasure animation.fader.TRIANGLES "Execute 3"][!SetOption shape.Triangle_Left-Shape_Faded MeterStyle "s.TriangleFaded_Left"]

[shape.Triangle_Left-Shape_Faded]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleFaded_Left
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 MyPath                           = 31, 110 | LineTo 1, 140 | LineTo 1, 80 | LineTo 31, 110
 DynamicVariables                 = 1
 LeftMouseDownAction              = [!SetOption shape.Triangle_Left-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 LeftMouseUpAction                = [!SetOption shape.Triangle_Left-Shape_Faded MeterStyle "s.TriangleFaded_Left"][!SetVariable Triangle_Left_Mechanic "(1 - #Triangle_Left_Mechanic#)"][!WriteKeyValue Variables Triangle_Left_Mechanic " (1 - #Triangle_Left_Mechanic#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.TRIANGLE_LEFT][!UpdateMeasure sound.TRIANGLE_LEFT][!UpdateMeasure f.Triangle_Left_Mechanic][!UpdateMeter #CURRENTSECTION#]
 RightMouseUpAction               = [!SetOption shape.Triangle_Left-Shape_Faded MeterStyle "s.TriangleFaded_Left"] [Play #Expand_2#][!UpdateMeter #CURRENTSECTION#][!Redraw]
 RightMouseDownAction             = [!SetOption shape.Triangle_Left-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
; --- TRIANGLE RIGHT

[shape.Triangle_Right-Shape]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleEmpty
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 DynamicVariables                 = 1
 MyPath                           = 1889, 110 | LineTo 1919, 140 | LineTo 1919, 80 | LineTo 1889, 110
 MouseOverAction                  = [!CommandMeasure animation.fader.TRIANGLES "Stop 5"][!CommandMeasure animation.fader.TRIANGLES "Execute 6"][Play #MouseOver_1#]
 MouseLeaveAction                 = [!CommandMeasure animation.fader.TRIANGLES "Stop 6"][!CommandMeasure animation.fader.TRIANGLES "Execute 5"][!SetOption shape.Triangle_Right-Shape_Faded MeterStyle "s.TriangleFaded_Right"]

[shape.Triangle_Right-Shape_Faded]
 Meter                            = SHAPE
 MeterStyle                       = s.TriangleFaded_Right
 X                                = 0
 Y                                = (#Pad_Top# + 0)
 MyPath                           = 1889, 110 | LineTo 1919, 140 | LineTo 1919, 80 | LineTo 1889, 110
 DynamicVariables                 = 1
 LeftMouseDownAction              = [!SetOption shape.Triangle_Right-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 LeftMouseUpAction                = [!SetOption shape.Triangle_Right-Shape_Faded MeterStyle "s.TriangleFaded_Right"][!SetVariable Triangle_Right_Mechanic "(1 - #Triangle_Right_Mechanic#)"][!WriteKeyValue Variables Triangle_Right_Mechanic " (1 - #Triangle_Right_Mechanic#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.TRIANGLE_RIGHT][!UpdateMeasure sound.TRIANGLE_RIGHT][!UpdateMeasure f.Triangle_Right_Mechanic][!UpdateMeter #CURRENTSECTION#][!Redraw]
 RightMouseDownAction             = [!SetOption shape.Triangle_Right-Shape_Faded MeterStyle "s.TriangleFilled"][!UpdateMeter #CURRENTSECTION#][!Redraw]
 RightMouseUpAction               = [!SetOption shape.Triangle_Right-Shape_Faded MeterStyle "s.TriangleFaded_Right"] [Play #Expand_2#][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
; --- LEFT LINES ---

; --- TOP DIRECTS LEFT

; - Threads lines

[shape.Top_Direct_Left_1]
 Meter                            = ROUNDLINE
 X                                = 660
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Direct_Left_1_2]
 Meter                            = ROUNDLINE
 X                                = 632
 Y                                = (#Pad_Top# - 25)
 LineStart                        = 0
 LineLength                       = 167
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #threads_shapes#
 Hidden                           = #Threads_State#
 
; - CPU Info lines

[shape.Top_Direct_Left_2]
 Meter                            = ROUNDLINE
 X                                = 512
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
[shape.Top_Direct_Left_2_2]
 Meter                            = ROUNDLINE
 X                                = 485
 Y                                = (#Pad_Top# - 25)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Direct_Left_2_3]
 Meter                            = ROUNDLINE
 X                                = 457
 Y                                = (#Pad_Top# - 53)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Direct_Left_2_4]
 Meter                            = ROUNDLINE
 X                                = 429
 Y                                = (#Pad_Top# - 81)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Direct_Left_2_5]
 Meter                            = ROUNDLINE
 X                                = 401
 Y                                = (#Pad_Top# - 109)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

; - RAM lines

[shape.Top_Direct_Left_3]
 Meter                            = ROUNDLINE
 X                                = 304
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Direct_Left_3_2]
 Meter                            = ROUNDLINE
 X                                = 277
 Y                                = (#Pad_Top# -25)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #ram_top_shapes#
 Hidden                           = #RAM_Top_State#

[shape.Top_Direct_Left_3_3]
 Meter                            = ROUNDLINE
 X                                = 249
 Y                                = (#Pad_Top# -53)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #ram_top_shapes#
 Hidden                           = #RAM_Top_State#

; - Note & calculator lines

[shape.Top_Direct_Left_4]
 Meter                            = ROUNDLINE
 X                                = 82
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 119
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- TOP ANGLES LEFT

; - Threads angles

[shape.Top_Angle_Left_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 856
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Left_1_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 820
 Y                                = (#Pad_Top# - 4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #threads_shapes#
 Hidden                           = #Threads_State#

; - CPU Info angles

[shape.Top_Angle_Left_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 648
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Left_2_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 612
 Y                                = (#Pad_Top# - 4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Angle_Left_2_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 584
 Y                                = (#Pad_Top# - 32)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Angle_Left_2_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 556
 Y                                = (#Pad_Top# - 60)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

[shape.Top_Angle_Left_2_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 528
 Y                                = (#Pad_Top# - 88)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #cpu_info_shapes#
 Hidden                           = #CPU_Info_State#

; - RAM Top angles

[shape.Top_Angle_Left_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 440
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Left_3_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 404
 Y                                = (#Pad_Top# -4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #ram_top_shapes#
 Hidden                           = #RAM_Top_State#

[shape.Top_Angle_Left_3_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 376
 Y                                = (#Pad_Top# -32)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #ram_top_shapes#
 Hidden                           = #RAM_Top_State#

; - Note & calculator angles

[shape.Top_Angle_Left_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 231
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Left_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 23
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- TOP LOWER ANGLES LEFT

[shape.Top-Lower_Angle_Left_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 821
 Y                                = (#Pad_Top# + 45)
 LineStart                        = 0
 LineLength                       = 19
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Left_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 606
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Left_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 358
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Left_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 X                                = 130
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- TOP LOWER DIRECTS LEFT

[shape.Top-Lower_Direct_Left_1]
 Meter                            = ROUNDLINE
 X                                = 648
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 160
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Left_2]
 Meter                            = ROUNDLINE
 X                                = 440
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 160
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Left_3]
 Meter                            = ROUNDLINE
 X                                = 231
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 121
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Left_4]
 Meter                            = ROUNDLINE
 X                                = 23
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 101
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- BOTTOM UPPER DIRECTS LEFT
 
[shape.Bottom-Upper_Direct_Left_1]
 Meter                            = ROUNDLINE
 X                                = 648
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 160
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Left_2]
 Meter                            = ROUNDLINE
 X                                = 440
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 160
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Left_3]
 Meter                            = ROUNDLINE
 X                                = 231
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 121
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Left_4]
 Meter                            = ROUNDLINE
 X                                = 23
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 101
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
 ; --- BOTTOM UPPER ANGLES LEFT

[shape.Bottom-Upper_Angle_Left_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 821
 Y                                = (#Pad_Top# + 175)
 LineStart                        = 0
 LineLength                       = 19
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Left_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 606
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Left_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 358
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Left_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 130
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- BOTTOM ANGLES LEFT

; - Throttling angles

[shape.Bottom_Angle_Left_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 856
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Left_1_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 820
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Throttling#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #throttling_shapes#
 Hidden                           = #Throttling_State#

; - CPU Top angles

[shape.Bottom_Angle_Left_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 648
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Left_2_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 612
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Angle_Left_2_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 584
 Y                                = (#Pad_Top# + 252 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Angle_Left_2_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 556
 Y                                = (#Pad_Top# + 280 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Angle_Left_2_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 528
 Y                                = (#Pad_Top# + 308 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#
 
; - VRAM Top angles

[shape.Bottom_Angle_Left_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 440
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Left_3_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 404
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_VRAM_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #vram_top_shapes#
 Hidden                           = #VRAM_Top_State#

[shape.Bottom_Angle_Left_3_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 376
 Y                                = (#Pad_Top# + 252 - #Pad_Bottom_VRAM_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #vram_top_shapes#
 Hidden                           = #VRAM_Top_State#

; - Timer & stopwatch angles

[shape.Bottom_Angle_Left_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 231
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Left_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 23
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

; --- BOTTOM DIRECTS LEFT

; - Throttling lines

[shape.Bottom_Direct_Left_1]
 Meter                            = ROUNDLINE
 X                                = 660
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Left_1_2]
 Meter                            = ROUNDLINE
 X                                = 632
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_Throttling#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 167
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #throttling_shapes#
 Hidden                           = #Throttling_State#
 
; - CPU Top lines

[shape.Bottom_Direct_Left_2]
 Meter                            = ROUNDLINE
 X                                = 512
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Left_2_2]
 Meter                            = ROUNDLINE
 X                                = 485
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Direct_Left_2_3]
 Meter                            = ROUNDLINE
 X                                = 457
 Y                                = (#Pad_Top# + 272 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Direct_Left_2_4]
 Meter                            = ROUNDLINE
 X                                = 429
 Y                                = (#Pad_Top# + 300 - #Pad_Bottom_CPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#

[shape.Bottom_Direct_Left_2_5]
 Meter                            = ROUNDLINE
 X                                = 402
 Y                                = (#Pad_Top# + 328 - #Pad_Bottom_CPU_Top#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes#
 Hidden                           = #CPU_Top_State#
 
; - VRAM Top lines

[shape.Bottom_Direct_Left_3]
 Meter                            = ROUNDLINE
 X                                = 304
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Left_3_2]
 Meter                            = ROUNDLINE
 X                                = 277
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_VRAM_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #vram_top_shapes#
 Hidden                           = #VRAM_Top_State#

[shape.Bottom_Direct_Left_3_3]
 Meter                            = ROUNDLINE
 X                                = 249
 Y                                = (#Pad_Top# + 272 - #Pad_Bottom_VRAM_Top#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #vram_top_shapes#
 Hidden                           = #VRAM_Top_State#
 
; - Timer and stopwatch lines

[shape.Bottom_Direct_Left_4]
 Meter                            = ROUNDLINE
 X                                = 82
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 119
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- LINES RIGHT ---

; --- TOP DIRECTS RIGHT

; - Clock info lines

[shape.Top_Direct_Right_1]
 Meter                            = ROUNDLINE
 X                                = 1095
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Direct_Right_1_2]
 Meter                            = ROUNDLINE
 X                                = 1122
 Y                                = (#Pad_Top# - 25)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #clock_info_shapes#
 Hidden                           = #Clock_Info_State#

; - GPU Info lines

[shape.Top_Direct_Right_2]
 Meter                            = ROUNDLINE
 X                                = 1303
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Direct_Right_2_2]
 Meter                            = ROUNDLINE
 X                                = 1330
 Y                                = (#Pad_Top# - 25)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Direct_Right_2_3]
 Meter                            = ROUNDLINE
 X                                = 1358
 Y                                = (#Pad_Top# - 53)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Direct_Right_2_4]
 Meter                            = ROUNDLINE
 X                                = 1386
 Y                                = (#Pad_Top# - 81)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Direct_Right_2_5]
 Meter                            = ROUNDLINE
 X                                = 1414
 Y                                = (#Pad_Top# - 109)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

; - Disk Top Write lines

[shape.Top_Direct_Right_3]
 Meter                            = ROUNDLINE
 X                                = 1511
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Direct_Right_3_2]
 Meter                            = ROUNDLINE
 X                                = 1538
 Y                                = (#Pad_Top# - 25)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #io_write_top_shapes#
 Hidden                           = #Disk_Write_Top_State#

[shape.Top_Direct_Right_3_3]
 Meter                            = ROUNDLINE
 X                                = 1566
 Y                                = (#Pad_Top# - 53)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #io_write_top_shapes#
 Hidden                           = #Disk_Write_Top_State#

; - Uptime lines

[shape.Top_Direct_Right_4]
 Meter                            = ROUNDLINE
 X                                = 1719
 Y                                = (#Pad_Top# + 2)
 LineStart                        = 0
 LineLength                       = 119
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- TOP ANGLES RIGHT

; - Clock Info angles

[shape.Top_Angle_Right_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1065
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Right_1_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1101
 Y                                = (#Pad_Top# - 4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #clock_info_shapes#
 Hidden                           = #Clock_Info_State#

; - GPU Info angles

[shape.Top_Angle_Right_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1273
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Right_2_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1309
 Y                                = (#Pad_Top# - 4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Angle_Right_2_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1337
 Y                                = (#Pad_Top# - 32)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Angle_Right_2_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1365
 Y                                = (#Pad_Top# - 60)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

[shape.Top_Angle_Right_2_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1393
 Y                                = (#Pad_Top# - 88)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1 
 Group                            = #gpu_info_shapes#
 Hidden                           = #GPU_Info_State#

; - Disk Top Write angles

[shape.Top_Angle_Right_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1481
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Right_3_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1517
 Y                                = (#Pad_Top# - 4)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_write_top_shapes#
 Hidden                           = #Disk_Write_Top_State#

[shape.Top_Angle_Right_3_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1545
 Y                                = (#Pad_Top# - 32)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_write_top_shapes#
 Hidden                           = #Disk_Write_Top_State#

; - Uptime angles

[shape.Top_Angle_Right_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1690
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top_Angle_Right_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1897
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 33
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

; --- TOP LOWER DIRECTS RIGHT

[shape.Top-Lower_Direct_Right_1]
 Meter                            = ROUNDLINE
 X                                = 1112
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 161
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Right_2]
 Meter                            = ROUNDLINE
 X                                = 1320
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 161
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Right_3]
 Meter                            = ROUNDLINE
 X                                = 1568
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 122
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Direct_Right_4]
 Meter                            = ROUNDLINE
 X                                = 1796
 Y                                = (#Pad_Top# + 32)
 LineStart                        = 0
 LineLength                       = 101
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
 ; --- TOP LOWER ANGLES RIGHT

[shape.Top-Lower_Angle_Right_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1099
 Y                                = (#Pad_Top# + 45)
 LineStart                        = 0
 LineLength                       = 19
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Right_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1314
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Right_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1562
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Top-Lower_Angle_Right_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 RotationAngle                    = (RAD(-180))
 X                                = 1790
 Y                                = (#Pad_Top# + 38)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- BOTTOM UPPER ANGLES RIGHT

[shape.Bottom-Upper_Angle_Right_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1099
 Y                                = (#Pad_Top# + 175)
 LineStart                        = 0
 LineLength                       = 19
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Right_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1314
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Right_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1562
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Angle_Right_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1790
 Y                                = (#Pad_Top# + 182)
 LineStart                        = 0
 LineLength                       = 9
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

 ; --- BOTTOM UPPER DIRECTS RIGHT

[shape.Bottom-Upper_Direct_Right_1]
 Meter                            = ROUNDLINE
 X                                = 1112
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 161
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Right_2]
 Meter                            = ROUNDLINE
 X                                = 1320
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 161
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Right_3]
 Meter                            = ROUNDLINE
 X                                = 1568
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 122
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom-Upper_Direct_Right_4]
 Meter                            = ROUNDLINE
 X                                = 1796
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 101
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- BOTTOM ANGLES RIGHT

; - Power Limit Angles

[shape.Bottom_Angle_Right_1]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1065
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Right_1_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1101
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Power_Limit#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #power_limit_shapes#
 Hidden                           = #Power_Limit_State#

; - GPU Top angles

[shape.Bottom_Angle_Right_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1273
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Right_2_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1309
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Angle_Right_2_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1337
 Y                                = (#Pad_Top# + 252 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Angle_Right_2_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1365
 Y                                = (#Pad_Top# + 280 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Angle_Right_2_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1393
 Y                                = (#Pad_Top# + 308 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

; - Disk Top Read angles

[shape.Bottom_Angle_Right_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1481
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Right_3_2]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1517
 Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Disk_Read_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_read_top_shapes#
 Hidden                           = #Disk_Read_Top_State#

[shape.Bottom_Angle_Right_3_3]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1545
 Y                                = (#Pad_Top# + 252 - #Pad_Bottom_Disk_Read_Top#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_read_top_shapes#
 Hidden                           = #Disk_Read_Top_State#

; - IDLE Time angles

[shape.Bottom_Angle_Right_4]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1690
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 43
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Angle_Right_5]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 1897
 Y                                = (#Pad_Top# + 188)
 LineStart                        = 0
 LineLength                       = 33
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- BOTTOM DIRECTS RIGHT

; - Power Limit lines

[shape.Bottom_Direct_Right_1]
 Meter                            = ROUNDLINE
 X                                = 1095
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Right_1_2]
 Meter                            = ROUNDLINE
 X                                = 1122
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_Power_Limit#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #power_limit_shapes#
 Hidden                           = #Power_Limit_State#

; - GPU Top lines

[shape.Bottom_Direct_Right_2]
 Meter                            = ROUNDLINE
 X                                = 1303
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Right_2_2]
 Meter                            = ROUNDLINE
 X                                = 1330
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Direct_Right_2_3]
 Meter                            = ROUNDLINE
 X                                = 1358
 Y                                = (#Pad_Top# + 272 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Direct_Right_2_4]
 Meter                            = ROUNDLINE
 X                                = 1386
 Y                                = (#Pad_Top# + 300 - #Pad_Bottom_GPU_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

[shape.Bottom_Direct_Right_2_5]
 Meter                            = ROUNDLINE
 X                                = 1414
 Y                                = (#Pad_Top# + 328 - #Pad_Bottom_GPU_Top#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 106
 LineHeight=2
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes#
 Hidden                           = #GPU_Top_State#

; - Disk Top Read lines

[shape.Bottom_Direct_Right_3]
 Meter                            = ROUNDLINE
 X                                = 1511
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Bottom_Direct_Right_3_2]
 Meter                            = ROUNDLINE
 X                                = 1538
 Y                                = (#Pad_Top# + 244 - #Pad_Bottom_Disk_Read_Top#)
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_read_top_shapes#
 Hidden                           = #Disk_Read_Top_State#

[shape.Bottom_Direct_Right_3_3]
 Meter                            = ROUNDLINE
 X                                = 1566
 Y                                = (#Pad_Top# + 272 - #Pad_Bottom_Disk_Read_Top#)
 H                                = 1
 LineStart                        = 0
 LineLength                       = 106
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #io_read_top_shapes#
 Hidden                           = #Disk_Read_Top_State#

; - IDLE Time lines

[shape.Bottom_Direct_Right_4]
 Meter                            = ROUNDLINE
 X                                = 1719
 Y                                = (#Pad_Top# + 217)
 LineStart                        = 0
 LineLength                       = 119
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- THIN LINES [HISTOGRAMS BG]

[shape.Left_Top]
 Meter                            = ROUNDLINE
 X                                = 495
 Y                                = (#Pad_Top# + 88)
 LineStart                        = 0
 LineLength                       = 295
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Left_Middle]
 Meter                            = ROUNDLINE
 X                                = 513
 Y                                = (#Pad_Top# + 110)
 LineStart                        = 0
 LineLength                       = 300
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Left_Bottom]
 Meter                            = ROUNDLINE
 X                                = 495
 Y                                = (#Pad_Top# + 136)
 LineStart                        = 0
 LineLength                       = 295
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Right_Top]
 Meter                            = ROUNDLINE
 X                                = 1130
 Y                                = (#Pad_Top# + 88)
 LineStart                        = 0
 LineLength                       = 295
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Right_Middle]
 Meter                            = ROUNDLINE
 X                                = 1110
 Y                                = (#Pad_Top# + 110)
 LineStart                        = 0
 LineLength                       = 300
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#

[shape.Right_Bottom]
 Meter                            = ROUNDLINE
 X                                = 1130
 Y                                = (#Pad_Top# + 136)
 LineStart                        = 0
 LineLength                       = 295
 MeterStyle                       = s.ThinLineStyle
 DynamicVariables                 = 1
 Group                            = #shapes#
 
; --- PLAYER'S SHAPES

;[shape.Play_Button]
; Meter                            = SHAPE
; MeterStyle                       = s.TriangleEmpty
; X                                = 957
; Y                                = 150
; MyPath                           = 0, 0 | LineTo 9, 6 | LineTo 0, 12 | LineTo 0, 0
; Group                            = #Player_Controls#
; LeftMouseUpAction = [!Refresh]
; Hidden=0
 
[shape.Play_Button]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100
 MyPath                           = 0, 0 | LineTo 9, 6 | LineTo 0, 12 | LineTo 0, 0
 X                                = 957
 Y                                = 150

[shape.Next_Button]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100
 MyPath                           = 0, 0 | LineTo 7, 4 | LineTo 7, 0 | LineTo 14, 4 | LineTo 7, 8 | LineTo 7, 4 | LineTo 0, 8 | LineTo 0, 0
 X                                = 980 
 Y                                = 152
  
[shape.Previuos_Button]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100
 MyPath                           = 0, 0 | LineTo -7, -4 | LineTo -7, 0 | LineTo -14, -4 | LineTo -7, -8 | LineTo -7, -4 | LineTo 0, -8 | LineTo 0, 0
 X                                = 940 
 Y                                = 160

[shape.Pause_Left_Button]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100
 MyPath                           = 0, 0 | LineTo 0, 12 | LineTo 3, 12 | LineTo 3, 0 | LineTo 0, 0 | 
 X                                = 955
 Y                                = 150

[shape.Pause_Right_Button]
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Global_Color# | Fill Color 0, 0, 0, 100
 MyPath                           = 0, 0 | LineTo 0, 12 | LineTo 3, 12 | LineTo 3, 0 | LineTo 0, 0
 X                                = 961
 Y                                = 150

; --- WINGS BG SHAPES ---

; --- WINGS BOTTOM LEFT

; - VRAM TOP

[shape.bg.WING_BOTTOM_LEFT_3_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 230
 Y                                = (#Pad_Top# + 194)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #vram_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable VRAM_Top_State "(1 - #VRAM_Top_State#)"][!WriteKeyValue Variables VRAM_Top_State " (1 - #VRAM_Top_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.VRAM_TOP][!UpdateMeasure sound.VRAM_TOP][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #vram_top#][!UpdateMeterGroup #vram_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.VRAM_TOP][!CommandMeasure terminator.VRAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable VRAM_Top_App "[sensor.VRAM_TOP_1]"][!SetVariable VRAM_Top_App_V "[formula.VRAM_TOP_SCALED_1]"][!DisableMeasure sensor.VRAM_TOP_1][!SetOption text.dynamic.VRAM_TOP_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_1_VALUE Text " #VRAM_Top_App_V_1#"][!UpdateMeasure sensor.VRAM_TOP_1][!UpdateMeasure formula.VRAM_TOP_SCALED_1][!UpdateMeter text.dynamic.VRAM_TOP_1][!UpdateMeter text.dynamic.VRAM_TOP_1_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.VRAM_TOP_1][!SetOption text.dynamic.VRAM_TOP_1 FontColor "#Font_Color#"][!SetOption text.dynamic.VRAM_TOP_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.VRAM_TOP_1_VALUE Text " %1B"][!UpdateMeasure sensor.VRAM_TOP_1][!UpdateMeasure formula.VRAM_TOP_SCALED_1][!UpdateMeter text.dynamic.VRAM_TOP_1][!UpdateMeter text.dynamic.VRAM_TOP_1_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_3_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 203
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_VRAM_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.VRAM_TOP][!CommandMeasure terminator.VRAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable VRAM_Top_App "[sensor.VRAM_TOP_2]"][!SetVariable VRAM_Top_App_V "[formula.VRAM_TOP_SCALED_2]"][!DisableMeasure sensor.VRAM_TOP_2][!SetOption text.dynamic.VRAM_TOP_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_2_VALUE Text " #VRAM_Top_App_V_2#"][!UpdateMeasure sensor.VRAM_TOP_2][!UpdateMeasure formula.VRAM_TOP_SCALED_2][!UpdateMeter text.dynamic.VRAM_TOP_2][!UpdateMeter text.dynamic.VRAM_TOP_2_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.VRAM_TOP_2][!SetOption text.dynamic.VRAM_TOP_2 FontColor "#Font_Color#"][!SetOption text.dynamic.VRAM_TOP_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.VRAM_TOP_2_VALUE Text " %1B"][!UpdateMeasure sensor.VRAM_TOP_2][!UpdateMeasure formula.VRAM_TOP_SCALED_2][!UpdateMeter text.dynamic.VRAM_TOP_2][!UpdateMeter text.dynamic.VRAM_TOP_2_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_3_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 175
 Y                                = (#Pad_Top# + 250 - #Pad_Bottom_VRAM_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.VRAM_TOP][!CommandMeasure terminator.VRAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable VRAM_Top_App "[sensor.VRAM_TOP_3]"][!SetVariable VRAM_Top_App_V "[formula.VRAM_TOP_SCALED_3]"][!DisableMeasure sensor.VRAM_TOP_3][!SetOption text.dynamic.VRAM_TOP_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.VRAM_TOP_3_VALUE Text " #VRAM_Top_App_V_3#"][!UpdateMeasure sensor.VRAM_TOP_3][!UpdateMeasure formula.VRAM_TOP_SCALED_3][!UpdateMeter text.dynamic.VRAM_TOP_3][!UpdateMeter text.dynamic.VRAM_TOP_3_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.VRAM_TOP_3][!SetOption text.dynamic.VRAM_TOP_3 FontColor "#Font_Color#"][!SetOption text.dynamic.VRAM_TOP_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.VRAM_TOP_3_VALUE Text " %1B"][!UpdateMeasure sensor.VRAM_TOP_3][!UpdateMeasure formula.VRAM_TOP_SCALED_3][!UpdateMeter text.dynamic.VRAM_TOP_3][!UpdateMeter text.dynamic.VRAM_TOP_3_VALUE][!UpdateMeasure terminator.VRAM_TOP][!Redraw]

; - CPU TOP

[shape.bg.WING_BOTTOM_LEFT_2_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 436
 Y                                = (#Pad_Top# + 194)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #cpu_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable CPU_Top_State "(1 - #CPU_Top_State#)"][!WriteKeyValue Variables CPU_Top_State " (1 - #CPU_Top_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.CPU_TOP][!UpdateMeasure sound.CPU_TOP][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #cpu_top#][!UpdateMeterGroup #cpu_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.CPU_TOP][!CommandMeasure terminator.CPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable CPU_Top_App "[sensor.CPU_TOP_1]"][!SetVariable CPU_Top_App_V_1 "[sensor.CPU_TOP_1:1]"][!DisableMeasure sensor.CPU_TOP_1][!SetOption text.dynamic.CPU_TOP_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_1_VALUE Text " #CPU_Top_App_V_1#%"][!UpdateMeasure sensor.CPU_TOP_1][!UpdateMeter text.dynamic.CPU_TOP_1][!UpdateMeter text.dynamic.CPU_TOP_1_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.CPU_TOP_1][!SetOption text.dynamic.CPU_TOP_1 FontColor "#Font_Color#"][!SetOption text.dynamic.CPU_TOP_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.CPU_TOP_1_VALUE Text " [*sensor.CPU_TOP_1:1*]%"][!SetVariable CPU_Top_App_V_1 "[*sensor.CPU_TOP_1:1*]"][!UpdateMeasure sensor.CPU_TOP_1][!UpdateMeter text.dynamic.CPU_TOP_1][!UpdateMeter text.dynamic.CPU_TOP_1_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_2_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 411
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_CPU_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.CPU_TOP][!CommandMeasure terminator.CPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable CPU_Top_App "[sensor.CPU_TOP_2]"][!SetVariable CPU_Top_App_V_2 "[sensor.CPU_TOP_2:1]"][!DisableMeasure sensor.CPU_TOP_2][!SetOption text.dynamic.CPU_TOP_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_2_VALUE Text " #CPU_Top_App_V_2#%"][!UpdateMeasure sensor.CPU_TOP_2][!UpdateMeter text.dynamic.CPU_TOP_2][!UpdateMeter text.dynamic.CPU_TOP_2_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.CPU_TOP_2][!SetOption text.dynamic.CPU_TOP_2 FontColor "#Font_Color#"][!SetOption text.dynamic.CPU_TOP_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.CPU_TOP_2_VALUE Text " [*sensor.CPU_TOP_2:1*]%"][!SetVariable CPU_Top_App_V_2 "[*sensor.CPU_TOP_2:1*]"][!UpdateMeasure sensor.CPU_TOP_2][!UpdateMeter text.dynamic.CPU_TOP_2][!UpdateMeter text.dynamic.CPU_TOP_2_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_2_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 383
 Y                                = (#Pad_Top# + 250 - #Pad_Bottom_CPU_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.CPU_TOP][!CommandMeasure terminator.CPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable CPU_Top_App "[sensor.CPU_TOP_3]"][!SetVariable CPU_Top_App_V_3 "[sensor.CPU_TOP_3:1]"][!DisableMeasure sensor.CPU_TOP_3][!SetOption text.dynamic.CPU_TOP_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_3_VALUE Text " #CPU_Top_App_V_3#%"][!UpdateMeasure sensor.CPU_TOP_3][!UpdateMeter text.dynamic.CPU_TOP_3][!UpdateMeter text.dynamic.CPU_TOP_3_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.CPU_TOP_3][!SetOption text.dynamic.CPU_TOP_3 FontColor "#Font_Color#"][!SetOption text.dynamic.CPU_TOP_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.CPU_TOP_3_VALUE Text " [*sensor.CPU_TOP_3:1*]%"][!SetVariable CPU_Top_App_V_3 "[*sensor.CPU_TOP_3:1*]"][!UpdateMeasure sensor.CPU_TOP_3][!UpdateMeter text.dynamic.CPU_TOP_3][!UpdateMeter text.dynamic.CPU_TOP_3_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_2_4]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 355
 Y                                = (#Pad_Top# + 278 - #Pad_Bottom_CPU_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Top_State# 
 Group                            = #cpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.CPU_TOP][!CommandMeasure terminator.CPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable CPU_Top_App "[sensor.CPU_TOP_4]"][!SetVariable CPU_Top_App_V_4 "[sensor.CPU_TOP_4:1]"][!DisableMeasure sensor.CPU_TOP_4][!SetOption text.dynamic.CPU_TOP_4 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_4_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_4_VALUE Text " #CPU_Top_App_V_4#%"][!UpdateMeasure sensor.CPU_TOP_4][!UpdateMeter text.dynamic.CPU_TOP_4][!UpdateMeter text.dynamic.CPU_TOP_4_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.CPU_TOP_4][!SetOption text.dynamic.CPU_TOP_4 FontColor "#Font_Color#"][!SetOption text.dynamic.CPU_TOP_4_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.CPU_TOP_4_VALUE Text " [*sensor.CPU_TOP_4:1*]%"][!SetVariable CPU_Top_App_V_4 "[*sensor.CPU_TOP_4:1*]"][!UpdateMeasure sensor.CPU_TOP_4][!UpdateMeter text.dynamic.CPU_TOP_4][!UpdateMeter text.dynamic.CPU_TOP_4_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_LEFT_2_5]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 327
 Y                                = (#Pad_Top# + 306 - #Pad_Bottom_CPU_Top#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.CPU_TOP][!CommandMeasure terminator.CPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable CPU_Top_App "[sensor.CPU_TOP_5]"][!SetVariable CPU_Top_App_V_5 "[sensor.CPU_TOP_5:1]"][!DisableMeasure sensor.CPU_TOP_5][!SetOption text.dynamic.CPU_TOP_5 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_5_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.CPU_TOP_5_VALUE Text " #CPU_Top_App_V_5#%"][!UpdateMeasure sensor.CPU_TOP_5][!UpdateMeter text.dynamic.CPU_TOP_5][!UpdateMeter text.dynamic.CPU_TOP_5_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.CPU_TOP_5][!SetOption text.dynamic.CPU_TOP_5 FontColor "#Font_Color#"][!SetOption text.dynamic.CPU_TOP_5_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.CPU_TOP_5_VALUE Text " [*sensor.CPU_TOP_5:1*]%"][!SetVariable CPU_Top_App_V_5 "[*sensor.CPU_TOP_5:1*]"][!UpdateMeasure sensor.CPU_TOP_5][!UpdateMeter text.dynamic.CPU_TOP_5][!UpdateMeter text.dynamic.CPU_TOP_5_VALUE][!UpdateMeasure terminator.CPU_TOP][!Redraw]

; - THROTTLING

[shape.bg.WING_BOTTOM_LEFT_1_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 646
 Y                                = (#Pad_Top# + 194)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #throttling_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Throttling_State "(1 - #Throttling_State#)"][!WriteKeyValue Variables Throttling_State " (1 - #Throttling_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.THROTTLING][!UpdateMeasure sound.THROTTLING][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeasureGroup #limiters#][!UpdateMeterGroup #throttling#][!UpdateMeterGroup #throttling_shapes#][!Redraw]
 RightMouseUpAction               = 

[shape.bg.WING_BOTTOM_LEFT_1_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 619
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_Throttling#)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #throttling_shapes# | #bg_wings_shapes# | #shapes#
 Hidden                           = #Throttling_State#

; --- WINGS BOTTOM RIGHT

; - POWER LIMIT

[shape.bg.WING_BOTTOM_RIGHT_1_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1097
 Y                                = (#Pad_Top# + 194)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #power_limit_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Power_Limit_State "(1 - #Power_Limit_State#)"][!WriteKeyValue Variables Power_Limit_State " (1 - #Power_Limit_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.POWER_LIMIT][!UpdateMeasure sound.POWER_LIMIT][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #power_limit#][!UpdateMeterGroup #power_limit_shapes#][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_1_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1124
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_Power_Limit#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #power_limit_shapes# | #bg_wings_shapes# | #shapes#
 Hidden                           = #Power_Limit_State#

; - GPU TOP

[shape.bg.WING_BOTTOM_RIGHT_2_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1305
 Y                                = (#Pad_Top# + 194)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable GPU_Top_State "(1 - #GPU_Top_State#)"][!WriteKeyValue Variables GPU_Top_State " (1 - #GPU_Top_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.GPU_TOP][!UpdateMeasure sound.GPU_TOP][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #gpu_top#][!UpdateMeterGroup #gpu_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.GPU_TOP][!CommandMeasure terminator.GPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable GPU_Top_App "[sensor.GPU_TOP_1]"][!SetVariable GPU_Top_App_V_1 "[sensor.GPU_TOP_1:1]"][!DisableMeasure sensor.GPU_TOP_1][!SetOption text.dynamic.GPU_TOP_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_1_VALUE Text " #GPU_Top_App_V_1#%"][!UpdateMeasure sensor.GPU_TOP_1][!UpdateMeter text.dynamic.GPU_TOP_1_VALUE][!UpdateMeter text.dynamic.GPU_TOP_1][!UpdateMeasure terminator.GPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.GPU_TOP_1][!SetOption text.dynamic.GPU_TOP_1 FontColor "#Font_Color#"][!SetOption text.dynamic.GPU_TOP_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.GPU_TOP_1_VALUE Text " [*sensor.GPU_TOP_1:1*]%"][!SetVariable GPU_Top_App_V_1 "[*sensor.GPU_TOP_1:1*]"][!UpdateMeasure sensor.GPU_TOP_1][!UpdateMeter text.dynamic.GPU_TOP_1_VALUE][!UpdateMeter text.dynamic.GPU_TOP_1][!UpdateMeasure terminator.GPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_2_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1332
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_GPU_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #gpu_top_shapes# | #bg_wings_shapes# | #shapes#
 Hidden                           = #GPU_Top_State#
 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.GPU_TOP][!CommandMeasure terminator.GPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable GPU_Top_App "[sensor.GPU_TOP_1]"][!SetVariable GPU_Top_App_V_2 "[sensor.GPU_TOP_2:1]"][!DisableMeasure sensor.GPU_TOP_2][!SetOption text.dynamic.GPU_TOP_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_2_VALUE Text " #GPU_Top_App_V_2#%"][!UpdateMeasure sensor.GPU_TOP_2][!UpdateMeter text.dynamic.GPU_TOP_2_VALUE][!UpdateMeter text.dynamic.GPU_TOP_2][!UpdateMeasure terminator.GPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.GPU_TOP_2][!SetOption text.dynamic.GPU_TOP_2 FontColor "#Font_Color#"][!SetOption text.dynamic.GPU_TOP_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.GPU_TOP_2_VALUE Text " [*sensor.GPU_TOP_2:1*]%"][!SetVariable GPU_Top_App_V_2 "[*sensor.GPU_TOP_2:1*]"][!UpdateMeasure sensor.GPU_TOP_2][!UpdateMeter text.dynamic.GPU_TOP_2_VALUE][!UpdateMeter text.dynamic.GPU_TOP_2][!UpdateMeasure terminator.GPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_2_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1360
 Y                                = (#Pad_Top# + 250 - #Pad_Bottom_GPU_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.GPU_TOP][!CommandMeasure terminator.GPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable GPU_Top_App "[sensor.GPU_TOP_1]"][!SetVariable GPU_Top_App_V_3 "[sensor.GPU_TOP_3:1]"][!DisableMeasure sensor.GPU_TOP_3][!SetOption text.dynamic.GPU_TOP_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_3_VALUE Text " #GPU_Top_App_V_3#%"][!UpdateMeasure sensor.GPU_TOP_3][!UpdateMeter text.dynamic.GPU_TOP_3_VALUE][!UpdateMeter text.dynamic.GPU_TOP_3][!UpdateMeasure terminator.GPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.GPU_TOP_3][!SetOption text.dynamic.GPU_TOP_3 FontColor "#Font_Color#"][!SetOption text.dynamic.GPU_TOP_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.GPU_TOP_3_VALUE Text " [*sensor.GPU_TOP_3:1*]%"][!SetVariable GPU_Top_App_V_3 "[*sensor.GPU_TOP_3:1*]"][!UpdateMeasure sensor.GPU_TOP_3][!UpdateMeter text.dynamic.GPU_TOP_3_VALUE][!UpdateMeter text.dynamic.GPU_TOP_3][!UpdateMeasure terminator.GPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_2_4]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1388
 Y                                = (#Pad_Top# + 278 - #Pad_Bottom_GPU_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.GPU_TOP][!CommandMeasure terminator.GPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable GPU_Top_App "[sensor.GPU_TOP_1]"][!SetVariable GPU_Top_App_V_4 "[sensor.GPU_TOP_4:1]"][!DisableMeasure sensor.GPU_TOP_4][!SetOption text.dynamic.GPU_TOP_4 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_4_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_4_VALUE Text " #GPU_Top_App_V_4#%"][!UpdateMeasure sensor.GPU_TOP_4][!UpdateMeter text.dynamic.GPU_TOP_4_VALUE][!UpdateMeter text.dynamic.GPU_TOP_4][!UpdateMeasure terminator.GPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.GPU_TOP_4][!SetOption text.dynamic.GPU_TOP_4 FontColor "#Font_Color#"][!SetOption text.dynamic.GPU_TOP_4_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.GPU_TOP_4_VALUE Text " [*sensor.GPU_TOP_4:1*]%"][!SetVariable GPU_Top_App_V_4 "[*sensor.GPU_TOP_4:1*]"][!UpdateMeasure sensor.GPU_TOP_4][!UpdateMeter text.dynamic.GPU_TOP_4_VALUE][!UpdateMeter text.dynamic.GPU_TOP_4][!UpdateMeasure terminator.GPU_TOP][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_2_5]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1416
 Y                                = (#Pad_Top# + 306 - #Pad_Bottom_GPU_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.GPU_TOP][!CommandMeasure terminator.GPU_TOP "Run"]
 MouseOverAction                  = [!SetVariable GPU_Top_App "[sensor.GPU_TOP_1]"][!SetVariable GPU_Top_App_V_5 "[sensor.GPU_TOP_5:1]"][!DisableMeasure sensor.GPU_TOP_5][!SetOption text.dynamic.GPU_TOP_5 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_5_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.GPU_TOP_5_VALUE Text " #GPU_Top_App_V_5#%"][!UpdateMeasure sensor.GPU_TOP_5][!UpdateMeter text.dynamic.GPU_TOP_5_VALUE][!UpdateMeter text.dynamic.GPU_TOP_5][!UpdateMeasure terminator.GPU_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.GPU_TOP_5][!SetOption text.dynamic.GPU_TOP_5 FontColor "#Font_Color#"][!SetOption text.dynamic.GPU_TOP_5_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.GPU_TOP_5_VALUE Text " [*sensor.GPU_TOP_5:1*]%"][!SetVariable GPU_Top_App_V_5 "[*sensor.GPU_TOP_5:1*]"][!UpdateMeasure sensor.GPU_TOP_5][!UpdateMeter text.dynamic.GPU_TOP_5_VALUE][!UpdateMeter text.dynamic.GPU_TOP_5][!UpdateMeasure terminator.GPU_TOP][!Redraw]

; - TOP IO READ

[shape.bg.WING_BOTTOM_RIGHT_3_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1513
 Y                                = (#Pad_Top# + 194)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #io_read_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Disk_Read_Top_State "(1 - #Disk_Read_Top_State#)"][!WriteKeyValue Variables Disk_Read_Top_State " (1 - #Disk_Read_Top_State#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.IO_READ_TOP][!UpdateMeasure sound.IO_READ_TOP][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #io_read_top#][!UpdateMeterGroup #io_read_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_READ][!CommandMeasure terminator.TOP_IO_READ "Run"]
 MouseOverAction                  = [!SetVariable IO_Read_Top_App "[sensor.TOP_IO_READ_1]"][!SetVariable IO_Read_Top_App_V_1 "[formula.TOP_IO_READ_SCALED_1]"][!DisableMeasure sensor.TOP_IO_READ_1][!SetOption text.dynamic.TOP_IO_READ_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_1_VALUE Text " #IO_Read_Top_App_V_1#"][!UpdateMeasure sensor.TOP_IO_READ_1][!UpdateMeasure formula.TOP_IO_READ_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_READ_1_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_1][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_READ_1][!SetOption text.dynamic.TOP_IO_READ_1 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_READ_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_READ_1_VALUE Text " %1B"][!SetVariable IO_Read_Top_App_V_1 "[*formula.TOP_IO_READ_SCALED_1*]"][!UpdateMeasure sensor.TOP_IO_READ_1][!UpdateMeasure formula.TOP_IO_READ_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_READ_1_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_1][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_3_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1540
 Y                                = (#Pad_Top# + 222 - #Pad_Bottom_DIsk_Read_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #io_read_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_READ][!CommandMeasure terminator.TOP_IO_READ "Run"]
 MouseOverAction                  = [!SetVariable IO_Read_Top_App "[sensor.TOP_IO_READ_2]"][!SetVariable IO_Read_Top_App_V_2 "[formula.TOP_IO_READ_SCALED_2]"][!DisableMeasure sensor.TOP_IO_READ_2][!SetOption text.dynamic.TOP_IO_READ_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_2_VALUE Text " #IO_Read_Top_App_V_2#"][!UpdateMeasure sensor.TOP_IO_READ_2][!UpdateMeasure formula.TOP_IO_READ_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_READ_2_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_2][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_READ_2][!SetOption text.dynamic.TOP_IO_READ_2 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_READ_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_READ_2_VALUE Text " %1B"][!SetVariable IO_Read_Top_App_V_2 "[*formula.TOP_IO_READ_SCALED_2*]"][!UpdateMeasure sensor.TOP_IO_READ_2][!UpdateMeasure formula.TOP_IO_READ_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_READ_2_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_2][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]

[shape.bg.WING_BOTTOM_RIGHT_3_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1568
 Y                                = (#Pad_Top# + 250 - #Pad_Bottom_DIsk_Read_Top#)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #io_read_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_READ][!CommandMeasure terminator.TOP_IO_READ "Run"]
 MouseOverAction                  = [!SetVariable IO_Read_Top_App "[sensor.TOP_IO_READ_3]"][!SetVariable IO_Read_Top_App_V_3 "[formula.TOP_IO_READ_SCALED_3]"][!DisableMeasure sensor.TOP_IO_READ_3][!SetOption text.dynamic.TOP_IO_READ_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_READ_3_VALUE Text " #IO_Read_Top_App_V_3#"][!UpdateMeasure sensor.TOP_IO_READ_3][!UpdateMeasure formula.TOP_IO_READ_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_READ_3_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_3][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_READ_3][!SetOption text.dynamic.TOP_IO_READ_3 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_READ_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_READ_3_VALUE Text " %1B"][!SetVariable IO_Read_Top_App_V_3 "[*formula.TOP_IO_READ_SCALED_3*]"][!UpdateMeasure sensor.TOP_IO_READ_3][!UpdateMeasure formula.TOP_IO_READ_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_READ_3_VALUE][!UpdateMeter text.dynamic.TOP_IO_READ_3][!UpdateMeasure terminator.TOP_IO_READ][!Redraw]

; --- WINGS TOP RIGHT

[shape.bg.WING_TOP_RIGHT_3_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1513
 Y                                = (#Pad_Top# + 7)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #io_write_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Disk_Write_Top_State "(1 - #Disk_Write_Top_State#)"][!WriteKeyValue Variables Disk_Write_Top_State " (1 - #Disk_Write_Top_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_Six "(4 - #Height_State_Six#)"][!WriteKeyValue Variables Height_State_Six " (4 - #Height_State_Six#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.IO_WRITE_TOP][!UpdateMeasure sound.IO_WRITE_TOP][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #io_write_top#][!UpdateMeterGroup #io_write_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_WRITE][!CommandMeasure terminator.TOP_IO_WRITE "Run"]
 MouseOverAction                  = [!SetVariable IO_Write_Top_App "[sensor.TOP_IO_WRITE_1]"][!SetVariable IO_Write_Top_App_V_1 "[formula.TOP_IO_WRITE_SCALED_1]"][!DisableMeasure sensor.TOP_IO_WRITE_1][!SetOption text.dynamic.TOP_IO_WRITE_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_1_VALUE Text " #IO_Write_Top_App_V_1#"][!UpdateMeasure sensor.TOP_IO_WRITE_1][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_WRITE_1_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_1][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_WRITE_1][!SetOption text.dynamic.TOP_IO_WRITE_1 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_1_VALUE Text " %1B"]#CGPU_Graph_Update_Leave#[!SetVariable IO_Write_Top_App_V_1 "[*formula.TOP_IO_WRITE_SCALED_1*]"][!UpdateMeasure sensor.TOP_IO_WRITE_1][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_WRITE_1_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_1][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]

[shape.bg.WING_TOP_RIGHT_3_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1540
 Y                                = (#Pad_Top# - 22)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #io_write_top_shapes# | #bg_wings_shapes# | #shapes#
 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_WRITE][!CommandMeasure terminator.TOP_IO_WRITE "Run"]
 MouseOverAction                  = [!SetVariable IO_Write_Top_App "[sensor.TOP_IO_WRITE_2]"][!SetVariable IO_Write_Top_App_V_2 "[formula.TOP_IO_WRITE_SCALED_2]"][!DisableMeasure sensor.TOP_IO_WRITE_2][!SetOption text.dynamic.TOP_IO_WRITE_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_2_VALUE Text " #IO_Write_Top_App_V_2#"][!UpdateMeasure sensor.TOP_IO_WRITE_2][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_WRITE_2_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_2][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_WRITE_2][!SetOption text.dynamic.TOP_IO_WRITE_2 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_2_VALUE Text " %1B"][!SetVariable IO_Write_Top_App_V_2 "[*formula.TOP_IO_WRITE_SCALED_2*]"][!UpdateMeasure sensor.TOP_IO_WRITE_2][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_WRITE_2_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_2][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]

[shape.bg.WING_TOP_RIGHT_3_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1568
 Y                                = (#Pad_Top# - 51)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #io_write_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.TOP_IO_WRITE][!CommandMeasure terminator.TOP_IO_WRITE "Run"]
 MouseOverAction                  = [!SetVariable IO_Write_Top_App "[sensor.TOP_IO_WRITE_3]"][!SetVariable IO_Write_Top_App_V_3 "[formula.TOP_IO_WRITE_SCALED_3]"][!DisableMeasure sensor.TOP_IO_WRITE_3][!SetOption text.dynamic.TOP_IO_WRITE_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_3_VALUE Text " #IO_Write_Top_App_V_3#"][!UpdateMeasure sensor.TOP_IO_WRITE_3][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_WRITE_3_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_3][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.TOP_IO_WRITE_3][!SetOption text.dynamic.TOP_IO_WRITE_3 FontColor "#Font_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.TOP_IO_WRITE_3_VALUE Text " %1B"][!SetVariable IO_Write_Top_App_V_3 "[*formula.TOP_IO_WRITE_SCALED_3*]"][!UpdateMeasure sensor.TOP_IO_WRITE_3][!UpdateMeasure formula.TOP_IO_WRITE_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_WRITE_3_VALUE][!UpdateMeter text.dynamic.TOP_IO_WRITE_3][!UpdateMeasure terminator.TOP_IO_WRITE][!Redraw]

[shape.bg.WING_TOP_RIGHT_2_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1302
 Y                                = (#Pad_Top# + 7)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #gpu_info_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable GPU_Info_State "(1 - #GPU_Info_State#)"][!WriteKeyValue Variables GPU_Info_State " (1 - #GPU_Info_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_Four "(7 - #Height_State_Four#)"][!WriteKeyValue Variables Height_State_Four " (7 - #Height_State_Four#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.GPU_INFO][!UpdateMeasure sound.GPU_INFO][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #gpu_info#][!UpdateMeterGroup #gpu_info_shapes#][!Redraw]
 RightMouseUpAction               = 
 MouseOverAction                  = 
 MouseLeaveAction                 = 

[shape.bg.WING_TOP_RIGHT_2_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1332
 Y                                = (#Pad_Top# - 22)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_RIGHT_2_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1360
 Y                                = (#Pad_Top# - 50)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_RIGHT_2_4]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1388
 Y                                = (#Pad_Top# - 78)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_RIGHT_2_5]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1416
 Y                                = (#Pad_Top# - 106)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #GPU_Info_State#
 Group                            = #gpu_info_shapes# | #bg_wings_shapes# | #shapes#

; --- CLOCK INFO

[shape.bg.WING_TOP_RIGHT_1_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 1095
 Y                                = (#Pad_Top# + 7)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Group                            = #clock_info_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Clock_Info_State "(1 - #Clock_Info_State#)"][!WriteKeyValue Variables Clock_Info_State " (1 - #Clock_Info_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_Two "(3 - #Height_State_Two#)"][!WriteKeyValue Variables Height_State_Two " (3 - #Height_State_Two#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.CLOCK_INFO][!UpdateMeasure sound.CLOCK_INFO][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #clock_info#][!UpdateMeterGroup #clock_info_shapes#][!Redraw]

[shape.bg.WING_TOP_RIGHT_1_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 1124
 Y                                = (#Pad_Top# - 22)
 MyPath                           = 0, 0 | LineTo 198, 0 | LineTo 178, 20 | LineTo -20, 20
 DynamicVariables                 = 1
 Hidden                           = #Clock_Info_State#
 Group                            = #clock_info_shapes# | #bg_wings_shapes# | #shapes#

; --- WINGS TOP LEFT

; - THREADS

[shape.bg.WING_TOP_LEFT_1_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 648
 Y                                = (#Pad_Top# + 7)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #threads_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable Threads_State "(1 - #Threads_State#)"][!WriteKeyValue Variables Threads_State " (1 - #Threads_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_One "(2 - #Height_State_One#)"][!WriteKeyValue Variables Height_State_One " (2 - #Height_State_One#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.THREADS][!UpdateMeasure sound.THREADS][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #threads#][!UpdateMeterGroup #threads_shapes#][!Redraw]

[shape.bg.WING_TOP_LEFT_1_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 619
 Y                                = (#Pad_Top# -22)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #Threads_State#
 Group                            = #threads_shapes# | #bg_wings_shapes# | #shapes#

; - CPU INFO

[shape.bg.WING_TOP_LEFT_2_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 440
 Y                                = (#Pad_Top# + 7)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #cpu_info_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable CPU_Info_State "(1 - #CPU_Info_State#)"][!WriteKeyValue Variables CPU_Info_State " (1 - #CPU_Info_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_Three "(6 - #Height_State_Three#)"][!WriteKeyValue Variables Height_State_Three " (6 - #Height_State_Three#)" "#@#\config\UserSettings.inc"][!EnableMeasure sound.CPU_INFO][!UpdateMeasure sound.CPU_INFO][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #cpu_info#][!UpdateMeterGroup #cpu_info_shapes#][!Redraw]

[shape.bg.WING_TOP_LEFT_2_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 411
 Y                                = (#Pad_Top# -22)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_LEFT_2_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 383
 Y                                = (#Pad_Top# -50)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_LEFT_2_4]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 355
 Y                                = (#Pad_Top# -78)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu_info_shapes# | #bg_wings_shapes# | #shapes#

[shape.bg.WING_TOP_LEFT_2_5]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 327
 Y                                = (#Pad_Top# -106)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #CPU_Info_State#
 Group                            = #cpu_info_shapes# | #bg_wings_shapes# | #shapes#

; - RAM TOP

[shape.bg.WING_TOP_LEFT_3_1]
 Meter                            = SHAPE
 MeterStyle                       = style.BG_Empty
 X                                = 232
 Y                                = (#Pad_Top# + 7)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Group                            = #ram_top_shapes# | #bg_wings_shapes# | #shapes#

 LeftMouseUpAction                = [!SetVariable RAM_Top_State "(1 - #RAM_Top_State#)"][!WriteKeyValue Variables RAM_Top_State " (1 - #RAM_Top_State#)" "#@#\config\UserSettings.inc"][!SetVariable Height_State_Five "(5 - #Height_State_Five#)"][!WriteKeyValue Variables Height_State_Five " (5 - #Height_State_Five#)" "#@#\config\UserSettings.inc"][!EnableMeasure f.sound.RAM_Top][!UpdateMeasure f.sound.RAM_Top][!UpdateMeasureGroup #sizer_top#][!UpdateMeterGroup #ram_top#][!UpdateMeterGroup #ram_top_shapes#][!Redraw]
 RightMouseUpAction               = 
 MiddleMouseUpAction              = [!UpdateMeasure terminator.RAM_TOP][!CommandMeasure terminator.RAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable RAM_Top_App "[sensor.RAM_TOP_1]"][!SetVariable RAM_Top_App_V "[formula.RAM_TOP_SCALED_1]"][!DisableMeasure sensor.RAM_TOP_1][!SetOption text.dynamic.RAM_TOP_1 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_1_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_1_VALUE Text " #RAM_Top_App_V_1#"][!UpdateMeasure sensor.RAM_TOP_1][!UpdateMeasure formula.RAM_TOP_SCALED_1][!UpdateMeter text.dynamic.RAM_TOP_1][!UpdateMeter text.dynamic.RAM_TOP_1_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.RAM_TOP_1][!SetOption text.dynamic.RAM_TOP_1 FontColor "#Font_Color#"][!SetOption text.dynamic.RAM_TOP_1_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.RAM_TOP_1_VALUE Text " %1B"][!UpdateMeasure sensor.RAM_TOP_1][!UpdateMeasure formula.RAM_TOP_SCALED_1][!UpdateMeter text.dynamic.RAM_TOP_1][!UpdateMeter text.dynamic.RAM_TOP_1_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]

[shape.bg.WING_TOP_LEFT_3_2]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 203
 Y                                = (#Pad_Top# -22)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.RAM_TOP][!CommandMeasure terminator.RAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable RAM_Top_App "[sensor.RAM_TOP_2]"][!SetVariable RAM_Top_App_V "[formula.RAM_TOP_SCALED_2]"][!DisableMeasure sensor.RAM_TOP_2][!SetOption text.dynamic.RAM_TOP_2 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_2_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_2_VALUE Text " #RAM_Top_App_V_2#"][!UpdateMeasure sensor.RAM_TOP_2][!UpdateMeasure formula.RAM_TOP_SCALED_2][!UpdateMeter text.dynamic.RAM_TOP_2][!UpdateMeter text.dynamic.RAM_TOP_2_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.RAM_TOP_2][!SetOption text.dynamic.RAM_TOP_2 FontColor "#Font_Color#"][!SetOption text.dynamic.RAM_TOP_2_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.RAM_TOP_2_VALUE Text " %1B"][!UpdateMeasure sensor.RAM_TOP_2][!UpdateMeasure formula.RAM_TOP_SCALED_2][!UpdateMeter text.dynamic.RAM_TOP_2][!UpdateMeter text.dynamic.RAM_TOP_2_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]

[shape.bg.WING_TOP_LEFT_3_3]
 Meter                            = SHAPE
 MeterStyle                       = style.BG
 X                                = 175
 Y                                = (#Pad_Top# -50)
 MyPath                           = -20, 0 | LineTo 178, 0 | LineTo 198, 20 | LineTo 0, 20
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram_top_shapes# | #bg_wings_shapes# | #shapes#

 MiddleMouseUpAction              = [!UpdateMeasure terminator.RAM_TOP][!CommandMeasure terminator.RAM_TOP "Run"]
 MouseOverAction                  = [!SetVariable RAM_Top_App "[sensor.RAM_TOP_3]"][!SetVariable RAM_Top_App_V "[formula.RAM_TOP_SCALED_3]"][!DisableMeasure sensor.RAM_TOP_3][!SetOption text.dynamic.RAM_TOP_3 FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_3_VALUE FontColor "#Font_Warning_Color#"][!SetOption text.dynamic.RAM_TOP_3_VALUE Text " #RAM_Top_App_V_3#"][!UpdateMeasure sensor.RAM_TOP_3][!UpdateMeasure formula.RAM_TOP_SCALED_3][!UpdateMeter text.dynamic.RAM_TOP_3][!UpdateMeter text.dynamic.RAM_TOP_3_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]
 MouseLeaveAction                 = [!EnableMeasure sensor.RAM_TOP_3][!SetOption text.dynamic.RAM_TOP_3 FontColor "#Font_Color#"][!SetOption text.dynamic.RAM_TOP_3_VALUE FontColor "#Font_Value_Color#"][!SetOption text.dynamic.RAM_TOP_3_VALUE Text " %1B"][!UpdateMeasure sensor.RAM_TOP_3][!UpdateMeasure formula.RAM_TOP_SCALED_3][!UpdateMeter text.dynamic.RAM_TOP_3][!UpdateMeter text.dynamic.RAM_TOP_3_VALUE][!UpdateMeasure terminator.RAM_TOP][!Redraw]

; --- LOG VIEWER BOTTOM SHAPES ---

[shape.Bottom_Angle_Left_Log]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(-135))
 RotationAngle                    = (RAD(180))
 X                                = 799
 Y                                = (#Pad_Top# + 246 - #Pad_Bottom_Logs#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#

;[shape.Top_Angle_Right_Log]
; Meter                            = ROUNDLINE
; StartAngle                       = (RAD(-135))
; RotationAngle                    = (RAD(180))
; X                                = 1101
; Y                                = (#Pad_Top# + 224 - #Pad_Bottom_Logs#)
; LineStart                        = 0
; LineLength                       = 30
; MeterStyle                       = s.LineStyle
; DynamicVariables                 = 1
; Group                            = #logs_bottom_shapes#
; Hidden                           = #Logs_Bottom_State#

[shape.Bottom_Angle_Right_Log]
 Meter                            = ROUNDLINE
 StartAngle                       = (RAD(135))
 X                                = 1122
 Y                                = (#Pad_Top# + 246 - #Pad_Bottom_Logs#)
 LineStart                        = 0
 LineLength                       = 30
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#

[shape.Direct_Left_Log]
 Meter                            = ROUNDLINE
 X                                = 632
 Y                                = (#Pad_Top# + 246 - #Pad_Bottom_Logs#)
 LineStart                        = 0
 LineLength                       = 167
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#

[shape.Direct_Right_Log]
 Meter                            = ROUNDLINE
 X                                = 1122
 Y                                = (#Pad_Top# + 246 - #Pad_Bottom_Logs#)
 LineStart                        = 0
 LineLength                       = 166
 MeterStyle                       = s.LineStyle
 DynamicVariables                 = 1
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#

[shape.Logs_Container_1_Visible]
 Meter                            = SHAPE
 X                                = 798
 Y                                = (#Pad_Top# + 227 - #Pad_Bottom_Logs# + 19)
 Shape                            = Path MyPath | Strokewidth 0 | Stroke Color #Global_Color# | Fill Color 0,0,0,1
 MyPath                           = 0, 0 | LineTo 22, -22 | Lineto 303, -22 | LineTo 325, 0 | LineTo 303, 22 | LineTo 22, 22 | ClosePath 1
 DynamicVariables                 = 1
 ; ; MouseActionCursorName            = #Cursor_Slider_XY#
 LeftMouseDownAction              = [!SetOption shape.Logs_Container_1_Visible MouseActionCursorName "#*Cursor_Slider_X*#"][!CommandMeasure m.Log_Bottom_Viewer_Slider "Start"][!EnableMeasure m.Log_Bottom_Viewer_Slider_Set]
 LeftMouseUpAction                = [!SetOption shape.Logs_Container_1_Visible MouseActionCursorName "#*Cursor_Slider_XY*#"][!Delay 100][!SetVariable Log_X_Scroll "0"]
 RightMouseUpAction               = [!SetOption shape.Logs_Container_1_Visible MouseActionCursorName "#*Cursor_Slider_XY*#"][!Delay 100][!SetVariable Log_Y_Scroll_1 "0"][!SetVariable Log_Y_Scroll "10"]
 RightMouseDownAction             = [!CommandMeasure m.Log_Bottom_Viewer_Slider "Start"][!EnableMeasure m.Log_Bottom_Viewer_Slider_Set_Y][!SetOption shape.Logs_Container_1_Visible MouseActionCursorName "#*Cursor_Slider_Y*#"]
 MouseScrollDownAction            = [!SetVariable Log_Y_Scroll "(Clamp(#Log_Y_Scroll#-20,-580,11))"][!UpdateMeter *][!Redraw]
 MouseScrollUpAction              = [!SetVariable Log_Y_Scroll "(Clamp(#Log_Y_Scroll#+20,-580,11))"][!UpdateMeter *][!Redraw]
 MiddleMouseUpAction              = ["#@#\logs\#Log_File#.log"]
 MouseOverAction                  = 
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#

[shape.Logs_Container]
 Meter                            = SHAPE
 X                                = 809
 Y                                = (#Pad_Top# + 227 - #Pad_Bottom_Logs#)
 W                                = 303
 Shape                            = Rectangle 0,0,303,38, 20 | StrokeWidth 0 
 DynamicVariables                 = 1
 Group                            = #logs_bottom_shapes#
 Hidden                           = #Logs_Bottom_State#