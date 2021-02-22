[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.4b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Lua log viewer. Written by Jeffrey Morley, thanks for this!

[Variables]
 Log_File                          = #Log_App_Terminate#
 Log_Y_Scroll                      = 10
 Log_Y_Scroll_1                    = 1
 Log_X_Scroll                      = 0
 Log_Viewer_Handle                 = 
 Log_Viewer_Handle_Y               = 


; --- Log viewer measure

; - "FileToRead" must contain path to a wished to view log 

[m.Log_Bottom]
 Measure                          = Script
 ScriptFile                       = #@#\scripts\LuaLogViewer.lua
 FileToRead                       = #Log_File#
 DynamicVariables                 = 1

; --- Slider

; - Slider in log viewer is still an experimental fucntion, and it works a bit not correctly

; - Mouse wheel's scroll is recommended

[m.Log_Bottom_Viewer_Slider]
 Measure                          = PLUGIN
 Plugin                           = Mouse
 LeftMouseDragAction              = [!SetVariable Log_Viewer_Handle "(clamp($MouseX$,[t.Log_Bottom_Viewer:X],[t.Log_Bottom_Viewer:XW]))"][!UpdateMeasure m.Log_Bottom_Viewer_Slider_Set][!UpdateMeter t.Log_Bottom_Viewer][!UpdateMeter shape.Logs_Container][!Redraw]
 LeftMouseUpAction                = [!SetVariable Log_Viewer_Handle "(clamp($MouseX$,[t.Log_Bottom_Viewer:X],[t.Log_Bottom_Viewer:XW]))"][!CommandMeasure m.Log_Bottom_Viewer_Slider "Stop"][!Delay 1][!UpdateMeasure m.Log_Bottom_Viewer_Slider_Set][!UpdateMeter t.Log_Bottom_Viewer][!UpdateMeter shape.Logs_Container][!Redraw]
 RightMouseDragAction             = [!SetVariable Log_Viewer_Handle_Y "$MouseY$"][!UpdateMeasure m.Log_Bottom_Viewer_Slider_Set_Y][!UpdateMeter t.Log_Bottom_Viewer][!UpdateMeter shape.Logs_Container][!Redraw]
 RightMouseUpAction               = [!SetVariable Log_Viewer_Handle_Y "$MouseY$"][!CommandMeasure m.Log_Bottom_Viewer_Slider "Stop"][!Delay 1][!UpdateMeasure m.Log_Bottom_Viewer_Slider_Set_Y][!UpdateMeter t.Log_Bottom_Viewer][!UpdateMeter shape.Logs_Container][!Redraw]
 RelativeToSkin                   = 1
 RequireDragging                  = 1
 DynamicVariables                 = 1
 Group                            = #logs_bottom#
     ifCondition                  = #Log_X_Scroll# = 5
          ifTrueAction            = [!SetVariable Log_X_Scroll "0"]
     ifCondition2                 = #Log_Y_Scroll_1# > 0
          ifTrueAction2           = [!SetVariable Log_Y_Scroll_1 "0"]

[m.Log_Bottom_Viewer_Slider_Set]
 Measure                          = CALC
 Formula                          = #Log_Viewer_Handle#
 MinValue                         = [shape.Logs_Container:X]
 MaxValue                         = ([shape.Logs_Container:X] + [shape.Logs_Container:W])
 DynamicVariables                 = 1
 InvertMeasure                    = 1
 OnUpdateAction                   = [!SetVariable Log_X_Scroll "[m.Log_Bottom_Viewer_Slider_Set:%,0]"]
 Group                            = #logs_bottom#
 Disabled                         = 1

[m.Log_Bottom_Viewer_Slider_Set_Y]
 Measure                          = CALC
 Formula                          = #Log_Viewer_Handle_Y#
 MinValue                         = 0
 MaxValue                         = 222
 DynamicVariables                 = 1
 InvertMeasure                    = 1
 OnUpdateAction                   = [!SetVariable Log_Y_Scroll_1 "[m.Log_Bottom_Viewer_Slider_Set_Y:0]"]
 Group                            = #logs_bottom#
 Disabled                         = 1

[t.Log_Bottom_Viewer]
 Meter                            = STRING
 MeasureName                      = m.Log_Bottom
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = (150 - #Log_X_Scroll# * 2.5)
 Y                                = (#Log_Y_Scroll# + #Log_Y_Scroll_1# - #Pad_Bottom_Logs#)
 W                                = 303
 AntiAlias                        = 1
 ClipString                       = 0
 DynamicVariables                 = 1
 Padding                          = 0,-10,0,0
 Container                        = shape.Logs_Container
 Group                            = #logs_bottom#
 MiddleMouseUpAction              = #Log_File#