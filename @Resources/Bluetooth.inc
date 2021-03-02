[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = Bluetooth switcher. Thanks to SweetMNM for this. It works through external .bat and VB script

[Variables]
 Bluetooth_Condition              = OFF

; - The measure [m.Bluetooth_Check] executes external script and checks bluetooth state

;[m.Bluetooth_Check]
; Measure                          = PLUGIN
; Plugin                           = RunCommand
; Program                          = "#@#\scripts\bluetooth\bluetoothCheck.bat"
; State                            = Hide
; OutputType                       = UTF8
; Group                            = #bluetooth# | #bluetooth_sensors# | #sensors# 
; FinishAction                     = [!DisableMeasure m.Bluetooth_Check][!UpdateMeasure m.Bluetooth_Check][!UpdateMeter t.Bluetooth_Switcher][!Redraw]
; Disabled                         = 1
;     IfMatch                      = BT_ON
;          IfMatchAction           = [!SetVariable Bluetooth_Condition "OFF"][!WriteKeyValue Variables Bluetooth_Condition " OFF" "#@#\Bluetooth.inc"][!SetVariable Bluetooth_State "0"][!WriteKeyValue Variables Bluetooth_State " 0" "#@#\config\UserSettings.inc"]
;          IfNotMatchAction        = [!SetVariable Bluetooth_Condition "ON"][!WriteKeyValue Variables Bluetooth_Condition " ON" "#@#\Bluetooth.inc"][!SetVariable Bluetooth_State "1"][!WriteKeyValue Variables Bluetooth_State " 1" "#@#\config\UserSettings.inc"]

; - The measure [m.Bluetooth_Inspector] it is a looper. It is counts from 0 to 10, and when it reaches 10 [m.Bluetooth_Check] is executes

; - So you will always see the actual bluetooth's state

;[m.Bluetooth_Inspector]
; Measure                          = Loop
; StartValue                       = 1
; EndValue                         = 10
; Increment                        = 1
; LoopCount                        = 0
; Group                            = #bluetooth# | #bluetooth_sensors# | #sensors# 
;;UpdateDivider                    = 20
;     ifCondition                  = m.Bluetooth_Inspector = 10
;          ifTrueAction            = [!CommandMeasure m.Bluetooth_Check "run"]

[m.Toggle_Bluetooth]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = "#@#\scripts\bluetooth\bluetoothToggle.bat"
 State                            = Hide
 OutputType                       = UTF8
 StartInFolder                    = "#@#\scripts\bluetooth\"
 Group                            = #bluetooth# | #bluetooth_sensors# | #sensors# 

; - Switcher doesn't work flawlessly, but at least it works. :)))

[t.Bluetooth_Switcher]
 Meter                            = STRING
 FontColor                        = #Global_Color#
 MeterStyle                       = style.text.Simple_Font_Center_Align
 SolidColor                       = 0, 0, 0, 1
 X                                = 1800
 Y                                = (#Pad_Top# + 102)
 H                                = 10
 W                                = 80
 FonSize                          = 10
 Text                             = "BT:[sensor.BLUETOOTH_CHECKER]"
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.Toggle_Bluetooth "run"][!EnableMeasure sound.BLUETOOTH][!UpdateMeasure sound.BLUETOOTH]
 RightMouseUpAction               = ["#@#\scripts\bluetooth\bluetoothDevices.url"]
 Group                            = #app_volume_controls_static# | #bluetooth# | #bluetooth_values# | #values#
 Hidden                           = ( #App_Volume_Control_Static_State# + #Bluetooth_Visible# )


[sensor.BLUETOOTH_CHECKER]
 Measure                          = REGISTRY
 RegHKey                          = HKEY_LOCAL_MACHINE
 RegKey                           = SYSTEM\CurrentControlSet\Services\bthserv\Parameters\BluetoothControlPanelTasks
 RegValue                         = State
 Substitute                       = "1":"ON","0":"OFF"
 DynamicVariables                 = 1
 Group                            = #bluetooth#
     onChangeAction               = [!UpdateMeter t.Bluetooth_Switcher]

[sensor.BLUETOOTH_STATE]
 Measure                          = CALC
 Formula                          = sensor.BLUETOOTH_CHECKER
 DynamicVariables                 = 1
     ifCondition                  = #CURRENTSECTION# = 0
          ifTrueAction            = [!SetVariable Bluetooth_State "1"][!WriteKeyValue Variables Bluetooth_State " 1" "#@#\#Config#"][!UpdateMeter t.Bluetooth_Switcher]
          ifFalseAction           = [!SetVariable Bluetooth_State "0"][!WriteKeyValue Variables Bluetooth_State " 0" "#@#\#Config#"][!UpdateMeter t.Bluetooth_Switcher]
