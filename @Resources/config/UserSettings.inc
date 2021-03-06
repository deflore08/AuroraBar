[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
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

 Update_Rate                      =16
 Cycles_2nd_Divider               =3
 Cycles_3rd_Divider               =2
 Divider_Negative_Meter           =0
 Divider_Negative_Measure         =-1
 Delay_x2                         =(#Update_Rate# * 2)
 Delay_x3                         =(#Update_Rate# * 3)
 DV_Main                          =1

; - Volume

; - #Player_Selection# sets player name depending on it's value from 1 to 8. (1 = AIMP; 2 = CAD; 3 = iTunes; 4 = MediaMonkey; 5 = Winamp; 6 = WMP; 7 = Spotify; 8 = WLM)

 Player_Name                      =AIMP
 Player_Selection                 =1
 Player_State                     =0

; - Player Positions steps

 Player_Position_Step             =5

; - Volume control steps

 Sys_Volume_Step                  =5
 Player_Volume_Step               =5

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
 Ping_App_1                       =ping -t #Ping_Host#

; - Drives

 Drive_One                        =C:
 Drive_Two                        =D:
 Temp_Folder                      =C:\Users\Mi\AppData\Local\Temp
 Cache_Folder                     =C:\Users\Mi\AppData\Local\Packages\Microsoft.MicrosoftEdge_8wekyb3d8bbwe\LocalCache

; - Limits
 
 CPU_Load_Max                     =80
 GPU_Load_Max                     =70
 CPU_Temp_Max                     =75
 GPU_Temp_Max                     =65

; - Other HW

 Bluetooth_State                 = 0
 Bluetooth_Visible               =1
 Audio_Devices_State             =1
 VRAM_Instance_State             =0

; --- BEHAVIOUR ---

 Window_X                         =0
 Window_Y                         =540
 Anchor_X                         =0
 Anchor_Y                         =50

 Monitor_Num                      =1
 Monitor                          =@#Monitor_Num#
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

 Pad_Top                         = 0
 Pad_X_Wings_Left                = 
 Pad_X_Wings_Right               =

; --- HEIGHT variables

; - #Height_State_One(1-6)# contains an unique value from 0 to 7. It needs to calculate HEIGHT mechanic (it's about TOP) in a formulas below

 Height_State_One                =0
 Height_State_Two                =0
 Height_State_Three              =0
 Height_State_Four               =0
 Height_State_Five               =0
 Height_State_Six                =0

; - #Pad_Bottom_N# defines a Y position for elements below BG. If it's hided, it will 112px. 

 Pad_Bottom_VRAM_Top             = 112
 Pad_Bottom_CPU_Top              = 112
 Pad_Bottom_Throttling           = 112
 Pad_Bottom_Power_Limit          = 112
 Pad_Bottom_GPU_Top              = 112
 Pad_Bottom_Disk_Read_Top        = 112
 Pad_Bottom_Logs                 = 112

; --- TRIANGLE mechanics determines behaviour of 4 triangles from all sides

 Triangle_Top_Mechanic           =1
 Triangle_Bottom_Mechanic        = 0
 Triangle_Left_Mechanic          =0
 Triangle_Right_Mechanic         =0

; --- SECTIONS STATES

 CPU_Top_State                   =1
 GPU_Top_State                   =1  
 CPU_Info_State                  =1 
 GPU_Info_State                  =1 
 RAM_Top_State                   =1
 VRAM_Top_State                  =1 
 Threads_State                   =1 
 Throttling_State                =1 
 Clock_Info_State                =1 
 Power_Limit_State               =1 
 Disk_Read_Top_State             =1 
 Disk_Write_Top_State            =1 
 Debug_State                     =1

 Logs_Bottom_State               =1
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

 Settings_Main                   =1
 Settings_Color                  =1
 Settings_Hardware               =1
 Settings_Behaviour              =1
 Settings_Close                  = 1

; - "Temporary" variables that controls switcher between main texts and menu texts

 Settings_Main_Temp              = 1
 Settings_Color_Temp             = 1
 Settings_Hardware_Temp          = 1
 Settings_Behaviour_Temp         = 1

; - #Settings_Temp_Control# controls [f.Temp_Vars_State] formula

 Settings_Temp_Control           =1

; --- DEPRECATED

; Drive_One_Min_Read               = 0
; Drive_One_Max_Read               = 3221225472
; Drive_One_Min_Write              = 0
; Drive_One_Max_Write              = 1610612736

; Drive_Two_Min_Read               = 0
; Drive_Two_Max_Read               = 134217728
; Drive_Two_Min_Write              = 0
; Drive_Two_Max_Write              = 67108864;

; --- COLORS ---

 R_Color                          = 
 G_Color                          = 
 B_Color                          = 
 A_Color                          = 

 RGB_Color                        =124, 12 , 239
 RGB_Font_Color                   =255, 255, 255
 RGB_Font_Warning_Color           = 
 Global_Color                     =#RGB_Color#, #Global_Alpha#
 Bar_Color                        =#Global_Color#
 Bar_BG_Color                     =#RGB_Color#, #Bar_BG_Alpha#

 BG_Color                         =0, 0, 0, 160

 Font_Color                       =0, 240 , 215, 255
 Font_Value_Color                 =0, 240, 117, 255
 Font_Warning_Color               =240, 24 , 222, 255 

 Global_Alpha                     =220
 Font_Alpha                       =255
 Pallete_Alpha                    =140
 Bar_BG_Alpha                     =50

; --- LAST COLORS

; - These vars force Aurora to remember current scheme

; - It needs for returning to your current scheme when mouse left out of a color buttons

 Last_Global_Color                =124, 12 , 239 
 Last_Bar_Color                   = 
 Last_BG_Color                    =124, 12 , 239
 Last_RGB_Color                   = 
 Last_RGB_Font_Color              =0, 240 , 215 
 Last_Font_Color                  =#Default_Last_Font_Color# 
 Last_Value_Color                 =0, 240, 117, 255 
 Last_Warning_Color               =240, 24 , 222
 Last_FontColor                   =#Font_Color#
 Last_Font_Size                   =10

; --- MAIN FONTS

 FontColor                        = #Font_Color#
 Font_Size                        = 10
 Font_Size_Small                  =7
 Faded_Font_Size_Small            =7
 Font                             =AGENCY FB
 Bold_Font                        =AGENCY FB
 String_Style                     =Normal
 T_String_Style                   =Normal

; --- TIME FONTS

 Time_Font_Main                   =BRETTON
 Time_Font_Size_Day               =15
 Time_Font_Size_Cday              =15
 Time_Font_Color_Main             =#Font_Color#
 Time_Font_Color_Hours            =#Font_Color#
 Time_Font_Color_Mins             =#Font_Color#
 Time_Font_Size_Main              =20
 Time_Font_Size_Hours             =40
 Time_Font_Size_Mins              =24
 Time_Font_Size_Secs              = 14
 Time_Font_Size_Date              = 15
 Time_Font_Size_Year              = 15

; --- CURSORS

 Cursors_Set                      =#Cursors_Set_Techno#

 Cursor_Slider_X                  =#Cursors_Set#\SizeWE.ani
 Cursor_Slider_Y                  =#Cursors_Set#\SizeNS.ani
 Cursor_Slider_XY                 =#Cursors_Set#\SizeAll.ani
 Cursor_Hand                      =#Cursors_Set#\Hand.ani
Position_Forward=+#Player_Position_Step#
Position_Backward=-#Player_Position_Step#
Sys_Volume_Down=-#Sys_Volume_Step#
Sys_Volume_Up=+#Sys_Volume_Step#
Player_Volume_Down=-#Player_Volume_Step#
Player_Volume_Up=+#Player_Volume_Step#
