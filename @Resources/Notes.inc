[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Quick note module
 
[Variables]

 Note                             = AURORABAR 2.0.0b 

[sensor.INPUT_NOTE]
 Measure                          = PLUGIN
 Plugin                           = InputText
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 45
 Y                                = (#Pad_Top# + 10)
 W                                = 150
 H                                = 15
 SolidColor                       = 0,0,0,255
 FontColor                        = 255,255,255,255
 DefaultValue                     = #Note#
 FocusDismiss                     = 1
 DynamicVariables                 = 1
 Group                            = #notes# | #notes_sensors# | #sensors#
 Command1                         = [!WriteKeyValue Variables Note " $UserInput$" "#@#Notes.inc"]
 Command2                         = [!SetVariable Note [sensor.INPUT_NOTE]][!UpdateMeter text.dynamic.NOTE][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"]
 OnDismissAction                  = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"]
 
[text.dynamic.NOTE]
 Meter                            = STRING
 X                                = 45
 Y                                = (#Pad_Top# + 10)
 W                                = 150
 H                                = 15
 ClipString                       = 1
 MeterStyle                       = style.text.Simple_Font_Left_Align
 StringCase                       = Upper
 Prefix                           = "NOTE: "
 Text                             = "#Note#"
 DynamicVariables                 = 1
 Group                            = #notes# | #notes_texts# | #texts#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure "sensor.INPUT_NOTE" "ExecuteBatch 1-2"]
 RightMouseUpAction               = [!SetClip #Note#]
