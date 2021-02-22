[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = This config contains all hardware's ID used (and maybe will be used in the future..) in the skin

[Variables]
 temp_max                         = m.Disk_One_Free

; --- MEASURES BEGINNING

[m.Disk_One_Label]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_One#
 Label                            = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
     onChangeAction               = [!UpdateMeasure m.Disk_One_Used][!UpdateMeasure m.Disk_One_Total][!UpdateMeasure m.Disk_One_Free][!UpdateMeter b.Drive_One][!UpdateMeter t.Drive_One]

[m.Disk_Two_Label]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_Two#
 Label                            = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
     onChangeAction               = [!UpdateMeasure m.Disk_Two_Used][!UpdateMeasure m.Disk_Two_Total][!UpdateMeasure m.Disk_Two_Free][!UpdateMeter b.Drive_Two][!UpdateMeter t.Drive_Two]

[m.Disk_One_Used]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_One#
 InvertMeasure                    = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[m.Disk_Two_Used]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_Two#
 InvertMeasure                    = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[m.Disk_One_Total]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_One#
 Total                            = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[m.Disk_Two_Total]
 Measure                          = FreeDiskSpace
 Drive                            = #Drive_Two#
 Total                            = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[m.Disk_One_Free]
 Measure                          = calc 
 Formula                          = ( m.Disk_One_Total - m.Disk_One_Used )
 Group                            = #drives_left_side#

[m.Disk_Two_Free]
 Measure                          = calc 
 Formula                          = ( m.Disk_Two_Total - m.Disk_Two_Used )
 Group                            = #drives_left_side#

[m.Temp_Size]
 Measure                          = PLUGIN
 Plugin                           = FolderInfo
 Folder                           = #temp_folder#
 InfoType                         = FolderSize
 IncludeHiddenFiles               = 1
 IncludeSubFolders                = 1
 IncludeSystemFiles               = 1
 RegExpFilter                     = .*
 MinValue                         = 0
 MaxValue                         = [m.Disk_One_Free]
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
     onChangeAction               = [!UpdateMeasure m.Temp_GB_Calc][!UpdateMeter b.Temp_Folder][!UpdateMeter t.Temp_Folder]

[m.Cache_Size]
 Measure                          = PLUGIN
 Plugin                           = FolderInfo
 Folder                           = #cache_folder#
 InfoType                         = FolderSize
 IncludeHiddenFiles               = 1
 IncludeSubFolders                = 1
 IncludeSystemFiles               = 1
 RegExpFilter                     = .*
 MinValue                         = 0
 MaxValue                         = [m.Disk_One_Free]
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
     onChangeAction               = [!UpdateMeasure m.Cache_GB_Calc][!UpdateMeter b.Cache_Folder][!UpdateMeter t.Cache_Folder]

[m.Temp_GB_Calc]
 Measure                          = CALC
 Formula                          = (m.Temp_Size / 1073741824 )
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[m.Cache_GB_Calc]
 Measure                          = CALC
 Formula                          = (m.Cache_Size / 1073741824 )
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

; - Clears the TEMP folder

[m.Temp_Clear]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Get-ChildItem -Path '#temp_folder#' -Include * -File -Recurse | foreach { $_.Delete()}
 State                            = Hide
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\temp_clear.log
 DynamicVariables                 = 1
 OnFinishAction                   = [!UpdateMeasure m.Temp_Size]

; - Clears the TEMP folder FORCED

; - FORCED means it trying to delete 'READ-ONLY' and 'HIDDEN' files

[m.Temp_Clear_Forced]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Get-ChildItem -Path '#temp_folder#' -Include * -File -Recurse -Force | foreach { $_.Delete()}
 State                            = Hide
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\temp_clear.log
 DynamicVariables                 = 1
 OnFinishAction                   = [!UpdateMeasure m.Temp_Size]

; - Clears the CACHE folder

; - FORCED means it trying to delete 'READ-ONLY' and 'HIDDEN' files

[m.Cache_Clear]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Get-ChildItem -Path '#cache_folder#' -Include * -File -Recurse | foreach { $_.Delete()}
 State                            = Hide
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\cache_clear.log
 DynamicVariables                 = 1
 OnFinishAction                   = [!UpdateMeasure m.Cache_Size]

; - Clears the CACHE folder FORCED

; - FORCED means it trying to delete 'READ-ONLY' and 'HIDDEN' files

[m.Cache_Clear_Forced]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = Get-ChildItem -Path '#cache_folder#' -Include * -File -Recurse -Force | foreach { $_.Delete()}
 State                            = Hide
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\cache_clear.log
 DynamicVariables                 = 1
 OnFinishAction                   = [!UpdateMeasure m.Cache_Size]

; - MEASURES END

; --- BARS BEGINNING

[f.Drive_One_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 70
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[b.Drive_One]
 Meter                            = BAR
 MeasureName                      = m.Disk_One_Used
 MeterStyle                       = b.LongBarLeftTop
 TransformationMatrix             = 1; 0; 1; 1; -[f.Drive_One_Y]; 0
 W                                = 100
 X                                = 38
 Y                                = [f.Drive_One_Y]
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [#Drive_One#]

[f.Temp_Folder_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 90
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[b.Temp_Folder]
 Meter                            = BAR
 MeasureName                      = m.Temp_Size
 MeterStyle                       = b.LongBarLeftTop
 TransformationMatrix             = 1; 0; 1; 1; -[f.Temp_Folder_Y]; 0
 W                                = 100
 X                                = 53
 Y                                = [f.Temp_Folder_Y]
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.Temp_Clear "Run"]
 MiddleMouseUpAction              = [!CommandMeasure m.Temp_Clear_Forced "Run"]
 RightMouseUpAction               = ["#temp_folder#"]

[f.Cache_Folder_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 120
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[b.Cache_Folder]
 Meter                            = BAR
 MeasureName                      = m.Cache_Size
 MeterStyle                       = b.LongBarLeftBottom
 TransformationMatrix             = 1; 0; -1; 1; [f.Cache_Folder_Y]; 0
 W                                = 100
 X                                = 61
 Y                                = [f.Cache_Folder_Y]
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#
 DynamicVariables                 = 1
 LeftMouseUpAction                = [!CommandMeasure m.Cache_Clear "Run"]
 MiddleMouseUpAction              = [!CommandMeasure m.Cache_Clear_Forced "Run"]
 RightMouseUpAction               = ["#cache_folder#"]
 
[f.Drive_Two_Y]
 Measure                          = CALC
 Formula                          = #Pad_Top# + 140
 DynamicVariables                 = 1
 Group                            = #drives_left_side#

[b.Drive_Two]
 Meter                            = BAR
 MeasureName                      = m.Disk_Two_Used
 MeterStyle                       = b.LongBarLeftBottom
 TransformationMatrix             = 1; 0; -1; 1; [f.Drive_Two_Y]; 0
 W                                = 100
 X                                = 46
 Y                                = [f.Drive_Two_Y]
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#
 LeftMouseUpAction                = [#Drive_Two#]

; - BARS END

; --- TEXTS BEGINNING

[t.Drive_One]
 Meter                            = STRING
 MeasureName                      = m.Disk_One_Label
 MeasureName2                     = m.Disk_One_Free
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 170
 Y                                = (#Pad_Top# + 67)
 FonSize                          = 10
 StringCase                       = Upper
 Text                             = #Drive_One# %2B
 NumOfDecimals                    = 1
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#

[t.Temp_Folder]
 Meter                            = STRING
 MeasureName                      = m.Temp_GB_Calc
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 183
 Y                                = (#Pad_Top# + 85)
 FonSize                          = 10
 Text                             = TEMP : %1 GB
 NumOfDecimals                    = 1
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#

[t.Cache_Folder]
 Meter                            = STRING
 MeasureName                      = m.Cache_GB_Calc
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 183
 Y                                = (#Pad_Top# + 117)
 FonSize                          = 10
 Text                             = CACHE:  %1 GB
 NumOfDecimals                    = 1
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#

[t.Drive_Two]
 Meter                            = STRING
 MeasureName                      = m.Disk_Two_Label
 MeasureName2                     = m.Disk_Two_Free
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 170
 Y                                = (#Pad_Top# + 137)
 FonSize                          = 10
 StringCase                       = Upper
 Text                             = #Drive_Two# %2B
 NumOfDecimals                    = 1
 AutoScale                        = 1
 DynamicVariables                 = 1
 Group                            = #drives_left_side#
 Hidden                           = #Disk_Left_Side_State#

; - TEXTS END
