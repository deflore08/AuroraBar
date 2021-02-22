[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Power Plan config and controller. Attention! Aurora will control a power plans even if you have 3rd-party apps for this. Original code parts by Pul53dr1v3r from Rainformer.

[Variables]
 Power_Plan_Current               = 0
 Power_Plan_Eco                   = a1841308-3541-4fab-bc81-f71556f20b4a
 Power_Plan_Balance               = 381b4222-f694-41f0-9685-ff5bb260df2e
 Power_Plan_Max                   = 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c

; --- MEASURES

[sensor.POWER_PLAN_ACTIVE_POWER]
 Measure                          = REGISTRY
 RegHKey                          = HKEY_LOCAL_MACHINE
 RegKey                           = SYSTEM\ControlSet001\Control\Power\User\PowerSchemes
 RegValue                         = ActivePowerScheme
; Substitute                       = "#Power_Plan_Max#":"1","#Power_Plan_Balance#":"2","#Power_Plan_Eco#":"3"
 DynamicVariables                 = 1
 Group                            = #power_plan# | #power_plan_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter shape.POWER_PLAN_INDICATOR_BOTTOM][!UpdateMeter shape.POWER_PLAN_INDICATOR_TOP]
     
     ifMatch                      = #Power_Plan_Max#
         ifMatchAction            = [!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color 0,0,0,0 | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color 0,0,0,0 | Fill Color 0, 0, 0, 0"]
     ifMatch2                     = #Power_Plan_Balance#
          ifMatchAction2          = [!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Value_Color# | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Value_Color# | Fill Color 0, 0, 0, 0"]
     ifMatch3                     = #Power_Plan_Eco#
          ifMatchAction3          = [!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Warning_Color# | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Warning_Color# | Fill Color 0, 0, 0, 0"]

[formula.POWER_PLAN_SWITCHER]
 Measure                          = CALC
 Formula                          = #Power_Plan_Current#
 DynamicVariables                 = 1
 Group                            = #power_plan# | #power_plan_sensors# | #sensors#
     
     ifCondition                  = #Power_Plan_Current# = 1
          ifTrueAction            = [!SetOption sensor.POWER_PLAN_EXECUTE Parameter "POWERCFG /SETACTIVE #Power_Plan_Eco#"][!UpdateMeasure "sensor.POWER_PLAN_EXECUTE"][!CommandMeasure "sensor.POWER_PLAN_EXECUTE" "Run"][!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Warning_Color# | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Warning_Color# | Fill Color 0, 0, 0, 0"]
     ifCondition2                 = #Power_Plan_Current# = 2
          ifTrueAction2           = [!SetOption sensor.POWER_PLAN_EXECUTE Parameter "POWERCFG /SETACTIVE #Power_Plan_Balance#"][!UpdateMeasure "sensor.POWER_PLAN_EXECUTE"][!CommandMeasure "sensor.POWER_PLAN_EXECUTE" "Run"][!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Value_Color# | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color #Font_Value_Color# | Fill Color 0, 0, 0, 0"]
     ifCondition3                 = #Power_Plan_Current# = 3
          ifTrueAction3           = [!SetOption sensor.POWER_PLAN_EXECUTE Parameter "POWERCFG /SETACTIVE #Power_Plan_Max#"][!UpdateMeasure "sensor.POWER_PLAN_EXECUTE"][!CommandMeasure "sensor.POWER_PLAN_EXECUTE" "Run"][!SetOption shape.POWER_PLAN_INDICATOR_TOP Shape "Path MyPath | Strokewidth 1 | Stroke Color 0,0,0,0 | Fill Color 0, 0, 0, 0"][!SetOption shape.POWER_PLAN_INDICATOR_BOTTOM Shape "Path MyPath | Strokewidth 1 | Stroke Color 0,0,0,0 | Fill Color 0, 0, 0, 0"]
     ifCondition4                 = #Power_Plan_Current# < 0
          ifTrueAction4           = [!SetVariable Power_Plan_Current "3"]
     ifCondition5                 = #Power_Plan_Current# > 3
          ifTrueAction5           = [!SetVariable Power_Plan_Current "1"]
     ifConditionMode              = 1

[sensor.POWER_PLAN_EXECUTE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 State                            = Hide

; --- INDICATORS ON TOP AND BOTTOM TRIANGLES

[shape.POWER_PLAN_INDICATOR_TOP]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Font_Color# | Fill Color 0, 0, 0, 0
 MyPath                           = 0, 0 | LineTo 10, 9 | LineTo 20, 0
 X                                = 950
 Y                                = (#Pad_Top# + 21)
 DynamicVariables                 = 1
 Group                            = #power_plan# | #power_plan_shapes# | #shapes#

[shape.POWER_PLAN_INDICATOR_BOTTOM]
 Meter                            = SHAPE
 Shape                            = Path MyPath | Strokewidth 1 | Stroke Color #Font_Color# | Fill Color 0, 0, 0, 0
 MyPath                           = 0, 0 | LineTo 10, -9 | LineTo 20, 0
 X                                = 950
 Y                                = (#Pad_Top# + 198)
 DynamicVariables                 = 1
 Group                            = #power_plan# | #power_plan_shapes# | #shapes#