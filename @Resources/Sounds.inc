[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Sounds config

[Variables]

 ; --- SOUNDS SETS

 Sounds_Set_Sci_Fi                = sci_fi
 Sounds_Set_Silent                = silent
 Sounds_Set                       = silent

; --- SOUNDS

 Click_1                          = "#@#\sounds\#Sounds_Set#\click_1.wav"
 Click_2                          = "#@#\sounds\#Sounds_Set#\click_2.wav"
 Click_3                          = "#@#\sounds\#Sounds_Set#\click_3.wav"
 Collapse_1                       = "#@#\sounds\#Sounds_Set#\collapse_1.wav"
 Collapse_2                       = "#@#\sounds\#Sounds_Set#\collapse_2.wav"
 Collapse_3                       = "#@#\sounds\#Sounds_Set#\collapse_3.wav"
 Critical_1                       = "#@#\sounds\#Sounds_Set#\critical_1.wav"
 Critical_2                       = "#@#\sounds\#Sounds_Set#\critical_2.wav"
 Critical_3                       = "#@#\sounds\#Sounds_Set#\critical_3.wav"
 Expand_1                         = "#@#\sounds\#Sounds_Set#\expand_1.wav"
 Expand_2                         = "#@#\sounds\#Sounds_Set#\expand_2.wav"
 Expand_3                         = "#@#\sounds\#Sounds_Set#\expand_3.wav"
 Fail_1                           = "#@#\sounds\#Sounds_Set#\fail_1.wav"
 Fail_2                           = "#@#\sounds\#Sounds_Set#\fail_2.wav"
 Fail_3                           = "#@#\sounds\#Sounds_Set#\fail_3.wav"
 MouseOver_1                      = "#@#\sounds\#Sounds_Set#\mouseover_1.wav"
 MouseOver_2                      = "#@#\sounds\#Sounds_Set#\mouseover_2.wav"
 MouseOver_3                      = "#@#\sounds\#Sounds_Set#\mouseover_3.wav"
 Slider_1                         = "#@#\sounds\#Sounds_Set#\slider_1.wav"
 Slider_2                         = "#@#\sounds\#Sounds_Set#\slider_2.wav"
 Slider_3                         = "#@#\sounds\#Sounds_Set#\slider_3.wav"
 Success_1                        = "#@#\sounds\#Sounds_Set#\success_1.wav"
 Success_2                        = "#@#\sounds\#Sounds_Set#\success_2.wav"
 Success_3                        = "#@#\sounds\#Sounds_Set#\success_3.wav"
 Warning_1                        = "#@#\sounds\#Sounds_Set#\warning_1.wav"
 Warning_2                        = "#@#\sounds\#Sounds_Set#\warning_2.wav"
 Warning_3                        = "#@#\sounds\#Sounds_Set#\warning_3.wav"

; --- SOUNDS MEASURES BEGINNING

; - These formulas controls a behaviour for some sounded measures

; --- TEST

[sound.test.TRIANGLE_TOP]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = #CRLF# $Player = New-Object System.Media.SoundPlayer #MouseOver_1#; `n $Player.Play();
 State                            = hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #@#\logs\sound_test.log
 Timeout                          = 2000
 FinishAction                     = [Play #MouseOver_1#]

[sound.CPU_TOP]
 Measure                          = CALC
 Formula                          = #CPU_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #CPU_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.GPU_TOP]
 Measure                          = CALC
 Formula                          = #GPU_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #GPU_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.CPU_INFO]
 Measure                          = CALC
 Formula                          = #CPU_Info_State#
 Group                            = #sounds_wings_top#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #CPU_Info_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.GPU_INFO]
 Measure                          = CALC
 Formula                          = #GPU_Info_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_top#
 Disabled                         = 1
     IfCondition                  = #GPU_Info_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[f.sound.RAM_Top]
 Measure                          = CALC
 Formula                          = #RAM_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_top#
 Disabled                         = 1
     IfCondition                  = #RAM_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.VRAM_TOP]
 Measure                          = CALC
 Formula                          = #VRAM_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #VRAM_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.IO_WRITE_TOP]
 Measure                          = CALC
 Formula                          = #Disk_Write_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_top#
 Disabled                         = 1
     IfCondition                  = #Disk_Write_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.IO_READ_TOP]
 Measure                          = CALC
 Formula                          = #Disk_Read_Top_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #Disk_Read_Top_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.THREADS]
 Measure                          = CALC
 Formula                          = #Threads_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_top#
 Disabled                         = 1
     IfCondition                  = #Threads_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]


[sound.CLOCK_INFO]
 Measure                          = CALC
 Formula                          = #Clock_Info_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_top#
 Disabled                         = 1
 IfCondition                      = #Clock_Info_State# = 0
     IfTrueAction                 = [Play #Expand_1#]
     IfFalseAction                = [Play #Collapse_1#]

 
[sound.THROTTLING]
 Measure                          = CALC
 Formula                          = #Throttling_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #Throttling_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.POWER_LIMIT]
 Measure                          = CALC
 Formula                          = #Power_Limit_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #Power_Limit_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.LOGS_BOTTOM]
 Measure                          = CALC
 Formula                          = #Logs_Bottom_State#
 DynamicVariables                 = 1
 Group                            = #sounds_wings_bottom#
 Disabled                         = 1
     IfCondition                  = #Logs_Bottom_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.DEBUG]
 Measure                          = CALC
 Formula                          = #Debug_State#
 DynamicVariables                 = 1
 Group                            = #debug#
 Disabled                         = 1
     IfCondition                  = #Debug_State# = 0
          IfTrueAction            = [Play #Expand_1#]
          IfFalseAction           = [Play #Collapse_1#]

[sound.TRIANGLE_TOP]
 Measure                          = CALC
 Formula                          = #Triangle_Top_Mechanic#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Triangle_Top_Mechanic# = 0
          IfTrueAction            = [Play #Expand_2#]
          IfFalseAction           = [Play #Collapse_2#]

[sound.TRIANGLE_BOTTOM]
 Measure                          = CALC
 Formula                          = #Triangle_Bottom_Mechanic#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = sound.TRIANGLE_BOTTOM = 1
          IfTrueAction            = [Play #Expand_2#]
          IfFalseAction           = [Play #Collapse_2#]

[sound.TRIANGLE_LEFT]
 Measure                          = CALC
 Formula                          = #Triangle_Left_Mechanic#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Triangle_Left_Mechanic# = 1
          IfTrueAction            = [Play #Expand_3#]
          IfFalseAction           = [Play #Collapse_3#]

[sound.TRIANGLE_RIGHT]
 Measure                          = CALC
 Formula                          = #Triangle_Right_Mechanic#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Triangle_Right_Mechanic# = 1
          IfTrueAction            = [Play #Expand_3#]
          IfFalseAction           = [Play #Collapse_3#]

[sound.BLUETOOTH]
 Measure                          = CALC
 Formula                          = #Bluetooth_State#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Bluetooth_State# = 1
          IfTrueAction            = [Play #Success_1#]
          IfFalseAction           = [Play #Fail_1#]

[sound.PLAYER_1_SHUFFLE]
 Measure                          = CALC
 Formula                          = #Player_1_Shuffle_State#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Player_1_Shuffle_State# = 0
          IfTrueAction            = [Play #Success_1#]
          IfFalseAction           = [Play #Fail_1#]

[sound.PLAYER_1_REPEAT]
 Measure                          = CALC
 Formula                          = #Player_1_Repeat_State#
 DynamicVariables                 = 1
 Disabled                         = 1
     IfCondition                  = #Player_1_Repeat_State# = 1
          IfTrueAction            = [Play #Success_1#]
          IfFalseAction           = [Play #Fail_1#]

; - SOUNDS MEASURES END
