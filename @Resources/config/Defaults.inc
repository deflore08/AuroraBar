[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = Default settings and state control variables. Do not change nothing here please, it's about yours and galaxy's safety.

[Variables]

; --- SETTINGS ---

; --- UPDATE RATES

; --- CONFIG

 Defaults                                       = config\Defaults.inc
 Config                                         = config\UserSettings.inc
 Hardware                                       = config\Hardware.inc
 Hotkeys                                        = config\Hotkeys.inc

 Backup_Folder                                  = #@#\backup
 Backup_Global_Folder                           = #ADDONSPATH#AuroraBar\Backup
 Restore_Folder                                 = #@#\config
 Update_Folder                                  = #ADDONSPATH#AuroraBar\Update\#New_Build#
 Service_Folder                                 = #ADDONSPATH#AuroraBar\Service

 Existance_Addons                               =
 Existance_Backup                               =
 Existance_Update                               =
 Existance_Service                              = 1

; --- BACKUPS

 Backup_Config                                  = #Backup_Folder#\UserSettings.backup
 Backup_Hardware                                = #Backup_Folder#\Hardware.backup
 Backup_Hotkeys                                 = #Backup_Folder#\Hotkeys.backup
      
 Backup_Config_Global                           = #Backup_Global_Folder#\UserSettings.backup
 Backup_Hardware_Global                         = #Backup_Global_Folder#\Hardware.backup
 Backup_Hotkeys_Global                          = #Backup_Global_Folder#\Hotkeys.backup
      
; --- LOGS      
      
; - Actions logs      
      
 Log_App_Terminate                              = #@#\logs\applications\app_terminate.log
      
; - Backups logs      
      
 Log_Backup_Config                              = #@#\logs\backups\backup_config.log
 Log_Backup_Hardware                            = #@#\logs\backups\backup_hardware.log
 Log_Backup_Hotkeys                             = #@#\logs\backups\backup_hotkeys.log
      
 Log_Restore_Config                             = #@#\logs\backups\restore_config.log
 Log_Restore_Hardware                           = #@#\logs\backups\restore_hardware.log
 Log_Restore_Hotkeys                            = #@#\logs\backups\restore_hotkeys.log
      
; - Cleaners logs      
      
 Log_Cache_Clear                                = #@#\logs\cleaners\cache_clear.log
 Log_Temp_Clear                                 = #@#\logs\cleaners\temp_clear.log
       
 ; - Updater logs      
      
 Log_Updater                                    = #@#\logs\updater\updater.log
 Log_Installer                                  = #@#\logs\updater\installer.log
 Log_Update_Completition                        = #@#\logs\updater\update_completition.log
      
; - Sensors logs      
      
 Log_CPU                                        = #@#\logs\sensors\cpu.log
 Log_GPU                                        = #@#\logs\sensors\gpu.log
 Log_RAM                                        = #@#\logs\sensors\ram.log
 Log_VRAM                                       = #@#\logs\sensors\vram.log
 Log_IO_Read                                    = #@#\logs\sensors\io_read.log
 Log_IO_Write                                   = #@#\logs\sensors\io_write.log

; --- CURSORS

 Cursors_Set_Techno                             = techno
 Cursors_Set_Classic                            = classic
 
 Default_Cursors_Set                            = #*Cursors_Set_Techno*#
 
 Default_Cursor_Slider_X                        = "#*Cursors_Set*#\SizeWE.ani"
 Default_Cursor_Slider_Y                        = "#*Cursors_Set*#\SizeNS.ani"
 Default_Cursor_Slider_XY                       = "#*Cursors_Set*#\SizeAll.ani"
 Default_Cursor_Hand                            = "#*Cursors_Set*#\Hand.ani"

; --- TOP UTILIZATIONS      
      
 CPU_Top_App                                    = 
 CPU_Top_App_V_1                                = [sensor.CPU_TOP_1:1]
 CPU_Top_App_V_2                                = [sensor.CPU_TOP_2:1]
 CPU_Top_App_V_3                                = [sensor.CPU_TOP_3:1]
 CPU_Top_App_V_4                                = [sensor.CPU_TOP_4:1]
 CPU_Top_App_V_5                                = [sensor.CPU_TOP_5:1]
 GPU_Top_App                                    =
 GPU_Top_App_V_1                                = [sensor.GPU_TOP_1:1]
 GPU_Top_App_V_2                                = [sensor.GPU_TOP_2:1]
 GPU_Top_App_V_3                                = [sensor.GPU_TOP_3:1]
 GPU_Top_App_V_4                                = [sensor.GPU_TOP_4:1]
 GPU_Top_App_V_5                                = [sensor.GPU_TOP_5:1]
 RAM_Top_App                                    = 
 RAM_Top_App_V_1                                = [sensor.RAM_TOP_1:1]
 RAM_Top_App_V_2                                = [sensor.RAM_TOP_2:1]
 RAM_Top_App_V_3                                = [sensor.RAM_TOP_3:1]
 VRAM_Top_App                                   =
 VRAM_Top_App_V_1                               = [sensor.VRAM_TOP_1:1]
 VRAM_Top_App_V_2                               = [sensor.VRAM_TOP_2:1]
 VRAM_Top_App_V_3                               = [sensor.VRAM_TOP_3:1]
 IO_Read_Top_App                                =
 IO_Read_Top_App_V_1                            = [formula.TOP_IO_READ_SCALED_1]
 IO_Read_Top_App_V_2                            = [formula.TOP_IO_READ_SCALED_2]
 IO_Read_Top_App_V_3                            = [formula.TOP_IO_READ_SCALED_3]
 IO_Write_Top_App                               = 
 IO_Write_Top_App_V_1                           = [formula.TOP_IO_WRITE_SCALED_1]
 IO_Write_Top_App_V_2                           = [formula.TOP_IO_WRITE_SCALED_2]
 IO_Write_Top_App_V_3                           = [formula.TOP_IO_WRITE_SCALED_3]
 App_Volume_Process                             = 
      
; --- HEALTH STATES      
      
 CPU_Health_State                               = GOOD
 GPU_Health_State                               = GOOD
 RAM_Health_State                               = GOOD
 VRAM_Health_State                              = GOOD
 IO_Read_Health_State                           = GOOD
 IO_Write_Health_State                          = GOOD
      
; - CPU HEALTH      
      
 CPU_Load_Health                                =
 CPU_Temp_Health                                =
      
; - GPU HEALTH      
      
 GPU_Load_Health                                =
 GPU_Temp_Health                                =
      
; --- SETTINGS ---      
      
; --- MAIN      
      
; - Effects      
      
 Default_Frosted_Glass_State                    = 0
 Default_Translucent_State                      = 1
 Default_ToolTips_State                         = 1
 Default_Sounds_State                           = 1
            
; - Updates      
      
 Default_Update_Rate                            = 16
 Default_Cycles_2nd_Divider                     = 3
 Default_Cycles_3rd_Divider                     = 2
 Default_Divider_Negative_Meter                 = 0
 Default_Divider_Negative_Measure               = -1
 Default_Delay_x2                               = (#*Update_Rate*# * 2)
 Default_Delay_x3                               = (#*Update_Rate*# * 3)
 Default_DV_Main                                = 1

; - Volume

 Default_Player_Name                            = AIMP
 Default_Player_Selection                       = 1
 Default_Player_State                           = 0
      
; - Player Positions steps      
      
 Default_Player_Position_Step                   = 5
 Default_Position_Forward                       = +#*Player_Position_Step*#
 Default_Position_Backward                      = -#*Player_Position_Step*#
      
; - Volume control steps      
      
 Default_Sys_Volume_Step                        = 5
 Default_Sys_Volume_Down                        = -#*Sys_Volume_Step*#
 Default_Sys_Volume_Up                          = +#*Sys_Volume_Step*#
      
 Default_Player_Volume_Step                     = 5
 Default_Player_Volume_Down                     = -#*Player_Volume_Step*#
 Default_Player_Volume_Up                       = +#*Player_Volume_Step*#
      
; - Applications      
      
; App names to display      
      
 Default_App_Volume_1S                          = aimp
 Default_App_Volume_2S                          = potplayer
 Default_App_Volume_3S                          = discord
 Default_App_Volume_4S                          = opera
      
; Full app names to control      
      
 Default_App_Volume_1                           = aimp.exe
 Default_App_Volume_2                           = potplayermini64.exe
 Default_App_Volume_3                           = discord.exe
 Default_App_Volume_4                           = opera.exe
      
; --- HARDWARE ---      

; - Network

 Default_Net_Max                                = 100
 Default_Ping_Max                               = 100
 Default_Ping_Timeout                           = 1000
 Default_Ping_Host                              = 8.8.8.8
 Default_Ping_App_1                             = ping -t #*Ping_Host*#
      
; - Drives      
      
 Default_Drive_One                              = C:
 Default_Drive_Two                              = D:
 Default_Temp_Folder                            = %localappdata%\Temp
 Default_Cache_Folder                           = %localappdata%\Packages\Microsoft.MicrosoftEdge_8wekyb3d8bbwe\LocalCache
      
; - Limits      
      
 Default_CPU_Load_Max                           = 80
 Default_GPU_Load_Max                           = 70
 Default_CPU_Temp_Max                           = 75
 Default_GPU_Temp_Max                           = 65

; - Other HW

 Default_Bluetooth_State                        = 1
 Default_Bluetooth_Visible                      = 1
 Default_Audio_Devices_State                    = 1
 Default_VRAM_Instance_State                    = 0
      
; --- BEHAVIOUR      
      
 Default_Window_X                               = 0
 Default_Window_Y                               = 540
 Default_Anchor_X                               = 0
 Default_Anchor_Y                               = 50
      
 Default_Monitor_Num                            = 1
 Default_Monitor                                = @#*Monitor_Num*#
 Default_Skin_Alpha                             = 255
      
 Default_Skin_Zpos                              = 0
 Default_Last_Zpos                              = 
 Default_Draggable                              = 1
 Default_Snapedge                               = 1
 Default_Keep_On_Screen                         = 1

; --- CPU & GPU HISTOGRAMS

 Default_CPU_Histogram_Width                    = 300
 Default_CPU_Histogram_X                        = 512
 Default_GPU_Histogram_Width                    = 300
 Default_GPU_Histogram_X                        = 1100

; --- STATE CONTROL ---

; - Attention: #Pad_Top# variable defines Y coordinate for eeeeeach element of Aurora.

; - Default value is "110". If your taskbar is on top of screen - you may use 150 and 140 (if icons is minimized) values to keep Aurora below taskbar. 

 Default_Pad_Top                                = 0
 Default_Pad_X_Wings_Left                       = 
 Default_Pad_X_Wings_Right                      =
       
; --- HEIGHT variables

; - #Height_State_One(1-6)# contains an unique value from 0 to 7. It needs to calculate HEIGHT mechanic (it's about TOP) in a formulas below

 Default_Height_State_One                       = 0
 Default_Height_State_Two                       = 0
 Default_Height_State_Three                     = 0
 Default_Height_State_Four                      = 0
 Default_Height_State_Five                      = 0
 Default_Height_State_Six                       = 0
       
; - #Pad_Bottom_INSTANCE# defines a Y position for elements below BG. If it's hided, it will 112px. 
       
 Default_Pad_Bottom_VRAM_Top                    = 112
 Default_Pad_Bottom_CPU_Top                     = 112
 Default_Pad_Bottom_Throttling                  = 112
 Default_Pad_Bottom_Power_Limit                 = 112
 Default_Pad_Bottom_GPU_Top                     = 112
 Default_Pad_Bottom_DIsk_Read_Top               = 112
 Default_Pad_Bottom_Logs                        = 112
      
; --- TRIANGLE mechanics determines behaviour of 4 triangles from all sides
      
 Default_Triangle_Top_Mechanic                  = 1
 Default_Triangle_Bottom_Mechanic               = 0
 Default_Triangle_Left_Mechanic                 = 0
 Default_Triangle_Right_Mechanic                = 0
       
; --- SECTIONS STATES       
       
 Default_CPU_Top_State                          = 1
 Default_GPU_Top_State                          = 1  
 Default_CPU_Info_State                         = 1 
 Default_GPU_Info_State                         = 1 
 Default_RAM_Top_State                          = 1 
 Default_VRAM_Top_State                         = 1 
 Default_Threads_State                          = 1 
 Default_Throttling_State                       = 1 
 Default_Clock_Info_State                       = 1 
 Default_Power_Limit_State                      = 1 
 Default_Disk_Read_Top_State                    = 1 
 Default_Disk_Write_Top_State                   = 1 
 Default_Debug_State                            = 1
       
 Default_Logs_Bottom_State                      = 1
 Default_Logs_Top_State                         = 0
       
 Default_Disk_Left_Side_State                   = 0
 Default_Calculator_State                       = 1
       
 Default_App_Volume_Control_Static_State        = 0
 Default_App_Volume_Control_Dyna_State          = 1
       
 Default_Pallete_State                          = 1
 Default_Clock_And_Date_State                   = 0
       
; --- PLAYER STATES       
       
 Default_Player_1_Artist_Title_State            = 1
 Default_Player_1_Shuffle_State                 = 0
 Default_Player_1_Repeat_State                  = 1
 Default_Player_2_Artist_Title_State            = 0
 Default_Player_2_Shuffle_State                 = 0
 Default_Player_2_Repeat_State                  = 0
       
; --- MENU variables, important       
       
; - #Settings_Menu# need to control menu        buttons (crystal shapes) 
       
; - #Aurora_BG_Behaviour_State# determine       s BG MouseOver\Leave behaviour
       
 Default_Settings_Menu                          = 0
 Default_Aurora_BG_Behaviour_State              = 0
      
; - The next variables controls the menu bookmarks
      
; - #Settings_Close# it's about X (close) button
      
 Default_Settings_Main                          = 1
 Default_Settings_Color                         = 1
 Default_Settings_Hardware                      = 1
 Default_Settings_Behaviour                     = 1
 Default_Settings_Close                         = 1
       
; - "Temporary" variables that controls switcher between main texts and menu texts
       
 Default_Settings_Main_Temp                     = 1
 Default_Settings_Color_Temp                    = 1
 Default_Settings_Hardware_Temp                 = 1
 Default_Settings_Behaviour_Temp                = 1
       
; - #Settings_Temp_Control# controls [f.Temp_Vars_State] formula
       
 Default_Settings_Temp_Control                  = 1

; --- DEPRECATED

; Default_Drive_One_Min_Read                     = 0
; Default_Drive_One_Max_Read                     = 3221225472
; Default_Drive_One_Min_Write                    = 0
; Default_Drive_One_Max_Write                    = 1610612736
      
; Default_Drive_Two_Min_Read                     = 0
; Default_Drive_Two_Max_Read                     = 134217728
; Default_Drive_Two_Min_Write                    = 0
; Default_Drive_Two_Max_Write                    = 67108864
      
; --- COLORS ---

 Default_R_Color                                = 
 Default_G_Color                                = 
 Default_B_Color                                = 
 Default_A_Color                                = 
       
 Default_RGB_Color                              = 124, 12 , 239
 Default_RGB_Font_Color                         = 255, 255, 255
 Default_RGB_Font_Warning_Color                 = 
 Default_Global_Color                           = #*RGB_Color*#, #*Global_Alpha*#
 Default_Bar_Color                              = #*Global_Color*#
 Default_Bar_BG_Color                           = #*RGB_Color*#, #*Bar_BG_Alpha*#
      
 Default_BG_Color                               = 0, 0, 0, 160
      
 Default_Font_Color                             = 0, 240 , 215, 255
 Default_Font_Value_Color                       = 0, 240, 117, 255
 Default_Font_Warning_Color                     = 240, 24 , 222, 255 
      
 Default_Global_Alpha                           = 220
 Default_Font_Alpha                             = 255
 Default_Pallete_Alpha                          = 140
 Default_Bar_BG_Alpha                           = 50

; --- LAST COLORS

; - These vars force Aurora to remember current scheme

; - It needs for returning to your current scheme when mouse left out of a color buttons

 Default_Last_Global_Color                      = 124, 12 , 239 
 Default_Last_Bar_Color                         = 
 Default_Last_BG_Color                          = 124, 12 , 239
 Default_Last_RGB_Color                         = 
 Default_Last_RGB_Font_Color                    = 0, 240 , 215 
 Default_Last_Font_Color                        = 0, 240 , 215 
 Default_Last_Value_Color                       = 0, 240, 117, 255 
 Default_Last_Warning_Color                     = 240, 24 , 222
 Default_Last_FontColor                         = #*Font_Color*#
 Default_Last_Font_Size                         = 10

; --- MAIN FONTS

 Default_FontColor                              = #*Font_Color*#
 Default_Font_Size                              = 10
 Default_Font_Size_Small                        = 7
 Default_Faded_Font_Size_Small                  = 7
 Default_Font                                   = AGENCY FB
 Default_Bold_Font                              = AGENCY FB
 Default_String_Style                           = Normal
 Default_T_String_Style                         = Normal

; --- TIME FONTS

 Default_Time_Font_Main                         = BRETTON
 Default_Time_Font_Size_Day                     = 15
 Default_Time_Font_Size_Cday                    = 15
 Default_Time_Font_Color_Main                   = #*Font_Color*#
 Default_Time_Font_Color_Hours                  = #*Font_Color*#
 Default_Time_Font_Color_Mins                   = #*Font_Color*#
 Default_Time_Font_Size_Main                    = 20
 Default_Time_Font_Size_Hours                   = 40
 Default_Time_Font_Size_Mins                    = 24
 Default_Time_Font_Size_Secs                    = 14
 Default_Time_Font_Size_Date                    = 15
 Default_Time_Font_Size_Year                    = 15

; --- SHELL     
     
 Net_Center                                     = Shell:::{7007ACC7-3202-11D1-AAD2-00805FC1270E}
 Time_And_Date                                  = Shell:::{E2E7934B-DCE5-43C4-9576-7FE4F75E7480}
 Device_Manager                                 = Shell:::{74246bfc-4c96-11d0-abef-0020af6b0b7a}
 Admin_Tools                                    = Shell:::{D20EA4E1-3957-11d2-A40B-0C5020524153}
 Firewall                                       = Shell:::{4026492F-2F69-46B8-B9BF-5654FC07E423}
 Run                                            = Shell:::{2559a1f3-21d7-11d4-bdaf-00c04f60b9f0}
 Sound                                          = Shell:::{F2DDFC82-8F12-4CDD-B7DC-D4FE1425AA4D}
 Computer                                       = Shell:::{20D04FE0-3AEA-1069-A2D8-08002B30309D}
 Control_Panel                                  = Shell:::{5399E694-6CE5-4D6C-8FCE-1D8870FDCBA0}
 Desktop                                        = Shell:::{3080F90D-D7AD-11D9-BD98-0000947B0257}
 System                                         = Shell:::{BB06C0E4-D293-4f75-8A90-CB05B6477EEE}
 Power_Options                                  = Shell:::{025A5937-A6BE-4686-A844-36FE4BEC8B6D}
       
; --- SET DEFAULTS ---

; --- SETTINGS ---

; --- MAIN | :32

; - Effects

 SET_DEFAULT_Frosted_Glass_State                = [!SetVariable Frosted_Glass_State "#Default_Frosted_Glass_State#"][!WriteKeyValue Variables Frosted_Glass_State "#Default_Frosted_Glass_State#" "#@#\#Config#"]
 SET_DEFAULT_Translucent_State                  = [!SetVariable Translucent_State "#Default_Translucent_State#"][!WriteKeyValue Variables Translucent_State "#Default_Translucent_State#" "#@#\#Config#"]
 SET_DEFAULT_ToolTips_State                     = [!SetVariable ToolTips_State "#Default_ToolTips_State#"][!WriteKeyValue Variables ToolTips_State "#Default_ToolTips_State#" "#@#\#Config#"]
 SET_DEFAULT_Sounds_State                       = [!SetVariable Sounds_State "#Default_Sounds_State#"][!WriteKeyValue Variables Sounds_State "#Default_Sounds_State#" "#@#\#Config#"]

; - Updates

 SET_DEFAULT_Update_Rate                        = [!SetVariable Update_Rate "#Default_Update_Rate#"][!WriteKeyValue Variables Update_Rate "#Default_Update_Rate#" "#@#\#Config#"]
 SET_DEFAULT_Cycles_2nd_Divider                 = [!SetVariable Cycles_2nd_Divider "#Default_Cycles_2nd_Divider#"][!WriteKeyValue Variables Cycles_2nd_Divider "#Default_Cycles_2nd_Divider#" "#@#\#Config#"]
 SET_DEFAULT_Cycles_3rd_Divider                 = [!SetVariable Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#"][!WriteKeyValue Variables Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#" "#@#\#Config#"]
 SET_DEFAULT_Default_Divider_Negative_Meter     = [!SetVariable Divider_Negative_Meter "#Default_Divider_Negative_Meter#"][!WriteKeyValue Variables Divider_Negative_Meter "#Default_Divider_Negative_Meter#" "#@#\#Config#"]
 SET_DEFAULT_Default_Divider_Negative_Measure   = [!SetVariable Divider_Negative_Measure "#Default_Divider_Negative_Measure#"][!WriteKeyValue Variables Divider_Negative_Measure "#Default_Divider_Negative_Measure#" "#@#\#Config#"]
 SET_DEFAULT_Default_Delay_x2                   = [!SetVariable Delay_x2 "#Default_Delay_x2#"][!WriteKeyValue Variables Delay_x2 "#Default_Delay_x2#" "#@#\#Config#"]
 SET_DEFAULT_Default_Delay_x3                   = [!SetVariable Delay_x3 "#Default_Delay_x3#"][!WriteKeyValue Variables Delay_x3 "#Default_Delay_x3#" "#@#\#Config#"]
 SET_DEFAULT_Default_DV_Main                    = [!SetVariable DV_Main "#Default_DV_Main#"][!WriteKeyValue Variables DV_Main "#Default_DV_Main#" "#@#\#Config#"]

; - Volume

 SET_DEFAULT_Player_Name                        = [!SetVariable Player_Name "#Default_Player_Name#"][!WriteKeyValue Variables Player_Name "#Default_Player_Name#" "#@#\#Config#"]
 SET_DEFAULT_Player_Selection                   = [!SetVariable Player_Selection "#Default_Player_Selection#"][!WriteKeyValue Variables Player_Selection "#Default_Player_Selection#" "#@#\#Config#"]
 SET_DEFAULT_Player_State                       = [!SetVariable Player_State "#Default_Player_State#"][!WriteKeyValue Variables Player_State "#Default_Player_State#" "#@#\#Config#"]

; - Player Positions steps

 SET_DEFAULT_Player_Position_Step               = [!SetVariable Player_Position_Step "#Default_Player_Position_Step#"][!WriteKeyValue Variables Player_Position_Step "#Default_Player_Position_Step#" "#@#\#Config#"]
 SET_DEFAULT_Position_Forward                   = [!SetVariable Position_Forward "#Default_Position_Forward#"][!WriteKeyValue Variables Position_Forward "#Default_Position_Forward#" "#@#\#Config#"]
 SET_DEFAULT_Position_Backward                  = [!SetVariable Position_Backward "#Default_Position_Backward#"][!WriteKeyValue Variables Position_Backward "#Default_Position_Backward#" "#@#\#Config#"]

; - Volume control steps

 SET_DEFAULT_Sys_Volume_Step                    = [!SetVariable Sys_Volume_Step "#Default_Sys_Volume_Step#"][!WriteKeyValue Variables Sys_Volume_Step "#Default_Sys_Volume_Step#" "#@#\#Config#"]
 SET_DEFAULT_Sys_Volume_Down                    = [!SetVariable Sys_Volume_Down "#Default_Sys_Volume_Down#"][!WriteKeyValue Variables Sys_Volume_Down "#Default_Sys_Volume_Down#" "#@#\#Config#"]
 SET_DEFAULT_Sys_Volume_Up                      = [!SetVariable Sys_Volume_Up "#Default_Sys_Volume_Up#"][!WriteKeyValue Variables Sys_Volume_Up "#Default_Sys_Volume_Up#" "#@#\#Config#"]

 SET_DEFAULT_Player_Volume_Step                 = [!SetVariable Player_Volume_Step "#Default_Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Step "#Default_Player_Volume_Step#" "#@#\#Config#"]
 SET_DEFAULT_Player_Volume_Down                 = [!SetVariable Player_Volume_Down "#Default_Player_Volume_Down#"][!WriteKeyValue Variables Player_Volume_Down "#Default_Player_Volume_Down#" "#@#\#Config#"]
 SET_DEFAULT_Player_Volume_Up                   = [!SetVariable Player_Volume_Up "#Default_Player_Volume_Up#"][!WriteKeyValue Variables Player_Volume_Up "#Default_Player_Volume_Up#" "#@#\#Config#"]

; - Applications

; App names to display

 SET_DEFAULT_App_Volume_1S                      = [!SetVariable App_Volume_1S "#Default_App_Volume_1S#"][!WriteKeyValue Variables App_Volume_1S "#Default_App_Volume_1S#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_2S                      = [!SetVariable App_Volume_2S "#Default_App_Volume_2S#"][!WriteKeyValue Variables App_Volume_2S "#Default_App_Volume_2S#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_3S                      = [!SetVariable App_Volume_3S "#Default_App_Volume_3S#"][!WriteKeyValue Variables App_Volume_3S "#Default_App_Volume_3S#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_4S                      = [!SetVariable App_Volume_4S "#Default_App_Volume_4S#"][!WriteKeyValue Variables App_Volume_4S "#Default_App_Volume_4S#" "#@#\#Config#"]

; Full app names to control

 SET_DEFAULT_App_Volume_1                       = [!SetVariable App_Volume_1 "#Default_App_Volume_1#"][!WriteKeyValue Variables App_Volume_1 "#Default_App_Volume_1#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_2                       = [!SetVariable App_Volume_2 "#Default_App_Volume_2#"][!WriteKeyValue Variables App_Volume_2 "#Default_App_Volume_2#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_3                       = [!SetVariable App_Volume_3 "#Default_App_Volume_3#"][!WriteKeyValue Variables App_Volume_3 "#Default_App_Volume_3#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_4                       = [!SetVariable App_Volume_4 "#Default_App_Volume_4#"][!WriteKeyValue Variables App_Volume_4 "#Default_App_Volume_4#" "#@#\#Config#"]

; --- HARDWARE | :17

; - Network

 SET_DEFAULT_Net_Max                            = [!SetVariable Net_Max "#Default_Net_Max#"][!WriteKeyValue Variables Net_Max "#Default_Net_Max#" "#@#\#Config#"]
 SET_DEFAULT_Ping_Max                           = [!SetVariable Ping_Max "#Default_Ping_Max#"][!WriteKeyValue Variables Ping_Max "#Default_Ping_Max#" "#@#\#Config#"]
 SET_DEFAULT_Ping_Timeout                       = [!SetVariable Ping_Timeout "#Default_Ping_Timeout#"][!WriteKeyValue Variables Ping_Timeout "#Default_Ping_Timeout#" "#@#\#Config#"]
 SET_DEFAULT_Ping_Host                          = [!SetVariable Ping_Host "#Default_Ping_Host#"][!WriteKeyValue Variables Ping_Host "#Default_Ping_Host#" "#@#\#Config#"]
 SET_DEFAULT_Ping_App_1                         = [!SetVariable Ping_App_1 "#Default_Ping_App_1#"][!WriteKeyValue Variables Ping_App_1 "#Default_Ping_App_1#" "#@#\#Config#"]

; - Drives

 SET_DEFAULT_Drive_One                          = [!SetVariable Drive_One "#Default_Drive_One#"][!WriteKeyValue Variables Drive_One "#Default_Drive_One#" "#@#\#Config#"]
 SET_DEFAULT_Drive_Two                          = [!SetVariable Drive_Two "#Default_Drive_Two#"][!WriteKeyValue Variables Drive_Two "#Default_Drive_Two#" "#@#\#Config#"]
 SET_DEFAULT_Temp_Folder                        = [!SetVariable Temp_Folder "#Default_Temp_Folder#"][!WriteKeyValue Variables Temp_Folder "#Default_Temp_Folder#" "#@#\#Config#"]
 SET_DEFAULT_Cache_Folder                       = [!SetVariable Cache_Folder "#Default_Cache_Folder#"][!WriteKeyValue Variables Cache_Folder "#Default_Cache_Folder#" "#@#\#Config#"]

; - Limits

 SET_DEFAULT_CPU_Load_Max                       = [!SetVariable CPU_Load_Max "#Default_CPU_Load_Max#"][!WriteKeyValue Variables CPU_Load_Max "#Default_CPU_Load_Max#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Load_Max                       = [!SetVariable GPU_Load_Max "#Default_GPU_Load_Max#"][!WriteKeyValue Variables GPU_Load_Max "#Default_GPU_Load_Max#" "#@#\#Config#"]
 SET_DEFAULT_CPU_Temp_Max                       = [!SetVariable CPU_Temp_Max "#Default_CPU_Temp_Max#"][!WriteKeyValue Variables CPU_Temp_Max "#Default_CPU_Temp_Max#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Temp_Max                       = [!SetVariable GPU_Temp_Max "#Default_GPU_Temp_Max#"][!WriteKeyValue Variables GPU_Temp_Max "#Default_GPU_Temp_Max#" "#@#\#Config#"]

; - Other HW

 SET_DEFAULT_Bluetooth_State                    = [!SetVariable Bluetooth_State "#Default_Bluetooth_State#"][!WriteKeyValue Variables Bluetooth_State "#Default_Bluetooth_State#" "#@#\#Config#"]
 SET_DEFAULT_Bluetooth_Visible                  = [!SetVariable Bluetooth_Visible "#Default_Bluetooth_Visible#"][!WriteKeyValue Variables Bluetooth_Visible "#Default_Bluetooth_Visible#" "#@#\#Config#"]
 SET_DEFAULT_Audio_Devices_State                = [!SetVariable Audio_Devices_State "#Default_Audio_Devices_State#"][!WriteKeyValue Variables Audio_Devices_State "#Default_Audio_Devices_State#" "#@#\#Config#"]
 SET_DEFAULT_VRAM_Instance_State                = [!SetVariable VRAM_Instance_State "#Default_VRAM_Instance_State#"][!WriteKeyValue Variables VRAM_Instance_State "#Default_VRAM_Instance_State#" "#@#\#Config#"]

; --- BEHAVIOUR

 SET_DEFAULT_Window_X                           = [!SetVariable Window_X "#Default_Window_X#"][!WriteKeyValue Variables Window_X "#Default_Window_X#" "#@#\#Config#"]
 SET_DEFAULT_Window_Y                           = [!SetVariable Window_Y "#Default_Window_Y#"][!WriteKeyValue Variables Window_Y "#Default_Window_Y#" "#@#\#Config#"]
 SET_DEFAULT_Anchor_X                           = [!SetVariable Anchor_X "#Default_Anchor_X#"][!WriteKeyValue Variables Anchor_X "#Default_Anchor_X#" "#@#\#Config#"]
 SET_DEFAULT_Anchor_Y                           = [!SetVariable Anchor_Y "#Default_Anchor_Y#"][!WriteKeyValue Variables Anchor_Y "#Default_Anchor_Y#" "#@#\#Config#"]

 SET_DEFAULT_Monitor_Num                        = [!SetVariable Monitor_Num "#Default_Monitor_Num#"][!WriteKeyValue Variables Monitor_Num "#Default_Monitor_Num#" "#@#\#Config#"]
 SET_DEFAULT_Monitor                            = [!SetVariable Monitor "#Default_Monitor#"][!WriteKeyValue Variables Monitor "#Default_Monitor#" "#@#\#Config#"]
 SET_DEFAULT_Skin_Alpha                         = [!SetVariable Skin_Alpha "#Default_Skin_Alpha#"][!WriteKeyValue Variables Skin_Alpha "#Default_Skin_Alpha#" "#@#\#Config#"]

 SET_DEFAULT_Skin_Zpos                          = [!SetVariable Skin_Zpos "#Default_Skin_Zpos#"][!WriteKeyValue Variables Skin_Zpos "#Default_Skin_Zpos#" "#@#\#Config#"]
 SET_DEFAULT_Last_Zpos                          = [!SetVariable Last_Zpos "#Default_Last_Zpos#"][!WriteKeyValue Variables Last_Zpos "#Default_Last_Zpos#" "#@#\#Config#"]
 SET_DEFAULT_Draggable                          = [!SetVariable Draggable "#Default_Draggable#"][!WriteKeyValue Variables Draggable "#Default_Draggable#" "#@#\#Config#"]
 SET_DEFAULT_Snapedge                           = [!SetVariable Snapedge "#Default_Snapedge#"][!WriteKeyValue Variables Snapedge "#Default_Snapedge#" "#@#\#Config#"]
 SET_DEFAULT_Keep_On_Screen                     = [!SetVariable Keep_On_Screen "#Default_Keep_On_Screen#"][!WriteKeyValue Variables Keep_On_Screen "#Default_Keep_On_Screen#" "#@#\#Config#"]

; --- CPU & GPU HISTOGRAMS

 SET_DEFAULT_CPU_Histogram_Width                = [!SetVariable CPU_Histogram_Width "#Default_CPU_Histogram_Width#"][!WriteKeyValue Variables CPU_Histogram_Width "#Default_CPU_Histogram_Width#" "#@#\#Config#"]
 SET_DEFAULT_CPU_Histogram_X                    = [!SetVariable CPU_Histogram_X "#Default_CPU_Histogram_X#"][!WriteKeyValue Variables CPU_Histogram_X "#Default_CPU_Histogram_X#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Histogram_Width                = [!SetVariable GPU_Histogram_Width "#Default_GPU_Histogram_Width#"][!WriteKeyValue Variables GPU_Histogram_Width "#Default_GPU_Histogram_Width#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Histogram_X                    = [!SetVariable GPU_Histogram_X "#Default_GPU_Histogram_X#"][!WriteKeyValue Variables GPU_Histogram_X "#Default_GPU_Histogram_X#" "#@#\#Config#"]

; --- STATE CONTROL ---

; Pad

 SET_DEFAULT_Pad_Top                            = [!SetVariable Pad_Top "#Default_Pad_Top#"][!WriteKeyValue Variables Pad_Top "#Default_Pad_Top#" "#@#\#Config#"]
 SET_DEFAULT_Pad_X_Wings_Left                   = [!SetVariable Pad_X_Wings_Left "#Default_Pad_X_Wings_Left#"][!WriteKeyValue Variables Pad_X_Wings_Left "#Default_Pad_X_Wings_Left#" "#@#\#Config#"]
 SET_DEFAULT_Pad_X_Wings_Right                  = [!SetVariable Pad_X_Wings_Right "#Default_Pad_X_Wings_Right#"][!WriteKeyValue Variables Pad_X_Wings_Right "#Default_Pad_X_Wings_Right#" "#@#\#Config#"]

; Height

 SET_DEFAULT_Height_State_One                   = [!SetVariable Height_State_One "#Default_Height_State_One#"][!WriteKeyValue Variables Height_State_One "#Default_Height_State_One#" "#@#\#Config#"]
 SET_DEFAULT_Height_State_Two                   = [!SetVariable Height_State_Two "#Default_Height_State_Two#"][!WriteKeyValue Variables Height_State_Two "#Default_Height_State_Two#" "#@#\#Config#"]
 SET_DEFAULT_Height_State_Three                 = [!SetVariable Height_State_Three "#Default_Height_State_Three#"][!WriteKeyValue Variables Height_State_Three "#Default_Height_State_Three#" "#@#\#Config#"]
 SET_DEFAULT_Height_State_Four                  = [!SetVariable Height_State_Four "#Default_Height_State_Four#"][!WriteKeyValue Variables Height_State_Four "#Default_Height_State_Four#" "#@#\#Config#"]
 SET_DEFAULT_Height_State_Five                  = [!SetVariable Height_State_Five "#Default_Height_State_Five#"][!WriteKeyValue Variables Height_State_Five "#Default_Height_State_Five#" "#@#\#Config#"]
 SET_DEFAULT_Height_State_Six                   = [!SetVariable Height_State_Six "#Default_Height_State_Six#"][!WriteKeyValue Variables Height_State_Six "#Default_Height_State_Six#" "#@#\#Config#"]

; Pads bottom

 SET_DEFAULT_Pad_Bottom_VRAM_Top                = [!SetVariable Pad_Bottom_VRAM_Top "#Default_Pad_Bottom_VRAM_Top#"][!WriteKeyValue Variables Pad_Bottom_VRAM_Top "#Default_Pad_Bottom_VRAM_Top#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_CPU_Top                 = [!SetVariable Pad_Bottom_CPU_Top "#Default_Pad_Bottom_CPU_Top#"][!WriteKeyValue Variables Pad_Bottom_CPU_Top "#Default_Pad_Bottom_CPU_Top#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_Throttling              = [!SetVariable Pad_Bottom_Throttling "#Default_Pad_Bottom_Throttling#"][!WriteKeyValue Variables Pad_Bottom_Throttling "#Default_Pad_Bottom_Throttling#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_Power_Limit             = [!SetVariable Pad_Bottom_Power_Limit "#Default_Pad_Bottom_Power_Limit#"][!WriteKeyValue Variables Pad_Bottom_Power_Limit "#Default_Pad_Bottom_Power_Limit#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_GPU_Top                 = [!SetVariable Pad_Bottom_GPU_Top "#Default_Pad_Bottom_GPU_Top#"][!WriteKeyValue Variables Pad_Bottom_GPU_Top "#Default_Pad_Bottom_GPU_Top#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_DIsk_Read_Top           = [!SetVariable Pad_Bottom_DIsk_Read_Top "#Default_Pad_Bottom_DIsk_Read_Top#"][!WriteKeyValue Variables Pad_Bottom_DIsk_Read_Top "#Default_Pad_Bottom_DIsk_Read_Top#" "#@#\#Config#"]
 SET_DEFAULT_Pad_Bottom_Logs                    = [!SetVariable Pad_Bottom_Logs "#Default_Pad_Bottom_Logs#"][!WriteKeyValue Variables Pad_Bottom_Logs "#Default_Pad_Bottom_Logs#" "#@#\#Config#"]

; Triangle mechanics

 SET_DEFAULT_Triangle_Top_Mechanic              = [!SetVariable Triangle_Top_Mechanic "#Default_Triangle_Top_Mechanic#"][!WriteKeyValue Variables Triangle_Top_Mechanic "#Default_Triangle_Top_Mechanic#" "#@#\#Config#"]
 SET_DEFAULT_Triangle_Bottom_Mechanic           = [!SetVariable Triangle_Bottom_Mechanic "#Default_Triangle_Bottom_Mechanic#"][!WriteKeyValue Variables Triangle_Bottom_Mechanic "#Default_Triangle_Bottom_Mechanic#" "#@#\#Config#"]
 SET_DEFAULT_Triangle_Left_Mechanic             = [!SetVariable Triangle_Left_Mechanic "#Default_Triangle_Left_Mechanic#"][!WriteKeyValue Variables Triangle_Left_Mechanic "#Default_Triangle_Left_Mechanic#" "#@#\#Config#"]
 SET_DEFAULT_Triangle_Right_Mechanic            = [!SetVariable Triangle_Right_Mechanic "#Default_Triangle_Right_Mechanic#"][!WriteKeyValue Variables Triangle_Right_Mechanic "#Default_Triangle_Right_Mechanic#" "#@#\#Config#"]

; Section states

 SET_DEFAULT_CPU_Top_State                      = [!SetVariable CPU_Top_State "#Default_CPU_Top_State#"][!WriteKeyValue Variables CPU_Top_State "#Default_CPU_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Top_State                      = [!SetVariable GPU_Top_State "#Default_GPU_Top_State#"][!WriteKeyValue Variables GPU_Top_State "#Default_GPU_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_CPU_Info_State                     = [!SetVariable CPU_Info_State "#Default_CPU_Info_State#"][!WriteKeyValue Variables CPU_Info_State "#Default_CPU_Info_State#" "#@#\#Config#"]
 SET_DEFAULT_GPU_Info_State                     = [!SetVariable GPU_Info_State "#Default_GPU_Info_State#"][!WriteKeyValue Variables GPU_Info_State "#Default_GPU_Info_State#" "#@#\#Config#"]
 SET_DEFAULT_RAM_Top_State                      = [!SetVariable RAM_Top_State "#Default_RAM_Top_State#"][!WriteKeyValue Variables RAM_Top_State "#Default_RAM_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_VRAM_Top_State                     = [!SetVariable VRAM_Top_State "#Default_VRAM_Top_State#"][!WriteKeyValue Variables VRAM_Top_State "#Default_VRAM_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_Threads_State                      = [!SetVariable Threads_State "#Default_Threads_State#"][!WriteKeyValue Variables Threads_State "#Default_Threads_State#" "#@#\#Config#"]
 SET_DEFAULT_Throttling_State                   = [!SetVariable Throttling_State "#Default_Throttling_State#"][!WriteKeyValue Variables Throttling_State "#Default_Throttling_State#" "#@#\#Config#"]
 SET_DEFAULT_Clock_Info_State                   = [!SetVariable Clock_Info_State "#Default_Clock_Info_State#"][!WriteKeyValue Variables Clock_Info_State "#Default_Clock_Info_State#" "#@#\#Config#"]
 SET_DEFAULT_Power_Limit_State                  = [!SetVariable Power_Limit_State "#Default_Power_Limit_State#"][!WriteKeyValue Variables Power_Limit_State "#Default_Power_Limit_State#" "#@#\#Config#"]
 SET_DEFAULT_Disk_Read_Top_State                = [!SetVariable Disk_Read_Top_State "#Default_Disk_Read_Top_State#"][!WriteKeyValue Variables Disk_Read_Top_State "#Default_Disk_Read_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_Disk_Write_Top_State               = [!SetVariable Disk_Write_Top_State "#Default_Disk_Write_Top_State#"][!WriteKeyValue Variables Disk_Write_Top_State "#Default_Disk_Write_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_Debug_State                        = [!SetVariable Debug_State "#Default_Debug_State#"][!WriteKeyValue Variables Debug_State "#Default_Debug_State#" "#@#\#Config#"]

 SET_DEFAULT_Logs_Bottom_State                  = [!SetVariable Logs_Bottom_State "#Default_Logs_Bottom_State#"][!WriteKeyValue Variables Logs_Bottom_State "#Default_Logs_Bottom_State#" "#@#\#Config#"]
 SET_DEFAULT_Logs_Top_State                     = [!SetVariable Logs_Top_State "#Default_Logs_Top_State#"][!WriteKeyValue Variables Logs_Top_State "#Default_Logs_Top_State#" "#@#\#Config#"]
 SET_DEFAULT_Disk_Left_Side_State               = [!SetVariable Disk_Left_Side_State "#Default_Disk_Left_Side_State#"][!WriteKeyValue Variables Disk_Left_Side_State "#Default_Disk_Left_Side_State#" "#@#\#Config#"]
 SET_DEFAULT_Calculator_State                   = [!SetVariable Calculator_State "#Default_Calculator_State#"][!WriteKeyValue Variables Calculator_State "#Default_Calculator_State#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_Control_Static_State    = [!SetVariable App_Volume_Control_Static_State "#Default_App_Volume_Control_Static_State#"][!WriteKeyValue Variables App_Volume_Control_Static_State "#Default_App_Volume_Control_Static_State#" "#@#\#Config#"]
 SET_DEFAULT_App_Volume_Control_Dyna_State      = [!SetVariable App_Volume_Control_Dyna_State "#Default_App_Volume_Control_Dyna_State#"][!WriteKeyValue Variables App_Volume_Control_Dyna_State "#Default_App_Volume_Control_Dyna_State#" "#@#\#Config#"]
 SET_DEFAULT_Pallete_State                      = [!SetVariable Pallete_State "#Default_Pallete_State#"][!WriteKeyValue Variables Pallete_State "#Default_Pallete_State#" "#@#\#Config#"]
 SET_DEFAULT_Clock_And_Date_State               = [!SetVariable Clock_And_Date_State "#Default_Clock_And_Date_State#"][!WriteKeyValue Variables Clock_And_Date_State "#Default_Clock_And_Date_State#" "#@#\#Config#"]

; Player states

 SET_DEFAULT_Player_1_Artist_Title_State        = [!SetVariable Player_1_Artist_Title_State "#Default_Player_1_Artist_Title_State#"][!WriteKeyValue Variables Player_1_Artist_Title_State "#Default_Player_1_Artist_Title_State#" "#@#\#Config#"]
 SET_DEFAULT_Player_1_Shuffle_State             = [!SetVariable Player_1_Shuffle_State "#Default_Player_1_Shuffle_State#"][!WriteKeyValue Variables Player_1_Shuffle_State "#Default_Player_1_Shuffle_State#" "#@#\#Config#"]
 SET_DEFAULT_Player_1_Repeat_State              = [!SetVariable Draggable "#Default_Player_1_Repeat_State#"][!WriteKeyValue Variables Player_1_Repeat_State "#Default_Player_1_Repeat_State#" "#@#\#Config#"]
 SET_DEFAULT_Player_2_Artist_Title_State        = [!SetVariable Player_2_Artist_Title_State "#Default_Player_2_Artist_Title_State#"][!WriteKeyValue Variables Player_2_Artist_Title_State "#Default_Player_2_Artist_Title_State#" "#@#\#Config#"]
 SET_DEFAULT_Player_2_Shuffle_State             = [!SetVariable Player_2_Shuffle_State "#Default_Player_2_Shuffle_State#"][!WriteKeyValue Variables Player_2_Shuffle_State "#Default_Player_2_Shuffle_State#" "#@#\#Config#"]
 SET_DEFAULT_Player_2_Repeat_State              = [!SetVariable Player_2_Repeat_State "#Default_Player_2_Repeat_State#"][!WriteKeyValue Variables Player_2_Repeat_State "#Default_Player_2_Repeat_State#" "#@#\#Config#"]

; Menu variables

 SET_DEFAULT_Settings_Menu                      = [!SetVariable Settings_Menu "#Default_Settings_Menu#"][!WriteKeyValue Variables Settings_Menu "#Default_Settings_Menu#" "#@#\#Config#"]
 SET_DEFAULT_Aurora_BG_Behaviour_State          = [!SetVariable Aurora_BG_Behaviour_State "#Default_Aurora_BG_Behaviour_State#"][!WriteKeyValue Variables Aurora_BG_Behaviour_State "#Default_Aurora_BG_Behaviour_State#" "#@#\#Config#"]

 SET_DEFAULT_Settings_Main                      = [!SetVariable Settings_Main "#Default_Settings_Main#"][!WriteKeyValue Variables Settings_Main "#Default_Settings_Main#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Color                     = [!SetVariable Settings_Color "#Default_Settings_Color#"][!WriteKeyValue Variables Settings_Color "#Default_Settings_Color#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Hardware                  = [!SetVariable Settings_Hardware "#Default_Settings_Hardware#"][!WriteKeyValue Variables Settings_Hardware "#Default_Settings_Hardware#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Behaviour                 = [!SetVariable Settings_Behaviour "#Default_Settings_Behaviour#"][!WriteKeyValue Variables Settings_Behaviour "#Default_Settings_Behaviour#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Close                     = [!SetVariable Settings_Close "#Default_Settings_Close#"][!WriteKeyValue Variables Settings_Close "#Default_Settings_Close#" "#@#\#Config#"]

 SET_DEFAULT_Settings_Main_Temp                 = [!SetVariable Settings_Main_Temp "#Default_Settings_Main_Temp#"][!WriteKeyValue Variables Settings_Main_Temp "#Default_Settings_Main_Temp#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Color_Temp                = [!SetVariable Settings_Color_Temp "#Default_Settings_Color_Temp#"][!WriteKeyValue Variables Settings_Color_Temp "#Default_Settings_Color_Temp#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Hardware_Temp             = [!SetVariable Settings_Hardware_Temp "#Default_Settings_Hardware_Temp#"][!WriteKeyValue Variables Settings_Hardware_Temp "#Default_Settings_Hardware_Temp#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Behaviour_Temp            = [!SetVariable Settings_Behaviour_Temp "#Default_Settings_Behaviour_Temp#"][!WriteKeyValue Variables Settings_Behaviour_Temp "#Default_Settings_Behaviour_Temp#" "#@#\#Config#"]
 SET_DEFAULT_Settings_Temp_Control              = [!SetVariable Settings_Temp_Control "#Default_Settings_Temp_Control#"][!WriteKeyValue Variables Settings_Temp_Control "#Default_Settings_Temp_Control#" "#@#\#Config#"]

; --- COLORS

 SET_DEFAULT_R_Color                            = [!SetVariable R_Color "#Default_R_Color#"][!WriteKeyValue Variables R_Color "#Default_R_Color#" "#@#\#Config#"]
 SET_DEFAULT_G_Color                            = [!SetVariable G_Color "#Default_G_Color#"][!WriteKeyValue Variables G_Color "#Default_G_Color#" "#@#\#Config#"]
 SET_DEFAULT_B_Color                            = [!SetVariable B_Color "#Default_B_Color#"][!WriteKeyValue Variables B_Color "#Default_B_Color#" "#@#\#Config#"]
 SET_DEFAULT_A_Color                            = [!SetVariable A_Color "#Default_A_Color#"][!WriteKeyValue Variables A_Color "#Default_A_Color#" "#@#\#Config#"]

 SET_DEFAULT_RGB_Color                          = [!SetVariable RGB_Color "#Default_RGB_Color#"][!WriteKeyValue Variables RGB_Color "#Default_RGB_Color#" "#@#\#Config#"]
 SET_DEFAULT_RGB_Font_Color                     = [!SetVariable RGB_Font_Color "#Default_RGB_Font_Color#"][!WriteKeyValue Variables RGB_Font_Color "#Default_RGB_Font_Color#" "#@#\#Config#"]
 SET_DEFAULT_RGB_Font_Warning_Color             = [!SetVariable RGB_Font_Warning_Color "#Default_RGB_Font_Warning_Color#"][!WriteKeyValue Variables RGB_Font_Warning_Color "#Default_RGB_Font_Warning_Color#" "#@#\#Config#"]
 SET_DEFAULT_Global_Color                       = [!SetVariable Global_Color "#Default_Global_Color#"][!WriteKeyValue Variables Global_Color "#Default_Global_Color#" "#@#\#Config#"]
 SET_DEFAULT_Bar_Color                          = [!SetVariable Bar_Color "#Default_Bar_Color#"][!WriteKeyValue Variables Bar_Color "#Default_Bar_Color#" "#@#\#Config#"]
 SET_DEFAULT_Bar_BG_Color                       = [!SetVariable Bar_BG_Color "#Default_Bar_BG_Color#"][!WriteKeyValue Variables Bar_BG_Color "#Default_Bar_BG_Color#" "#@#\#Config#"]
 
 SET_DEFAULT_BG_Color                           = [!SetVariable BG_Color "#Default_BG_Color#"][!WriteKeyValue Variables BG_Color "#Default_BG_Color#" "#@#\#Config#"]

 SET_DEFAULT_Font_Color                         = [!SetVariable Font_Color "#Default_Font_Color#"][!WriteKeyValue Variables Font_Color "#Default_Font_Color#" "#@#\#Config#"]
 SET_DEFAULT_Font_Value_Color                   = [!SetVariable Font_Value_Color "#Default_Font_Value_Color#"][!WriteKeyValue Variables Font_Value_Color "#Default_Font_Value_Color#" "#@#\#Config#"]
 SET_DEFAULT_Font_Warning_Color                 = [!SetVariable Font_Warning_Color "#Default_Font_Warning_Color#"][!WriteKeyValue Variables Font_Warning_Color "#Default_Font_Warning_Color#" "#@#\#Config#"]

 SET_DEFAULT_Global_Alpha                       = [!SetVariable Global_Alpha "#Default_Global_Alpha#"][!WriteKeyValue Variables Global_Alpha "#Default_Global_Alpha#" "#@#\#Config#"]
 SET_DEFAULT_Font_Alpha                         = [!SetVariable Font_Alpha "#Default_Font_Alpha#"][!WriteKeyValue Variables Font_Alpha "#Default_Font_Alpha#" "#@#\#Config#"]
 SET_DEFAULT_Pallete_Alpha                      = [!SetVariable Pallete_Alpha "#Default_Pallete_Alpha#"][!WriteKeyValue Variables Pallete_Alpha "#Default_Pallete_Alpha#" "#@#\#Config#"]
 SET_DEFAULT_Bar_BG_Alpha                       = [!SetVariable Bar_BG_Alpha "#Default_Bar_BG_Alpha#"][!WriteKeyValue Variables Bar_BG_Alpha "#Default_Bar_BG_Alpha#" "#@#\#Config#"]

 SET_DEFAULT_Last_Global_Color                  = [!SetVariable Last_Global_Color "#Default_Last_Global_Color#"][!WriteKeyValue Variables Last_Global_Color "#Default_Last_Global_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_Bar_Color                     = [!SetVariable Last_Bar_Color "#Default_Last_Bar_Color#"][!WriteKeyValue Variables Last_Bar_Color "#Default_Last_Bar_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_BG_Color                      = [!SetVariable Last_BG_Color "#Default_Last_BG_Color#"][!WriteKeyValue Variables Last_BG_Color "#Default_Last_BG_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_RGB_Color                     = [!SetVariable Last_RGB_Color "#Default_Last_RGB_Color#"][!WriteKeyValue Variables Last_RGB_Color "#Default_Last_RGB_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_RGB_Font_Color                = [!SetVariable Last_RGB_Font_Color "#Default_Last_RGB_Font_Color#"][!WriteKeyValue Variables Last_RGB_Font_Color "#Default_Last_RGB_Font_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_Font_Color                    = [!SetVariable Last_Font_Color "#*Default_Last_Font_Color*#"][!WriteKeyValue Variables Last_Font_Color "#*Default_Last_Font_Color*#" "#@#\#Config#"]
 SET_DEFAULT_Last_Value_Color                   = [!SetVariable Last_Value_Color "#Default_Last_Value_Color#"][!WriteKeyValue Variables Last_Value_Color "#Default_Last_Value_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_Warning_Color                 = [!SetVariable Last_Warning_Color "#Default_Last_Warning_Color#"][!WriteKeyValue Variables Last_Warning_Color "#Default_Last_Warning_Color#" "#@#\#Config#"]
 SET_DEFAULT_Last_FontColor                     = [!SetVariable Last_FontColor "#Default_Last_FontColor#"][!WriteKeyValue Variables Last_FontColor "#Default_Last_FontColor#" "#@#\#Config#"]
 SET_DEFAULT_Last_Font_Size                     = [!SetVariable Last_Font_Size "#Default_Last_Font_Size#"][!WriteKeyValue Variables Last_Font_Size "#Default_Last_Font_Size#" "#@#\#Config#"]

; --- MAIN FONTS

 SET_DEFAULT_FontColor                          = [!SetVariable FontColor "#Default_FontColor#"][!WriteKeyValue Variables Last_FontColor "#Default_FontColor#" "#@#\#Config#"]
 SET_DEFAULT_Font_Size                          = [!SetVariable Font_Size "#Default_Font_Size#"][!WriteKeyValue Variables Last_Font_Size "#Default_Font_Size#" "#@#\#Config#"]
 SET_DEFAULT_Font_Size_Small                    = [!SetVariable Font_Size_Small "#Default_Font_Size_Small#"][!WriteKeyValue Variables Font_Size_Small "#Default_Font_Size_Small#" "#@#\#Config#"]
 SET_DEFAULT_Faded_Font_Size_Small              = [!SetVariable Faded_Font_Size_Small "#Default_Faded_Font_Size_Small#"][!WriteKeyValue Variables Faded_Font_Size_Small "#Default_Faded_Font_Size_Small#" "#@#\#Config#"]
 SET_DEFAULT_Font                               = [!SetVariable Font "#Default_Font#"][!WriteKeyValue Variables Font "#Default_Font#" "#@#\#Config#"]
 SET_DEFAULT_Bold_Font                          = [!SetVariable Bold_Font "#Default_Bold_Font#"][!WriteKeyValue Variables Bold_Font "#Default_Bold_Font#" "#@#\#Config#"]
 SET_DEFAULT_String_Style                       = [!SetVariable String_Style "#Default_String_Style#"][!WriteKeyValue Variables String_Style "#Default_String_Style#" "#@#\#Config#"]
 SET_DEFAULT_T_String_Style                     = [!SetVariable T_String_Style "#Default_T_String_Style#"][!WriteKeyValue Variables T_String_Style "#Default_T_String_Style#" "#@#\#Config#"]

; --- TIME FONTS

 SET_DEFAULT_Time_Font_Main                     = [!SetVariable Time_Font_Main "#Default_Time_Font_Main#"][!WriteKeyValue Variables Time_Font_Main "#Default_Time_Font_Main#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Day                 = [!SetVariable Time_Font_Size_Day "#Default_Time_Font_Size_Day#"][!WriteKeyValue Variables Time_Font_Size_Day "#Default_Time_Font_Size_Day#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Cday                = [!SetVariable Time_Font_Size_Cday "#Default_Time_Font_Size_Cday#"][!WriteKeyValue Variables Time_Font_Size_Cday "#Default_Time_Font_Size_Cday#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Color_Main               = [!SetVariable Time_Font_Color_Main "#Default_Time_Font_Color_Main#"][!WriteKeyValue Variables Time_Font_Color_Main "#Default_Time_Font_Color_Main#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Color_Hours              = [!SetVariable Time_Font_Color_Hours "#Default_Time_Font_Color_Hours#"][!WriteKeyValue Variables Time_Font_Color_Hours "#Default_Time_Font_Color_Hours#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Color_Mins               = [!SetVariable Time_Font_Color_Mins "#Default_Time_Font_Color_Mins#"][!WriteKeyValue Variables Time_Font_Color_Mins "#Default_Time_Font_Color_Mins#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Main                = [!SetVariable Time_Font_Size_Main "#Default_Time_Font_Size_Main#"][!WriteKeyValue Variables Time_Font_Size_Main "#Default_Time_Font_Size_Main#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Hours               = [!SetVariable Time_Font_Size_Hours "#Default_Time_Font_Size_Hours#"][!WriteKeyValue Variables Time_Font_Size_Hours "#Default_Time_Font_Size_Hours#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Mins                = [!SetVariable Time_Font_Size_Mins "#Default_Time_Font_Size_Mins#"][!WriteKeyValue Variables Time_Font_Size_Mins "#Default_Time_Font_Size_Mins#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Secs                = [!SetVariable Time_Font_Size_Secs "#Default_Time_Font_Size_Secs#"][!WriteKeyValue Variables Time_Font_Size_Secs "#Default_Time_Font_Size_Secs#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Date                = [!SetVariable Time_Font_Size_Date "#Default_Time_Font_Size_Date#"][!WriteKeyValue Variables Time_Font_Size_Date "#Default_Time_Font_Size_Date#" "#@#\#Config#"]
 SET_DEFAULT_Time_Font_Size_Year                = [!SetVariable Time_Font_Size_Year "#Default_Time_Font_Size_Year#"][!WriteKeyValue Variables Time_Font_Size_Year "#Default_Time_Font_Size_Year#" "#@#\#Config#"]

; --- CURSORS

 SET_DEFAULT_Cursors_Set                        = [!SetVariable Cursors_Set "#Default_Cursors_Set#"][!WriteKeyValue Variables Cursors_Set "#Default_Cursors_Set#" "#@#\#Config#"]
 SET_DEFAULT_Cursor_Slider_X                    = [!SetVariable Cursor_Slider_X "#Default_Cursor_Slider_X#"][!WriteKeyValue Variables Cursor_Slider_X "#Default_Cursor_Slider_X#" "#@#\#Config#"]
 SET_DEFAULT_Cursor_Slider_Y                    = [!SetVariable Cursor_Slider_Y "#Default_Cursor_Slider_Y#"][!WriteKeyValue Variables Cursor_Slider_Y "#Default_Cursor_Slider_Y#" "#@#\#Config#"]
 SET_DEFAULT_Cursor_Slider_XY                   = [!SetVariable Cursor_Slider_XY "#Default_Cursor_Slider_XY#"][!WriteKeyValue Variables Cursor_Slider_XY "#Default_Cursor_Slider_XY#" "#@#\#Config#"]
 SET_DEFAULT_Cursor_Hand                        = [!SetVariable Cursor_Hand "#Default_Cursor_Hand#"][!WriteKeyValue Variables Cursor_Hand "#Default_Cursor_Hand#" "#@#\#Config#"]

 SET_DEFAULT                                    = #SET_DEFAULT_Frosted_Glass_State#   #SET_DEFAULT_Translucent_State#   #SET_DEFAULT_ToolTips_State#   #SET_DEFAULT_Sounds_State#   #SET_DEFAULT_Update_Rate#   #SET_DEFAULT_Cycles_2nd_Divider#   #SET_DEFAULT_Cycles_3rd_Divider#   #SET_DEFAULT_Default_Divider_Negative_Meter#   #SET_DEFAULT_Default_Divider_Negative_Measure#   #SET_DEFAULT_Default_Delay_x2#   #SET_DEFAULT_Default_Delay_x3#   #SET_DEFAULT_Default_DV_Main#   #SET_DEFAULT_Player_Name#   #SET_DEFAULT_Player_Selection#   #SET_DEFAULT_Player_State#   #SET_DEFAULT_Player_Position_Step#   #SET_DEFAULT_Position_Forward#   #SET_DEFAULT_Position_Backward#   #SET_DEFAULT_Sys_Volume_Step#   #SET_DEFAULT_Sys_Volume_Down#   #SET_DEFAULT_Sys_Volume_Up#   #SET_DEFAULT_Player_Volume_Step#   #SET_DEFAULT_Player_Volume_Down#   #SET_DEFAULT_Player_Volume_Up#   #SET_DEFAULT_App_Volume_1S#   #SET_DEFAULT_App_Volume_2S#   #SET_DEFAULT_App_Volume_3S#   #SET_DEFAULT_App_Volume_4S#   #SET_DEFAULT_App_Volume_1#   #SET_DEFAULT_App_Volume_2#   #SET_DEFAULT_App_Volume_3#   #SET_DEFAULT_App_Volume_4#   #SET_DEFAULT_Net_Max#   #SET_DEFAULT_Ping_Max#   #SET_DEFAULT_Ping_Timeout#   #SET_DEFAULT_Ping_Host#   #SET_DEFAULT_Ping_App_1#   #SET_DEFAULT_Drive_One#   #SET_DEFAULT_Drive_Two#   #SET_DEFAULT_Temp_Folder#   #SET_DEFAULT_Cache_Folder#   #SET_DEFAULT_CPU_Load_Max#   #SET_DEFAULT_GPU_Load_Max#   #SET_DEFAULT_CPU_Temp_Max#   #SET_DEFAULT_GPU_Temp_Max#   #SET_DEFAULT_Bluetooth_State#   #SET_DEFAULT_Bluetooth_Visible#   #SET_DEFAULT_Audio_Devices_State#   #SET_DEFAULT_VRAM_Instance_State#   #SET_DEFAULT_Window_X#   #SET_DEFAULT_Window_Y#   #SET_DEFAULT_Anchor_X#   #SET_DEFAULT_Anchor_Y#   #SET_DEFAULT_Monitor_Num#   #SET_DEFAULT_Monitor#   #SET_DEFAULT_Skin_Alpha#   #SET_DEFAULT_Skin_Zpos#   #SET_DEFAULT_Last_Zpos#   #SET_DEFAULT_Draggable#   #SET_DEFAULT_Snapedge#   #SET_DEFAULT_Keep_On_Screen#   #SET_DEFAULT_CPU_Histogram_Width#   #SET_DEFAULT_CPU_Histogram_X#   #SET_DEFAULT_GPU_Histogram_Width#   #SET_DEFAULT_GPU_Histogram_X#   #SET_DEFAULT_Pad_Top#   #SET_DEFAULT_Pad_X_Wings_Left#   #SET_DEFAULT_Pad_X_Wings_Right#   #SET_DEFAULT_Height_State_One#   #SET_DEFAULT_Height_State_Two#   #SET_DEFAULT_Height_State_Three#   #SET_DEFAULT_Height_State_Four#   #SET_DEFAULT_Height_State_Five#   #SET_DEFAULT_Height_State_Six#   #SET_DEFAULT_Pad_Bottom_VRAM_Top#   #SET_DEFAULT_Pad_Bottom_CPU_Top#   #SET_DEFAULT_Pad_Bottom_Throttling#   #SET_DEFAULT_Pad_Bottom_Power_Limit#   #SET_DEFAULT_Pad_Bottom_GPU_Top#   #SET_DEFAULT_Pad_Bottom_DIsk_Read_Top#   #SET_DEFAULT_Pad_Bottom_Logs#   #SET_DEFAULT_Triangle_Top_Mechanic#   #SET_DEFAULT_Triangle_Bottom_Mechanic#   #SET_DEFAULT_Triangle_Left_Mechanic#   #SET_DEFAULT_Triangle_Right_Mechanic#   #SET_DEFAULT_CPU_Top_State#   #SET_DEFAULT_GPU_Top_State#   #SET_DEFAULT_CPU_Info_State#   #SET_DEFAULT_GPU_Info_State#   #SET_DEFAULT_RAM_Top_State#   #SET_DEFAULT_VRAM_Top_State#   #SET_DEFAULT_Threads_State#   #SET_DEFAULT_Throttling_State#   #SET_DEFAULT_Clock_Info_State#   #SET_DEFAULT_Power_Limit_State#   #SET_DEFAULT_Disk_Read_Top_State#   #SET_DEFAULT_Disk_Write_Top_State#   #SET_DEFAULT_Debug_State#   #SET_DEFAULT_Logs_Bottom_State#   #SET_DEFAULT_Logs_Top_State#   #SET_DEFAULT_Disk_Left_Side_State#   #SET_DEFAULT_Calculator_State#   #SET_DEFAULT_App_Volume_Control_Static_State#   #SET_DEFAULT_App_Volume_Control_Dyna_State#   #SET_DEFAULT_Pallete_State#   #SET_DEFAULT_Clock_And_Date_State#   #SET_DEFAULT_Player_1_Artist_Title_State#   #SET_DEFAULT_Player_1_Shuffle_State#   #SET_DEFAULT_Player_1_Repeat_State#   #SET_DEFAULT_Player_2_Artist_Title_State#   #SET_DEFAULT_Player_2_Shuffle_State#   #SET_DEFAULT_Player_2_Repeat_State#   #SET_DEFAULT_Settings_Menu#   #SET_DEFAULT_Aurora_BG_Behaviour_State#   #SET_DEFAULT_Settings_Main#   #SET_DEFAULT_Settings_Color#   #SET_DEFAULT_Settings_Hardware#   #SET_DEFAULT_Settings_Behaviour#   #SET_DEFAULT_Settings_Close#   #SET_DEFAULT_Settings_Main_Temp#   #SET_DEFAULT_Settings_Color_Temp#   #SET_DEFAULT_Settings_Hardware_Temp#   #SET_DEFAULT_Settings_Behaviour_Temp#   #SET_DEFAULT_Settings_Temp_Control#   #SET_DEFAULT_R_Color#   #SET_DEFAULT_G_Color#   #SET_DEFAULT_B_Color#   #SET_DEFAULT_A_Color#   #SET_DEFAULT_RGB_Color#   #SET_DEFAULT_RGB_Font_Color#   #SET_DEFAULT_RGB_Font_Warning_Color#   #SET_DEFAULT_Global_Color#   #SET_DEFAULT_Bar_Color#   #SET_DEFAULT_Bar_BG_Color#   #SET_DEFAULT_BG_Color#   #SET_DEFAULT_Font_Color#   #SET_DEFAULT_Font_Value_Color#   #SET_DEFAULT_Font_Warning_Color#   #SET_DEFAULT_Global_Alpha#   #SET_DEFAULT_Font_Alpha#   #SET_DEFAULT_Pallete_Alpha#   #SET_DEFAULT_Bar_BG_Alpha#   #SET_DEFAULT_Last_Global_Color#   #SET_DEFAULT_Last_Bar_Color#   #SET_DEFAULT_Last_BG_Color#   #SET_DEFAULT_Last_RGB_Color#   #SET_DEFAULT_Last_RGB_Font_Color#   #SET_DEFAULT_Last_Font_Color#   #SET_DEFAULT_Last_Value_Color#   #SET_DEFAULT_Last_Warning_Color#   #SET_DEFAULT_Last_FontColor#   #SET_DEFAULT_Last_Font_Size#   #SET_DEFAULT_FontColor#   #SET_DEFAULT_Font_Size#   #SET_DEFAULT_Font_Size_Small#   #SET_DEFAULT_Faded_Font_Size_Small#   #SET_DEFAULT_Font#   #SET_DEFAULT_Bold_Font#   #SET_DEFAULT_String_Style#   #SET_DEFAULT_T_String_Style#   #SET_DEFAULT_Time_Font_Main#   #SET_DEFAULT_Time_Font_Size_Day#   #SET_DEFAULT_Time_Font_Size_Cday#   #SET_DEFAULT_Time_Font_Color_Main#   #SET_DEFAULT_Time_Font_Color_Hours#   #SET_DEFAULT_Time_Font_Color_Mins#   #SET_DEFAULT_Time_Font_Size_Main#   #SET_DEFAULT_Time_Font_Size_Hours#   #SET_DEFAULT_Time_Font_Size_Mins#   #Time_Font_Size_Secs#   #Time_Font_Size_Date#   #Time_Font_Size_Year#   #SET_DEFAULT_Cursors_Set#   #SET_DEFAULT_Cursor_Slider_X#   #SET_DEFAULT_Cursor_Slider_Y#   #SET_DEFAULT_Cursor_Slider_XY#   #SET_DEFAULT_Cursor_Hand#   [!Delay 2000][!Refresh]
