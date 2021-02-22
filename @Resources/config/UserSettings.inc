[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = User-defined settings

[Variables]

; --- SETTINGS ---

; --- MAIN

; - Effects

 Frosted_Glass_State             =0
 Translucent_State               =1
 ToolTips_State                  =1
 Sounds_State                    =1

; - Updates

 Update_Rate                      = 16
 Cycles_2nd_Divider               = 3
 Cycles_3rd_Divider               =2
 Divider_Negative_Meter           =0
 Divider_Negative_Measure         =-1
 Delay_x2                         =32
 Delay_x3                         =48
 DV_Main                          =1

; - Volume

; - #Player_Selection# sets player name depending on it's value from 1 to 8. (1 = AIMP; 2 = CAD; 3 = iTunes; 4 = MediaMonkey; 5 = Winamp; 6 = WMP; 7 = Spotify; 8 = WLM)

 Player_Name                      =AIMP
 Player_Selection                 =1
 Player_State                     =0

; - Player Positions steps

 Player_Position_Step             =5
 Position_Forward                 =+5
 Position_Backward                =-5

; - Volume control steps

 Sys_Volume_Step                  =33
 Sys_Volume_Down                  =-5
 Sys_Volume_Up                    =+5

 Player_Volume_Step               = 5
 Player_Volume_Down               =-1
 Player_Volume_Up                 =+1

; - Applications

; App names to display

 App_Volume_1S                    =aimp
 App_Volume_2S                    =potplayer
 App_Volume_3S                    =discord
 App_Volume_4S                    =opera

; Full app names to control

 App_Volume_1                     =aimp.exe
 App_Volume_2                     =potplayermini64.exe
 App_Volume_3                     =discord.exe
 App_Volume_4                     =opera.exe

; --- HARDWARE

; - Network

 Net_Max                          =100
 Ping_Timeout                     =1000
 Ping_Max                         =100
 Ping_Host                        =8.8.8.8
 Ping_App_1                       =ping -t 8.8.8.8

; - Drives

 Drive_One                        =C:
 Drive_Two                        =D:
 Temp_Folder                      =C:\Users\Mi\AppData\Local\Temp
 Cache_Folder                     =C:\Users\Mi\AppData\Local\Packages\Microsoft.MicrosoftEdge_8wekyb3d8bbwe\LocalCache

; - Limits
 
 CPU_Load_Max                     =80
 GPU_Load_Max                     =70
 CPU_Temp_Max                     =75
 GPU_Temp_Max                     =20

; - Other HW

 Bluetooth_State                 = 1
 Bluetooth_Visible               =1
 Audio_Devices_State             =1
 VRAM_Instance_State             =0

; --- BEHAVIOUR ---

 Window_X                         =0
 Window_Y                         =540
 Anchor_X                         =0
 Anchor_Y                         =50

 Monitor_Num                      =4
 Monitor                          =@1
 Skin_Alpha                       =255

 Skin_Zpos                        =0
 Last_Zpos                        = 
 Draggable                        =1
 Snapedge                         =1
 Keep_On_Screen                   =1

; --- CPU & GPU HISTOGRAMS

 CPU_Histogram_Width             =300
 CPU_Histogram_X                 =512
 GPU_Histogram_Width             =300
 GPU_Histogram_X                 =1100

; --- STATE CONTROL ---

; - Attention: #Pad_Top# variable defines Y coordinate for eeeeeach element of Aurora.

; - Default value is "110". If your taskbar is on top of screen - you may use 150 and 140 (if icons is minimized) values to keep Aurora below taskbar. 

 Pad_Top                         = 110
 Pad_X_Wings_Left                = 
 Pad_X_Wings_Right               =

; --- HEIGHT variables

; - #Height_State_One(1-6)# contains an unique value from 0 to 7. It needs to calculate HEIGHT mechanic (it's about TOP) in a formulas below

 Height_State_One                = 2
 Height_State_Two                = 3
 Height_State_Three              = 6
 Height_State_Four               = 7
 Height_State_Five               = 5
 Height_State_Six                = 4

; - #Pad_Bottom_N# defines a Y position for elements below BG. If it's hided, it will 112px. 

 Pad_Bottom_VRAM_Top             = 0
 Pad_Bottom_CPU_Top              = 0
 Pad_Bottom_Throttling           = 0
 Pad_Bottom_Power_Limit          = 0
 Pad_Bottom_GPU_Top              = 0
 Pad_Bottom_Disk_Read_Top        = 0
 Pad_Bottom_Logs                 = 112

; --- TRIANGLE mechanics determines behaviour of 4 triangles from all sides

 Triangle_Top_Mechanic           = 0
 Triangle_Bottom_Mechanic        = 1
 Triangle_Left_Mechanic          = (1 - 1)
 Triangle_Right_Mechanic         = (1 - 1)

; --- SECTIONS STATES

 CPU_Top_State                   = 0
 GPU_Top_State                   = 0  
 CPU_Info_State                  = 0 
 GPU_Info_State                  = 0 
 RAM_Top_State                   = 0
 VRAM_Top_State                  = 0 
 Threads_State                   = 0 
 Throttling_State                = 0 
 Clock_Info_State                = 0 
 Power_Limit_State               = 0 
 Disk_Read_Top_State             = 0 
 Disk_Write_Top_State            = 0 
 Debug_State                     =1

 Logs_Bottom_State               = 1
 Logs_Top_State                  =0

 Disk_Left_Side_State            = 0
 Calculator_State                = 1

 App_Volume_Control_Static_State = 0
 App_Volume_Control_Dyna_State   = 1

 Pallete_State                   =1
 Clock_And_Date_State            = 0

; --- PLAYER STATES

 Player_1_Artist_Title_State     =1
 Player_1_Shuffle_State          =0
 Player_1_Repeat_State           = 0
 Player_2_Artist_Title_State     =0
 Player_2_Shuffle_State          =0
 Player_2_Repeat_State           =0


; --- MENU variables, important

; - #Settings_Menu# need to control menu buttons (crystal shapes) 

; - #Aurora_BG_Behaviour_State# determines BG MouseOver\Leave behaviour

 Settings_Menu                   = 0
 Aurora_BG_Behaviour_State       = 0

; - The next variables controls the menu bookmarks

; - #Settings_Close# it's about X (close) button

 Settings_Main                   = 1
 Settings_Color                  = 1
 Settings_Hardware               = 1
 Settings_Behaviour              = 1
 Settings_Close                  = 1

; - "Temporary" variables that controls switcher between main texts and menu texts

 Settings_Main_Temp              = 1
 Settings_Color_Temp             = 1
 Settings_Hardware_Temp          = 1
 Settings_Behaviour_Temp         = 1

; - #Settings_Temp_Control# controls [f.Temp_Vars_State] formula

 Settings_Temp_Control           = 1
Divider_Main=5

; --- DEPRECATED

; Drive_One_Min_Read               = 0
; Drive_One_Max_Read               = 3221225472
; Drive_One_Min_Write              = 0
; Drive_One_Max_Write              = 1610612736

; Drive_Two_Min_Read               = 0
; Drive_Two_Max_Read               = 134217728
; Drive_Two_Min_Write              = 0
; Drive_Two_Max_Write              = 67108864;
