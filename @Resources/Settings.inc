[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Settings module. Includes some meters and most variables to configure the skin.

; --- MEASURES BEGINNING

; --- HWINFO SHARED MEMORY VIEWER MEASURE

[m.HWiNFO_SMV]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Parameter                        = hwinfosmv.exe /rmskin="#@#\#Hardware#"
 StartInFolder                    = "#@#\executable\"

; --- BACKUPING AND RESTORING MEASURES

; - Local backups to #@#\backups\

; - Necessary for local short-term backups

[shell.BACKUP_CONFIG]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Config# -Destination #Backup_Config# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Config#
 FinishAction                     = [Play #Success_1#]

[shell.BACKUP_HARDWARE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Hardware# -Destination #Backup_Hardware# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Hardware#
 FinishAction                     = [Play #Success_1#]

[shell.BACKUP_HOTKEYS]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Hotkeys# -Destination #Backup_Hotkeys# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Hardware#
 FinishAction                     = [Play #Success_1#]

[shell.RESTORE_CONFIG]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Backup_Config# -Destination #@#\#Config# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Config#
 FinishAction                     = [Play #Success_2#]

[shell.RESTORE_HARDWARE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Backup_Hardware# -Destination #@#\#Hardware# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Hardware#
 FinishAction                     = [Play #Success_2#]

[shell.RESTORE_HOTKEYS]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #@#\#Backup_Hotkeys# -Destination #@#\#Hotkeys# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Hardware#
 FinishAction                     = [Play #Success_2#]

; --- HEALTH AND THREAT FORMULAS

[formula.CPU_HEALTH]
 Measure                          = CALC
 Formula                          = ( #CPU_Load_Health# + #CPU_Temp_Health# + sensor.THROTTLING_CPU + sensor.POWER_LIMIT_CPU )
 DynamicVariables                 = 1
     ifCondition                  = formula.CPU_HEALTH = 0
          ifTrueAction            = [!SetVariable CPU_Health_State "GOOD"]
     ifCondition2                 = ( formula.CPU_HEALTH = 1 ) || ( formula.CPU_HEALTH = 2 )
          ifTrueAction2           = [!SetVariable CPU_Health_State "ATTENTION"]
     ifCondition3                 = formula.CPU_HEALTH = 3
          ifTrueAction3           = [!SetVariable CPU_Health_State "WARNING"]
     ifCondition4                 = formula.CPU_HEALTH = 4
          ifTrueAction4           = [!SetVariable CPU_Health_State "CRITICAL"]

; - Global Backups to #ADDONSPATH#\AuroraBar\Backups\ 

; - Necessary for global long-term backups to restore configs after updating/patching

; --- PLAYER SELECTION MEASURE

[formula.PLAYER_SELECTION]
 Measure                          = CALC
 DynamicVariables                 = 1
     ifCondition                  = #Player_Selection# < 1
          ifTrueAction            = [!SetVariable Player_Selection "8"][!WriteKeyValue Variables Player_Selection "8" "#@#\#Config#"][!SetVariable Player_Name "AIMP"][!WriteKeyValue Variables Player_Name "AIMP" "#@#\#Config#"]
     ifCondition2                 = #Player_Selection# > 8
          ifTrueAction2           = [!SetVariable Player_Selection "1"][!WriteKeyValue Variables Player_Selection "1" "#@#\#Config#"][!SetVariable Player_Name "WLM"][!WriteKeyValue Variables Player_Name "WLM" "#@#\#Config#"]
     ifCondition3                 = #Player_Selection# = 1
          ifTrueAction3           = [!SetVariable Player_Name "AIMP"][!WriteKeyValue Variables Player_Name "AIMP" "#@#\#Config#"]
     ifCondition4                 = #Player_Selection# = 2
          ifTrueAction4           = [!SetVariable Player_Name "CAD"][!WriteKeyValue Variables Player_Name "CAD" "#@#\#Config#"]
     ifCondition5                 = #Player_Selection# = 3
          ifTrueAction5           = [!SetVariable Player_Name "ITUNES"][!WriteKeyValue Variables Player_Name "ITUNES" "#@#\#Config#"]
     ifCondition6                 = #Player_Selection# = 4
          ifTrueAction6           = [!SetVariable Player_Name "MEDIAMONKEY"][!WriteKeyValue Variables Player_Name "MEDIAMONKEY" "#@#\#Config#"]
     ifCondition7                 = #Player_Selection# = 5
          ifTrueAction7           = [!SetVariable Player_Name "WINAMP"][!WriteKeyValue Variables Player_Name "WINAMP" "#@#\#Config#"]
     ifCondition8                 = #Player_Selection# = 6
          ifTrueAction8           = [!SetVariable Player_Name "WMP"][!WriteKeyValue Variables Player_Name "WMP" "#@#\#Config#"]
     ifCondition9                 = #Player_Selection# = 7
          ifTrueAction9           = [!SetVariable Player_Name "SPOTIFY"][!WriteKeyValue Variables Player_Name "SPOTIFY" "#@#\#Config#"]
     ifCondition10                = #Player_Selection# = 8
          ifTrueAction10          = [!SetVariable Player_Name "WLM"][!WriteKeyValue Variables Player_Name "WLM" "#@#\#Config#"]
     ifConditionMode              = 0

; --- MAIN:SETTINGS INPUT MEASURE

[m.Input_Main]
 Measure                          = PLUGIN
 Plugin                           = InputText
 SolidColor                       = 0,0,0,255
 FontFace                         = #Font#
 FontSize                         = #Font_Size#
 StringCase                       = Upper
 FontColor                        = #Font_Value_Color#
 DynamicVariables                 = 1

; - Sets #Player_Name# - for "NowPlaying" plugin

 Command1                         = [!WriteKeyValue Variables Player_Name "$UserInput$" "#@#\#Config#"] DefaultValue="#Player_Name#" X=920 W=30 H=14 Y="(#Pad_Top#+120)"
 Command2                         = [!SetVariable Player_Name [m.Input_Main]]

; - Sets #App_Volume_1# - for "AppVolume" plugin to CONTROLL APP

 Command3                         = [!WriteKeyValue Variables App_Volume_1 " $UserInput$.exe" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_1#" X=968 W=50 H=14 Y="(#Pad_Top#+35)"
 Command4                         = [!SetVariable App_Volume_1 [m.Input_Main].exe]

; - Sets #App_Volume_2# - for "AppVolume" plugin to CONTROLL APP

 Command5                         = [!WriteKeyValue Variables App_Volume_2 " $UserInput$.exe" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_2#" X=968 W=50 H=14 Y="(#Pad_Top#+52)"
 Command6                         = [!SetVariable App_Volume_2 [m.Input_Main].exe]

; - Sets #App_Volume_3# - for "AppVolume" plugin to CONTROLL APP

 Command7                         = [!WriteKeyValue Variables App_Volume_3 " $UserInput$.exe" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_3#" X=968 W=50 H=14 Y="(#Pad_Top#+69)"
 Command8                         = [!SetVariable App_Volume_3 [m.Input_Main].exe]

; - Sets #App_Volume_4# - for "AppVolume" plugin to CONTROLL APP

 Command9                         = [!WriteKeyValue Variables App_Volume_4 " $UserInput$.exe" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_4#" X=968 W=50 H=14 Y="(#Pad_Top#+86)"
 Command10                        = [!SetVariable App_Volume_4 [m.Input_Main].exe]

; - Sets #App_Volume_1S# - for "AppVolume" plugin to DISPLAY APP NAME

 Command11                        = [!WriteKeyValue Variables App_Volume_1S " $UserInput$" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_1S#" X=968 W=50 H=14 Y="(#Pad_Top#+35)"
 Command12                        = [!SetVariable App_Volume_1S [m.Input_Main]]
 
; - Sets #App_Volume_2S# - for "AppVolume" plugin to DISPLAY APP NAME

 Command13                        = [!WriteKeyValue Variables App_Volume_2S " $UserInput$" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_2S#" X=968 W=50 H=14 Y="(#Pad_Top#+52)"
 Command14                        = [!SetVariable App_Volume_2S [m.Input_Main]]

; - Sets #App_Volume_3S# - for "AppVolume" plugin to DISPLAY APP NAME

 Command15                        = [!WriteKeyValue Variables App_Volume_3S " $UserInput$" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_3S#" X=968 W=50 H=14 Y="(#Pad_Top#+69)"
 Command16                        = [!SetVariable App_Volume_3S [m.Input_Main]]

; - Sets #App_Volume_4S# - for "AppVolume" plugin to DISPLAY APP NAME

 Command17                        = [!WriteKeyValue Variables App_Volume_4S " $UserInput$" "#@#\AppVolumeControl.inc"] DefaultValue="#App_Volume_4S#" X=968 W=50 H=14 Y="(#Pad_Top#+86)"
 Command18                        = [!SetVariable App_Volume_4S [m.Input_Main]]

; - Sets UPDATE RATE value

 Command19                        = [!WriteKeyValue Variables Update_Rate " $UserInput$" "#@#\#Config#"] DefaultValue="#Update_Rate#" X=969 W=20 H=14 Y="(#Pad_Top#+120)" InputNumber=1 InputLimit=4
 Command20                        = [!SetVariable Update_Rate [m.Input_Main]][!Refresh]

; --- HARDWARE:SETTINGS INPUT MEASURE

[m.Input_Hardware]
 Measure                          = PLUGIN
 Plugin                           = InputText
 SolidColor                       = 0,0,0,255
 FontFace                         = #Font#
 FontSize                         = #Font_Size#
 StringCase                       = Upper
 FontColor                        = #Font_Value_Color#
 FocusDismiss                     = 1
 DynamicVariables                 = 1
 OnDismissAction                  = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"]

; - Sets #Net_Max# and #MaxNetOut#

 Command1                         = [!WriteKeyValue Variables Net_Max " $UserInput$" "#@#\#Config#"] DefaultValue="#Net_Max#" X=930 W=20 H=14 Y="(#Pad_Top#+33)" InputNumber=1 InputLimit=4
 Command2                         = [!SetVariable Net_Max [m.Input_Hardware]][!UpdateMeasure m.VALUES_CONTROLLER][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]

; - Sets #Ping_Max#

 Command3                         = [!WriteKeyValue Variables Ping_Max " $UserInput$" "#@#\#Config#"] DefaultValue="#Ping_Max#" X=930 W=20 H=14 Y="(#Pad_Top#+50)" InputNumber=1 InputLimit=4
 Command4                         = [!SetVariable Ping_Max [m.Input_Hardware]][!UpdateMeasure m.VALUES_CONTROLLER][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]

; - Sets #Ping_Timeout#

 Command5                         = [!WriteKeyValue Variables Ping_Timeout " $UserInput$" "#@#\#Config#"] DefaultValue="#Ping_Timeout#" X=930 W=20 H=14 Y="(#Pad_Top#+67)" InputNumber=1 InputLimit=4
 Command6                         = [!SetVariable Ping_Timeout [m.Input_Hardware]][!UpdateMeasure m.VALUES_CONTROLLER][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]

; - Sets #Ping_Host#

 Command7                         = [!WriteKeyValue Variables Ping_Host " $UserInput$" "#@#\#Config#"] DefaultValue="#Ping_Host#" X=900 W=50 H=14 Y="(#Pad_Top#+84)"
 Command8                         = [!SetVariable Ping_Host [m.Input_Hardware]][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeter text.HARDWARE_Settings_PING_HOST][!UpdateMeter text.HARDWARE_Settings_PING_HOST_Value][!UpdateMeasure sensor.PING][!Redraw]

; - Sets #Drive_One# 

 Command9                         = [!WriteKeyValue Variables Drive_One " $UserInput$:" "#@#\#Config#"] DefaultValue="#Drive_One#" X=942 W=7 H=14 Y="(#Pad_Top#+118)" InputLimit=1
 Command10                        = [!SetVariable Drive_One [m.Input_Hardware]:][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeter text.Main_Settings_DRIVE_ONE][!UpdateMeter text.Main_Settings_DRIVE_ONE_Value][!UpdateMeasure m.Disk_One_Label][!Redraw]


; - Sets #Drive_Two#

 Command11                        = [!WriteKeyValue Variables Drive_Two " $UserInput$:" "#@#\#Config#"] DefaultValue="#Drive_Two#" X=942 W=7 H=14 Y="(#Pad_Top#+135)" InputLimit=1
 Command12                        = [!SetVariable Drive_Two [m.Input_Hardware]:][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeter text.Main_Settings_DRIVE_TWO][!UpdateMeter text.Main_Settings_DRIVE_TWO_Value][!UpdateMeasure m.Disk_Two_Label][!Redraw]

; - Sets TEMP FOLDER path

 Command13                        = [!WriteKeyValue Variables Temp_Folder " $UserInput$" "#@#\#Config#"] DefaultValue="#temp_folder#" X=873 W=80 H=16 Y="(#Pad_Top#+151)"
 Command14                        = [!SetVariable Temp_Folder [m.Input_Hardware]][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeasure m.Temp_Size][!UpdateMeter text.Main_Settings_TEMP_FOLDER][!UpdateMeter text.Main_Settings_TEMP_FOLDER_Value][!Redraw]

; - Sets CACHE FOLDER path

 Command15                        = [!WriteKeyValue Variables Cache_Folder " $UserInput$" "#@#\#Config#"] DefaultValue="#cache_folder#" X=873 W=80 H=16 Y="(#Pad_Top#+168)"
 Command16                        = [!SetVariable Cache_Folder [m.Input_Hardware]][!SetVariable Skin_Zpos "#Last_Zpos#"][!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!UpdateMeasure m.Cache_Size][!UpdateMeter text.Main_Settings_CACHE_FOLDER][!UpdateMeter text.Main_Settings_CACHE_FOLDER_Value][!Redraw]


[m.SWITCHERS_CONTROLLER]
 Measure                          = CALC
 Formula                          = 
 DynamicVariables                 = 1
     
     ifCondition                  = #Frosted_Glass_State# = 1
          ifTrueAction            = [!WriteKeyValue m.Frosted_Glass Type " Blur" "#@#\Settings.inc"][!SetOption text.Main_Settings_FROSTED_Value Text "ON"][!WriteKeyValue text.Main_Settings_FROSTED_Value FontColor " #*Font_Value_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_FROSTED_Value FontColor " #*Font_Value_Color*#"]
          ifFalseAction           = [!WriteKeyValue m.Frosted_Glass Type " None" "#@#\Settings.inc"][!SetOption text.Main_Settings_FROSTED_Value Text "OFF"][!WriteKeyValue text.Main_Settings_FROSTED_Value FontColor " #*Font_Warning_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_FROSTED_Value FontColor " #*Font_Warning_Color*#"]
     
     ifCondition2                 = #Translucent_State# = 0
          ifTrueAction2           = [!SetOption text.Main_Settings_TRANSLUCENT_Value Text "ON"][!WriteKeyValue text.Main_Settings_TRANSLUCENT_Value FontColor " #*Font_Value_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_TRANSLUCENT_Value FontColor " #*Font_Value_Color*#"]
          ifFalseAction2          = [!SetOption text.Main_Settings_TRANSLUCENT_Value Text "OFF"][!WriteKeyValue text.Main_Settings_TRANSLUCENT_Value FontColor " #*Font_Warning_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_TRANSLUCENT_Value FontColor " #*Font_Warning_Color*#"]
     
     ifCondition3                 = #ToolTips_State# = 0
          ifTrueAction3           = [!SetOption text.Main_Settings_TOOLTIPS_Value Text "ON"][!WriteKeyValue text.Main_Settings_TOOLTIPS_Value FontColor " #*Font_Value_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_TOOLTIPS_Value FontColor " #*Font_Value_Color*#"]
          ifFalseAction3          = [!SetOption text.Main_Settings_TOOLTIPS_Value Text "OFF"][!SetOption text.Main_Settings_TOOLTIPS_Value FontColor "#*Font_Warning_Color*#"][!WriteKeyValue text.Main_Settings_TOOLTIPS_Value FontColor " #*Font_Warning_Color*#" "#@#\Settings.inc"]
     
     ifCondition4                 = #Sounds_State# = 0
          ifTrueAction4           = [!WriteKeyValue Variables Sounds_Set " #Sounds_Set_Sci_Fi#" "#@#\Sounds.inc"][!SetOption text.Main_Settings_SOUNDS_Value Text "ON"][!WriteKeyValue text.Main_Settings_SOUNDS_Value FontColor " #*Font_Value_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_SOUNDS_Value FontColor " #*Font_Value_Color*#"]
          ifFalseAction4          = [!WriteKeyValue Variables Sounds_Set " #Sounds_Set_Silent#" "#@#\Sounds.inc"][!SetOption text.Main_Settings_SOUNDS_Value Text "OFF"][!SetOption text.Main_Settings_SOUNDS_Value FontColor " #*Font_Warning_Color*#"][!WriteKeyValue text.Main_Settings_SOUNDS_Value FontColor "#*Font_Warning_Color*#" "#@#\Settings.inc"][!SetOption text.Main_Settings_SOUNDS_Value FontColor "#*Font_Warning_Color*#"]

     ifCondition5                 = #Bluetooth_Visible# = 0
          ifTrueAction5           = [!SetOption text.HARDWARE_Settings_BLUETOOTH_Value Text "ON"][!SetOption text.HARDWARE_Settings_BLUETOOTH_Value FontColor "#*Font_Value_Color*#"][!WriteKeyValue text.HARDWARE_Settings_BLUETOOTH_Value FontColor "#*Font_Value_Color*#" "#@#\Settings.inc"]
          ifFalseAction5          = [!SetOption text.HARDWARE_Settings_BLUETOOTH_Value Text "OFF"][!SetOption text.HARDWARE_Settings_BLUETOOTH_Value FontColor "#*Font_Warning_Color*#"][!WriteKeyValue text.HARDWARE_Settings_BLUETOOTH_Value FontColor "#*Font_Warning_Color*#" "#@#\Settings.inc"]

     ifCondition6                 = #Audio_Devices_State# = 0
          ifTrueAction6           = [!SetOption text.HARDWARE_Settings_AUDIO_DEVICES_Value Text "ON"][!SetOption text.HARDWARE_Settings_AUDIO_DEVICES_Value FontColor "#*Font_Value_Color*#"][!WriteKeyValue text.HARDWARE_Settings_BLUETOOTH_Value FontColor "#*Font_Value_Color*#" "#@#\Settings.inc"]
          ifFalseAction6          = [!SetOption text.HARDWARE_Settings_AUDIO_DEVICES_Value Text "OFF"][!SetOption text.HARDWARE_Settings_AUDIO_DEVICES_Value FontColor "#*Font_Warning_Color*#"][!WriteKeyValue text.HARDWARE_Settings_AUDIO_DEVICES_Value FontColor "#*Font_Warning_Color*#" "#@#\Settings.inc"]

     ifCondition7                 = #VRAM_Instance_State# = 0
          ifTrueAction7           = [!SetOption text.HARDWARE_Settings_VRAM_Value Text "VIDEO"][!WriteKeyValue text.HARDWARE_Settings_VRAM_Value Text " VIDEO" "#@#\Settings.inc"][!SetOption sensor.VRAM HWiNFOSensorId "#*HWiNFO-GPU1-MemoryUsage-SensorId*#"][!SetOption sensor.VRAM HWiNFOSensorInstance "#*HWiNFO-GPU1-MemoryUsage-SensorInstance*#"][!SetOption sensor.VRAM HWiNFOEntryId "#*HWiNFO-GPU1-MemoryUsage-EntryId*#"][!WriteKeyValue sensor.VRAM HWiNFOSensorId " #*HWiNFO-GPU1-MemoryUsage-SensorId*#" "#@#\Memory.inc"][!WriteKeyValue sensor.VRAM HWiNFOSensorInstance " #*HWiNFO-GPU1-MemoryUsage-SensorInstance*#" "#@#\Memory.inc"][!WriteKeyValue sensor.VRAM HWiNFOEntryId " #*HWiNFO-GPU1-MemoryUsage-EntryId*#" "#@#\Memory.inc"]
          ifFalseAction7          = [!SetOption text.HARDWARE_Settings_VRAM_Value Text "VIRTUAL"][!WriteKeyValue text.HARDWARE_Settings_VRAM_Value Text " VIRTUAL" "#@#\Settings.inc"][!SetOption sensor.VRAM HWiNFOSensorId "#*HWiNFO-MEMORY-VirtualMLoad-SensorId*#"][!SetOption sensor.VRAM HWiNFOSensorInstance "#*HWiNFO-MEMORY-VirtualMLoad-SensorInstance*#"][!SetOption sensor.VRAM HWiNFOEntryId "#*HWiNFO-MEMORY-VirtualMLoad-EntryId*#"][!WriteKeyValue sensor.VRAM HWiNFOSensorId " #*HWiNFO-MEMORY-VirtualMLoad-SensorId*#" "#@#\Memory.inc"][!WriteKeyValue sensor.VRAM HWiNFOSensorInstance " #*HWiNFO-MEMORY-VirtualMLoad-SensorInstance*#" "#@#\Memory.inc"][!WriteKeyValue sensor.VRAM HWiNFOEntryId " #*HWiNFO-MEMORY-VirtualMLoad-EntryId*#" "#@#\Memory.inc"]

; --- VALUES CONTROLLER

; - Keep some values are positive and corect

[m.VALUES_CONTROLLER]
 Measure                          = CALC
 Formula                          = #Sys_Volume_Step#
 DynamicVariables                 = 1

; - VOLUME & PLAYER Values

     ifCondition                  = ( #Sys_Volume_Step# < 1 ) || ( #Sys_Volume_Step# > 50 )
          ifTrueAction            = [!SetVariable Sys_Volume_Step "1"][!WriteKeyValue Variables Sys_Volume_Step " 1" "#@#\#Config#"]
     ifCondition2                 = ( #Player_Volume_Step# < 1 ) || ( #Player_Volume_Step# > 50 )
          ifTrueAction2           = [!SetVariable Player_Volume_Step "1"][!WriteKeyValue Variables Player_Volume_Step " 1" "#@#\#Config#"]
     ifCondition3                 = ( #Player_Position_Step# < 1 ) || ( #Player_Position_Step# > 50 )
          ifTrueAction3           = [!SetVariable Player_Position_Step "1"][!WriteKeyValue Variables Player_Position_Step " 1" "#@#\#Config#"]

; - UPDATE Values

     ifCondition4                 = #Update_Rate# < 16
          ifTrueAction4           = [!SetVariable Update_Rate "50"][!WriteKeyValue Variables Update_Rate " 50" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
     ifCondition5                 = #Update_Rate# > 50
          ifTrueAction5           = [!SetVariable Update_Rate "16"][!WriteKeyValue Variables Update_Rate " 16" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!Redraw]
     ifCondition6                 = #Cycles_2nd_Divider# < 3
          ifTrueAction6           = [!SetVariable Cycles_2nd_Divider "10"][!WriteKeyValue Variables Cycles_2nd_Divider " 10" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
     ifCondition7                 = #Cycles_2nd_Divider# > 10
          ifTrueAction7           = [!SetVariable Cycles_2nd_Divider "3"][!WriteKeyValue Variables Cycles_2nd_Divider " 3" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
     ifCondition8                 = ( #Cycles_3rd_Divider# < 2 ) || ( #Cycles_3rd_Divider# > 4 )
          ifTrueAction8           = [!SetVariable Cycles_3rd_Divider "2"][!WriteKeyValue Variables Cycles_3rd_Divider " 2" "#@#\#Config#"][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]

; - NET Values

     ifCondition9                 = ( #Net_Max# < 1 ) || ( #Net_Max# > 1000 )
          ifTrueAction9           = [!SetVariable Net_Max "1"][!WriteKeyValue Variables Net_Max "1" "#@#\#Config#"]
     ifCondition10                = ( #Ping_Max# < 10 ) || ( #Ping_Max# > 1000 )
          ifTrueAction10          = [!SetVariable Ping_Max "10"][!WriteKeyValue Variables Ping_Max "10" "#@#\#Config#"]
     ifCondition11                = ( #Ping_Timeout# < 500 ) || ( #Ping_Timeout# > 9999 )
          ifTrueAction11          = [!SetVariable Ping_Timeout "500"][!WriteKeyValue Variables Ping_Timeout "500" "#@#\#Config#"]

; - PROCESSORS UNITS Values

     ifCondition12                = #CPU_Load_Max# < 0
          ifTrueAction12          = [!SetVariable CPU_Load_Max "0"][!WriteKeyValue Variables CPU_Load_Max "0" "#@#\#Config#"]

     ifCondition13                = #CPU_Load_Max# > 100
          ifTrueAction13          = [!SetVariable CPU_Load_Max "100"][!WriteKeyValue Variables CPU_Load_Max "100" "#@#\#Config#"]

     ifCondition14                = #GPU_Load_Max# < 0
          ifTrueAction14          = [!SetVariable GPU_Load_Max "0"][!WriteKeyValue Variables GPU_Load_Max "0" "#@#\#Config#"]

     ifCondition15                = #GPU_Load_Max# > 100
          ifTrueAction15          = [!SetVariable GPU_Load_Max "100"][!WriteKeyValue Variables GPU_Load_Max "100" "#@#\#Config#"]

     ifCondition16                = #CPU_Temp_Max# < 0
          ifTrueAction16          = [!SetVariable CPU_Temp_Max "0"][!WriteKeyValue Variables CPU_Temp_Max "0" "#@#\#Config#"]

     ifCondition17                = #CPU_Temp_Max# > 105
          ifTrueAction17          = [!SetVariable CPU_Temp_Max "105"][!WriteKeyValue Variables CPU_Temp_Max "105" "#@#\#Config#"]

     ifCondition18                = #GPU_Temp_Max# < 0
          ifTrueAction18          = [!SetVariable GPU_Temp_Max "0"][!WriteKeyValue Variables GPU_Temp_Max "0" "#@#\#Config#"]

     ifCondition19                = #GPU_Temp_Max# > 105
          ifTrueAction19          = [!SetVariable GPU_Temp_Max "105"][!WriteKeyValue Variables GPU_Temp_Max "105" "#@#\#Config#"]

; - BEHAVIOUR

; - Zpos

     ifCondition20                = #Skin_Zpos# < -2
          ifTrueAction20          = [!SetVariable Skin_Zpos "-2"][!WriteKeyValue Variables Skin_Zpos "-2" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

     ifCondition21                = #Skin_Zpos# > 2
          ifTrueAction21          = [!SetVariable Skin_Zpos "2"][!WriteKeyValue Variables Skin_Zpos "2" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

; - Skin Alpha

     ifCondition22                = #Skin_Alpha# < 25
          ifTrueAction22          = [!SetVariable Skin_Alpha "25"][!WriteKeyValue Variables Skin_Alpha "25" "#@#\#Config#"][!UpdateMeasure #CURRENTSECTION#][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

     ifCondition23                = #Skin_Alpha# > 255
          ifTrueAction23          = [!SetVariable Skin_Alpha "255"][!WriteKeyValue Variables Skin_Alpha "255" "#@#\#Config#"][!UpdateMeasure #CURRENTSECTION#][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

; - Window X

     ifCondition24                = #Window_X# < -1920
          ifTrueAction24          = [!SetVariable Window_X "-1920"][!WriteKeyValue Variables Window_X "-1920" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!Redraw]

     ifCondition25                = #Window_X# > 1920
          ifTrueAction25          = [!SetVariable Window_X "1920"][!WriteKeyValue Variables Window_X "1920" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!Redraw]

; - Window Y

     ifCondition26                = #Window_Y# < 0
          ifTrueAction26          = [!SetVariable Window_Y "0"][!WriteKeyValue Variables Window_Y "0" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!Redraw]

     ifCondition27                = #Window_Y# > 1080
          ifTrueAction27          = [!SetVariable Window_Y "1080"][!WriteKeyValue Variables Window_Y "1080" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!Redraw]

; - Anchor X

     ifCondition28                = #Anchor_X# < 0
          ifTrueAction28          = [!SetVariable Anchor_X "0"][!WriteKeyValue Variables Anchor_X "0" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!Redraw]

     ifCondition29                = #Anchor_X# > 100
          ifTrueAction29          = [!SetVariable Anchor_X "100"][!WriteKeyValue Variables Anchor_X "100" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!Redraw]

; - Anchor Y

     ifCondition30                = #Anchor_Y# < 0
          ifTrueAction30          = [!SetVariable Anchor_Y "0"][!WriteKeyValue Variables Anchor_Y "0" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!Redraw]

     ifCondition31                = #Anchor_Y# > 100
          ifTrueAction31          = [!SetVariable Anchor_Y "100"][!WriteKeyValue Variables Anchor_Y "100" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!Redraw]

     ifCondition32                = #Monitor_Num# < 0
          ifTrueAction32          = [!SetVariable Monitor_Num "0"][!WriteKeyValue Variables Monitor_Num "0" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!Redraw]

     ifCondition33                = #Monitor_Num# > 10
          ifTrueAction33          = [!SetVariable Monitor_Num "10"][!WriteKeyValue Variables Monitor_Num "10" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!Redraw]

     ifConditionMode              = 1

; --- This measure handles all Behaviour settings

[sensor.BEHAVIOUR]
 Measure                          = CALC
 DynamicVariables                 = 1
     OnUpdateAction               = [!SetWindowPosition "#Window_X#@#Monitor_Num#" "#Window_Y#" "#Anchor_X#%" "#Anchor_Y#%"][!UpdateMeter BG]
     
; --- ZPOS

     ifCondition                  = #Skin_Zpos# = -2
          ifTrueAction            = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!SetOption text.Behaviour_Settings_ZPOS_Value Text "DESKTOP"][!SetOption text.Behaviour_Settings_ZPOS_Value FontColor " #*Font_Warning_Color*#"]
     ifCondition2                 = #Skin_Zpos# = -1
          ifTrueAction2           = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!SetOption text.Behaviour_Settings_ZPOS_Value Text "BOTTOM"][!SetOption text.Behaviour_Settings_ZPOS_Value FontColor " #*Font_Warning_Color*#"]
     ifCondition3                 = #Skin_Zpos# = 0
          ifTrueAction3           = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!SetOption text.Behaviour_Settings_ZPOS_Value Text "NORMAL"][!SetOption text.Behaviour_Settings_ZPOS_Value FontColor " #*Font_Value_Color*#"]
     ifCondition4                 = #Skin_Zpos# = 1
          ifTrueAction4           = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!SetOption text.Behaviour_Settings_ZPOS_Value Text "ON TOP"][!SetOption text.Behaviour_Settings_ZPOS_Value FontColor " #*Font_Warning_Color*#"]
     ifCondition5                 = #Skin_Zpos# = 2
          ifTrueAction5           = [!Zpos "#Skin_Zpos#" "AuroraBar\Bar"][!SetOption text.Behaviour_Settings_ZPOS_Value Text "ALWAYS TOP"][!SetOption text.Behaviour_Settings_ZPOS_Value FontColor " #*Font_Warning_Color*#"]

; --- DRAGGABLE

     ifCondition6                 = #Draggable# = 1
          ifTrueAction6           = [!Draggable 1][!SetOption text.Behaviour_Settings_DRAG_Value Text "YES"][!SetOption text.Behaviour_Settings_DRAG_Value FontColor "#*Font_Value_Color*#"]
          ifFalseAction6          = [!Draggable 0][!SetOption text.Behaviour_Settings_DRAG_Value Text "NO"][!SetOption text.Behaviour_Settings_DRAG_Value FontColor "#*Font_Warning_Color*#"]

; --- SNAPEDGE

     ifCondition7                 = #Snapedge# = 1
          ifTrueAction7           = [!SnapEdges 1][!SetOption text.Behaviour_Settings_SNAPEDGE_Value Text "YES"][!SetOption text.Behaviour_Settings_SNAPEDGE_Value FontColor "#*Font_Value_Color*#"]
          ifFalseAction7          = [!SnapEdges 0][!SetOption text.Behaviour_Settings_SNAPEDGE_Value Text "NO"][!SetOption text.Behaviour_Settings_SNAPEDGE_Value FontColor "#*Font_Warning_Color*#"]

; --- KEEP ON SCREEN

     ifCondition8                 = #Keep_On_Screen# = 1
          ifTrueAction8           = [!KeepOnScreen 1][!SetOption text.Behaviour_Settings_KEEPONSCREEN_Value Text "YES"][!SetOption text.Behaviour_Settings_KEEPONSCREEN_Value FontColor "#*Font_Value_Color*#"]
          ifFalseAction8          = [!KeepOnScreen 0][!SetOption text.Behaviour_Settings_KEEPONSCREEN_Value Text "NO"][!SetOption text.Behaviour_Settings_KEEPONSCREEN_Value FontColor "#*Font_Warning_Color*#"]

     ifConditionMode              = 1

; --- FROSTED GLASS

; - "Frosted Glass" makes skins background blured.

; - 3 possible option is there:

; - Type = None
; - Type = Blur
; - Type = Acrylic | this method eats a lot of CPU

[m.Frosted_Glass]
 Measure                          = PLUGIN
 Plugin                           = FrostedGlass
 Type                             = None
 Border                           = None

; --- TRANSLUCENT TASKBAR

; - "Translucent Taskbar" makes taskbar trasparent.

; - AccentState = 0 to OFF
; - AccentState = 1 for blur
; - AccentState = 2 to off blur

[m.Translucent_Taskbar]
 Measure                          = PLUGIN
 Plugin                           = TranslucentTaskbar
 AccentState                      = 2
;UpdateDivider                    = 1
 Disabled                         = #Translucent_State#

; - MEASURES END

; --- TEXTS BEGINNING

[text.Main_Settings_Menu]
 Meter                            = STRING
 MeterStyle                       = style.text.Settings_Menu
 X                                = 890
 Y                                = (#Pad_Top# + 7)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "MAINS"
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Main_Temp#
 
 MouseOverAction                  = [!SetOption text.Main_Settings_Menu FontColor "#Global_Color#"][!DisableMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 MouseLeaveAction                 = [!SetOption text.Main_Settings_Menu FontColor "#Bar_BG_Color#"][!EnableMeasure f.Menu_Text_Colors_Control][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 LeftMouseUpAction                = [!SetVariable Settings_Main "0"][!WriteKeyValue Variables Settings_Main " 0" "#@#\#Config#"]    [!SetVariable Settings_Behaviour "1"][!WriteKeyValue Variables Settings_Behaviour " 1" "#@#\#Config#"]     [!SetVariable Settings_Hardware "1"][!WriteKeyValue Variables Settings_Hardware " 1" "#@#\#Config#"]     [!SetVariable Settings_Color "1"][!WriteKeyValue Variables Settings_Color " 1" "#@#\#Config#"]     [!EnableMeasure f.Menu_Text_Colors_Control]#Settings_Menu_Main_Updater#
 
 RightMouseUpAction               = 

[text.Color_Settings_Menu]
 Meter                            = STRING
 MeterStyle                       = style.text.Settings_Menu
 X                                = 1032
 Y                                = (#Pad_Top# + 7)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "COLOR"
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Color_Temp#
 
 MouseOverAction                  = [!SetOption text.Color_Settings_Menu FontColor "#Global_Color#"][!DisableMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 MouseLeaveAction                 = [!SetOption text.Color_Settings_Menu FontColor "#Bar_BG_Color#"][!EnableMeasure f.Menu_Text_Colors_Control][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 LeftMouseUpAction                = [!SetVariable Settings_Color "0"][!WriteKeyValue Variables Settings_Color " 0" "#@#\#Config#"]    [!SetVariable Settings_Main "1"][!WriteKeyValue Variables Settings_Main " 1" "#@#\#Config#"]     [!SetVariable Settings_Hardware "1"][!WriteKeyValue Variables Settings_Hardware " 1" "#@#\#Config#"]     [!SetVariable Settings_Behaviour "1"][!WriteKeyValue Variables Settings_Behaviour " 1" "#@#\#Config#"]     [!EnableMeasure f.Menu_Text_Colors_Control]#Settings_Menu_Color_Updater#
 RightMouseUpAction               = 

[text.Hardware_Settings_Menu]
 Meter                            = STRING
 MeterStyle                       = style.text.Settings_Menu
 X                                = 1032
 Y                                = (#Pad_Top# + 195)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "HARDW"
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Hardware_Temp#
 
 MouseOverAction                  = [!SetOption text.Hardware_Settings_Menu FontColor "#Global_Color#"][!DisableMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 MouseLeaveAction                 = [!SetOption text.Hardware_Settings_Menu FontColor "#Bar_BG_Color#"][!EnableMeasure f.Menu_Text_Colors_Control][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 LeftMouseUpAction                = [!SetVariable Settings_Hardware "0"][!WriteKeyValue Variables Settings_Hardware " 0" "#@#\#Config#"]    [!SetVariable Settings_Main "1"][!WriteKeyValue Variables Settings_Main " 1" "#@#\#Config#"]     [!SetVariable Settings_Behaviour "1"][!WriteKeyValue Variables Settings_Behaviour " 1" "#@#\#Config#"]     [!SetVariable Settings_Color "1"][!WriteKeyValue Variables Settings_Color " 1" "#@#\#Config#"]     [!EnableMeasure f.Menu_Text_Colors_Control]#Settings_Menu_Hardware_Updater#
 
 RightMouseUpAction               = 

[text.Behaviour_Settings_Menu]
 Meter                            = STRING
 MeterStyle                       = style.text.Settings_Menu
 X                                = 891
 Y                                = (#Pad_Top# + 195)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = "BEHVR"
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Behaviour_Temp#
 
 MouseOverAction                  = [!SetOption text.Behaviour_Settings_Menu FontColor "#Global_Color#"][!DisableMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 
 MouseLeaveAction                 = [!SetOption text.Behaviour_Settings_Menu FontColor "#Bar_BG_Color#"][!EnableMeasure f.Menu_Text_Colors_Control][!UpdateMeasure f.Menu_Text_Colors_Control][!UpdateMeter #CURRENTSECTION#][!Redraw]
 
 LeftMouseUpAction                = [!SetVariable Settings_Behaviour "0"][!WriteKeyValue Variables Settings_Behaviour " 0" "#@#\#Config#"]    [!SetVariable Settings_Main "1"][!WriteKeyValue Variables Settings_Main " 1" "#@#\#Config#"]     [!SetVariable Settings_Hardware "1"][!WriteKeyValue Variables Settings_Hardware " 1" "#@#\#Config#"]     [!SetVariable Settings_Color "1"][!WriteKeyValue Variables Settings_Color " 1" "#@#\#Config#"]     [!EnableMeasure f.Menu_Text_Colors_Control] #Settings_Menu_Behaviour_Updater#
 RightMouseUpAction               = 

; --- MAIN SETTINGS TEXTS BEGINNING

; - LEFT TOP CORNER

[text.Main_Settings_SOUNDS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 35)
 W                                = 55
 Text                             = "SOUNDS:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Sounds_State "(1 - #Sounds_State#)"][!WriteKeyValue Variables Sounds_State "(1 - #Sounds_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_SOUNDS_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        =#Font_Warning_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 35)
 W                                = 20
 Text                             = ""
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Sounds_State "(1 - #Sounds_State#)"][!WriteKeyValue Variables Sounds_State "(1 - #Sounds_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_TOOLTIPS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 52)
 W                                = 55
 Text                             = "TOOLTIPS:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable ToolTips_State "(1 - #ToolTips_State#)"][!WriteKeyValue Variables ToolTips_State "(1 - #ToolTips_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_TOOLTIPS_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 52)
 W                                = 20
 Text                             = ""
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable ToolTips_State "(1 - #ToolTips_State#)"][!WriteKeyValue Variables ToolTips_State "(1 - #ToolTips_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_FROSTED]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 69)
 W                                = 55
 Text                             = "FROSTED:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Frosted_Glass_State "(1 - #Frosted_Glass_State#)"][!WriteKeyValue Variables Frosted_Glass_State "(1 - #Frosted_Glass_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_FROSTED_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 69)
 W                                = 20
 Text                             = ""
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Frosted_Glass_State "(1 - #Frosted_Glass_State#)"][!WriteKeyValue Variables Frosted_Glass_State "(1 - #Frosted_Glass_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_TRANSLUCENT]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 86)
 W                                = 55
 Text                             = "TRANSLUCID:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Translucent_State "(1 - #Translucent_State#)"][!WriteKeyValue Variables Translucent_State "(1 - #Translucent_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

[text.Main_Settings_TRANSLUCENT_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 86)
 Text                             = ""
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!SetVariable Translucent_State "(1 - #Translucent_State#)"][!WriteKeyValue Variables Translucent_State "(1 - #Translucent_State#)" "#@#\#Config#"][!Delay 5][!Refresh]

; - RIGHT TOP CORNER

[text.Main_Settings_APP_VOLUME_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 35)
 Text                             = ":VLM 1"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 3-4"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 11-12"][!Update]

[text.Main_Settings_APP_VOLUME_1_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 35)
 W                                = 50
 Text                             = "#App_Volume_1#"
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 3-4"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 11-12"][!Update]
 MouseScrollUpAction              = 
 MouseScrollDownAction            = 

[text.Main_Settings_APP_VOLUME_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 52)
 Text                             = ":VLM2"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 5-6"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 13-14"][!Update]

[text.Main_Settings_APP_VOLUME_2_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 52)
 W                                = 50
 Text                             = "#App_Volume_2#"
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 5-6"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 13-14"][!Update]
 MouseScrollUpAction              = 
 MouseScrollDownAction            = 

[text.Main_Settings_APP_VOLUME_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 69)
 Text                             = ":VLM3"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 7-8"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 15-16"][!Update]

[text.Main_Settings_APP_VOLUME_3_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 69)
 W                                = 50
 Text                             = "#App_Volume_3#"
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 7-8"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 15-16"][!Update]
 MouseScrollUpAction              = 
 MouseScrollDownAction            = 

[text.Main_Settings_APP_VOLUME_4]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 86)
 Text                             = ":VLM4"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 9-10"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 17-18"][!Update]

[text.Main_Settings_APP_VOLUME_4_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 86)
 W                                = 50
 Text                             = "#App_Volume_4#"
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "ExecuteBatch 9-10"][!Update]
 RightMouseUpAction               = [!CommandMeasure m.Input_Main "ExecuteBatch 17-18"][!Update]
 MouseScrollUpAction              = 
 MouseScrollDownAction            = 

; - RIGHT BOTTOM CORNER

[text.Main_Settings_UPDATE_RATE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 120)
 Text                             = ":UPDATE RATE"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "Executebatch 19-20"]
 MouseScrollUpAction              = [!SetVariable Update_Rate "(#Update_Rate# + 1)"][!WriteKeyValue Variables Update_Rate "(#Update_Rate# + 1)" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeterGroup #debug#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Update_Rate "(#Update_Rate# - 1)"][!WriteKeyValue Variables Update_Rate "(#Update_Rate# - 1)" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeterGroup #debug#][!Redraw]
 RightMouseUpAction               = [!SetVariable Update_Rate "#Default_Update_Rate#"][!WriteKeyValue Variables Update_Rate "#Default_Update_Rate#" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]

[formula.UPDATE_RATE_MAIN_CYCLE]
 Measure                          = CALC
 Formula                          = #Update_Rate# * #Cycles_Max#
 DynamicVariables                 = 1

[text.Main_Settings_UPDATE_RATE_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 120)
 W                                = 20
 Text                             = [formula.UPDATE_RATE_MAIN_CYCLE]
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 MouseScrollUpAction              = [!SetVariable Update_Rate "(#Update_Rate# + 1)"][!WriteKeyValue Variables Update_Rate "(#Update_Rate# + 1)" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeterGroup #debug#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Update_Rate "(#Update_Rate# - 1)"][!WriteKeyValue Variables Update_Rate "(#Update_Rate# - 1)" "#@#\#Config#"][!SetVariable Delay "[!Delay [#Update_Rate]]"][!UpdateMeasure formula.UPDATE_RATE_MAIN_CYCLE][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_UPDATE_RATE_Value][!UpdateMeter text.Main_Settings_UPDATE_RATE][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeterGroup #debug#][!Redraw]
 RightMouseUpAction               = [!SetVariable Update_Rate "#Default_Update_Rate#"][!WriteKeyValue Variables Update_Rate "#Default_Update_Rate#" "#@#\#Config#"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Main "Executebatch 19-20"]

[formula.2ND_CYCLE_DIVIDER]
 Measure                          = CALC
 Formula                          = (#Update_Rate# * #Cycles_2nd_Divider# * #Cycles_Max#)
 DynamicVariables                 = 1

[text.MAIN_SETTINGS_2ND_CYCLE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 137)
 Text                             = ":2ND RATE"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 MouseScrollUpAction              = [!SetVariable Cycles_2nd_Divider "(#Cycles_2nd_Divider# + 1)"][!WriteKeyValue Variables Cycles_2nd_Divider "(#Cycles_2nd_Divider# + 1)" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
 MouseScrollDownAction            = [!SetVariable Cycles_2nd_Divider "(#Cycles_2nd_Divider# - 1)"][!WriteKeyValue Variables Cycles_2nd_Divider "(#Cycles_2nd_Divider# - 1)" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
 RightMouseUpAction               = [!SetVariable Cycles_2nd_Divider "#Default_Divider_Main#"][!WriteKeyValue Variables Divider_Main "#Default_Divider_Main#" "#@#\#Config#"]

[text.MAIN_SETTINGS_2ND_CYCLE_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 137)
 W                                = 20
 Text                             = "[formula.2ND_CYCLE_DIVIDER] x#Cycles_2nd_Divider# "
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 MouseScrollUpAction              = [!SetVariable Cycles_2nd_Divider "(#Cycles_2nd_Divider# + 1)"][!WriteKeyValue Variables Divider_Main "(#Cycles_2nd_Divider# + 1)" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
 MouseScrollDownAction            = [!SetVariable Cycles_2nd_Divider "(#Cycles_2nd_Divider# - 1)"][!WriteKeyValue Variables Divider_Main "(#Cycles_2nd_Divider# - 1)" "#@#\#Config#"][!UpdateMeasure formula.2ND_CYCLE_DIVIDER][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_2ND_CYCLE][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!Redraw]
 RightMouseUpAction               = [!SetVariable Cycles_2nd_Divider "#Default_Cycles_2nd_Divider#"][!WriteKeyValue Variables Cycles_2nd_Divider "#Default_Cycles_2nd_Divider#" "#@#\#Config#"]

[formula.3RD_CYCLE_DIVIDER]
 Measure                          = CALC
 Formula                          = (#Update_Rate# * #Cycles_2nd_Divider# * #Cycles_3rd_Divider# * #Cycles_Max#)
 DynamicVariables                 = 1

[text.MAIN_SETTINGS_3RD_CYCLE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 154)
 Text                             = ":3RD RATE"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 MouseScrollUpAction              = [!SetVariable Cycles_3rd_Divider "(#Cycles_3rd_Divider# + 1)"][!WriteKeyValue Variables Cycles_3rd_Divider "(#Cycles_3rd_Divider# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE][!Redraw]
 MouseScrollDownAction            = [!SetVariable Cycles_3rd_Divider "(#Cycles_3rd_Divider# - 1)"][!WriteKeyValue Variables Cycles_3rd_Divider "(#Cycles_3rd_Divider# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE][!Redraw]
 RightMouseUpAction               = [!SetVariable Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#"][!WriteKeyValue Variables Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#" "#@#\#Config#"]

[text.MAIN_SETTINGS_3RD_CYCLE_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 154)
 W                                = 20
 Text                             = "[formula.3RD_CYCLE_DIVIDER] x#Cycles_3rd_Divider# "
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 MouseScrollUpAction              = [!SetVariable Cycles_3rd_Divider "(#Cycles_3rd_Divider# + 1)"][!WriteKeyValue Variables Cycles_3rd_Divider "(#Cycles_3rd_Divider# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE][!Redraw]
 MouseScrollDownAction            = [!SetVariable Cycles_3rd_Divider "(#Cycles_3rd_Divider# - 1)"][!WriteKeyValue Variables Cycles_3rd_Divider "(#Cycles_3rd_Divider# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure formula.3RD_CYCLE_DIVIDER][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE_VALUE][!UpdateMeter text.MAIN_SETTINGS_3RD_CYCLE][!Redraw]
 RightMouseUpAction               = [!SetVariable Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#"][!WriteKeyValue Variables Cycles_3rd_Divider "#Default_Cycles_3rd_Divider#" "#@#\#Config#"]

[text.Main_Check_Version]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 171)
 Text                             = ""
 DynamicVariables                 = 1
 Group                            = #settings_main# | #updater#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!Log "Update requested.."][!SetVariable Update_Initialized "1"][!WriteKeyValue Variables Update_Initialized "1" "#Service_Folder#\Service.inc"][!SetVariable Update_Completed "0"][!WriteKeyValue Variables Update_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER]
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#

[text.Main_Check_Version_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 171)
 W                                = 20
 Text                             = #New_Version#
 DynamicVariables                 = 1
 Group                            = #settings_main# | #updater#
 Hidden                           = #Settings_Main#
 LeftMouseUpAction                = [!Log "Update requested.."][!SetVariable Update_Initialized "1"][!WriteKeyValue Variables Update_Initialized "1" "#Service_Folder#\Service.inc"][!SetVariable Update_Completed "0"][!WriteKeyValue Variables Update_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER]
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#

; - LEFT BOTTOM CORNER

[text.Main_Settings_PLAYER_NAME]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 120)
 Text                             = "PLAYER:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 MouseScrollUpAction              = [!SetVariable Player_Selection "(#Player_Selection# + 1)"][!WriteKeyValue Variables Player_Selection "(#Player_Selection# + 1)" "#@#\#Config#"][!UpdateMeasure formula.PLAYER_SELECTION][!UpdateMeter text.Main_Settings_PLAYER_NAME][!UpdateMeter text.Main_Settings_PLAYER_NAME_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Selection "(#Player_Selection# - 1)"][!WriteKeyValue Variables Player_Selection "(#Player_Selection# - 1)" "#@#\#Config#"][!UpdateMeasure formula.PLAYER_SELECTION][!UpdateMeter text.Main_Settings_PLAYER_NAME][!UpdateMeter text.Main_Settings_PLAYER_NAME_Value][!Redraw]

[text.Main_Settings_PLAYER_NAME_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 120)
 W                                = 40
 Text                             = "#Player_Name#"
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 MouseScrollUpAction              = [!SetVariable Player_Selection "(#Player_Selection# + 1)"][!WriteKeyValue Variables Player_Selection "(#Player_Selection# + 1)" "#@#\#Config#"][!UpdateMeasure formula.PLAYER_SELECTION][!UpdateMeter text.Main_Settings_PLAYER_NAME][!UpdateMeter text.Main_Settings_PLAYER_NAME_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Selection "(#Player_Selection# - 1)"][!WriteKeyValue Variables Player_Selection "(#Player_Selection# - 1)" "#@#\#Config#"][!UpdateMeasure formula.PLAYER_SELECTION][!UpdateMeter text.Main_Settings_PLAYER_NAME][!UpdateMeter text.Main_Settings_PLAYER_NAME_Value][!Redraw]

[text.Main_Settings_SYSTEM_VOLUME_STEP]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 137)
 Text                             = "SYSTEM VLM:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Sys_Volume_Step "#Default_Sys_Volume_Step#"][!WriteKeyValue Variables Sys_Volume_Step " #Default_Sys_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #histograms#][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!UpdateMeasure m.System_Volume][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]
 MouseScrollUpAction              = [!SetVariable Sys_Volume_Step "(#Sys_Volume_Step# + 1)"][!WriteKeyValue Variables Sys_Volume_Step "(#Sys_Volume_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure m.System_Volume][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!UpdateMeasure m.System_Volume][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Sys_Volume_Step "(#Sys_Volume_Step# - 1)"][!WriteKeyValue Variables Sys_Volume_Step "(#Sys_Volume_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure m.System_Volume][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!UpdateMeasure m.System_Volume][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]

[text.Main_Settings_SYSTEM_VOLUME_STEP_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 137)
 W                                = 20
 Text                             = "#Sys_Volume_Step#"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Sys_Volume_Step "#Default_System_Volume_Step#"][!WriteKeyValue Variables Sys_Volume_Step " #Default_System_Volume_Step#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]
 MouseScrollUpAction              = [!SetVariable Sys_Volume_Step "(#Sys_Volume_Step# + 1)"][!WriteKeyValue Variables Sys_Volume_Step "(#Sys_Volume_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Sys_Volume_Step "(#Sys_Volume_Step# - 1)"][!WriteKeyValue Variables Sys_Volume_Step "(#Sys_Volume_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP][!UpdateMeter text.Main_Settings_SYSTEM_VOLUME_STEP_Value][!SetVariable Sys_Volume_Down "-#Sys_Volume_Step#"][!SetVariable Sys_Volume_Up "+#Sys_Volume_Step#"][!UpdateMeterGroup #cpu_histograms#][!Redraw]

[text.Main_Settings_PLAYER_VOLUME_STEP]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 154)
 Text                             = "PLAYER VLM:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Player_Volume_Step "#Default_Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Step " #Default_Player_Volume_Step#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!SetVariable Player_Volume_Up "+#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Up "+#Player_Volume_Step#" "#@#\#Config#"][!WriteKeyValue Variables Player_Volume_Down "-#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]
 MouseScrollUpAction              = [!SetVariable Player_Volume_Step "(#Player_Volume_Step# + 1)"][!WriteKeyValue Variables Player_Volume_Step "(#Player_Volume_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!SetVariable Player_Volume_Up "+#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Up "+#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Volume_Step "(#Player_Volume_Step# - 1)"][!WriteKeyValue Variables Player_Volume_Step "(#Player_Volume_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Down "-#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]

[text.Main_Settings_PLAYER_VOLUME_STEP_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 154)
 W                                = 20
 Text                             = "#Player_Volume_Step#"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Player_Volume_Step "#Default_Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Step " #Default_Player_Volume_Step#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!SetVariable Player_Volume_Up "+#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Up "+#Player_Volume_Step#" "#@#\#Config#"][!WriteKeyValue Variables Player_Volume_Down "-#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]
 MouseScrollUpAction              = [!SetVariable Player_Volume_Step "(#Player_Volume_Step# + 1)"][!WriteKeyValue Variables Player_Volume_Step "(#Player_Volume_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!SetVariable Player_Volume_Up "+#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Up "+#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Volume_Step "(#Player_Volume_Step# - 1)"][!WriteKeyValue Variables Player_Volume_Step "(#Player_Volume_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP][!UpdateMeter text.Main_Settings_PLAYER_VOLUME_STEP_Value][!SetVariable Player_Volume_Down "-#Player_Volume_Step#"][!WriteKeyValue Variables Player_Volume_Down "-#Player_Volume_Step#" "#@#\#Config#"][!UpdateMeterGroup #gpu_histograms#][!Redraw]

[text.Main_Settings_PLAYER_POSITION_STEP]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 171)
 Text                             = "PLAYER POS:"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Player_Position_Step "#Default_Player_Position_Step#"][!WriteKeyValue Variables Player_Position_Step " #Default_Player_Position_Step#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!SetVariable Position_Forward "+#Player_Position_Step#"][!SetVariable Position_Backward "-#Player_Position_Step#"][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollUpAction              = [!SetVariable Player_Position_Step "(#Player_Position_Step# + 1)"][!WriteKeyValue Variables Player_Position_Step "(#Player_Position_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!SetVariable Position_Forward "+#Player_Position_Step#"][!SetVariable Position_Backward "-#Player_Position_Step#"][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Position_Step "(#Player_Position_Step# - 1)"][!WriteKeyValue Variables Player_Position_Step "(#Player_Position_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!Redraw]

[text.Main_Settings_PLAYER_POSITION_STEP_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 171)
 W                                = 20
 Text                             = "#Player_Position_Step#"
 DynamicVariables                 = 1
 Group                            = #settings_main#
 Hidden                           = #Settings_Main#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable Player_Position_Step "#Default_Player_Position_Step#"][!WriteKeyValue Variables Player_Position_Step " #Default_Player_Position_Step#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!SetVariable Position_Forward "+#Player_Position_Step#"][!SetVariable Position_Backward "-#Player_Position_Step#"][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollUpAction              = [!SetVariable Player_Position_Step "(#Player_Position_Step# + 1)"][!WriteKeyValue Variables Player_Position_Step "(#Player_Position_Step# + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!SetVariable Position_Forward "+#Player_Position_Step#"][!SetVariable Position_Backward "-#Player_Position_Step#"][!UpdateMeter bar.PROGRESS][!UpdateMeter bar.PROGRESS_SHADOW][!Redraw]
 MouseScrollDownAction            = [!SetVariable Player_Position_Step "(#Player_Position_Step# - 1)"][!WriteKeyValue Variables Player_Position_Step "(#Player_Position_Step# - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP][!UpdateMeter text.Main_Settings_PLAYER_POSITION_STEP_Value][!Redraw]

; - MAIN SETTINGS TEXTS END

; --- BEHAVIOUR SETTINGS TEXTS BEGINNING

; - BEHAVIOUR SETTINGS TEXTS END

; --- HARDWARE SETTINGS TEXTS BEGINNING

; --- RIGHT TOP CORNER

[text.HARDWARE_Settings_NET_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 35)
 W                                = 55
 Text                             = "NET MAX:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 1-2"]
 RightMouseUpAction               = [!SetVariable Net_Max "#Default_Net_Max#"][!WriteKeyValue Variables Net_Max "#Default_Net_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]
 MouseScrollUpAction              = [!SetVariable Net_Max "(#Net_Max# + 5)"][!WriteKeyValue Variables Net_Max "(#Net_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]
 MouseScrollDownAction            = [!SetVariable Net_Max "(#Net_Max# - 5)"][!WriteKeyValue Variables Net_Max "(#Net_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]


[text.HARDWARE_Settings_NET_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 35)
 W                                = 20
 Text                             = #Net_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 1-2"]
 RightMouseUpAction               = [!SetVariable Net_Max "#Default_Net_Max#"][!WriteKeyValue Variables Net_Max "#Default_Net_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]
 MouseScrollUpAction              = [!SetVariable Net_Max "(#Net_Max# + 5)"][!WriteKeyValue Variables Net_Max "(#Net_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]
 MouseScrollDownAction            = [!SetVariable Net_Max "(#Net_Max# - 5)"][!WriteKeyValue Variables Net_Max "(#Net_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_NET_MAX][!UpdateMeter text.HARDWARE_Settings_NET_MAX_Value][!UpdateMeasure sensor.NET_TOTAL][!Redraw]

[text.HARDWARE_Settings_PING_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 52)
 W                                = 55
 Text                             = "PING MAX:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 3-4"]
 RightMouseUpAction               = [!SetVariable Ping_Max "#Default_Ping_Max#"][!WriteKeyValue Variables Ping_Max "#Default_Ping_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]
 MouseScrollUpAction              = [!SetVariable Ping_Max "(#Ping_Max# + 10)"][!WriteKeyValue Variables Ping_Max "(#Ping_Max# + 10)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]
 MouseScrollDownAction            = [!SetVariable Ping_Max "(#Ping_Max# - 10)"][!WriteKeyValue Variables Ping_Max "(#Ping_Max# - 10)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]

[text.HARDWARE_Settings_PING_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 52)
 W                                = 20
 Text                             = #Ping_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 3-4"]
 RightMouseUpAction               = [!SetVariable Ping_Max "#Default_Ping_Max#"][!WriteKeyValue Variables Ping_Max "#Default_Ping_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]
 MouseScrollUpAction              = [!SetVariable Ping_Max "(#Ping_Max# + 10)"][!WriteKeyValue Variables Ping_Max "(#Ping_Max# + 10)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]
 MouseScrollDownAction            = [!SetVariable Ping_Max "(#Ping_Max# - 10)"][!WriteKeyValue Variables Ping_Max "(#Ping_Max# - 10)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.PING][!UpdateMeter text.HARDWARE_Settings_PING_MAX][!UpdateMeter text.HARDWARE_Settings_PING_MAX_Value][!UpdateMeter bar.PING][!Redraw]

[text.HARDWARE_Settings_PING_TIMEOUT]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 69)
 W                                = 55
 Text                             = "PING OUT:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 5-6"]
 RightMouseUpAction               = [!SetVariable Ping_Timeout "#Default_Ping_Timeout#"][!WriteKeyValue Variables Ping_Timeout "#Default_Ping_Timeout#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]
 MouseScrollUpAction              = [!SetVariable Ping_Timeout "(#Ping_Timeout# + 100)"][!WriteKeyValue Variables Ping_Timeout "(#Ping_Timeout# + 100)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]
 MouseScrollDownAction            = [!SetVariable Ping_Timeout "(#Ping_Timeout# - 100)"][!WriteKeyValue Variables Ping_Timeout "(#Ping_Timeout# - 100)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]

[text.HARDWARE_Settings_PING_TIMEOUT_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 69)
 W                                = 20
 Text                             = #Ping_Timeout#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 5-6"]
 RightMouseUpAction               = [!SetVariable Ping_Timeout "#Default_Ping_Timeout#"][!WriteKeyValue Variables Ping_Timeout "#Default_Ping_Timeout#" "#@#\#Config#"][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]
 MouseScrollUpAction              = [!SetVariable Ping_Timeout "(#Ping_Timeout# + 100)"][!WriteKeyValue Variables Ping_Timeout "(#Ping_Timeout# + 100)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]
 MouseScrollDownAction            = [!SetVariable Ping_Timeout "(#Ping_Timeout# - 100)"][!WriteKeyValue Variables Ping_Timeout "(#Ping_Timeout# - 100)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT][!UpdateMeter text.HARDWARE_Settings_PING_TIMEOUT_Value][!UpdateMeasure sensor.PING][!Redraw]

[text.HARDWARE_Settings_PING_HOST]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 86)
 W                                = 55
 Text                             = "HOST:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 7-8"]

[text.HARDWARE_Settings_PING_HOST_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 86)
 W                                = 50
 Text                             = #Ping_Host#
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 7-8"]

; - LEFT BOTTOM CORNER

[text.Main_Settings_DRIVE_ONE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 120)
 Text                             = "DRIVE ONE:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 9-10"]
 RightMouseUpAction               = [!SetVariable Drive_One "#Default_Drive_One#"][!WriteKeyValue Variables Drive_One "#Default_Drive_One#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_DRIVE_ONE][!UpdateMeter text.Main_Settings_DRIVE_ONE_Value][!UpdateMeasure m.Disk_One_Label][!Redraw]

[text.Main_Settings_DRIVE_ONE_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 120)
 W                                = 50
 Text                             = #Drive_One#
 StringCase                       = Upper
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 9-10"]
 RightMouseUpAction               = [!SetVariable Drive_One "#Default_Drive_One#"][!WriteKeyValue Variables Drive_One "#Default_Drive_One#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_DRIVE_ONE][!UpdateMeter text.Main_Settings_DRIVE_ONE_Value][!UpdateMeasure m.Disk_One_Label][!Redraw]

[text.Main_Settings_DRIVE_TWO]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 137)
 Text                             = "DRIVE TWO:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 11-12"]
 RightMouseUpAction               = [!SetVariable Drive_Two "#Default_Drive_Two#"][!WriteKeyValue Variables Drive_Two "#Default_Drive_Two#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_DRIVE_TWO][!UpdateMeter text.Main_Settings_DRIVE_TWO_Value][!UpdateMeasure m.Disk_Two_Label][!Redraw]

[text.Main_Settings_DRIVE_TWO_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 137)
 W                                = 20
 StringCase                       = Upper
 Text                             = #Drive_Two#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 11-12"]
 RightMouseUpAction               = [!SetVariable Drive_Two "#Default_Drive_Two#"][!WriteKeyValue Variables Drive_Two "#Default_Drive_Two#" "#@#\#Config#"][!UpdateMeter text.Main_Settings_DRIVE_TWO][!UpdateMeter text.Main_Settings_DRIVE_TWO_Value][!UpdateMeasure m.Disk_Two_Label][!Redraw]

[text.Main_Settings_TEMP_FOLDER]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 154)
 Text                             = "TEMP:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 13-14"]
 RightMouseUpAction               = [!SetVariable Temp_Folder "#Default_Temp_Folder#"][!WriteKeyValue Variables Temp_Folder "#Default_Temp_Folder#" "#@#\#Config#"][!UpdateMeasure m.Temp_Size][!UpdateMeter text.Main_Settings_TEMP_FOLDER][!UpdateMeter text.Main_Settings_TEMP_FOLDER_Value][!Redraw]

[text.Main_Settings_TEMP_FOLDER_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 154)
 W                                = 50
 Text                             = #temp_folder#
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 13-14"]
 RightMouseUpAction               = [!SetVariable Temp_Folder "#Default_Temp_Folder#"][!WriteKeyValue Variables Temp_Folder "#Default_Temp_Folder#" "#@#\#Config#"][!UpdateMeasure m.Temp_Size][!UpdateMeter text.Main_Settings_TEMP_FOLDER][!UpdateMeter text.Main_Settings_TEMP_FOLDER_Value][!Redraw]

[text.Main_Settings_CACHE_FOLDER]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 171)
 Text                             = "CACHE:"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 15-16"]
 RightMouseUpAction               = [!SetVariable Cache_Folder "#Default_Cache_Folder#"][!WriteKeyValue Variables Cache_Folder "#Default_Cache_Folder#" "#@#\#Config#"][!UpdateMeasure m.Cache_Size][!UpdateMeter text.Main_Settings_CACHE_FOLDER][!UpdateMeter text.Main_Settings_CACHE_FOLDER_Value][!Redraw]

[text.Main_Settings_CACHE_FOLDER_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 171)
 W                                = 50
 Text                             = #cache_folder#
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseDownAction              = [!SetVariable Last_Zpos "#Skin_Zpos#"][!Zpos "0" "AuroraBar\Bar"]
 LeftMouseUpAction                = [!CommandMeasure m.Input_Hardware "Executebatch 15-16"]
 RightMouseUpAction               = [!SetVariable Cache_Folder "#Default_Cache_Folder#"][!WriteKeyValue Variables Cache_Folder "#Default_Cache_Folder#" "#@#\#Config#"][!UpdateMeasure m.Cache_Size][!UpdateMeter text.Main_Settings_CACHE_FOLDER][!UpdateMeter text.Main_Settings_CACHE_FOLDER_Value][!Redraw]

; - RIGHT TOP CORNER

[text.HARDWARE_Settings_CPU_LOAD_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 35)
 Text                             = ":CPU LOAD"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable CPU_Load_Max "#Default_CPU_Load_Max#"][!WriteKeyValue Variables CPU_Load_Max "#Default_CPU_Load_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable CPU_Load_Max "(#CPU_Load_Max# + 5)"][!WriteKeyValue Variables CPU_Load_Max "(#CPU_Load_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable CPU_Load_Max "(#CPU_Load_Max# - 5)"][!WriteKeyValue Variables CPU_Load_Max "(#CPU_Load_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]

[text.HARDWARE_Settings_CPU_LOAD_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 35)
 W                                = 20
 Text                             = #CPU_Load_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable CPU_Load_Max "#Default_CPU_Load_Max#"][!WriteKeyValue Variables CPU_Load_Max "#Default_CPU_Load_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable CPU_Load_Max "(#CPU_Load_Max# + 5)"][!WriteKeyValue Variables CPU_Load_Max "(#CPU_Load_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable CPU_Load_Max "(#CPU_Load_Max# - 5)"][!WriteKeyValue Variables CPU_Load_Max "(#CPU_Load_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_LOAD_MAX_Value][!Redraw]

[text.HARDWARE_Settings_GPU_LOAD_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 52)
 Text                             = ":GPU LOAD"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable GPU_Load_Max "#Default_GPU_Load_Max#"][!WriteKeyValue Variables GPU_Load_Max "#Default_GPU_Load_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable GPU_Load_Max "(#GPU_Load_Max# + 5)"][!WriteKeyValue Variables GPU_Load_Max "(#GPU_Load_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable GPU_Load_Max "(#GPU_Load_Max# - 5)"][!WriteKeyValue Variables GPU_Load_Max "(#GPU_Load_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]

[text.HARDWARE_Settings_GPU_LOAD_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 52)
 W                                = 20
 Text                             = #GPU_Load_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable GPU_Load_Max "#Default_GPU_Load_Max#"][!WriteKeyValue Variables GPU_Load_Max "#Default_GPU_Load_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable GPU_Load_Max "(#GPU_Load_Max# + 5)"][!WriteKeyValue Variables GPU_Load_Max "(#GPU_Load_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable GPU_Load_Max "(#GPU_Load_Max# - 5)"][!WriteKeyValue Variables GPU_Load_Max "(#GPU_Load_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_LOAD_MAX_Value][!Redraw]

[text.HARDWARE_Settings_CPU_TEMP_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 69)
 Text                             = ":CPU TEMP"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable CPU_Temp_Max "#Default_CPU_Temp_Max#"][!WriteKeyValue Variables CPU_Temp_Max "#Default_CPU_Temp_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable CPU_Temp_Max "(#CPU_Temp_Max# + 5)"][!WriteKeyValue Variables CPU_Temp_Max "(#CPU_Temp_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable CPU_Temp_Max "(#CPU_Temp_Max# - 5)"][!WriteKeyValue Variables CPU_Temp_Max "(#CPU_Temp_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]

[text.HARDWARE_Settings_CPU_TEMP_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 69)
 W                                = 20
 Text                             = #CPU_Temp_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable CPU_Temp_Max "#Default_CPU_Temp_Max#"][!WriteKeyValue Variables CPU_Temp_Max "#Default_CPU_Temp_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable CPU_Temp_Max "(#CPU_Temp_Max# + 5)"][!WriteKeyValue Variables CPU_Temp_Max "(#CPU_Temp_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable CPU_Temp_Max "(#CPU_Temp_Max# - 5)"][!WriteKeyValue Variables CPU_Temp_Max "(#CPU_Temp_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_CPU_TEMP_MAX_Value][!Redraw]

[text.HARDWARE_Settings_GPU_TEMP_MAX]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 86)
 Text                             = ":GPU TEMP"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable GPU_Temp_Max "#Default_GPU_Temp_Max#"][!WriteKeyValue Variables GPU_Temp_Max "#Default_GPU_Temp_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable GPU_Temp_Max "(#GPU_Temp_Max# + 5)"][!WriteKeyValue Variables GPU_Temp_Max "(#GPU_Temp_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable GPU_Temp_Max "(#GPU_Temp_Max# - 5)"][!WriteKeyValue Variables GPU_Temp_Max "(#GPU_Temp_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]

[text.HARDWARE_Settings_GPU_TEMP_MAX_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 86)
 W                                = 20
 Text                             = #GPU_Temp_Max#
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Cursor_Slider_Y#
 RightMouseUpAction               = [!SetVariable GPU_Temp_Max "#Default_GPU_Temp_Max#"][!WriteKeyValue Variables GPU_Temp_Max "#Default_GPU_Temp_Max#" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable GPU_Temp_Max "(#GPU_Temp_Max# + 5)"][!WriteKeyValue Variables GPU_Temp_Max "(#GPU_Temp_Max# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable GPU_Temp_Max "(#GPU_Temp_Max# - 5)"][!WriteKeyValue Variables GPU_Temp_Max "(#GPU_Temp_Max# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX][!UpdateMeter text.HARDWARE_Settings_GPU_TEMP_MAX_Value][!Redraw]

; - RIGHT BOTTOM CORNER

[text.HARDWARE_Settings_VRAM]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 120)
 Text                             = ":VRAM INST"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable VRAM_Instance_State "(1 - #VRAM_Instance_State#)"][!WriteKeyValue Variables VRAM_Instance_State "(1 - #VRAM_Instance_State#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_VRAM][!UpdateMeter text.HARDWARE_Settings_VRAM_Value][!UpdateMeasure sensor.VRAM][!UpdateMeter bar.VRAM_LOAD][!UpdateMeter text.dynamic.VRAM_LOAD_VALUE][!Redraw]

[text.HARDWARE_Settings_VRAM_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 120)
 W                                = 50
 Text                             = VIDEO
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable VRAM_Instance_State "(1 - #VRAM_Instance_State#)"][!WriteKeyValue Variables VRAM_Instance_State "(1 - #VRAM_Instance_State#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_VRAM][!UpdateMeter text.HARDWARE_Settings_VRAM_Value][!UpdateMeasure sensor.VRAM][!UpdateMeter bar.VRAM_LOAD][!UpdateMeter text.dynamic.VRAM_LOAD_VALUE][!Redraw]

[text.HARDWARE_Settings_AUDIO_DEVICES]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 137)
 Text                             = ":AUDIO DEVS"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Audio_Devices_State "(1 - #Audio_Devices_State#)"][!WriteKeyValue Variables Audio_Devices_State "(1 - #Audio_Devices_State#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_AUDIO_DEVICES_Value][!UpdateMeter text.HARDWARE_Settings_AUDIO_DEVICES][!UpdateMeter t.Headphones][!UpdateMeter t.Speakers][!Redraw]

[text.HARDWARE_Settings_AUDIO_DEVICES_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        =#Font_Warning_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 137)
 W                                = 50
 Text                             = ""
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Audio_Devices_State "(1 - #Audio_Devices_State#)"][!WriteKeyValue Variables Audio_Devices_State "(1 - #Audio_Devices_State#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter text.HARDWARE_Settings_AUDIO_DEVICES_Value][!UpdateMeter text.HARDWARE_Settings_AUDIO_DEVICES][!UpdateMeter t.Headphones][!UpdateMeter t.Speakers][!Redraw]

[text.HARDWARE_Settings_BLUETOOTH]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 154)
 Text                             = ":BLUETOOTH"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Bluetooth_Visible "(1 - #Bluetooth_Visible#)"][!WriteKeyValue Variables Bluetooth_Visible "(1 - #Bluetooth_Visible#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter t.Bluetooth_Switcher][!UpdateMeter text.HARDWARE_Settings_BLUETOOTH][!Updatemeter text.HARDWARE_Settings_BLUETOOTH_Value][!Redraw]

[text.HARDWARE_Settings_BLUETOOTH_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        =#Font_Warning_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 154)
 W                                = 50
 Text                             = ""
 StringCase                       = Upper
 ClipString                       = 1
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 ; ; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Bluetooth_Visible "(1 - #Bluetooth_Visible#)"][!WriteKeyValue Variables Bluetooth_Visible "(1 - #Bluetooth_Visible#)" "#@#\#Config#"][!UpdateMeasure m.SWITCHERS_CONTROLLER][!UpdateMeter t.Bluetooth_Switcher][!UpdateMeter text.HARDWARE_Settings_BLUETOOTH][!Updatemeter text.HARDWARE_Settings_BLUETOOTH_Value][!Redraw]

[text.HARDWARE_Settings_HWINFO_SMV]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 171)
 W                                = 80
 Text                             = "OPEN  HWINFO SMV"
 DynamicVariables                 = 1
 Group                            = #settings_hardware#
 Hidden                           = #Settings_Hardware#
 LeftMouseUpAction                = [!CommandMeasure m.HWiNFO_SMV "Run"]

; - HARDWARE SETTINGS TEXTS END

; --- BEHAVIOUR BEGINNING

; - LEFT TOP CORNER

[text.Behaviour_Settings_ZPOS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 35)
 W                                = 55
 Text                             = "ZPOS:"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 RightMouseUpAction               = [!SetVariable Skin_Zpos "#Default_Skin_Zpos#"][!WriteKeyValue Variables Skin_Zpos "#Default_Skin_Zpos#" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Skin_Zpos "((#Skin_Zpos#) - 1)"][!WriteKeyValue Variables Skin_Zpos "((#Skin_Zpos#) - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable Skin_Zpos "((#Skin_Zpos#) + 1)"][!WriteKeyValue Variables Skin_Zpos "((#Skin_Zpos#) + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

[text.Behaviour_Settings_ZPOS_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 35)
 W                                = 20
 Text                             = "#Skin_Zpos#"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 RightMouseUpAction               = [!SetVariable Skin_Zpos "#Default_Skin_Zpos#"][!WriteKeyValue Variables Skin_Zpos "#Default_Skin_Zpos#" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Skin_Zpos "((#Skin_Zpos#) - 1)"][!WriteKeyValue Variables Skin_Zpos "((#Skin_Zpos#) - 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable Skin_Zpos "((#Skin_Zpos#) + 1)"][!WriteKeyValue Variables Skin_Zpos "((#Skin_Zpos#) + 1)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_ZPOS][!UpdateMeter text.Behaviour_Settings_ZPOS_Value][!Redraw]

[text.Behaviour_Settings_DRAG]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 52)
 W                                = 55
 Text                             = "DRAGGABLE:"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!SetVariable Draggable "(1 - #Draggable#)"][!WriteKeyValue Variables Draggable "(1 - #Draggable#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_DRAG][!UpdateMeter text.Behaviour_Settings_DRAG_Value][!Redraw]

[text.Behaviour_Settings_DRAG_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 52)
 W                                = 20
 Text                             = "YES"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Draggable "(1 - #Draggable#)"][!WriteKeyValue Variables Draggable "(1 - #Draggable#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_DRAG][!UpdateMeter text.Behaviour_Settings_DRAG_Value][!Redraw]

[text.Behaviour_Settings_SNAPEDGE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 69)
 W                                = 55
 Text                             = "SNAPEDGE:"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!SetVariable Snapedge "(1 - #Snapedge#)"][!WriteKeyValue Variables Snapedge "(1 - #Snapedge#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_SNAPEDGE][!UpdateMeter text.Behaviour_Settings_SNAPEDGE_Value][!Redraw]

[text.Behaviour_Settings_SNAPEDGE_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 69)
 W                                = 20
 Text                             = "YES"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Hand#
 LeftMouseUpAction                = [!SetVariable Snapedge "(1 - #Snapedge#)"][!WriteKeyValue Variables Snapedge "(1 - #Snapedge#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_SNAPEDGE][!UpdateMeter text.Behaviour_Settings_SNAPEDGE_Value][!Redraw]

[text.Behaviour_Settings_KEEPONSCREEN]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 86)
 W                                = 55
 Text                             = "ONSCREEN:"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!SetVariable Keep_On_Screen "(1 - #Keep_On_Screen#)"][!WriteKeyValue Variables Keep_On_Screen "(1 - #Keep_On_Screen#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_KEEPONSCREEN][!UpdateMeter text.Behaviour_Settings_KEEPONSCREEN_Value][!Redraw]

[text.Behaviour_Settings_KEEPONSCREEN_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 86)
 Text                             = "YES"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!SetVariable Keep_On_Screen "(1 - #Keep_On_Screen#)"][!WriteKeyValue Variables Keep_On_Screen "(1 - #Keep_On_Screen#)" "#@#\#Config#"][!UpdateMeasure sensor.BEHAVIOUR][!UpdateMeter text.Behaviour_Settings_KEEPONSCREEN][!UpdateMeter text.Behaviour_Settings_KEEPONSCREEN_Value][!Redraw]

; - RIGHT TOP CORNER

[text.Behaviour_Settings_WINDOW_X]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 35)
 Text                             = ":X WINDOW"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Window_X "(#Window_X# + 10)"][!WriteKeyValue Variables Window_X "(#Window_X# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Window_X "(#Window_X# - 10)"][!WriteKeyValue Variables Window_X "(#Window_X# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Window_X "#Default_Window_X#"][!WriteKeyValue Variables Window_X "#Default_Window_X#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_WINDOW_X_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 35)
 W                                = 20
 Text                             = #Window_X#px
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Window_X "(#Window_X# + 10)"][!WriteKeyValue Variables Window_X "(#Window_X# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Window_X "(#Window_X# - 10)"][!WriteKeyValue Variables Window_X "(#Window_X# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Window_X "#Default_Window_X#"][!WriteKeyValue Variables Window_X "#Default_Window_X#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_X][!UpdateMeter text.Behaviour_Settings_WINDOW_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_WINDOW_Y]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 52)
 Text                             = ":Y WINDOW"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Window_Y "(#Window_Y# + 10)"][!WriteKeyValue Variables Window_Y "(#Window_Y# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Window_Y "(#Window_Y# - 10)"][!WriteKeyValue Variables Window_Y "(#Window_Y# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Window_Y "#Default_Window_Y#"][!WriteKeyValue Variables Window_Y "#Default_Window_Y#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_WINDOW_Y_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 52)
 W                                = 20
 Text                             = #Window_Y#px
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Window_Y "(#Window_Y# + 10)"][!WriteKeyValue Variables Window_Y "(#Window_Y# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Window_Y "(#Window_Y# - 10)"][!WriteKeyValue Variables Window_Y "(#Window_Y# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Window_Y "#Default_Window_Y#"][!WriteKeyValue Variables Window_Y "#Default_Window_Y#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_WINDOW_Y][!UpdateMeter text.Behaviour_Settings_WINDOW_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_ANCHOR_X]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 69)
 Text                             = ":X ANCHOR"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Anchor_X "(#Anchor_X# + 10)"][!WriteKeyValue Variables Anchor_X "(#Anchor_X# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Anchor_X "(#Anchor_X# - 10)"][!WriteKeyValue Variables Anchor_X "(#Anchor_X# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Anchor_X "#Default_Anchor_X#"][!WriteKeyValue Variables Anchor_X "#Default_Anchor_X#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_ANCHOR_X_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 69)
 W                                = 20
 Text                             = #Anchor_X#%
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Anchor_X "(#Anchor_X# + 10)"][!WriteKeyValue Variables Anchor_X "(#Anchor_X# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Anchor_X "(#Anchor_X# - 10)"][!WriteKeyValue Variables Anchor_X "(#Anchor_X# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Anchor_X "#Default_Anchor_X#"][!WriteKeyValue Variables Anchor_X "#Default_Anchor_X#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_X][!UpdateMeter text.Behaviour_Settings_ANCHOR_X_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_ANCHOR_Y]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 86)
 Text                             = ":Y ANCHOR"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Anchor_Y "(#Anchor_Y# + 10)"][!WriteKeyValue Variables Anchor_Y "(#Anchor_Y# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Anchor_Y "(#Anchor_Y# - 10)"][!WriteKeyValue Variables Anchor_Y "(#Anchor_Y# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Anchor_Y "#Default_Anchor_Y#"][!WriteKeyValue Variables Anchor_Y "#Default_Anchor_Y#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_ANCHOR_Y_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 86)
 W                                = 20
 Text                             = #Anchor_Y#%
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
;; MouseActionCursorName            = #Cursor_Slider_Y#
 LeftMouseUpAction                = [!CommandMeasure m.Input_Behaviour "Executebatch 0-0"]
 MouseScrollUpAction              = [!SetVariable Anchor_Y "(#Anchor_Y# + 10)"][!WriteKeyValue Variables Anchor_Y "(#Anchor_Y# + 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Anchor_Y "(#Anchor_Y# - 10)"][!WriteKeyValue Variables Anchor_Y "(#Anchor_Y# - 10)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 RightMouseUpAction               = [!SetVariable Anchor_Y "#Default_Anchor_Y#"][!WriteKeyValue Variables Anchor_Y "#Default_Anchor_Y#" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y][!UpdateMeter text.Behaviour_Settings_ANCHOR_Y_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

; - LEFT BOTTOM CORNER

[text.Behaviour_Settings_ALPHA]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 120)
 W                                = 55
 Text                             = "SKIN ALPHA:"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 RightMouseUpAction               = [!SetVariable Skin_Alpha "#Default_Skin_Alpha#"][!WriteKeyValue Variables Skin_Alpha "#Default_Skin_Aplha#" "#@#\#Config#"][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable Skin_Alpha "(#Skin_Alpha# + 5)"][!WriteKeyValue Variables Skin_Alpha "(#Skin_Alpha# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Skin_Alpha "(#Skin_Alpha# - 5)"][!WriteKeyValue Variables Skin_Alpha "(#Skin_Alpha# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]

[text.Behaviour_Settings_ALPHA_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 950
 Y                                = (#Pad_Top# + 120)
 W                                = 20
 Text                             = "#Skin_Alpha#"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 RightMouseUpAction               = [!SetVariable Skin_Alpha "#Default_Skin_Alpha#"][!WriteKeyValue Variables Skin_Alpha "#Default_Skin_Aplha#" "#@#\#Config#"][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]
 MouseScrollUpAction              = [!SetVariable Skin_Alpha "(#Skin_Alpha# + 5)"][!WriteKeyValue Variables Skin_Alpha "(#Skin_Alpha# + 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]
 MouseScrollDownAction            = [!SetVariable Skin_Alpha "(#Skin_Alpha# - 5)"][!WriteKeyValue Variables Skin_Alpha "(#Skin_Alpha# - 5)" "#@#\#Config#"][!UpdateMeasure m.VALUES_CONTROLLER][!SetTransparency #Skin_Alpha#][!UpdateMeter text.Behaviour_Settings_ALPHA][!UpdateMeter text.Behaviour_Settings_ALPHA_Value][!Redraw]

[text.Behaviour_Settings_HOTKEYS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 137)
 W                                = 85
 Text                             = "HOTKEYS SETTINGS"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = #@#\Hotkeys.inc

[text.Behaviour_Settings_RESET_HARDWARE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 154)
 W                                = 85
 Text                             = "RESET   HARDWARE"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 

[text.Behaviour_Settings_DEFAULT_SETTINGS]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Warning_Color#
 X                                = 875
 Y                                = (#Pad_Top# + 171)
 W                                = 85
 Text                             = "DEFAULT  SETTINGS"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 MiddleMouseUpAction              = #SET_DEFAULT#



; - RIGHT BOTTOM CORNER

[text.Behaviour_Settings_MONITOR]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 120)
 Text                             = ":MONITOR"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 MouseScrollUpAction              = [!SetVariable Monitor_Num "(#Monitor_Num# + 1)"][!WriteKeyValue Variables Monitor_Num "(#Monitor_Num# + 1)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Monitor_Num "(#Monitor_Num# - 1)"][!WriteKeyValue Variables Monitor_Num "(#Monitor_Num# - 1)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 
[text.Behaviour_Settings_MONITOR_Value]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 FontColor                        = #Font_Value_Color#
 X                                = 969
 Y                                = (#Pad_Top# + 120)
 W                                = 20
 Text                             = @#Monitor_Num#
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = 
 MouseScrollUpAction              = [!SetVariable Monitor_Num "(#Monitor_Num# + 1)"][!WriteKeyValue Variables Monitor_Num "(#Monitor_Num# + 1)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]
 MouseScrollDownAction            = [!SetVariable Monitor_Num "(#Monitor_Num# - 1)"][!WriteKeyValue Variables Monitor_Num "(#Monitor_Num# - 1)" "#@#\#Config#"][!UpdateMeter text.Behaviour_Settings_MONITOR][!UpdateMeter text.Behaviour_Settings_MONITOR_Value][!UpdateMeasure m.VALUES_CONTROLLER][!UpdateMeasure sensor.BEHAVIOUR][!Redraw]

[text.Behaviour_Settings_MANAGE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 137)
 Text                             = "MANAGE    AURORA"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!Manage Skins "AuroraBar\Bar" "AuroraBar.ini"]

[text.Behaviour_Settings_REFRESH]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 154)
 Text                             = "RENEW RAINMETER"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!RefreshApp]

[text.Behaviour_Settings_ABOUT]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 FontColor                        = #Font_Value_Color#
 X                                = 1048
 Y                                = (#Pad_Top# + 171)
 Text                             = "ABOUT RAINMETER"
 DynamicVariables                 = 1
 Group                            = #settings_behaviour#
 Hidden                           = #Settings_Behaviour#
 LeftMouseUpAction                = [!About]

; - TEXTS END

; --- MENU BUTTONS BEGINNING

; - The buttons that looks like crystals

[c.shape_Top_Left_Gear_E]
 Meter                            = SHAPE
 MeterStyle                       = s.Color_Elements
 X                                = 882
 Y                                = (#Pad_Top# + 32)
 MyPath                           = 0, 0 | LineTo 12, 0 | LineTo 36, 24 | LineTo 36, 36 | LineTo 24, 36 | LineTo 0, 12
 Modifier                         = Rotate 0
 Group                            = #config#
 DynamicVariables                 = 1
 Hidden                           = #Settings_Menu#
 MouseOverAction                  = [!SetOption c.shape_Top_Left_Gear_E MeterStyle "s.Color_Elements_Filled"][Play #MouseOver_2#][!SetVariable Settings_Main_Temp "0"][!UpdateMeter c.shape_Top_Left_Gear_E][!UpdateMeter t.System_Volume][!UpdateMeter text.Main_Settings_Menu][!Redraw]
 MouseLeaveAction                 =
 LeftMouseUpAction                = [!SetOption c.shape_Top_Left_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Main "0"][!WriteKeyValue Variables Settings_Main " 0" "#@#\#Config#"]    [!SetVariable Settings_Temp_Control " 0"][!WriteKeyValue Variables Settings_Temp_Control " 0" "#@#\#Config#"] #Settings_Menu_Main_Updater#

[c.shape_Top_Right_Gear_E]
 Meter                            = SHAPE
 MeterStyle                       = s.Color_Elements
 X                                = 1003
 Y                                = (#Pad_Top# + 32)
 MyPath                           = 0, 0 | LineTo 12, 0 | LineTo 36, 24 | LineTo 36, 36 | LineTo 24, 36 | LineTo 0, 12
 Modifier                         = Rotate 90
 Group                            = #config#
 DynamicVariables                 = 1
 Hidden                           = #Settings_Menu#
 MouseOverAction                  = [!SetOption c.shape_Top_Right_Gear_E MeterStyle "s.Color_Elements_Filled"][Play #MouseOver_2#][!SetVariable Settings_Color_Temp "0"][!UpdateMeter c.shape_Top_Right_Gear_E][!UpdateMeter t.Player_Volume][!UpdateMeter text.Color_Settings_Menu][!Redraw]
 MouseLeaveAction                 =
 LeftMouseUpAction                = [!SetOption c.shape_Top_Right_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Color "0"][!WriteKeyValue Variables Settings_Color " 0" "#@#\#Config#"]       [!SetVariable Settings_Temp_Control " 0"][!UpdateMeasure f.Menu_Control][!WriteKeyValue Variables Settings_Temp_Control " 0" "#@#\#Config#"]#Settings_Menu_Color_Updater#

[c.shape_Bottom_Left_Gear_E]
 Meter                            = SHAPE
 MeterStyle                       = s.Color_Elements
 X                                = 882
 Y                                = (#Pad_Top# + 153)
 MyPath                           = 0, 0 | LineTo 12, 0 | LineTo 36, 24 | LineTo 36, 36 | LineTo 24, 36 | LineTo 0, 12
 Modifier                         = Rotate 90
 Group                            = #config#
 DynamicVariables                 = 1
 Hidden                           = #Settings_Menu#
 MouseOverAction                  = [!SetOption c.shape_Bottom_Left_Gear_E MeterStyle "s.Color_Elements_Filled"][Play #MouseOver_2#][!SetVariable Settings_Behaviour_Temp "0"][!UpdateMeter c.shape_Bottom_Left_Gear_E][!UpdateMeter text.dynamic.DAY][!UpdateMeter text.Behaviour_Settings_Menu][!Redraw]
 MouseLeaveAction                 =
 LeftMouseUpAction                = [!SetOption c.shape_Bottom_Left_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Behaviour "0"][!WriteKeyValue Variables Settings_Behaviour " 0" "#@#\#Config#"]    [!SetVariable Settings_Temp_Control " 0"][!UpdateMeasure f.Menu_Control][!WriteKeyValue Variables Settings_Temp_Control " 0" "#@#\#Config#"]#Settings_Menu_Behaviour_Updater#

[c.shape_Bottom_Right_Gear_E]
 Meter                            = SHAPE
 MeterStyle                       = s.Color_Elements
 X                                = 1003
 Y                                = (#Pad_Top# + 153)
 MyPath                           = 0, 0 | LineTo 12, 0 | LineTo 36, 24 | LineTo 36, 36 | LineTo 24, 36 | LineTo 0, 12
 Modifier                         = Rotate 0
 Group                            = #config#
 DynamicVariables                 = 1
 Hidden                           = #Settings_Menu#
 MouseOverAction                  = [!SetOption c.shape_Bottom_Right_Gear_E MeterStyle "s.Color_Elements_Filled"][Play #MouseOver_2#][!SetVariable Settings_Hardware_Temp "0"][!UpdateMeter c.shape_Bottom_Right_Gear_E][!UpdateMeter text.dynamic.MONTH][!UpdateMeter text.Hardware_Settings_Menu][!Redraw]
 MouseLeaveAction                 = 
 LeftMouseUpAction                = [!SetOption c.shape_Bottom_Right_Gear_E MeterStyle "s.Color_Elements"][!SetVariable Settings_Hardware "0"][!WriteKeyValue Variables Settings_Hardware " 0" "#@#\#Config#"]      [!SetVariable Settings_Temp_Control " 0"][!UpdateMeasure f.Menu_Control][!WriteKeyValue Variables Settings_Temp_Control " 0" "#@#\#Config#"]#Settings_Menu_Hardware_Updater#

; - MENU BUTTONS END

; --- X SHAPE BEGINNING

; - The cross that closes settings

[c.shape_X_1]
 Meter                            = SHAPE
 Shape                            = Line 10, 10, 25, 25 | StrokeColor #Font_Warning_Color# | StrokeWidth 4
 X                                = 943
 Y                                = (#Pad_Top# + 93)
 LineColor                        = #Font_Warning_Color#
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Close#

[c.shape_X_2]
 Meter                            = SHAPE
 Shape                            = Line 25, 10, 10, 25 | StrokeColor #Font_Warning_Color# | StrokeWidth 4
 X                                = 943
 Y                                = (#Pad_Top# + 93)
 LineColor                        = #Font_Warning_Color#
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Close#

[c.shape_Round_Close]
 Meter                            = SHAPE
 Shape                            = Ellipse 0, 0, 10, 10 | Fill Color 0,0,0,1 | StrokeWidth 0
 X                                = 960
 Y                                = (#Pad_Top# + 110)
 LineColor                        = #Font_Warning_Color#
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = #Settings_Close#
 LeftMouseUpAction                = [!SetVariable Aurora_BG_Behaviour_State "1"] [!WriteKeyValue Variables Aurora_BG_Behaviour_State " 1" "#@#\#Config#"]   [!SetVariable Settings_Main "1"][!WriteKeyValue Variables Settings_Main " 1" "#@#\#Config#"][!SetVariable Settings_Color "1"][!WriteKeyValue Variables Settings_Color " 1" "#@#\#Config#"][!SetVariable Settings_Behaviour "1"][!WriteKeyValue Variables Settings_Behaviour " 1" "#@#\#Config#"][!SetVariable Settings_Hardware "1"][!WriteKeyValue Variables Settings_Hardware " 1" "#@#\#Config#"][!SetVariable Settings_Menu " 0"][!SetVariable Settings_Temp_Control " 1"][!WriteKeyValue Variables Settings_Temp_Control " 1" "#@#\#Config#"] #Settings_Menu_Close_Updater#
 MouseOverAction                  = [Play #MouseOver_1#]

; - X SHAPE END

; --- DIRECT LINES BEGINNING

; - They separates config "square" for 4 part

; - TOP LINE

[shape.Settings_Menu_Top_Line]
 Meter                            = ROUNDLINE
 LineColor                        = #Bar_BG_Color#
 StartAngle                       = (RAD(90))
 LineStart                        = 0
 LineLength                       = 60
 LineWidth                        = 2
 X                                = 960
 Y                                = (#Pad_Top# + 38)
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = ( 1 - #Aurora_BG_Behaviour_State# * #Settings_Color# )

; - BOTTOM LINE

[shape.Settings_Menu_Bottom_Line]
 Meter                            = ROUNDLINE
 LineColor                        = #Bar_BG_Color#
 StartAngle                       = (RAD(90))
 LineStart                        = 0
 LineLength                       = 60
 LineWidth                        = 2
 X                                = 960
 Y                                = (#Pad_Top# + 122)
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = ( 1 - #Aurora_BG_Behaviour_State# * #Settings_Color# )

; - LEFT LINE

[shape.Settings_Menu_Left_Line]
 Meter                            = ROUNDLINE
 LineColor                        = #Bar_BG_Color#
 StartAngle                       = (RAD(0))
 LineStart                        = 0
 LineLength                       = 60
 LineWidth                        = 2
 X                                = 889
 Y                                = (#Pad_Top# + 111)
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = ( 1 - #Aurora_BG_Behaviour_State# * #Settings_Color# )

; - RIGHT LINE

[shape.Settings_Menu_Right_Line]
 Meter                            = ROUNDLINE
 LineColor                        = #Bar_BG_Color#
 StartAngle                       = (RAD(0))
 LineStart                        = 0
 LineLength                       = 60
 LineWidth                        = 2
 X                                = 971
 Y                                = (#Pad_Top# + 111)
 DynamicVariables                 = 1
 Group                            = #settings_menu#
 Hidden                           = ( 1 - #Aurora_BG_Behaviour_State# * #Settings_Color# )
