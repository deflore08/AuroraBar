[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Hotkeys module. You might define your own custom hotkeys here. It's pretty easily, just check the code parts below, copy it and set a needed action manually. :) Attention: some definitions might cause freezes and input lags. For example: CTRL+S

; --- QUICK REFRESH

;[m.HK.Quick_Refresh]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL S
; KeyUpAction                      = [!Refresh]
;;;UpdateDivider                    = #Divider_Negative_Measure#

;[hotkey.CONSOLE]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL D
; KeyUpAction                      = [!CommandMeasure "sensor.COMMAND_INPUT" "ExecuteBatch 1-2"]

; --- MUTE SYSTEM VOLUME

;[m.HK.System_Mute]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL 0
; KeyUpAction                      = [!CommandMeasure m.System_Volume "ToggleMute"][!UpdateMeasure m.System_Volume][!UpdateMeasure m.Volume_Values_Controller][!UpdateMeter b.System_Volume][!UpdateMeter t.System_Volume][!Redraw]
;;;UpdateDivider                    = #Divider_Negative_Measure#

; --- APP VOLUME CONTROL

[m.HK.App_Volume_1]
 Measure                          = PLUGIN
 Plugin                           = HotKey
 HotKey                           = CTRL F1
 KeyUpAction                      = [!CommandMeasure m.App_1_Volume_Static "ToggleMute"][!Update]
;;;UpdateDivider                    = #Divider_Negative_Measure#

[m.HK.App_Volume_2]
 Measure                          = PLUGIN
 Plugin                           = HotKey
 HotKey                           = CTRL F2
 KeyUpAction                      = [!CommandMeasure m.App_2_Volume_Static "ToggleMute"][!Update]
;;;UpdateDivider                    = #Divider_Negative_Measure#

[m.HK.App_Volume_3]
 Measure                          = PLUGIN
 Plugin                           = HotKey
 HotKey                           = CTRL F3
 KeyUpAction                      = [!CommandMeasure m.App_3_Volume_Static "ToggleMute"][!Update]
;;;UpdateDivider                    = #Divider_Negative_Measure#

[m.HK.App_Volume_4]
 Measure                          = PLUGIN
 Plugin                           = HotKey
 HotKey                           = CTRL F4
 KeyUpAction                      = [!CommandMeasure m.App_4_Volume_Static "ToggleMute"][!Update]
;;;UpdateDivider                    = #Divider_Negative_Measure#

; --- CALCULATOR

; - Conсieved as quick calculator use by hotkeys

; - Developement freezed for a while

;[m.HK.Calculator_Open]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT C
; KeyDownAction                    = [!SetVariable Triangle_Left_Mechanic "1"][!EnableMeasure sound.TRIANGLE_LEFT]

;[m.HK.Calculator_1]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 1
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_1]][!SetVariable Display_Between "#Display_Between#[m.Number_1]"][!Update][!Redraw]

;[m.HK.Calculator_2]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 2
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_2]][!SetVariable Display_Between "#Display_Between#[m.Number_2]"][!Update][!Redraw]

;[m.HK.Calculator_3]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 3
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_3]][!SetVariable Display_Between "#Display_Between#[m.Number_3]"][!Update][!Redraw]

;[m.HK.Calculator_4]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 4
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_4]][!SetVariable Display_Between "#Display_Between#[m.Number_4]"][!Update][!Redraw]

;[m.HK.Calculator_5]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 5
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_5]][!SetVariable Display_Between "#Display_Between#[m.Number_5]"][!Update][!Redraw]

;[m.HK.Calculator_6]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 6
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_6]][!SetVariable Display_Between "#Display_Between#[m.Number_6]"][!Update][!Redraw]

;[m.HK.Calculator_7]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 7
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_7]][!SetVariable Display_Between "#Display_Between#[m.Number_7]"][!Update][!Redraw]

;[m.HK.Calculator_8]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 8
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_8]][!SetVariable Display_Between "#Display_Between#[m.Number_8]"][!Update][!Redraw]

;[m.HK.Calculator_9]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 9
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_9]][!SetVariable Display_Between "#Display_Between#[m.Number_9]"][!Update][!Redraw]

;[m.HK.Calculator_0]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL ALT 0
; KeyUpAction                      = [!UpdateMeasure m.Operator_AC][!Update][!SetVariable Display_Result [m.Number_0]][!SetVariable Display_Between "#Display_Between#[m.Number_0]"][!Update][!Redraw]

;[m.HK.Calculator_%]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL SHIFT 5
; KeyUpAction                      = [!SetVariable Display_Result [m.Operator_%]][!SetVariable Display_Between "#Display_Between#[m.Operator_%]"][!Update][!Redraw]

;[m.HK.Calculator_/]
; Measure                          = PLUGIN
; Plugin                           = HotKey
; HotKey                           = CTRL SHIFT \
; KeyUpAction                      = [!SetVariable Calc_Formula "#Calc_Formula##Display_Result#/"][!SetOption m.Operator_AC String "yes"][!SetVariable Display_Between "#Display_Between#/"][!Update][!Redraw]