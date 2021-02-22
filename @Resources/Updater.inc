[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.3b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Updater module

[Variables]
 Version                           = 2.1.3b
 Build                             = 2131
 New_Build                         = [m.Updater_Parser_Check_Build]
 New_Version                       = [m.Updater_Parser_Check_Version]
 Download_URL                      = https://github.com/deflore08/AuroraBar/releases/download/#New_Version#/AuroraBar_#New_Version#.rmskin

[m.Updater_Parser_Parent]
 Measure                          = WebParser
 URL                              = https://forum.rainmeter.net/viewtopic.php?f=130&t=35830
 RegExp                           = (?siU)title="Build (.*)"><strong.*class="postlink">AuroraBar (.*)</a> 
 UpdateRate                       = 60
 Debug                            = 1
 Group                            = #updater#

[m.Updater_Parser_Check_Version]
 Measure                          = WebParser
 URL                              = [m.Updater_Parser_Parent]
 StringIndex                      = 2
 DynamicVariables                 = 1
 Group                            = #updater#

[m.Updater_Parser_Check_Build]
 Measure                          = WebParser
 URL                              = [m.Updater_Parser_Parent]
 StringIndex                      = 1
 DynamicVariables                 = 1
 Group                            = #updater#
     ifCondition                  = m.Updater_Parser_Check_Build > #Build#
          ifTrueAction            = [!SetOption text.Main_Check_Version Text "AVAILABLE"][!SetOption text.Main_Check_Version FontColor "#*Font_Warning_Color*#"][!SetOption text.Main_Check_Version_Value FontColor "#*Font_Warning_Color*#"]
     ifCondition2                 = m.Updater_Parser_Check_Build = #Build#
          ifTrueAction2           = [!SetOption text.Main_Check_Version Text "UP TO DATE"][!SetOption text.Main_Check_Version_Value FontColor "#*Font_Value_Color*#"][!SetOption text.Main_Check_Version FontColor "#*Font_Color*#"]
     ifCondition3                 = m.Updater_Parser_Check_Build < #Build#
          ifTrueAction3           = [!SetOption text.Main_Check_Version Text "CUSTOM"][!SetOption text.Main_Check_Version_Value FontColor "#*Font_Warning_Color*#"][!SetOption text.Main_Check_Version FontColor "#*Font_Warning_Color*#"]
     ifConditionMode              = 1

[m.Updater_Downloader]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path #Update_Folder# -ItemType Directory -Force #CRLF# $client = new-object System.Net.WebClient #CRLF# $client.DownloadFile("""#Download_URL#""", """#Update_Folder#\AuroraBar_#New_Version#.rmskin""")
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Updater#
 FinishAction                     = [!SetVariable Update_Download_Completed "1"][!WriteKeyValue Variables Update_Download_Completed "1" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER]

[shell.BACKUP_GLOBAL]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Config# -Destination #Backup_Config_Global# -Force #CRLF# New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Hardware# -Destination #Backup_Hardware_Global# -Force #CRLF# New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Hotkeys# -Destination #Backup_Hotkeys_Global# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Config#
 FinishAction                     = [!SetVariable Backups_Restored "0"][!WriteKeyValue Variables Backups_Restored "0" "#Service_Folder#\Service.inc"][!Log "[UPDATE] Backup succefully completed."][Play #Success_1#]

[shell.BACKUP_CONFIG]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Config# -Destination #Backup_Config_Global# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Config#
 FinishAction                     = [!Log "[UPDATE] Backuping Config list.."][!CommandMeasure shell.BACKUP_CONFIG_CHECK "Run"]
 Group                            = #updater#

[shell.BACKUP_HOTKEYS]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Hotkeys# -Destination #Backup_Hotkeys_Global# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Hotkeys#
 FinishAction                     = [!Log "[UPDATE] Backuping Hotkeys list.."][!CommandMeasure shell.BACKUP_HOTKEYS_CHECK "Run"]
 Group                            = #updater#

[shell.BACKUP_HARDWARE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path #Backup_Global_Folder# -ItemType Directory #CRLF# Copy-Item -Path #@#\#Hardware# -Destination #Backup_Hardware_Global# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Backup_Hardware#
 FinishAction                     = [!Log "[UPDATE] Backuping Hardware list.."][!CommandMeasure shell.BACKUP_HARDWARE_CHECK "Run"]
 Group                            = #updater#

[shell.BACKUP_CONFIG_CHECK]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Test-Path -Path '#Backup_Config_Global#' 
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 Group                            = #updater#
 ifMatch                          = ^True$
     ifMatchAction                = [!SetVariable Backup_Config_Completed "1"][!WriteKeyValue Variables Backup_Config_Completed "1" "#Service_Folder#\Service.inc"][!CommandMeasure shell.BACKUP_HOTKEYS "Run"][!Log "[UPDATE] Success! Config list backuped."]
 ifMatch2                         = ^False$
     ifMatchAction2               = [!SetVariable Backup_Config_Completed "0"][!WriteKeyValue Variables Backup_Config_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Fail! Config list isn't backuped."]

[shell.BACKUP_HOTKEYS_CHECK]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Test-Path -Path '#Backup_Hotkeys_Global#' 
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 Group                            = #updater#
 ifMatch                          = ^True$
     ifMatchAction                = [!SetVariable Backup_Hotkeys_Completed "1"][!WriteKeyValue Variables Backup_Hotkeys_Completed "1" "#Service_Folder#\Service.inc"][!CommandMeasure shell.BACKUP_HARDWARE "Run"][!Log "[UPDATE] Success! Hotkeys list backuped."]
 ifMatch2                         = ^False$
     ifMatchAction2               = [!SetVariable Backup_Hotkeys_Completed "0"][!WriteKeyValue Variables Backup_Hotkeys_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Fail! Hotkeys list isn't backuped."]

[shell.BACKUP_HARDWARE_CHECK]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Test-Path -Path '#Backup_Hardware_Global#' 
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 Group                            = #updater#
 ifMatch                          = ^True$
     ifMatchAction                = [!SetVariable Backup_Hardware_Completed "1"][!WriteKeyValue Variables Backup_Hardware_Completed "1" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Success! Hardware list backuped."]
 ifMatch2                         = ^False$
     ifMatchAction2               = [!SetVariable Backup_Hardware_Completed "0"][!WriteKeyValue Variables Backup_Hardware_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Fail! Hardware list isn't backuped."]

[shell.RESTORE_CONFIG]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #Backup_Config_Global# -Destination #@#\#Config# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Config#
 FinishAction                     = [!SetVariable Restore_Config_Completed "1"][!WriteKeyValue Variables Restore_Config_Completed "1" "#Service_Folder#\Service.inc"][!CommandMeasure shell.RESTORE_HARDWARE "Run"][!Log "[UPDATE] Config list restored."]
 Group                            = #updater#

[shell.RESTORE_HARDWARE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #Backup_Hardware_Global# -Destination #@#\#Hardware# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Hardware#
 FinishAction                     = [!SetVariable Restore_Hardware_Completed "1"][!WriteKeyValue Variables Restore_Hardware_Completed "1" "#Service_Folder#\Service.inc"][!CommandMeasure shell.RESTORE_HOTKEYS "Run"][!Log "[UPDATE] Hardware list restored."]
 Group                            = #updater#

[shell.RESTORE_HOTKEYS]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Copy-Item -Path #Backup_Hotkeys_Global# -Destination #@#\#Hotkeys# -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Restore_Hotkeys
 FinishAction                     = [!SetVariable Restore_Hotkeys_Completed "1"][!WriteKeyValue Variables Restore_Hotkeys_Completed "1" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Hotkeys list restored."]
 Group                            = #updater#

[m.Updater_Skin_Installer]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = #Update_Folder#\AuroraBar_#New_Version#.rmskin
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Installer#
 Hidden                           = 1
 FinishAction                     = [!Log "[UPDATE] Installation initialized."]
 Group                            = #updater#

[m.UPDATER_CHECK_INSTALL]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Test-Path -Path '#Service_Folder#\Service.inc' 
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Installer#
 Hidden                           = 1
 Group                            = #updater#
 ifMatch                          = ^True$
     ifMatchAction                = [!SetVariable Existance_Service "1"][!WriteKeyValue Variables Existance_Service " 1" "#@#\#Defaults#"]
 ifMatch2                         = ^False$
     ifMatchAction2               = [!SetVariable Existance_Service "0"][!WriteKeyValue Variables Existance_Service " 0" "#@#\#Defaults#"][!CommandMeasure shell.ADDONS_MAKER "Run"]
          ifMatchMode             = 0

[m.UPDATER_BUILD_CREATE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path '#ADDONSPATH#AuroraBar\Update\#Build#\finished.#Build#' -ItemType File
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutpuFile                        = #Log_Update_Completition#
 TimeOut                          = 1000
 Hidden                           = 1
 FinishAction                     = [!Log "[UPDATE] Trying to finish update.."]
; Group                            = #updater#

[m.UPDATER_CHECK_UPDATE_FILE_EXISTANCE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Test-Path -Path '#Update_Folder#\AuroraBar_#New_Version#.rmskin' 
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 Hidden                           = 1
 Group                            = #updater#
 ifMatch                          = ^True$
     ifMatchAction                = [!SetVariable Update_Ready_To_Install "1"][!WriteKeyValue Variables Update_Ready_To_Install "1" "#Service_Folder#\Service.inc"][!Log "[UPDATE] Download finished and update is ready to install."][!UpdateMeasure sensor.UPDATE_CONTROLLER]
 ifMatch2                         = ^False$
     ifMatchAction2               = [!SetVariable Update_Download_Completed "0"][!WriteKeyValue Variables Update_Download_Completed "0" "#Service_Folder#\Service.inc"][!UpdateMeasure sensor.UPDATE_CONTROLLER][!Log "[UPDATE] Cannot find the update file, trying to download again."]
     ifMatchMode                  = 0

[shell.ADDONS_MAKER]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = New-Item -Path '#ADDONSPATH#AuroraBar\Service' -ItemType Directory #CRLF# New-Item -Path '#ADDONSPATH#AuroraBar\Update' -ItemType Directory #CRLF# New-Item -Path '#ADDONSPATH#AuroraBar\Backup' -ItemType Directory #CRLF# Copy-Item -Path #@#\update\Service.inc -Destination #Service_Folder#\Service.inc -Force
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_Installer#
 FinishAction                     = [!CommandMeasure m.UPDATER_CHECK_INSTALL "Run"][!Delay 1000][!SetVariable Previous_Version "#Version#"][!WriteKeyValue Variables Previous_Version "#Version#" "#Service_Folder#\Service.inc"][!SetVariable Previous_Build "#Build#"][!WriteKeyValue Variables Previous_Build "#Build#" "#Service_Folder#\Service.inc"][!SetVariable Update_Flag "0"][!WriteKeyValue Variables Update_Flag " 0" "#Service_Folder#\Service.inc"][!Log "[INSTALLATION] A new installation detected. Errors below it's fine, do not pay attention. Service directories has been created. Skin will be refreshed now."][!Delay 1000][!Refresh]
 Hidden                           = 1

; --- CONTROLLER

[sensor.UPDATE_CONTROLLER]
 Measure                          = CALC
 DynamicVariables                 = 1

     ifCondition                  = #Existance_Service# = 0
          ifTrueAction            = [!SetVariable New_Installation "New"][!WriteKeyValue Variables New_Installation " 1" "#Service_Folder#\Service.inc" ]
               ifFalseAction      = [!SetVariable New_Installation "Update"][!WriteKeyValue Variables New_Installation " 0" "#Service_Folder#\Service.inc" ]
     
;     ifCondition2                 = ( #Update_Initialized# = 1 ) && ( #Update_Completed# = 0 )
;          iftrueAction2           = [!Log "Update operation initialized. Begin download [AuroraBar [m.Updater_Parser_Check_Version] Build [m.Updater_Parser_Check_Build]]"][!UpdateMeasure m.Updater_Downloader][!CommandMeasure m.Updater_Downloader "Run"]

     ifCondition2                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 0) && (#Update_Ready_To_Install# = 0) && (#Backup_Config_Completed# = 0) && (#Backup_Hotkeys_Completed# = 0) && (#Backup_Hardware_Completed# = 0) && (#Restore_Config_Completed# = 0) && (#Restore_Hotkeys_Completed# = 0) && (#Restore_Hardware_Completed# = 0)
          ifTrueAction2           = [!Log "[UPDATE] Update operation initialized. Begin download [AuroraBar [m.Updater_Parser_Check_Version] Build [m.Updater_Parser_Check_Build]]"][!UpdateMeasure m.Updater_Downloader][!CommandMeasure m.Updater_Downloader "Run"][!SetVariable Build "#New_Build#"]

     ifCondition3                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 0) && (#Backup_Config_Completed# = 0) && (#Backup_Hotkeys_Completed# = 0) && (#Backup_Hardware_Completed# = 0) && (#Restore_Config_Completed# = 0) && (#Restore_Hotkeys_Completed# = 0) && (#Restore_Hardware_Completed# = 0)
          ifTrueAction3           = [!UpdateMeasure m.UPDATER_CHECK_UPDATE_FILE_EXISTANCE][!CommandMeasure m.UPDATER_CHECK_UPDATE_FILE_EXISTANCE "Run"]

     ifCondition4                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 1) && (#Backup_Config_Completed# = 0) && (#Backup_Hotkeys_Completed# = 0) && (#Backup_Hardware_Completed# = 0) && (#Restore_Config_Completed# = 0) && (#Restore_Hotkeys_Completed# = 0) && (#Restore_Hardware_Completed# = 0)
          ifTrueAction4           = [!Log "[UPDATE] Initializing backup process.."][!CommandMeasure shell.BACKUP_CONFIG "Run"]

     ifCondition5                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 1) && (#Backup_Config_Completed# = 1) && (#Backup_Hotkeys_Completed# = 1) && (#Backup_Hardware_Completed# = 1) && (#Restore_Config_Completed# = 0) && (#Restore_Hotkeys_Completed# = 0) && (#Restore_Hardware_Completed# = 0)
          ifTrueAction5           = [!Log "[UPDATE] Backup operation succesfully completed. Initializing installation.."][!CommandMeasure m.Updater_Skin_Installer "Run"]

     ifCondition6                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 1) && (#Backup_Config_Completed# = 1) && (#Backup_Hotkeys_Completed# = 1) && (#Backup_Hardware_Completed# = 1) && (#Restore_Config_Completed# = 0) && (#Restore_Hotkeys_Completed# = 0) && (#Restore_Hardware_Completed# = 0) && (#Current_Build# = #Build#)
          ifTrueAction6           = [!Log "[UPDATE] Update applied. Trying to restore configuration.."][!CommandMeasure shell.RESTORE_CONFIG "Run"]

     ifCondition7                 = (#Update_Initialized# = 1) && (#Update_Completed# = 0) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 1) && (#Backup_Config_Completed# = 1) && (#Backup_Hotkeys_Completed# = 1) && (#Backup_Hardware_Completed# = 1) && (#Restore_Config_Completed# = 1) && (#Restore_Hotkeys_Completed# = 1) && (#Restore_Hardware_Completed# = 1) && (#Current_Build# = #Build#)
          ifTrueAction7           = [!Log "[UPDATE] Configuration restored! Finishing the update operation.."][!SetVariable Update_Completed "1"][!WriteKeyValue Variables Update_Completed "1" "#Service_Folder#\Service.inc"]
     
     ifCondition8                 = (#Update_Initialized# = 1) && (#Update_Completed# = 1) && (#Update_Download_Completed# = 1) && (#Update_Ready_To_Install# = 1) && (#Backup_Config_Completed# = 1) && (#Backup_Hotkeys_Completed# = 1) && (#Backup_Hardware_Completed# = 1) && (#Restore_Config_Completed# = 1) && (#Restore_Hotkeys_Completed# = 1) && (#Restore_Hardware_Completed# = 1) && (#Current_Build# = #Build#)
          ifTrueAction8           = [!Log "[UPDATE] Update succesfully completed! The new version is [AuroraBar [m.Updater_Parser_Check_Version] Build [m.Updater_Parser_Check_Build]]. Enjoy!"][!SetVariable Update_Initialized "1"][!WriteKeyValue Variables Update_Initialized "0" "#Service_Folder#\Service.inc"][!SetVariable Update_Download_Completed "0"][!WriteKeyValue Variables Update_Download_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Update_Ready_To_Install "0"][!WriteKeyValue Variables Update_Ready_To_Install "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Config_Completed "0"][!WriteKeyValue Variables Backup_Config_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Hotkeys_Completed "0"][!WriteKeyValue Variables Backup_Hotkeys_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Hardware_Completed "0"][!WriteKeyValue Variables Backup_Hardware_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Config_Completed "0"][!WriteKeyValue Variables Restore_Config_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Hotkeys_Completed "0"][!WriteKeyValue Variables Restore_Hotkeys_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Hardware_Completed "0"][!WriteKeyValue Variables Restore_Hardware_Completed "0" "#Service_Folder#\Service.inc"][!Delay 300][!Refresh]

     ifConditionMode              = 1
 


[text.Updater_Text123]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Center_Align
 Text                             = Version: AuroraBar #New_Version# #CRLF#Download link: #Download_URL# #CRLF# #New_Installation# #Existance_Service# #Previous_Build# [m.Updater_Parser_Check_Build] #CRLF# #Update_Folder#
 SolidColor                       = 200,0,0,200
 X                                = 950
 Y                                = (#Pad_Top# - 100)
 DynamicVariables                 = 1
 Group                            = #updater#
 Hidden                           = 1

[test.LUA_LOGGER]
 Measure                          = Script
 ScriptFile                       = #@#\scripts\Logger.lua
 FileToWrite                      = #@#\scripts\123.log

[b.TEST_DOWNLOAD_BUTTON1]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 200,0,0,200
 X                                = 1050
 Y                                = (#Pad_Top# + 135)
 DynamicVariables                 = 1
; LeftMouseUpAction                = [!CommandMeasure test.LUA_LOGGER "writeToFile()"]
 LeftMouseUpAction                = [!UpdateMeasure m.Updater_Downloader][!CommandMeasure m.Updater_Downloader "Run"]
 RightMouseUpAction               = [!SetVariable Update_Initialized "1"][!WriteKeyValue Variables Update_Initialized "0" "#Service_Folder#\Service.inc"][!SetVariable Update_Download_Completed "0"][!WriteKeyValue Variables Update_Download_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Update_Ready_To_Install "0"][!WriteKeyValue Variables Update_Ready_To_Install "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Config_Completed "0"][!WriteKeyValue Variables Backup_Config_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Hotkeys_Completed "0"][!WriteKeyValue Variables Backup_Hotkeys_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Backup_Hardware_Completed "0"][!WriteKeyValue Variables Backup_Hardware_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Config_Completed "0"][!WriteKeyValue Variables Restore_Config_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Hotkeys_Completed "0"][!WriteKeyValue Variables Restore_Hotkeys_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Restore_Hardware_Completed "0"][!WriteKeyValue Variables Restore_Hardware_Completed "0" "#Service_Folder#\Service.inc"][!SetVariable Update_Completed "1"][!WriteKeyValue Variables Update_Completed "1" "#Service_Folder#\Service.inc"][!Log "Update state reseted"][!Delay 300][!Refresh]
 Hidden                           = 1
 Group                            = #updater#

[b.TEST_INSTALL_BUTTON1]
 Meter                            = SHAPE
 Shape                            = Rectangle 0, 0, 19, 19 | Strokewidth 0 | Fill Color 0,220,0,200
 X                                = 1050
 Y                                = (#Pad_Top# + 170)
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.Updater_Skin_Installer "Run"]
 Hidden                           = 1
 Group                            = #updater#