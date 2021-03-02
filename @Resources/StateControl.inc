[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = Control state variables. If you refresh skin, they will make sure that you are guaranteed find Aurora in the latest condition.

[Variables]

 Zpos_State                      = 
 Click_Throught_State            =
 Draggable_State                 =  

 Warning_Update_Divider          = 1

; --- These vars contains bangs for updating some measures and meters when you use menu

; Settings_Menu_Main_Updater      = [!UpdateMeasure f.Menu_Control][!UpdateMeasure f.Temp_Vars_State][!UpdateMeasure f.Aurora_Bg_Behaviour][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_main#][!Redraw]

 Settings_Menu_Main_Updater      = [!UpdateMeasureGroup #menu_measures#][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_main#][!UpdateMeterGroup #settings_color#][!UpdateMeterGroup #settings_hardware#][!UpdateMeterGroup #settings_behaviour#][!Redraw]

 Settings_Menu_Color_Updater     = [!UpdateMeasureGroup #menu_measures#][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_color#][!UpdateMeterGroup #settings_main#][!UpdateMeterGroup #settings_hardware#][!UpdateMeterGroup #settings_behaviour#][!Redraw]
 
 Settings_Menu_Behaviour_Updater = [!UpdateMeasureGroup #menu_measures#][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_behaviour#][!UpdateMeterGroup #settings_color#][!UpdateMeterGroup #settings_main#][!UpdateMeterGroup #settings_hardware#][!Redraw]
 
 Settings_Menu_Hardware_Updater  = [!UpdateMeasureGroup #menu_measures#][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_hardware#][!UpdateMeterGroup #settings_behaviour#][!UpdateMeterGroup #settings_color#][!UpdateMeterGroup #settings_main#][!Redraw]
 
 Settings_Menu_Close_Updater     = [!UpdateMeasure f.Menu_Control][!UpdateMeasureGroup #menu_measures#][!UpdateMeterGroup #config#][!UpdateMeter BG][!UpdateMeterGroup #clock_and_date#][!UpdateMeterGroup #player_controls#][!UpdateMeterGroup #settings_menu#][!UpdateMeterGroup #settings_main#][!UpdateMeterGroup #settings_color#][!UpdateMeterGroup #settings_behaviour#][!UpdateMeterGroup #settings_hardware#][!Redraw][!SetVariable Settings_Menu " 0"][!WriteKeyValue Variables Settings_Menu " 0" "#@#\#Config#"][!CommandMeasure animation.fader.CRYSTALS "Execute 2"][!UpdateMeter *][!Redraw]

; Test_DynamicVar_SetGroup        = [!SetOptionGroup #shapes# DynamicVariables "0"][!SetOptionGroup #cpu_info_shapes# DynamicVariables "0"][!SetOptionGroup #ram_top_shapes# DynamicVariables "0"][!SetOptionGroup #threads_shapes# DynamicVariables "0"][!SetOptionGroup #clock_info_shapes# DynamicVariables "0"][!SetOptionGroup #gpu_info_shapes# DynamicVariables "0"][!SetOptionGroup #io_read_top_shapes# DynamicVariables "0"][!SetOptionGroup #io_write_top_shapes# DynamicVariables "0"][!SetOptionGroup #vram_top_shapes# DynamicVariables "0"][!SetOptionGroup #cpu_top_shapes# DynamicVariables "0"][!SetOptionGroup #throttling_shapes# DynamicVariables "0"][!SetOptionGroup #power_limit_shapes# DynamicVariables "0"][!SetOptionGroup #gpu_top_shapes# DynamicVariables "0"][!SetOptionGroup #texts# DynamicVariables "0"][!SetOptionGroup #bars# DynamicVariables "0"][!SetVariable DV_Main "0"]
; Test_DynamicVar_SetGrou1        = [!SetOptionGroup #shapes# DynamicVariables "1"][!SetOptionGroup #cpu_info_shapes# DynamicVariables "1"][!SetOptionGroup #ram_top_shapes# DynamicVariables "1"][!SetOptionGroup #threads_shapes# DynamicVariables "0"][!SetOptionGroup #clock_info_shapes# DynamicVariables "1"][!SetOptionGroup #gpu_info_shapes# DynamicVariables "1"][!SetOptionGroup #io_read_top_shapes# DynamicVariables "1"][!SetOptionGroup #io_write_top_shapes# DynamicVariables "1"][!SetOptionGroup #vram_top_shapes# DynamicVariables "1"][!SetOptionGroup #cpu_top_shapes# DynamicVariables "1"][!SetOptionGroup #throttling_shapes# DynamicVariables "1"][!SetOptionGroup #power_limit_shapes# DynamicVariables "1"][!SetOptionGroup #gpu_top_shapes# DynamicVariables "1"][!SetOptionGroup #texts# DynamicVariables "1"][!SetOptionGroup #bars# DynamicVariables "1"][!SetVariable DV_Main "1"]

; Test_DynamicVar_SetGroup        = [!SetOptionGroup #shapes#;UpdateDivider "-1"][!SetOptionGroup #cpu_info_shapes#;UpdateDivider "-1"][!SetOptionGroup #ram_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #threads_shapes#;UpdateDivider "-1"][!SetOptionGroup #clock_info_shapes#;UpdateDivider "-1"][!SetOptionGroup #gpu_info_shapes#;UpdateDivider "-1"][!SetOptionGroup #io_read_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #io_write_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #vram_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #cpu_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #throttling_shapes#;UpdateDivider "-1"][!SetOptionGroup #power_limit_shapes#;UpdateDivider "-1"][!SetOptionGroup #gpu_top_shapes#;UpdateDivider "-1"][!SetOptionGroup #texts#;UpdateDivider "-1"][!SetOptionGroup #bars#;UpdateDivider "-1"]
; Test_DynamicVar_SetGrou1        = [!SetOptionGroup #shapes# DynamicVariables "1"][!SetOptionGroup #cpu_info_shapes# DynamicVariables "1"][!SetOptionGroup #ram_top_shapes# DynamicVariables "1"][!SetOptionGroup #threads_shapes# DynamicVariables "0"][!SetOptionGroup #clock_info_shapes# DynamicVariables "1"][!SetOptionGroup #gpu_info_shapes# DynamicVariables "1"][!SetOptionGroup #io_read_top_shapes# DynamicVariables "1"][!SetOptionGroup #io_write_top_shapes# DynamicVariables "1"][!SetOptionGroup #vram_top_shapes# DynamicVariables "1"][!SetOptionGroup #cpu_top_shapes# DynamicVariables "1"][!SetOptionGroup #throttling_shapes# DynamicVariables "1"][!SetOptionGroup #power_limit_shapes# DynamicVariables "1"][!SetOptionGroup #gpu_top_shapes# DynamicVariables "1"][!SetOptionGroup #texts# DynamicVariables "1"][!SetOptionGroup #bars# DynamicVariables "1"][!SetVariable DV_Main "1"]

; - These variables contains bangs for BG meter, and used by formulas below 

; Aurora_Config_MouseOver         = [!SetVariable Settings_Menu " 0"][!WriteKeyValue Variables Settings_Menu " 0" "#@#\#Config#"][!CommandMeasure animation.fader.CRYSTALS "Execute 2"]
; Aurora_Config_MouseLeave        = [!CommandMeasure animation.fader.CRYSTALS "Execute 1"][!SetVariable Settings_Menu " 1"][!WriteKeyValue Variables Settings_Menu " 1" "#@#\#Config#"]
 
 Aurora_Config_MouseOver         = [!SetVariable Settings_Menu " 0"][!WriteKeyValue Variables Settings_Menu " 0" "#@#\#Config#"][!CommandMeasure animation.fader.CRYSTALS "Execute 2"]
 Aurora_Config_MouseLeave        = [!CommandMeasure animation.fader.CRYSTALS "Execute 1"]

; = Deprecated 

 ;Set_Aurora_Mouse_Behaviour      = [!WriteKeyValue BG MouseOverAction " nothing" "#@#BG.inc"][!WriteKeyValue BG MouseLeaveAction " nothing" "#@#BG.inc"][!SetVariable Aurora_Config_MouseOver "-" ][!SetVariable Aurora_Config_MouseLeave "-"][!SetVariable Settings_Menu " 1"][!WriteKeyValue Variables Settings_Menu " 1" "#@#\#Config#"]
 
 ;Back_Aurora_Mouse_Behaviour     = [!SetVariable Aurora_Config_MouseOver """[!SetVariable Settings_Menu  " 0"][!WriteKeyValue Variables Settings_Menu  " 0" #@#\#Config#]"""][!SetVariable Aurora_Config_MouseLeave """[!SetVariable Settings_Menu " 1"][!WriteKeyValue Variables Settings_Menu " 1" #@#\#Config#]"""][!SetVariable Settings_Menu " 0"][!WriteKeyValue Variables Settings_Menu " 0" "#@#\#Config#"][!WriteKeyValue BG MouseOverAction " #*Aurora_Config_MouseOver*#" "#@#\BG.inc"][!WriteKeyValue BG MouseLeaveAction " #*Aurora_Config_MouseLeave*#" "#@#\BG.inc"][!HideMeterGroup #settings_menu#] ##

; --- CPU | GPU MEASURES ENFORCER

 Warning_Measures_Update         = [!UpdateMeasure sensor.POWER_LIMIT_CPU][!UpdateMeasure sensor.THROTTLING_CPU][!UpdateMeasure sensor.CPU_LOAD][!UpdateMeasure sensor.CPU_TEMPERATURE][!UpdateMeasure sensor.GPU_LOAD][!UpdateMeasure sensor.GPU_TEMPERATURE][!UpdateMeasure sensor.THROTTLING_GPU][!UpdateMeasure sensor.POWER_LIMIT_GPU][!UpdateMeasure sensor.PING][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeasure sensor.PROCESS_APP_1_STATIC][!UpdateMeasure sensor.PROCESS_APP_2_STATIC][!UpdateMeasure sensor.PROCESS_APP_3_STATIC][!UpdateMeasure sensor.PROCESS_APP_4_STATIC][!UpdateMeasure formula.POWER_PLAN_SWITCHER][!UpdateMeasure m.Volume_Values_Controller]

; --- CPU | GPU Graph's Enforcer 

; - The next variables force histogramms to update faster, thus when you choose a colors delay are minimized

; CGPU_Graph_Update_Over           = [!SetOption histogram.CPU_TEMPERATURE;UpdateDivider "1"][!SetOption histogram.CPU_LOAD;UpdateDivider "1"][!SetOption histogram.GPU_TEMPERATURE;UpdateDivider "1"][!SetOption histogram.GPU_LOAD;UpdateDivider "1"][!UpdateMeter *]
; CGPU_Graph_Update_Leave          = [!SetOption histogram.CPU_TEMPERATURE;UpdateDivider "#Divider_Graph#"][!SetOption histogram.CPU_LOAD;UpdateDivider "#Divider_Graph#"][!SetOption histogram.GPU_TEMPERATURE;UpdateDivider "#Divider_Graph#"][!SetOption histogram.GPU_LOAD;UpdateDivider "#Divider_Graph#"][!UpdateMeter *]

; - It's a little bit difficult here. [f.Menu_Control] sets the behavior of BG and buttons depending on the overall picture. If the amount (#Settings_Main# + #Settings_Color# + #Settings_Hardware# + #Settings_Behaviour#) <4 - this means

; - some of the menu items are open and you need appropriate behavior. The menu buttons are hidden and # Aurora_BG_Behaviour_State # is commanded to hide. And the buttons themselves get a new MouseLeave mechanic, so as not to call

; - bugs when they disappear and do not change the variables of the _Temp type, for which [f.Temp_Vars_State] is responsible. When all menus are closed (total = 4), the buttons get the old mechanics back, #Aurora_BG_Behaviour_State#.

[f.Menu_Control]
 Measure                          = CALC
 Formula                          = (#Settings_Main# + #Settings_Color# + #Settings_Hardware# + #Settings_Behaviour#)
 DynamicVariables                 = 1
 Group                            = #menu_measures#
     ifCondition                  = f.Menu_Control < 4
          
          ifTrueAction           = [!SetVariable Settings_Menu " 1"][!WriteKeyValue Variables Settings_Menu " 1" "#@#\#Config#"][!SetVariable Clock_And_Date_State "1"][!WriteKeyValue Variables Clock_And_Date_State " 1" "#@#\#Config#"]     [!SetVariable Aurora_BG_Behaviour_State "1"][!WriteKeyValue Variables Aurora_BG_Behaviour_State " 1" "#@#\#Config#"]      [!SetVariable Settings_Close " 0"][!WriteKeyValue Variables Settings_Close " 0" "#@#\#Config#"]

          ifFalseAction          = [!SetVariable Settings_Menu "1"][!WriteKeyValue Variables Settings_Menu " 1" "#@#\#Config#"][!SetVariable Clock_And_Date_State "0"][!WriteKeyValue Variables Clock_And_Date_State " 0" "#@#\#Config#"]     [!SetVariable Aurora_BG_Behaviour_State "0"][!WriteKeyValue Variables Aurora_BG_Behaviour_State " 0" "#@#\#Config#"]      [!SetVariable Settings_Close " 1"][!WriteKeyValue Variables Settings_Close " 1" "#@#\#Config#"]

     ifCondition2                = #Settings_Color# = 0
          ifTrueAction2          = [!SetOption c.shape_Top_Right_Gear_E MouseLeaveAction "-"]   [!SetVariable Settings_Color_Temp "0"][!WriteKeyValue Variables Settings_Color_Temp " 0" "#@#\#Config#"]
          ifFalseAction2         = [!SetOption c.shape_Top_Right_Gear_E MouseLeaveAction """[!SetOption c.shape_Top_Right_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Color_Temp "1"][!UpdateMeter c.shape_Top_Right_Gear_E][!UpdateMeter t.Player_Volume][!UpdateMeter text.Color_Settings_Menu][!Redraw]"""]       [!SetVariable Settings_Color_Temp "1"][!WriteKeyValue Variables Settings_Color_Temp " 1" "#@#\#Config#"]
     
     ifCondition3                = #Settings_Main# = 0 
          ifTrueAction3          = [!SetOption c.shape_Top_Left_Gear_E MouseLeaveAction "-"]    [!SetVariable Settings_Main_Temp "0"][!WriteKeyValue Variables Settings_Main_Temp " 0" "#@#\#Config#"]
          ifFalseAction3         = [!SetOption c.shape_Top_Left_Gear_E MouseLeaveAction """[!SetOption c.shape_Top_Left_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Main_Temp "1"][!UpdateMeter c.shape_Top_Left_Gear_E][!UpdateMeter t.System_Volume][!UpdateMeter text.Main_Settings_Menu][!Redraw]"""]     [!SetVariable Settings_Main_Temp "1"][!WriteKeyValue Variables Settings_Main_Temp " 1" "#@#\#Config#"]
     
     ifCondition4                = #Settings_Hardware# = 0
          ifTrueAction4          = [!SetOption c.shape_Bottom_Right_Gear_E MouseLeaveAction "-"]    [!SetVariable Settings_Hardware_Temp "0"][!WriteKeyValue Variables Settings_Hardware_Temp " 0" "#@#\#Config#"]
          ifFalseAction4         = [!SetOption c.shape_Bottom_Right_Gear_E MouseLeaveAction """[!SetOption c.shape_Bottom_Right_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Hardware_Temp "1"][!UpdateMeter c.shape_Bottom_Right_Gear_E][!UpdateMeter text.dynamic.MONTH][!UpdateMeter text.Hardware_Settings_Menu][!Redraw]"""]     [!SetVariable Settings_Hardware_Temp "1"][!WriteKeyValue Variables Settings_Hardware_Temp " 1" "#@#\#Config#"]
    
     ifCondition5                = #Settings_Behaviour# = 0
          ifTrueAction5          = [!SetOption c.shape_Bottom_Left_Gear_E MouseLeaveAction "-"]    [!SetVariable Settings_Behaviour_Temp "0"][!WriteKeyValue Variables Settings_Behaviour_Temp " 0" "#@#\#Config#"]
          ifFalseAction5         = [!SetOption c.shape_Bottom_Left_Gear_E MouseLeaveAction """[!SetOption c.shape_Bottom_Left_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Behaviour_Temp "1"][!UpdateMeter c.shape_Bottom_Left_Gear_E][!UpdateMeter text.dynamic.DAY][!UpdateMeter text.Behaviour_Settings_Menu][!Redraw]"""]     [!SetVariable Settings_Behaviour_Temp "1"][!WriteKeyValue Variables Settings_Behaviour_Temp " 1" "#@#\#Config#"]

     ifConditionMode             = 1

; - The formula [f.Temp_Vars_State] controls temporary variables of settings (_Temp), this is necessary, because when you enter the menu, switches start playing.

; - This formula ensures that the meters are in the correct position when entering and exiting the menu. By default, it is disabled, otherwise it will forcibly change variables when not needed.

; - The # Settings_Temp_Control # variable changes cz to 0 when the menu buttons are pressed, and then the counter turns on. When you click on the close button of the menu, # Settings_Temp_Control # returns back to 1, thereby disabling this formula.

; - Also, when exiting the menu, ifTrueAction sets default color values for buttons. This is necessary because when entering the menu, the logic of the MouseLeaveAction parameters, which are responsible for changing the color, changes.

; CAUTION: Logic is changed, bacause it's always called an issues. Now it is always enabled. Looking for a solution. UPDATED: IT WAS A JOKE I SET IT BACK..

[f.Temp_Vars_State]
 Measure                          = CALC
 Formula                          = #Settings_Close#
 DynamicVariables                 = 1
 Group                            = #menu_measures#
 Disabled                         = #Settings_Temp_Control#
      ifCondition                 = #Settings_Close# = 1
        
          ifTrueAction            = [!SetOption c.shape_Top_Right_Gear_E MeterStyle "s.Color_Elements"][!SetOption c.shape_Top_Left_Gear_E MeterStyle "s.Color_Elements"][!SetOption c.shape_Bottom_Right_Gear_E MeterStyle "s.Color_Elements"][!SetOption c.shape_Bottom_Left_Gear_E MeterStyle "s.Color_Elements"]   [!SetVariable Settings_Color_Temp "1"][!WriteKeyValue Variables Settings_Color_Temp " 1" "#@#\#Config#"]   [!SetVariable Settings_Main_Temp "1"][!WriteKeyValue Variables Settings_Main_Temp " 1" "#@#\#Config#"]     [!SetVariable Settings_Hardware_Temp "1"][!WriteKeyValue Variables Settings_Hardware_Temp " 1" "#@#\#Config#"]       [!SetVariable Settings_Behaviour_Temp "1"][!WriteKeyValue Variables Settings_Behaviour_Temp " 1" "#@#\#Config#"]     [!SetOption text.Behaviour_Settings_Menu FontColor "#Global_Color#"][!SetOption text.Color_Settings_Menu FontColor "#Global_Color#"][!SetOption text.Hardware_Settings_Menu FontColor "#Global_Color#"][!SetOption text.Main_Settings_Menu FontColor "#Global_Color#"]
          
          ifFalseAction           = [!SetVariable Settings_Color_Temp "0"][!WriteKeyValue Variables Settings_Color_Temp " 0" "#@#\#Config#"]   [!SetVariable Settings_Main_Temp "0"][!WriteKeyValue Variables Settings_Main_Temp " 0" "#@#\#Config#"]     [!SetVariable Settings_Hardware_Temp "0"][!WriteKeyValue Variables Settings_Hardware_Temp " 0" "#@#\#Config#"]       [!SetVariable Settings_Behaviour_Temp "0"][!WriteKeyValue Variables Settings_Behaviour_Temp " 0" "#@#\#Config#"]
          
     ifConditionMode              = 1

; - When we go into the menu, the MouseOver logic on BG should change so that the menu buttons are not displayed on hover. But when exiting the menu it should be the last one

; - Responsible for this is [f.Aurora_Bg_Behaviour] and # Aurora_BG_Behaviour_State #. It works in conjunction with # Aurora_Config_MouseOver # and # Aurora_Config_MouseLeave #, assigning the desired values ​​of the MouseOver (Leave) Action parameter to the BG metric.

[f.Aurora_Bg_Behaviour]
 Measure                          = CALC
 Formula                          = #Aurora_BG_Behaviour_State#
 DynamicVariables                 = 1
 Group                            = #menu_measures#
     ifCondition                  = #Aurora_BG_Behaviour_State# = 1
          ifTrueAction            = [!SetOption BG MouseOverAction "-"][!SetOption BG MouseLeaveAction "-"][!WriteKeyValue BG MouseOverAction " nothing to do :)" "#@#\BG.inc"][!WriteKeyValue BG MouseLeaveAction " nothing to do :)" "#@#BG.inc"]
          ifFalseAction           = [!SetOption BG MouseOverAction "#*Aurora_Config_MouseOver*#"][!SetOption BG MouseLeaveAction "#*Aurora_Config_MouseLeave*#"][!WriteKeyValue BG MouseOverAction " #*Aurora_Config_MouseOver*#" "#@#\BG.inc"][!WriteKeyValue BG MouseLeaveAction " #*Aurora_Config_MouseLeave*#" "#@#\BG.inc"]
          ifConditionMode         = 0

; - [f.Menu_Text_Colors_Control] Control the colors of menu button. CAREFUL, IFCONDITIONMODE=1!

[f.Menu_Text_Colors_Control]
 Measure                          = CALC
 Formula                          = f.Menu_Control < 4
 DynamicVariables                 = 1
 Group                            = #menu_measures#
 Disabled                         = #Settings_Temp_Control#
     ifCondition                  = f.Menu_Control < 4
          ifTrueAction            = [!SetOption text.Main_Settings_Menu FontColor "#Bar_Bg_Color#"]   [!SetOption text.Color_Settings_Menu FontColor "#Bar_Bg_Color#"]      [!SetOption text.Behaviour_Settings_Menu FontColor "#Bar_Bg_Color#"]       [!SetOption text.Hardware_Settings_Menu FontColor "#Bar_Bg_Color#"]
          ifFalseAction           = [!SetOption text.Main_Settings_Menu FontColor "#Global_Color#"]   [!SetOption text.Color_Settings_Menu FontColor "#Global_Color#"]      [!SetOption text.Behaviour_Settings_Menu FontColor "#Global_Color#"]       [!SetOption text.Hardware_Settings_Menu FontColor "#Global_Color#"]

     ifCondition2                 = (f.Menu_Control < 4) && (#Settings_Main# = 0)
          ifTrueAction2           = [!SetOption text.Main_Settings_Menu FontColor "#Global_Color#"]
     
     ifCondition3                 = (f.Menu_Control < 4) && (#Settings_Color# = 0)
          ifTrueAction3           = [!SetOption text.Color_Settings_Menu FontColor "#Global_Color#"]

     ifCondition4                 = (f.Menu_Control < 4) && (#Settings_Behaviour# = 0)
          ifTrueAction4           = [!SetOption text.Behaviour_Settings_Menu FontColor "#Global_Color#"]

     ifCondition5                 = (f.Menu_Control < 4) && (#Settings_Hardware# = 0)
          ifTrueAction5           = [!SetOption text.Hardware_Settings_Menu FontColor "#Global_Color#"]

     ifConditionMode              = 1

; --- APP TOP CONTROL VARIABLES

; - The following variables exist to store the current values of the selected applications on hover. They help to avoid errors when closing applications

; - When the mouse is over an application, these variables store the name of the application. This way, you can be sure that you closed the selected application and not any other
 



 ;Clock_And_Date_Hide             = ][!HideMeterGroup #player_controls#][!SetVariable Clock_And_Date_State " 1"][!WriteKeyValue Variables Clock_And_Date_State " 1" "#@#\#Config#"]
 ;Clock_And_Date_Show             = [!ShowMeterGroup #player_controls#][!SetVariable Clock_And_Date_State " 0"][!WriteKeyValue Variables Clock_And_Date_State " 0" "#@#\#Config#"]

 ;Main_Settings_Show              = [!ShowMeterGroup #Settings_Color#][!WriteKeyValue Variables Settings_Color " 0" "#@#\#Config#"] 
 ;Main_Settings_Hide              = [!HideMeterGroup #Settings_Color#][!WriteKeyValue Variables Settings_Color " 1" "#@#\#Config#"]

 ;Hardware_Settings_Show          = [!ShowMeterGroup #settings_hardware#][!WriteKeyValue Variables Settings_Hardware " 0" "#@#\#Config#"]
 ;Hardware_Settings_Hide          = [!HideMetergroup #settings_hardware#][!WriteKeyValue Variables Settings_Hardware " 1" "#@#\#Config#"]

 ;Behaviour_Settings_Show         = [!ShowMetergroup #settings_behaviour#][!WriteKeyValue Variables Settings_Behaviour " 0" "#@#\#Config#"]
 ;Behaviour_Settings_Hide         = [!HideMeterGroup #settings_behaviour#][!WriteKeyValue Variables Settings_Behaviour " 1" "#@#\#Config#"]

 ;Menu_Settings_Show              = [!ShowMeterGroup #settings_menu#][!WriteKeyValue Variables Settings_Menu " 0" "#@#\#Config#"]
 ;Menu_Settings_Hide              = [!HideMetergroup #settings_menu#][!WriteKeyValue Variables Settings_Menu " 1" "#@#\#Config#"]


; - The formula "f.Height_Top_Sizer" checks 6 variables and takes MAX from them. This MAX value then determines the height of the cover through the "Pad_Top" variable

; - Values from 0 to 7 used in next variables : "Height_State_One", "Height_State_Two", "Height_State_Three", "Height_State_Four", "Height_State_Five", "Height_State_Six"

; - This method allows you to monitor the state of the "wings" on both sides and determine the height depending on which wings are currently open.

[f.Height_Top_Sizer]
 Measure                         = Calc
 Formula                         = ( Max ( #Height_State_One#, Max ( #Height_State_Two#, Max ( #Height_State_Three#, Max ( #Height_State_Four#, Max ( #Height_State_Five#, #Height_State_Six#))))))
 DynamicVariables                = 1
 Group                           = #sizer_top#
     ifCondition                 = (f.Height_Top_Sizer = 0) || (f.Height_Top_Sizer = 1)
          ifTrueAction           = [!SetVariable Pad_Top " 0"][!WriteKeyValue Variables Pad_Top " 0" "#@#\#Config#"][!UpdateMeasureGroup #drives_left_side#][!UpdateMeasureGroup #app_volume_controls_static#][!UpdateMeasureGroup #app_volume_controls_dynamic#][!UpdateMeter *][!Redraw]
     ifCondition2                = (f.Height_Top_Sizer = 2) || (f.Height_Top_Sizer = 3)
          ifTrueAction2          = [!SetVariable Pad_Top " 30"][!WriteKeyValue Variables Pad_Top " 30" "#@#\#Config#"][!UpdateMeasureGroup #drives_left_side#][!UpdateMeasureGroup #app_volume_controls_static#][!UpdateMeasureGroup #app_volume_controls_dynamic#][!UpdateMeter *][!Redraw]
     ifCondition3                = (f.Height_Top_Sizer = 4) || (f.Height_Top_Sizer = 5)
          ifTrueAction3          = [!SetVariable Pad_Top "55"][!WriteKeyValue Variables Pad_Top " 55" "#@#\#Config#"][!UpdateMeasureGroup #drives_left_side#][!UpdateMeasureGroup #app_volume_controls_static#][!UpdateMeasureGroup #app_volume_controls_dynamic#][!UpdateMeter *][!Redraw]
     ifCondition4                = (f.Height_Top_Sizer = 6) || (f.Height_Top_Sizer = 7)
          ifTrueAction4          = [!SetVariable Pad_Top " 110"][!WriteKeyValue Variables Pad_Top " 110" "#@#\#Config#"][!UpdateMeasureGroup #drives_left_side#][!UpdateMeasureGroup #app_volume_controls_static#][!UpdateMeasureGroup #app_volume_controls_dynamic#][!UpdateMeter *][!Redraw]

; - The formula "f.Height_Top_Check" checks the sum of all open "wings" on top and then determines the behavior of the upper triangle

; - Thus, the Top Triangle becomes a little "smart" (but still not enought) and acts depending on the state of the wings

; - It is the same the for "f.Height_Bottom_Check"

[f.Height_Top_Check]
 Measure                         = Calc
 Formula                         = ( #Height_State_One# + #Height_State_Two# + #Height_State_Three# + #Height_State_Four# + #Height_State_Five# + #Height_State_Six#)
 DynamicVariables                = 1
 Group                           = #sizer_top#
 Disabled                        = 1
     ifCondition                 = f.Height_Top_Check = 27
          ifTrueAction           = [!SetVariable Triangle_Top_Mechanic " 0"][!WriteKeyValue Variables Triangle_Top_Mechanic " 0" "#@#\#Config#"]
     ifCondition2                = f.Height_Top_Check = 0
          ifTrueAction2          = [!SetVariable Triangle_Top_Mechanic " 1"][!WriteKeyValue Variables Triangle_Top_Mechanic " 1" "#@#\#Config#"]

[f.Height_Bottom_Check]
 Measure                         = Calc
 Formula                         = ( #CPU_Top_State# + #VRAM_Top_State# + #GPU_Top_State# + #Disk_Read_Top_State# + #Throttling_State# + #Power_Limit_State#)
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
 Disabled                        = 0
     ifCondition                 = f.Height_Bottom_Check = 6
          ifTrueAction           = [!SetVariable Triangle_Bottom_Mechanic " 0"][!WriteKeyValue Variables Triangle_Bottom_Mechanic " 0" "#@#\#Config#"]
     ifCondition2                = f.Height_Bottom_Check = 0
          ifTrueAction2          = [!SetVariable Triangle_Bottom_Mechanic " 1"][!WriteKeyValue Variables Triangle_Bottom_Mechanic " 1" "#@#\#Config#"]

[f.CPU_Top_Height]
 Measure                         = Calc
 Formula                         = #CPU_Top_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #CPU_Top_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_CPU_Top "0"][!WriteKeyValue Variables Pad_Bottom_CPU_Top " 0" "#@#\#Config#"]
     ifCondition2                = #CPU_Top_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_CPU_Top "112"][!WriteKeyValue Variables Pad_Bottom_CPU_Top " 112" "#@#\#Config#"]

[f.VRAM_Top_Height]
 Measure                         = Calc
 Formula                         = #VRAM_Top_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #VRAM_Top_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_VRAM_Top "0"][!WriteKeyValue Variables Pad_Bottom_VRAM_Top " 0" "#@#\#Config#"]
     ifCondition2                = #VRAM_Top_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_VRAM_Top "112"][!WriteKeyValue Variables Pad_Bottom_VRAM_Top " 112" "#@#\#Config#"]

[f.GPU_Top_Height]
 Measure                         = Calc
 Formula                         = #GPU_Top_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #GPU_Top_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_GPU_Top "0"][!WriteKeyValue Variables Pad_Bottom_GPU_Top " 0" "#@#\#Config#"]
     ifCondition2                = #GPU_Top_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_GPU_Top "112"][!WriteKeyValue Variables Pad_Bottom_GPU_Top " 112" "#@#\#Config#"]

[f.Disk_Read_Top_Height]
 Measure                         = Calc
 Formula                         = #Disk_Read_Top_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #Disk_Read_Top_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_Disk_Read_Top "0"][!WriteKeyValue Variables Pad_Bottom_Disk_Read_Top " 0" "#@#\#Config#"]
     ifCondition2                = #Disk_Read_Top_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_Disk_Read_Top "112"][!WriteKeyValue Variables Pad_Bottom_Disk_Read_Top " 112" "#@#\#Config#"]

[f.Throttling_Height]
 Measure                         = Calc
 Formula                         = #Throttling_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #Throttling_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_Throttling "0"][!WriteKeyValue Variables Pad_Bottom_Throttling " 0" "#@#\#Config#"]
     ifCondition2                = #Throttling_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_Throttling "112"][!WriteKeyValue Variables Pad_Bottom_Throttling " 112" "#@#\#Config#"]

[f.Power_Limit_Height]
 Measure                         = Calc
 Formula                         = #Power_Limit_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #Power_Limit_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_Power_Limit "0"][!WriteKeyValue Variables Pad_Bottom_Power_Limit " 0" "#@#\#Config#"]
     ifCondition2                = #Power_Limit_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_Power_Limit "112"][!WriteKeyValue Variables Pad_Bottom_Power_Limit " 112" "#@#\#Config#"]

[f.Logs_Bottom_Height]
 Measure                         = Calc
 Formula                         = #Logs_Bottom_State#
 DynamicVariables                = 1
 Group                           = #sizer_bottom#
     ifCondition                 = #Logs_Bottom_State# = 0
          ifTrueAction           = [!SetVariable Pad_Bottom_Logs "0"][!WriteKeyValue Variables Pad_Bottom_Logs " 0" "#@#\#Config#"]
     ifCondition2                = #Logs_Bottom_State# = 1
          ifTrueAction2          = [!SetVariable Pad_Bottom_Logs "112"][!WriteKeyValue Variables Pad_Bottom_Logs " 112" "#@#\#Config#"]

; --- TRIANGLES MECHANIC BEGINNING

; - These mechanics touches TRIANGLES at the sides of skin. TOP and BOTTOM triangles controls summurary state of wings at top and bottom, obvious.

; - RIGHT and LEFT triangles have the similar mechanics but they controls they own stuff - calculator\disk for the left, and volume controls for right one. Easy.

[f.Triangle_Top_Mechanic]
 Measure                         = Calc
 Formula                         = #Triangle_Top_Mechanic#
 DynamicVariables                = 1
 Disabled                        = 1
     ifCondition                 = #Triangle_Top_Mechanic# = 0
          ifTrueAction           = [!DisableMeasureGroup #sounds_wings_top#][!SetVariable RAM_Top_State "0"][!WriteKeyValue Variables RAM_Top_State " 0" "#@#\#Config#"][!SetVariable CPU_Info_State "0"][!WriteKeyValue Variables CPU_Info_State " 0" "#@#\#Config#"][!SetVariable Threads_State "0"][!WriteKeyValue Variables Threads_State " 0" "#@#\#Config#"][!SetVariable Clock_Info_State "0"][!WriteKeyValue Variables Clock_Info_State " 0" "#@#\#Config#"][!SetVariable GPU_Info_State "0"][!WriteKeyValue Variables GPU_Info_State " 0" "#@#\#Config#"][!SetVariable Disk_Write_Top_State "0"][!WriteKeyValue Variables Disk_Write_Top_State " 0" "#@#\#Config#"][!SetVariable Height_State_One "2"][!WriteKeyValue Variables Height_State_One " 2" "#@#\#Config#"][!SetVariable Height_State_Two "3"][!WriteKeyValue Variables Height_State_Two " 3" "#@#\#Config#"][!SetVariable Height_State_Three "6"][!WriteKeyValue Variables Height_State_Three " 6" "#@#\#Config#"][!SetVariable Height_State_Four "7"][!WriteKeyValue Variables Height_State_Four " 7" "#@#\#Config#"][!SetVariable Height_State_Five "5"][!WriteKeyValue Variables Height_State_Five " 5" "#@#\#Config#"][!SetVariable Height_State_Six "4"][!WriteKeyValue Variables Height_State_Six " 4" "#@#\#Config#"][!UpdateMeasureGroup #sizer_top#]
     ifCondition2                = #Triangle_Top_Mechanic# = 1
          ifTrueAction2          = [!DisableMeasureGroup #sounds_wings_top#][!SetVariable RAM_Top_State "1"][!WriteKeyValue Variables RAM_Top_State " 1" "#@#\#Config#"][!SetVariable CPU_Info_State "1"][!WriteKeyValue Variables CPU_Info_State " 1" "#@#\#Config#"][!SetVariable Threads_State "1"][!WriteKeyValue Variables Threads_State " 1" "#@#\#Config#"][!SetVariable Clock_Info_State "1"][!WriteKeyValue Variables Clock_Info_State " 1" "#@#\#Config#"][!SetVariable GPU_Info_State "1"][!WriteKeyValue Variables GPU_Info_State " 1" "#@#\#Config#"][!SetVariable Disk_Write_Top_State "1"][!WriteKeyValue Variables Disk_Write_Top_State " 1" "#@#\#Config#"][!SetVariable Height_State_One "0"][!WriteKeyValue Variables Height_State_One " 0" "#@#\#Config#"][!SetVariable Height_State_Two "0"][!WriteKeyValue Variables Height_State_Two " 0" "#@#\#Config#"][!SetVariable Height_State_Three "0"][!WriteKeyValue Variables Height_State_Three " 0" "#@#\#Config#"][!SetVariable Height_State_Four "0"][!WriteKeyValue Variables Height_State_Four " 0" "#@#\#Config#"][!SetVariable Height_State_Five "0"][!WriteKeyValue Variables Height_State_Five " 0" "#@#\#Config#"][!SetVariable Height_State_Six "0"][!WriteKeyValue Variables Height_State_Six " 0" "#@#\#Config#"][!UpdateMeasureGroup #sizer_top#]

;[f.Triangle_Top_Mechanic]
; Measure                         = Calc
; Formula                         = #Triangle_Top_Mechanic#
; DynamicVariables                = 1
; Disabled                        = 1
;     ifCondition                 = #Triangle_Top_Mechanic# = 0
;          ifTrueAction           = [!DisableMeasureGroup #sounds_wings_top#][!SetVariable RAM_Top_State "0"][!WriteKeyValue Variables RAM_Top_State " 0" "#@#\#Config#"][!SetVariable CPU_Info_State "0"][!WriteKeyValue Variables CPU_Info_State " 0" "#@#\#Config#"][!SetVariable Threads_State "0"][!WriteKeyValue Variables Threads_State " 0" "#@#\#Config#"][!SetVariable Clock_Info_State "0"][!WriteKeyValue Variables Clock_Info_State " 0" "#@#\#Config#"][!SetVariable GPU_Info_State "0"][!WriteKeyValue Variables GPU_Info_State " 0" "#@#\#Config#"][!SetVariable Disk_Write_Top_State "0"][!WriteKeyValue Variables Disk_Write_Top_State " 0" "#@#\#Config#"][!SetVariable Height_State_One "2"][!WriteKeyValue Variables Height_State_One " 2" "#@#\#Config#"][!SetVariable Height_State_Two "3"][!WriteKeyValue Variables Height_State_Two " 3" "#@#\#Config#"][!SetVariable Height_State_Three "6"][!WriteKeyValue Variables Height_State_Three " 6" "#@#\#Config#"][!SetVariable Height_State_Four "7"][!WriteKeyValue Variables Height_State_Four " 7" "#@#\#Config#"][!SetVariable Height_State_Five "5"][!WriteKeyValue Variables Height_State_Five " 5" "#@#\#Config#"][!SetVariable Height_State_Six "4"][!WriteKeyValue Variables Height_State_Six " 4" "#@#\#Config#"]
;     ifCondition2                = #Triangle_Top_Mechanic# = 1
;          ifTrueAction2          = [!DisableMeasureGroup #sounds_wings_top#][!SetVariable RAM_Top_State "1"][!WriteKeyValue Variables RAM_Top_State " 1" "#@#\#Config#"][!SetVariable CPU_Info_State "1"][!WriteKeyValue Variables CPU_Info_State " 1" "#@#\#Config#"][!SetVariable Threads_State "1"][!WriteKeyValue Variables Threads_State " 1" "#@#\#Config#"][!SetVariable Clock_Info_State "1"][!WriteKeyValue Variables Clock_Info_State " 1" "#@#\#Config#"][!SetVariable GPU_Info_State "1"][!WriteKeyValue Variables GPU_Info_State " 1" "#@#\#Config#"][!SetVariable Disk_Write_Top_State "1"][!WriteKeyValue Variables Disk_Write_Top_State " 1" "#@#\#Config#"][!SetVariable Height_State_One "0"][!WriteKeyValue Variables Height_State_One " 0" "#@#\#Config#"][!SetVariable Height_State_Two "0"][!WriteKeyValue Variables Height_State_Two " 0" "#@#\#Config#"][!SetVariable Height_State_Three "0"][!WriteKeyValue Variables Height_State_Three " 0" "#@#\#Config#"][!SetVariable Height_State_Four "0"][!WriteKeyValue Variables Height_State_Four " 0" "#@#\#Config#"][!SetVariable Height_State_Five "0"][!WriteKeyValue Variables Height_State_Five " 0" "#@#\#Config#"][!SetVariable Height_State_Six "0"][!WriteKeyValue Variables Height_State_Six " 0" "#@#\#Config#"]

[f.Triangle_Bottom_Mechanic]
 Measure                         = Calc
 Formula                         = #Triangle_Bottom_Mechanic#
 DynamicVariables                = 1
 Disabled                        = 1
     ifCondition                 = f.Triangle_Bottom_Mechanic = 1
          ifTrueAction           = [!DisableMeasureGroup #sounds_wings_bottom#][!SetVariable CPU_Top_State "0"][!WriteKeyValue Variables CPU_Top_State " 0" "#@#\#Config#"][!SetVariable VRAM_Top_State "0"][!WriteKeyValue Variables VRAM_Top_State " 0" "#@#\#Config#"][!SetVariable GPU_Top_State "0"][!WriteKeyValue Variables GPU_Top_State " 0" "#@#\#Config#"][!SetVariable Disk_Read_Top_State "0"][!WriteKeyValue Variables Disk_Read_Top_State " 0" "#@#\#Config#"][!SetVariable Throttling_State "0"][!WriteKeyValue Variables Throttling_State " 0" "#@#\#Config#"][!SetVariable Power_Limit_State "0"][!WriteKeyValue Variables Power_Limit_State " 0" "#@#\#Config#"][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #vram_top#][!UpdateMeterGroup #vram_top_shapes#][!UpdateMeterGroup #cpu_top#][!UpdateMeterGroup #cpu_top_shapes#][!UpdateMeterGroup #throttling#][!UpdateMeterGroup #throttling_shapes#][!UpdateMeterGroup #power_limit#][!UpdateMeterGroup #power_limit_shapes#][!UpdateMeterGroup #gpu_top#][!UpdateMeterGroup #gpu_top_shapes#][!UpdateMeterGroup #io_read_top#][!UpdateMeterGroup #io_read_top_shapes#][!Redraw]
          ;[!SetVariable Logs_Bottom_State "0"][!WriteKeyValue Variables Logs_Bottom_State " 0" "#@#\#Config#"]
     ifCondition2                = f.Triangle_Bottom_Mechanic = 0
          ifTrueAction2          = [!DisableMeasureGroup #sounds_wings_bottom#][!SetVariable CPU_Top_State "1"][!WriteKeyValue Variables CPU_Top_State " 1" "#@#\#Config#"][!SetVariable VRAM_Top_State "1"][!WriteKeyValue Variables VRAM_Top_State " 1" "#@#\#Config#"][!SetVariable GPU_Top_State "1"][!WriteKeyValue Variables GPU_Top_State " 1" "#@#\#Config#"][!SetVariable Disk_Read_Top_State "1"][!WriteKeyValue Variables Disk_Read_Top_State " 1" "#@#\#Config#"][!SetVariable Throttling_State "1"][!WriteKeyValue Variables Throttling_State " 1" "#@#\#Config#"][!SetVariable Power_Limit_State "1"][!WriteKeyValue Variables Power_Limit_State " 1" "#@#\#Config#"][!SetVariable Logs_Bottom_State "1"][!WriteKeyValue Variables Logs_Bottom_State " 1" "#@#\#Config#"][!UpdateMeasureGroup #sizer_bottom#][!UpdateMeterGroup #vram_top#][!UpdateMeterGroup #vram_top_shapes#][!UpdateMeterGroup #cpu_top#][!UpdateMeterGroup #cpu_top_shapes#][!UpdateMeterGroup #throttling#][!UpdateMeterGroup #throttling_shapes#][!UpdateMeterGroup #power_limit#][!UpdateMeterGroup #power_limit_shapes#][!UpdateMeterGroup #gpu_top#][!UpdateMeterGroup #gpu_top_shapes#][!UpdateMeterGroup #io_read_top#][!UpdateMeterGroup #io_read_top_shapes#][!Redraw]

[f.Triangle_Left_Mechanic]
 Measure                         = Calc
 Formula                         = #Triangle_Left_Mechanic#
 DynamicVariables                = 1
     ifCondition                 = #Triangle_Left_Mechanic# = 0
          ifTrueAction           = [!SetVariable Disk_Left_Side_State "0"][!WriteKeyValue Variables Disk_Left_Side_State " 0" "#@#\#Config#"][!SetVariable Calculator_State "1"][!WriteKeyValue Variables Calculator_State " 1" "#@#\#Config#"][!UpdateMeterGroup #calculator#][!UpdateMeterGroup #drives_left_side#][!Redraw]
     ifCondition2                = #Triangle_Left_Mechanic# = 1
          ifTrueAction2          = [!SetVariable Disk_Left_Side_State "1"][!WriteKeyValue Variables Disk_Left_Side_State " 1" "#@#\#Config#"][!SetVariable Calculator_State "0"][!WriteKeyValue Variables Calculator_State " 0" "#@#\#Config#"][!UpdateMeterGroup #calculator#][!UpdateMeterGroup #drives_left_side#][!Redraw]

[f.Triangle_Right_Mechanic]
 Measure                         = Calc
 Formula                         = #Triangle_Right_Mechanic#
 DynamicVariables                = 1
     ifCondition                 = #Triangle_Right_Mechanic# = 0
          ifTrueAction           = [!SetVariable App_Volume_Control_Static_State "0"][!WriteKeyValue Variables App_Volume_Control_Static_State " 0" "#@#\#Config#"][!SetVariable App_Volume_Control_Dyna_State "1"][!WriteKeyValue Variables App_Volume_Control_Dyna_State " 1" "#@#\#Config#"][!UpdateMeterGroup #app_volume_controls_static#][!UpdateMeterGroup #app_volume_controls_dynamic#]
     ifCondition2                = #Triangle_Right_Mechanic# = 1
          ifTrueAction2          = [!SetVariable App_Volume_Control_Static_State "1"][!WriteKeyValue Variables App_Volume_Control_Static_State " 1" "#@#\#Config#"][!SetVariable App_Volume_Control_Dyna_State "0"][!WriteKeyValue Variables App_Volume_Control_Dyna_State " 0" "#@#\#Config#"][!UpdateMeterGroup #app_volume_controls_static#][!UpdateMeterGroup #app_volume_controls_dynamic#]

; - TRIANGLES MECHANIC END