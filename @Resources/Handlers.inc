[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.6b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 4.0
 Information                      = It handles all update cycles inside Aurora. This approach is designed to make utilization evenly and neutralize Rainmeter's freezes, to protect you from lags and to minimize affection on your system as less as it possible. At least for a while.. Remember, the more you use, the more performance you lose. 

[Variables]
 Delay                             = [!Delay [#Update_Rate]]
 Cycle                             = 0
 Cycle_Reset                       = 1
 2nd_Cycle                         = 0
 3rd_Cycle                         = 0
 1st_Cycle_Body                    = 0
 2nd_Cycle_Body                    = 0
 3rd_Cycle_Body                    = 0
 Cycles_Max                        = 30


 Main_Increment                    = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]
 Main_Increment_Debug              = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE_DEBUG][!UpdateMeterGroup #debug#][!Redraw]

 Update_Time                       = [!UpdateMeasure sensor.TIME_SECS]
 Update_Players                    = [!UpdateMeasure sensor.PLAYER][!UpdateMeasure sensor.PLAYER_PROGRESS][!UpdateMeasure sensor.PLAYER_STATE_BUTTON_PLAY_1]
 Update_Volume                     = [!UpdateMeasure m.System_Volume]
 Update_App_Volume                 = [!UpdateMeasureGroup #app_volume_controls_static_sensors#]

; - CPU

 Update_CPU                        = [!UpdateMeasure sensor.CPU_LOAD][!UpdateMeasure sensor.CPU_TEMPERATURE]
 Update_CPU_Info                   = [!UpdateMeasureGroup #cpu_info#]
 Update_CPU_Main                   = [!UpdateMeasure sensor.CPU_LOAD][!UpdateMeasure sensor.CPU_TEMPERATURE]
 Update_CPU_Cores                  = [!UpdateMeasureGroup #cpu_cores#]

; - GPU

 Update_GPU                        = [!UpdateMeasure sensor.GPU_LOAD][!UpdateMeasure sensor.GPU_TEMPERATURE]
 Update_GPU_Info                   = [!UpdateMeasureGroup #gpu_info#]
 Update_GP

; - COMMON INFO

 Update_Limiters                   = [!UpdateMeasureGroup #limiters_sensors#]
 Update_Clock_Info                 = [!UpdateMeasureGroup #clock_info#]
 Update_Threads                    = [!UpdateMeasureGroup #threads#]

 Update_Bluetooth                  = [!UpdateMeasure sensor.BLUETOOTH_CHECKER][!UpdateMeasure sensor.BLUETOOTH_STATE]

; - DRIVES

 Update_Drive_1                    = [!UpdateMeasure sensor.DRIVE_1_TOTAL_ACTIVITY]
 Update_Drive_2                    = [!UpdateMeasure sensor.DRIVE_2_TOTAL_ACTIVITY]

 Update_Drives                     = [!UpdateMeasure sensor.DRIVE_1_TOTAL_ACTIVITY][!UpdateMeasure sensor.DRIVE_2_TOTAL_ACTIVITY]

; - MEMORY

 Update_RAM                        = [!UpdateMeasure sensor.RAM]
 Update_VRAM                       = [!UpdateMeasure sensor.VRAM]

 Update_Memory                     = [!UpdateMeasureGroup #ram_sensors#][!UpdateMeasureGroup #vram_sensors#]

; - NET

 Update_Net                        = [!UpdateMeasure sensor.NET_TOTAL]

; --- TOP PROCESS

 Update_CPU_TOP                    = [!UpdateMeasureGroup #cpu_top#]
 Update_GPU_TOP                    = [!UpdateMeasureGroup #gpu_top#]
 Update_RAM_TOP                    = [!UpdateMeasureGroup #ram_top#]
 Update_VRAM_TOP                   = [!UpdateMeasureGroup #vram_top#]
 Update_IO_WRITE_TOP               = [!UpdateMeasureGroup #io_write_top#]
 Update_IO_READ_TOP                = [!UpdateMeasureGroup #io_read_top#]

; --- EXNTENTED TOP PROCESS

; - CPU

 Update_CPU_Top_1                  = [!UpdateMeasure sensor.CPU_TOP_1]
 Update_CPU_Top_2                  = [!UpdateMeasure sensor.CPU_TOP_2]
 Update_CPU_Top_3                  = [!UpdateMeasure sensor.CPU_TOP_3]
 Update_CPU_Top_4                  = [!UpdateMeasure sensor.CPU_TOP_4]
 Update_CPU_Top_5                  = [!UpdateMeasure sensor.CPU_TOP_5]

; - GPU

 Update_GPU_Top_1                  = [!UpdateMeasure sensor.GPU_TOP_1]
 Update_GPU_Top_2                  = [!UpdateMeasure sensor.GPU_TOP_2]
 Update_GPU_Top_3                  = [!UpdateMeasure sensor.GPU_TOP_3]
 Update_GPU_Top_4                  = [!UpdateMeasure sensor.GPU_TOP_4]
 Update_GPU_Top_5                  = [!UpdateMeasure sensor.GPU_TOP_5]

; - RAM

 Update_RAM_Top_1                  = [!UpdateMeasure sensor.RAM_TOP_1]
 Update_RAM_Top_2                  = [!UpdateMeasure sensor.RAM_TOP_2]
 Update_RAM_Top_3                  = [!UpdateMeasure sensor.RAM_TOP_3]

; - VRAM

 Update_VRAM_Top_1                 = [!UpdateMeasure sensor.VRAM_TOP_1]
 Update_VRAM_Top_2                 = [!UpdateMeasure sensor.VRAM_TOP_2]
 Update_VRAM_Top_3                 = [!UpdateMeasure sensor.VRAM_TOP_3]

; - IO WRITE

 Update_IO_Write_Top_1             = [!UpdateMeasure sensor.TOP_IO_WRITE_1]
 Update_IO_Write_Top_2             = [!UpdateMeasure sensor.TOP_IO_WRITE_2]
 Update_IO_Write_Top_3             = [!UpdateMeasure sensor.TOP_IO_WRITE_3]

; - IO READ

 Update_IO_Read_Top_1              = [!UpdateMeasure sensor.TOP_IO_READ_1]
 Update_IO_Read_Top_2              = [!UpdateMeasure sensor.TOP_IO_READ_2]
 Update_IO_Read_Top_3              = [!UpdateMeasure sensor.TOP_IO_READ_3]

; --- MAIN CYCLE'S HANDLER

; - All updates inside depends on this measure. #Cycle# it is a variable for counter. Each iteration inside cycle do #Cycle# + 1 until it reach the last. Then #Cycle# nulifies and all over again.

; - Look below for 2nd and 3rd update cycles, which rules less critical measures inside the skin.

[handler.MAIN_CYCLE]
 Measure                          = CALC
 Formula                          = #Cycle#
 DynamicVariables                 = 1
 Group                            = #handlers#
 Disabled                         = 0
    
; ---

    ifCondition                   = #CURRENTSECTION# = 1
        ifTrueAction              = #Update_Time#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition2                  = #CURRENTSECTION# = 2
        ifTrueAction2             = #Update_CPU#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition3                  = #CURRENTSECTION# = 3
        ifTrueAction3             = #Update_GPU#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition4                  = #CURRENTSECTION# = 4
        ifTrueAction4             = #Update_CPU_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---    

    ifCondition5                  = #CURRENTSECTION# = 5
        ifTrueAction5             = #Update_GPU_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---    

    ifCondition6                  = #CURRENTSECTION# = 6
        ifTrueAction6             = #Update_CPU_TOP#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---    

    ifCondition7                  = #CURRENTSECTION# = 7
        ifTrueAction7             = #Update_GPU_TOP#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---    

    ifCondition8                  = #CURRENTSECTION# = 8
        ifTrueAction8             = #Update_RAM_TOP#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---    

    ifCondition9                  = #CURRENTSECTION# = 9
        ifTrueAction9             = #Update_VRAM_Top#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition10                 = #CURRENTSECTION# = 10
        ifTrueAction10            = #Update_Drives#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition11                 = #CURRENTSECTION# = 11
        ifTrueAction11            = #Update_IO_WRITE_TOP#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition12                 = #CURRENTSECTION# = 12
        ifTrueAction12            = #Update_IO_READ_TOP#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition13                 = #CURRENTSECTION# = 13
        ifTrueAction13            = #Update_Limiters#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition14                 = #CURRENTSECTION# = 14
        ifTrueAction14            = #Update_Threads#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition15                 = #CURRENTSECTION# = 15
        ifTrueAction15            = #Update_Clock_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition16                 = #CURRENTSECTION# = 16
        ifTrueAction16            = #Update_Players#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition17                 = #CURRENTSECTION# = 17
        ifTrueAction17            = #Update_Volume#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition18                 = #CURRENTSECTION# = 18
        ifTrueAction18            = #Update_Players#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition19                 = #CURRENTSECTION# = 19
        ifTrueAction19            = #Update_Net#    [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition20                 = #CURRENTSECTION# = 20
        ifTrueAction20            = #Update_App_Volume#    [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition21                 = #CURRENTSECTION# = 21
        ifTrueAction21            = #Update_Bluetooth#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition22                 = #CURRENTSECTION# = 22
        ifTrueAction22            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition23                 = #CURRENTSECTION# = 23
        ifTrueAction23            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition24                 = #CURRENTSECTION# = 24
        ifTrueAction24            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition25                 = #CURRENTSECTION# = 25
        ifTrueAction25            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition26                 = #CURRENTSECTION# = 26
        ifTrueAction26            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition27                 = #CURRENTSECTION# = 27
        ifTrueAction27            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition28                 = #CURRENTSECTION# = 28
        ifTrueAction28            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition29                 = #CURRENTSECTION# = 29
        ifTrueAction29            = [!UpdateMeasureGroup #updater#][!UpdateMeterGroup #updater#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE]

; ---

    ifCondition30                 = #CURRENTSECTION# = 30
        ifTrueAction30            = #Update_Memory#   [!SetVariable Cycle "1"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE][!Redraw]
      
;    ifCondition10                 = #CURRENTSECTION# = 10
;        ifTrueAction10            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeterGroup #debug#][!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeterGroup #debug#][!SetVariable Cycle "1"][!SetVariable 2nd_Cycle "(#2nd_Cycle# + 1)"][!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeasure handler.2ND_CYCLE][!UpdateMeterGroup #debug#][!Redraw]

[handler.MAIN_CYCLE_DEBUG]
 Measure                          = CALC
 Formula                          = #Cycle#
 DynamicVariables                 = 1
 Group                            = #handlers#
 Disabled                         = 1
    
; ---

    ifCondition                   = #CURRENTSECTION# = 1
        ifTrueAction              = #Update_Time#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition2                  = #CURRENTSECTION# = 2
        ifTrueAction2             = #Update_Volume#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition3                  = #CURRENTSECTION# = 3
        ifTrueAction3             = #Update_Limiters#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition4                  = #CURRENTSECTION# = 4
        ifTrueAction4             = #Update_Clock_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---    

    ifCondition5                  = #CURRENTSECTION# = 5
        ifTrueAction5             = #Update_Threads#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---    

    ifCondition6                  = #CURRENTSECTION# = 6
        ifTrueAction6             = #Update_CPU#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---    

    ifCondition7                  = #CURRENTSECTION# = 7
        ifTrueAction7             = #Update_GPU#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---    

    ifCondition8                  = #CURRENTSECTION# = 8
        ifTrueAction8             = #Update_CPU_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---    

    ifCondition9                  = #CURRENTSECTION# = 9
        ifTrueAction9             = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition10                 = #CURRENTSECTION# = 10
        ifTrueAction10            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition11                 = #CURRENTSECTION# = 11
        ifTrueAction11            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition12                 = #CURRENTSECTION# = 12
        ifTrueAction12            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition13                 = #CURRENTSECTION# = 13
        ifTrueAction13            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition14                 = #CURRENTSECTION# = 14
        ifTrueAction14            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition15                 = #CURRENTSECTION# = 15
        ifTrueAction15            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition16                 = #CURRENTSECTION# = 16
        ifTrueAction16            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition17                 = #CURRENTSECTION# = 17
        ifTrueAction17            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition18                 = #CURRENTSECTION# = 18
        ifTrueAction18            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition19                 = #CURRENTSECTION# = 19
        ifTrueAction19            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition20                 = #CURRENTSECTION# = 20
        ifTrueAction20            = #Update_Time#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition21                 = #CURRENTSECTION# = 21
        ifTrueAction21            = #Update_CPU_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition22                 = #CURRENTSECTION# = 22
        ifTrueAction22            = #Update_CPU_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition23                 = #CURRENTSECTION# = 23
        ifTrueAction23            = #Update_CPU_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition24                 = #CURRENTSECTION# = 24
        ifTrueAction24            = #Update_CPU_Top_4#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition25                 = #CURRENTSECTION# = 25
        ifTrueAction25            = #Update_CPU_Top_5#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition26                 = #CURRENTSECTION# = 26
        ifTrueAction26            = #Update_GPU_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition27                 = #CURRENTSECTION# = 27
        ifTrueAction27            = #Update_GPU_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition28                 = #CURRENTSECTION# = 28
        ifTrueAction28            = #Update_GPU_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition29                 = #CURRENTSECTION# = 29
        ifTrueAction29            = #Update_GPU_Top_4#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition30                 = #CURRENTSECTION# = 30
        ifTrueAction30            = #Update_GPU_Top_5#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition31                 = #CURRENTSECTION# = 31
        ifTrueAction31            = #Update_RAM_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition32                 = #CURRENTSECTION# = 32
        ifTrueAction32            = #Update_RAM_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition33                 = #CURRENTSECTION# = 33
        ifTrueAction33            = #Update_RAM_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition34                 = #CURRENTSECTION# = 34
        ifTrueAction34            = #Update_VRAM_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition35                 = #CURRENTSECTION# = 35
        ifTrueAction35            = #Update_VRAM_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition36                 = #CURRENTSECTION# = 36
        ifTrueAction36            = #Update_VRAM_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition37                 = #CURRENTSECTION# = 37
        ifTrueAction37            = #Update_IO_Write_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition38                 = #CURRENTSECTION# = 38
        ifTrueAction38            = #Update_IO_Write_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition39                 = #CURRENTSECTION# = 39
        ifTrueAction39            = #Update_IO_Write_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition40                 = #CURRENTSECTION# = 40
        ifTrueAction40            = #Update_IO_Read_Top_1#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition41                 = #CURRENTSECTION# = 41
        ifTrueAction41            = #Update_IO_Read_Top_2#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition42                 = #CURRENTSECTION# = 42
        ifTrueAction42            = #Update_IO_Read_Top_3#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition43                 = #CURRENTSECTION# = 43
        ifTrueAction43            = #Update_Time#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition44                 = #CURRENTSECTION# = 44
        ifTrueAction44            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition45                 = #CURRENTSECTION# = 45
        ifTrueAction45            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition46                 = #CURRENTSECTION# = 46
        ifTrueAction46            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition47                 = #CURRENTSECTION# = 47
        ifTrueAction47            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition48                 = #CURRENTSECTION# = 48
        ifTrueAction48            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition49                 = #CURRENTSECTION# = 49
        ifTrueAction49            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition50                 = #CURRENTSECTION# = 50
        ifTrueAction50            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]

; ---

    ifCondition51                 = #CURRENTSECTION# = 51
        ifTrueAction51            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition52                 = #CURRENTSECTION# = 52
        ifTrueAction52            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition53                 = #CURRENTSECTION# = 53
        ifTrueAction53            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition54                 = #CURRENTSECTION# = 54
        ifTrueAction54            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition55                 = #CURRENTSECTION# = 55
        ifTrueAction55            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition56                 = #CURRENTSECTION# = 56
        ifTrueAction56            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition57                 = #CURRENTSECTION# = 57
        ifTrueAction57            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition58                 = #CURRENTSECTION# = 58
        ifTrueAction58            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition59                 = #CURRENTSECTION# = 59
        ifTrueAction59            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition60                 = #CURRENTSECTION# = 60
        ifTrueAction60            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition61                 = #CURRENTSECTION# = 61
        ifTrueAction61            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition62                 = #CURRENTSECTION# = 62
        ifTrueAction62            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition63                 = #CURRENTSECTION# = 63
        ifTrueAction63            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition64                 = #CURRENTSECTION# = 64
        ifTrueAction64            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition65                 = #CURRENTSECTION# = 65
        ifTrueAction65            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition66                 = #CURRENTSECTION# = 66
        ifTrueAction66            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition67                 = #CURRENTSECTION# = 67
        ifTrueAction67            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition68                 = #CURRENTSECTION# = 68
        ifTrueAction68            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition69                 = #CURRENTSECTION# = 69
        ifTrueAction69            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
        
; ---

    ifCondition70                 = #CURRENTSECTION# = 70
        ifTrueAction70            = [!SetVariable Cycle "1"]#Delay#[!SetVariable 2nd_Cycle "(#2nd_Cycle# + 1)"][!UpdateMeasure handler.2ND_CYCLE_DEBUG][!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]  
        
        

[handler.2ND_CYCLE_DEBUG]
 Measure                          = CALC
 Formula                          = #2nd_Cycle_Body#
 DynamicVariables                 = 1
 Group                            = #handlers#
 Disabled                         = 0
    ifCondition                   = #2nd_Cycle# = 3
        ifTrueAction              = [!PauseMeasure handler.MAIN_CYCLE_DEBUG][!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
   ifCondition2                   = #CURRENTSECTION# = 1
        ifTrueAction2             = #Update_Net#   [!UpdateMeasureGroup #app_volume_static_process#][!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition3                  = #CURRENTSECTION# = 2 
        ifTrueAction3             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition4                  = #CURRENTSECTION# = 3
        ifTrueAction4             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition5                  = #CURRENTSECTION# = 4
        ifTrueAction5             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition6                  = #CURRENTSECTION# = 5
        ifTrueAction6             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition7                  = #CURRENTSECTION# = 6
        ifTrueAction7             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition8                  = #CURRENTSECTION# = 7
        ifTrueAction8             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition9                  = #CURRENTSECTION# = 8
        ifTrueAction9             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UpdateMeterGroup #debug#][!Redraw]
    ifCondition10                 = #CURRENTSECTION# = 9
        ifTrueAction10            = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!SetVariable 3rd_Cycle "(#3rd_Cycle# + 1)"][!SetVariable 2nd_Cycle "0"][!SetVariable 2nd_Cycle_Body "0"][!UnpauseMeasure handler.MAIN_CYCLE_DEBUG][!UpdateMeasure handler.MAIN_CYCLE_DEBUG][!UpdateMeasure handler.3RD_CYCLE_DEBUG]


;[handler.1ST_CYCLE]
; Measure                          = CALC
; Formula                          = #Cycle#
; DynamicVariables                 = 1
; Group                            = #handlers#
; Disabled                         = 0
;    ifCondition                   = #CURRENTSECTION# = 1
;        ifTrueAction              = #Update_Time#   #Update_Players#   #Update_Volume#   #Update_CPU#   #Update_CPU_Info#   [!UpdateMeasureGroup #threads#][!UpdateMeasureGroup #clock_info#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition2                  = #CURRENTSECTION# = 2
;        ifTrueAction2             = [!UpdateMeterGroup #threads#][!UpdateMeterGroup #clock_info#][!UpdateMeterGroup #cpu_info#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition3                  = #CURRENTSECTION# = 3 
;        ifTrueAction3             = #Update_GPU#   #Update_GPU_Info#   [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition4                  = #CURRENTSECTION# = 4
;        ifTrueAction4             = [!UpdateMeasure sensor.POWER_PLAN_ACTIVE_POWER][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition5                  = #CURRENTSECTION# = 5
;        ifTrueAction5             = [!UpdateMeasureGroup #net_sensors#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition6                  = #CURRENTSECTION# = 6
;        ifTrueAction6             = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition7                  = #CURRENTSECTION# = 7
;        ifTrueAction7             = [!UpdateMeasureGroup #ram#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition8                  = #CURRENTSECTION# = 8
;        ifTrueAction8             = [!UpdateMeterGroup #ram#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition9                  = #CURRENTSECTION# = 9
;        ifTrueAction9             = [!UpdateMeasureGroup #drives#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition10                 = #CURRENTSECTION# = 10
;        ifTrueAction10            = #Update_Time#   #Update_Players#   #Update_Volume#   #Update_Limiters#   [!UpdateMeterGroup #drives#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition11                 = #CURRENTSECTION# = 11
;        ifTrueAction11            = [!UpdateMeasureGroup #ram#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition12                 = #CURRENTSECTION# = 12
;        ifTrueAction12            = [!UpdateMeterGroup #ram#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition13                 = #CURRENTSECTION# = 13
;        ifTrueAction13            = [!UpdateMeasureGroup #drives_left_side#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition14                 = #CURRENTSECTION# = 14
;        ifTrueAction14            = [!UpdateMeterGroup #drives_left_side#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition15                 = #CURRENTSECTION# = 15
;        ifTrueAction15            = [!UpdateMeasureGroup #app_volume_controls_static#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition16                 = #CURRENTSECTION# = 16
;        ifTrueAction16            = [!UpdateMeasureGroup #cpu_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition17                 = #CURRENTSECTION# = 17
;        ifTrueAction17            = [!UpdateMeterGroup #cpu_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition18                 = #CURRENTSECTION# = 18 
;        ifTrueAction18            = [!UpdateMeasureGroup #gpu_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition19                 = #CURRENTSECTION# = 19
;        ifTrueAction19            = [!UpdateMeterGroup #gpu_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition20                 = #CURRENTSECTION# = 20
;        ifTrueAction20            = #Update_Time#   #Update_Players#   #Update_Volume#   #Update_Limiters#   [!UpdateMeasureGroup #ram_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition21                 = #CURRENTSECTION# = 21
;        ifTrueAction21            = [!UpdateMeterGroup #ram_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition22                 = #CURRENTSECTION# = 22
;        ifTrueAction22            = [!UpdateMeasureGroup #vram_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition23                 = #CURRENTSECTION# = 23
;        ifTrueAction23            = [!UpdateMeterGroup #vram_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition24                 = #CURRENTSECTION# = 24
;        ifTrueAction24            = [!UpdateMeasureGroup #io_read_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition25                 = #CURRENTSECTION# = 25
;        ifTrueAction25            = [!UpdateMeterGroup #io_read_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition26                 = #CURRENTSECTION# = 26
;        ifTrueAction26            = [!UpdateMeasureGroup #io_write_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition27                 = #CURRENTSECTION# = 27
;        ifTrueAction27            = [!UpdateMeterGroup #io_write_top#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition28                 = #CURRENTSECTION# = 28
;        ifTrueAction28            = #Update_Time#   #Update_Players#    #Update_Volume# [!UpdateMeasureGroup #app_volume_controls_dynamic#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition29                 = #CURRENTSECTION# = 29
;        ifTrueAction29            = [!UpdateMeterGroup #app_volume_controls_dynamic#][!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!Redraw]
;    ifCondition30                 = #CURRENTSECTION# = 30
;        ifTrueAction30            = [!SetVariable Cycle "(#Cycle# + 1)"]#Delay#[!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeterGroup #debug#][!SetVariable Cycle "1"][!SetVariable 2nd_Cycle "(#2nd_Cycle# + 1)"][!UpdateMeasure handler.1ST_CYCLE][!UpdateMeasure handler.2ND_CYCLE][!UpdateMeterGroup #debug#][!Redraw]


;[handler.2ND_CYCLE]
; Measure                          = CALC
; Formula                          = #2nd_Cycle_Body#
; DynamicVariables                 = 1
; Group                            = #handlers#
; Disabled                         = 0
;    ifCondition                   = #2nd_Cycle# = 3
;        ifTrueAction              = [!PauseMeasure handler.MAIN_CYCLE][!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;   ifCondition2                   = #CURRENTSECTION# = 1
;        ifTrueAction2             = #Update_Net#   [!UpdateMeasureGroup #app_volume_static_process#][!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition3                  = #CURRENTSECTION# = 2 
;        ifTrueAction3             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition4                  = #CURRENTSECTION# = 3
;        ifTrueAction4             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition5                  = #CURRENTSECTION# = 4
;        ifTrueAction5             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition6                  = #CURRENTSECTION# = 5
;        ifTrueAction6             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition7                  = #CURRENTSECTION# = 6
;        ifTrueAction7             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition8                  = #CURRENTSECTION# = 7
;        ifTrueAction8             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition9                  = #CURRENTSECTION# = 8
;        ifTrueAction9             = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition10                 = #CURRENTSECTION# = 9
;        ifTrueAction10            = [!SetVariable 2nd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UnPauseMeasure handler.MAIN_CYCLE][!SetVariable 3rd_Cycle "(#3rd_Cycle# + 1)"][!SetVariable 2nd_Cycle "0"][!SetVariable 2nd_Cycle_Body "0"][!UnpauseMeasure handler.MAIN_CYCLE][!UpdateMeasure handler.MAIN_CYCLE][!UpdateMeasure handler.3RD_CYCLE]

;[handler.3RD_CYCLE]
; Measure                          = CALC
; Formula                          = #3rd_Cycle_Body#
; DynamicVariables                 = 1
; Group                            = #handlers#
; Disabled                         = 0
;    ifCondition                   = #3rd_Cycle# = 3
;        ifTrueAction              = [!PauseMeasure handler.MAIN_CYCLE][!PauseMeasure handler.2ND_CYCLE][!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;   ifCondition2                   = #CURRENTSECTION# = 1
;        ifTrueAction2             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition3                  = #CURRENTSECTION# = 2 
;        ifTrueAction3             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition4                  = #CURRENTSECTION# = 3
;        ifTrueAction4             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition5                  = #CURRENTSECTION# = 4
;        ifTrueAction5             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition6                  = #CURRENTSECTION# = 5
;        ifTrueAction6             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition7                  = #CURRENTSECTION# = 6
;        ifTrueAction7             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition8                  = #CURRENTSECTION# = 7
;        ifTrueAction8             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition9                  = #CURRENTSECTION# = 8
;        ifTrueAction9             = [!SetVariable 3rd_Cycle_Body "(#3rd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#]
;    ifCondition10                 = #CURRENTSECTION# = 9
;        ifTrueAction10            = [!SetVariable 3rd_Cycle_Body "(#2nd_Cycle_Body# + 1)"]#Delay#[!UpdateMeasure #CURRENTSECTION#][!UnPauseMeasure handler.MAIN_CYCLE][!SetVariable 3rd_Cycle "(#3rd_Cycle# + 1)"][!SetVariable 3rd_Cycle "0"][!SetVariable 3rd_Cycle_Body "0"][!UnpauseMeasure handler.MAIN_CYCLE][!UpdateMeasure handler.MAIN_CYCLE][!UnpauseMeasure handler.2ND_CYCLE][!UpdateMeasure handler.2ND_CYCLE][!UpdateMeasure handler.3RD_CYCLE]