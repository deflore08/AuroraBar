[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = Clock, weather, volume, mid section

[Variables]

; --- SLIDERS VARS

 Player_1_Progress_Handle         = 0
 
; --- MEASURES BEGINNING
 
[sensor.PLAYER_1_PROGRESS_SLIDER]
 Measure                          = PLUGIN
 Plugin                           = Mouse
 LeftMouseDragAction              = [!SetVariable Player_1_Progress_Handle "(clamp(($MouseX$),[bar.PROGRESS:X],[bar.PROGRESS:XW]))"][!UpdateMeasure sensor.PLAYER_1_PROGRESS_SLIDER_SET][!UpdateMeasure sensor.PLAYER][!UpdateMeter bar.PROGRESS][!Redraw][!UpdateMeasure sensor.PLAYER_PROGRESS]
 LeftMouseUpAction                = [!SetVariable Player_1_Progress_Handle "(clamp(($MouseX$),[bar.PROGRESS:X],[bar.PROGRESS:XW]))"][!CommandMeasure sensor.PLAYER_1_PROGRESS_SLIDER "Stop"][!Delay 1][!UpdateMeasure sensor.PLAYER_1_PROGRESS_SLIDER_SET][!UpdateMeasure sensor.PLAYER][!UpdateMeter bar.PROGRESS][!Redraw]
 RelativeToSkin                   = 1
 RequireDragging                  = 1
 DynamicVariables                 = 1

[sensor.PLAYER_1_PROGRESS_SLIDER_SET]
 Measure                          = CALC
 Formula                          = #Player_1_Progress_Handle#
 MinValue                         = [bar.PROGRESS:X]
 MaxValue                         = ([bar.PROGRESS:X] + [bar.PROGRESS:W])
 DynamicVariables                 = 1
 InvertMeasure                    = 0
 OnUpdateAction                   = [!CommandMeasure sensor.PLAYER "SetPosition [sensor.PLAYER_1_PROGRESS_SLIDER_SET:%,0]"]
 Disabled                         = 1
 
[sensor.PLAYER]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = #Player_Name#
 PlayerType                       = Volume
 DynamicVariables                 = 1
 UpdateDivider                    = 1
     onChangeAction               = [!UpdateMeasure m.Volume_Values_Controller][!UpdateMeter b.Player_Volume][!UpdateMeter t.Player_Volume]

[sensor.PLAYER_REPEAT]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = Repeat
     ifCondition                  = sensor.PLAYER_REPEAT = 0
          ifTrueAction            = [!SetOption button.REPEAT FontColor "#*Bar_BG_Color*#"][!SetVariable Player_1_Repeat_State "0"][!WriteKeyValue Variables Player_1_Repeat_State " 0" "#@#\config\UserSettings.inc"]
          ifFalseAction           = [!SetOption button.REPEAT FontColor "#*Global_Color*#"][!SetVariable Player_1_Repeat_State "1"][!WriteKeyValue Variables Player_1_Repeat_State " 1" "#@#\config\UserSettings.inc"]
     ifConditionMode              = 1
     
[sensor.PLAYER_SHUFFLE]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = Shuffle
     ifCondition                  = sensor.PLAYER_SHUFFLE = 0
          ifTrueAction            = [!SetOption button.SHUFFLE FontColor "#*Bar_BG_Color*#"][!SetVariable Player_1_Shuffle_State "0"][!WriteKeyValue Variables Player_1_Repeat_State " 0" "#@#\config\UserSettings.inc"]
          ifFalseAction           = [!SetOption button.SHUFFLE FontColor "#*Global_Color*#"][!SetVariable Player_1_Shuffle_State "1"][!WriteKeyValue Variables Player_1_Repeat_State " 1" "#@#\config\UserSettings.inc"]
     ifConditionMode              = 1

[sensor.PLAYER_ARTIST]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = Artist

[sensor.PLAYER_TITLE]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = Title

[sensor.PLAYER_PROGRESS]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = Progress
     onChangeAction               = [!UpdateMeter bar.PROGRESS]

[sensor.PLAYER_STATE_BUTTON_PLAY_1]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "NIL", "1": "shape.Pause_Left_Button", "2": "shape.Play_Button"
     onChangeAction               = [!UpdateMeasureGroup #player_controls#][!UpdateMeterGroup #player_controls#][!Redraw]
     ifCondition                  = #CURRENTSECTION# = 0
          ifTrueAction            = [!SetVariable Player_State "1"]
          ifFalseAction           = [!SetVariable Player_State "0"]

[sensor.PLAYER_STATE_BUTTON_PLAY_2]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "NIL", "1": "shape.Pause_Right_Button", "2":"NILL"
 Group                            = #player_controls#
     onChangeAction               = [!UpdateMeter button.PLAY_2]
 
[sensor.PLAYER_STATE_BUTTON_PREVIOUS]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "NIL", "1": "shape.Previuos_Button", "2": "shape.Previuos_Button"
 Group                            = #player_controls#
 
[sensor.PLAYER_STATE_BUTTON_NEXT]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "NIL", "1": "shape.Next_Button", "2": "shape.Next_Button"
 Group                            = #player_controls#
 
[sensor.PLAYER_STATE_BUTTON_PROGRESS]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "1", "1": "0", "2": "0"
 Group                            = #player_controls#
 
[sensor.PLAYER_STATE_REPEAT]
 Measure                          = PLUGIN
 Plugin                           = NowPlaying.dll
 PlayerName                       = [sensor.PLAYER]
 PlayerType                       = State
 Substitute                       = "0": "NIL", "1":"shape.Pause_Right_Button", "2": "NIL"
 Group                            = #player_controls#

; --- TIME

; - [sensor.TIME] returns the time in a 24-hour format (i.e. HH:MM)

; - For 12-hour format, change the Format option above to: %I:%M %p

; - Refer to the Rainmeter manual for other format codes.

[sensor.TIME]
 Measure                          = TIME
 Format                           = %H:%M:%S

[sensor.TIME_HOURS]
 Measure                          = TIME
 Format                           = %H
     onChangeAction               = [!UpdateMeasure sensor.MONTH][!UpdateMeasure sensor.DAY][!UpdateMeasure sensor.CURRENT_DAY][!UpdateMeter text.dynamic.TIME_HOURS]
 
[sensor.TIME_MINS]
 Measure                          = TIME
 Format                           = %M
     onChangeAction               = [!UpdateMeasure sensor.TIME_HOURS][!UpdateMeter text.dynamic.TIME_MINS]
 
[sensor.TIME_SECS]
 Measure                          = TIME
 Format                           = %S
     onChangeAction               = [!UpdateMeasure sensor.TIME_MINS][!UpdateMeasure sensor.TIME_HOURS][!UpdateMeter text.dynamic.TIME_SECS][!UpdateMeasure formula.COUNTER_STOPWATCH_TIME][!UpdateMeasureGroup #uptime_sensors#]

; --- DATE

; - Returns the date as DD.MM.YYYY

; - Is not used

;[m.Date]
; Measure                          = Time
; Format                           = %d.%m

; - Is not used

;[m.Year]
; Measure                          = Time
; Format                           = %Y

[sensor.MONTH]
 Measure                          = TIME
 Format                           = %m
     onChangeAction               = [!UpdateMeter text.dynamic.MONTH]

[sensor.DAY]
 Measure                          = TIME
 Format                           = %d
     onChangeAction               = [!UpdateMeter text.dynamic.DAY]

[sensor.CURRENT_DAY]
 Measure                          = TIME
 Format                           = %A
     onChangeAction               = [!UpdateMeter text.dynamic.CURRENT_DAY]

; - MEASURES END

 ; --- TEXTS BEGINNING

[updater.NOTIFICATION]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 955
 Y                                = (#Pad_Top# + 45)
 Text                             = "Version #New_Version# Available"
 FontColor                        = #Font_Warning_Color#
 StringCase                       = Upper
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date# | #updater#
 Hidden                           = 1
 LeftMouseUpAction                = [!Log "Update requested.."][!SetVariable Update_Initialized "1"][!WriteKeyValue Variables Update_Initialized "1" "#Service_Folder#\Service.inc"][!SetVariable Update_Completed "0"][!WriteKeyValue Variables Update_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER]

[text.dynamic.TIME_HOURS]
 MeasureName                      = sensor.TIME_HOURS
 Meter                            = STRING
 X                                = 890
 Y                                = (#Pad_Top# + 90)
 FontColor                        = #Font_Color#
 FontSize                         = #Time_Font_Size_Hours#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 StringAlign                      = Left
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 MiddleMouseUpAction              = #Time_And_Date#
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = #Clock_And_Date_State#

[text.dynamic.TIME_MINS]
 MeasureName                      = sensor.TIME_MINS
 Meter                            = STRING
 X                                = 1028
 Y                                = (#Pad_Top# + 93)
 FontColor                        = #Font_Color#
 FontSize                         = #Time_Font_Size_Mins#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 StringAlign                      = Right
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = #Clock_And_Date_State#

[text.dynamic.TIME_SECS]
 MeasureName                      = sensor.TIME_SECS
 Meter                            = STRING
 X                                = 1028
 Y                                = (#Pad_Top# + 116)
 FontColor                        = #Font_Color#
 FontSize                         = #Time_Font_Size_Secs#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 StringAlign                      = Right
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = #Clock_And_Date_State#

[text.dynamic.DAY]
 MeasureName                      = sensor.DAY
 Meter                            = STRING
 X                                = 865
 Y                                = (#Pad_Top# + 195)
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Time_Font_Size_Day#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 StringAlign                      = Left
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = (1 - #Settings_Behaviour_Temp#)

[text.dynamic.MONTH]
 MeasureName                      = sensor.MONTH
 Meter                            = STRING
 X                                = 1055
 Y                                = (#Pad_Top# + 195)
 FontColor                        = #Font_Value_Color#
 FontSize                         = #Time_Font_Size_Year#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 StringAlign                      = Right
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = (1 - #Settings_Hardware_Temp#)

[text.dynamic.CURRENT_DAY]
 MeasureName                      = sensor.CURRENT_DAY
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 958
 Y                                = (#Pad_Top# + 73)
 W                                = 150
 H                                = 30
 FontColor                        = #Font_Color#
 FontSize                         = #Time_Font_Size_Cday#
 FontFace                         = #Time_Font_Main#
 StringStyle                      = #String_Style#
 Text                             = %1
 NumOfDecimals                    = 0
 AntiAlias                        = 1
 DynamicVariables                 = 1
 Group                            = #clock_and_date#
 Hidden                           = #Clock_And_Date_State#

[text.dynamic.ARTIST]
 Meter                            = STRING
 MeasureName                      = sensor.PLAYER_ARTIST
 MeasureName2                     = sensor.PLAYER_TITLE
 MeterStyle                       = style.text.Simple_Font_Center_Align
 X                                = 958
 Y                                = (#Pad_Top# + 35)
 W                                = 92
 ClipString                       = 1
 Text                             = %1 #CRLF# %2
 DynamicVariables                 = 1
 Hidden                           = (#Player_1_Artist_Title_State# + #Clock_And_Date_State#)

; - TEXTS END

; --- BARS BEGINNING

[bar.PROGRESS]
 Meter                            = BAR
 MeasureName                      = sensor.PLAYER_PROGRESS
 X                                = 930
 Y                                = (#Pad_Top# + 158)
 W                                = 60
 H                                = 3
 BarColor                         = #Global_Color#
 SolidColor                       = #Bar_BG_Color#
 BarOrientation                   = HORIZONTAL
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#
 MouseActionCursorName            = #Cursor_Slider_X#
 MouseScrollDownAction            = [!CommandMeasure sensor.PLAYER "SetPosition -#Player_Position_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeasure sensor.PLAYER_PROGRESS][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure sensor.PLAYER "SetPosition +#Player_Position_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeasure sensor.PLAYER_PROGRESS][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.PLAYER_1_PROGRESS_SLIDER "Start"][!EnableMeasure sensor.PLAYER_1_PROGRESS_SLIDER_SET]

[bar.PROGRESS_SHADOW]
 Meter                            = BAR
 MeasureName                      = sensor.PLAYER_PROGRESS
 X                                = 930
 Y                                = (#Pad_Top# + 158)
 W                                = 60
 H                                = 18
 BarColor                         = 0 ,0 ,0,0
 BarOrientation                   = HORIZONTAL
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#
 MouseActionCursorName            = #Cursor_Slider_X#
 MouseScrollDownAction            = [!CommandMeasure sensor.PLAYER "SetPosition -#Player_Position_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeasure sensor.PLAYER_PROGRESS][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollUpAction              = [!CommandMeasure sensor.PLAYER "SetPosition +#Player_Position_Step#"][!UpdateMeasure sensor.PLAYER][!UpdateMeasure sensor.PLAYER_PROGRESS][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 LeftMouseDownAction              = [!CommandMeasure sensor.PLAYER_1_PROGRESS_SLIDER "Start"][!EnableMeasure sensor.PLAYER_1_PROGRESS_SLIDER_SET]

; - BARS END

; --- BUTTONS BEGINNING

; - Player control buttons

[button.PREVIOUS]
 Meter                            = SHAPE
 MeterStyle                       = [sensor.PLAYER_STATE_BUTTON_PREVIOUS]
 Y                                = (#Pad_Top# + 148)
 DynamicVariables                 = 1
 Group                            = #player_controls#
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "Previous"]

; - Play1 and Play2 switches between play and pause icon

; - It controls by player measures

[button.PLAY_1]
 Meter                            = SHAPE
 MeterStyle                       = [sensor.PLAYER_STATE_BUTTON_PLAY_1]
 Y                                = (#Pad_Top# + 138)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "PlayPause"]
 
[button.PLAY_2]
 Meter                            = SHAPE
 MeterStyle                       = [sensor.PLAYER_STATE_BUTTON_PLAY_2]
 Y                                = (#Pad_Top# + 138)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "PlayPause"]

[button.NEXT]
 Meter                            = SHAPE
 MeterStyle                       = [sensor.PLAYER_STATE_BUTTON_NEXT]
 DynamicVariables                 = 1
 Y                                = (#Pad_Top# + 140)
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "Next"]

[button.REPEAT]
 Meter                            = STRING
 MeasureName                      = sensor.PLAYER_REPEAT
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontColor                        = #Global_Color#
 X                                = 1008
 Y                                = (#Pad_Top# + 137)
 Text                             = "R"
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "SetRepeat -1"]

[button.SHUFFLE]
 Meter                            = STRING
 MeasureName                      = sensor.PLAYER_SHUFFLE
 MeterStyle                       = style.text.Simple_Font_Center_Align
 FontColor                        = #Global_Color#
 X                                = 912
 Y                                = (#Pad_Top# + 137)
 Text                             = "S"
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 Group                            = #player_controls#

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "SetShuffle -1"]

[shape.PAUSE_SQUARE_INVISIBLE]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,0,0,1
 X                                = 950
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "PlayPause"][!UpdateMeasure sensor.PLAYER_STATE_BUTTON_PLAY_1]

[shape.NEXT_SQUARE_INVISIBLE]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,0,0,1
 X                                = 976
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "Next"]

[shape.PREVIOUS_SQUARE_INVISIBLE]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,0,0,1
 X                                = 925
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "Previous"]

[shape.SHUFFLE_SQUARE_INVISIBLE]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,0,0,1
 X                                = 903
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)

 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "SetShuffle -1"][!UpdateMeasure sensor.PLAYER_SHUFFLE][!EnableMeasure sound.PLAYER_1_SHUFFLE][!UpdateMeasure sound.PLAYER_1_SHUFFLE][!UpdateMeter button.SHUFFLE][!Redraw]

[shape.REPEAT_SQUARE_INVISIBLE]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,0,0,1
 X                                = 998
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
 Hidden                           = (#Player_State# + #Clock_And_Date_State#)
 
 LeftMouseUpAction                = [!CommandMeasure sensor.PLAYER "SetRepeat -1"][!UpdateMeasure sensor.PLAYER_REPEAT][!EnableMeasure sound.PLAYER_1_REPEAT][!UpdateMeasure sound.PLAYER_1_REPEAT][!UpdateMeter button.REPEAT][!Redraw]

; - BUTTONS END