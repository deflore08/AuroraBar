[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.5b
 Author                           = deflore08 (deflore08@daid-art.online) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Top process measures and meters.

[Variables]

; --- SENSORS 

; - CPU SENSORS

[terminator.CPU_TOP]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #CPU_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasureGroup #cpu_top#]
 Group                            = #terminators# | #sensors#

[sensor.CPU_TOP_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = CPU
 Index                            = 1
 Blacklist                        = _Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc 
 Group                            = #cpu_top# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TOP_1][!UpdateMeter text.dynamic.CPU_TOP_1_VALUE]

[sensor.CPU_TOP_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = CPU
 Index                            = 2
 Blacklist                        = _Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc 
 DynamicVariables                 = 1
 Disabled                         = #CPU_Top_State#
 Group                            = #cpu_top# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TOP_2][!UpdateMeter text.dynamic.CPU_TOP_2_VALUE]

[sensor.CPU_TOP_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = CPU
 Index                            = 3
 Blacklist                        = _Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc 
 DynamicVariables                 = 1
 Disabled                         = #CPU_Top_State#
 Group                            = #cpu_top# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TOP_3][!UpdateMeter text.dynamic.CPU_TOP_3_VALUE]

[sensor.CPU_TOP_4]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = CPU
 Index                            = 4
 Blacklist                        = _Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc 
 DynamicVariables                 = 1
 Disabled                         = #CPU_Top_State#
 Group                            = #cpu_top# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TOP_4][!UpdateMeter text.dynamic.CPU_TOP_4_VALUE]

[sensor.CPU_TOP_5]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = CPU
 Index                            = 5
 Blacklist                        = _Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc 
 DynamicVariables                 = 1
 Disabled                         = #CPU_Top_State#
 Group                            = #cpu_top# | #cpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.CPU_TOP_5][!UpdateMeter text.dynamic.CPU_TOP_5_VALUE]

; --- GPU SENSORS

[terminator.GPU_TOP]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #GPU_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasureGroup #gpu_top#]
 Group                            = #terminators# | #sensors#

[sensor.GPU_TOP_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = GPU
 Index                            = 1
 MinValue                         = 0
 MaxValue                         = 100
 Blacklist                        = dwm|csrss
 Group                            = #gpu_top# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TOP_1][!UpdateMeter text.dynamic.GPU_TOP_1_VALUE]

[sensor.GPU_TOP_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = GPU
 Index                            = 2
 MinValue                         = 0
 MaxValue                         = 100
 Blacklist                        = dwm|csrss
 DynamicVariables                 = 1
 Disabled                         = #GPU_Top_State#
 Group                            = #gpu_top# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TOP_2][!UpdateMeter text.dynamic.GPU_TOP_2_VALUE]

[sensor.GPU_TOP_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = GPU
 Index                            = 3
 MinValue                         = 0
 MaxValue                         = 100
 Blacklist                        = dwm|csrss
 DynamicVariables                 = 1
 Disabled                         = #GPU_Top_State#
 Group                            = #gpu_top# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TOP_3][!UpdateMeter text.dynamic.GPU_TOP_3_VALUE]

[sensor.GPU_TOP_4]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = GPU
 Index                            = 4
 MinValue                         = 0
 MaxValue                         = 100
 Blacklist                        = dwm|csrss
 DynamicVariables                 = 1
 Disabled                         = #GPU_Top_State#
 Group                            = #gpu_top# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TOP_4][!UpdateMeter text.dynamic.GPU_TOP_4_VALUE]

[sensor.GPU_TOP_5]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = GPU
 Index                            = 5
 MinValue                         = 0
 MaxValue                         = 100
 Blacklist                        = dwm|csrss
 DynamicVariables                 = 1
 Disabled                         = #GPU_Top_State#
 Group                            = #gpu_top# | #gpu_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.GPU_TOP_5][!UpdateMeter text.dynamic.GPU_TOP_5_VALUE]

; --- DRIVES SENSORS

[terminator.TOP_IO_WRITE]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #IO_Write_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasureGroup #io_write_top#]
 Group                            = #terminators# | #sensors#

[terminator.TOP_IO_READ]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #IO_Read_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasureGroup #io_read_top#]
 Group                            = #terminators# | #sensors#

[sensor.TOP_IO_READ_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IO
 Index                            = 1
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_READ_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_READ_1]

[formula.TOP_IO_READ_SCALED_1]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_READ_1
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_READ_1_VALUE]

[sensor.TOP_IO_READ_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IO
 Index                            = 2
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_READ_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_READ_2]

[formula.TOP_IO_READ_SCALED_2]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_READ_2
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_READ_2_VALUE]

[sensor.TOP_IO_READ_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IO
 Index                            = 3
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_READ_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_READ_3]

[formula.TOP_IO_READ_SCALED_3]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_READ_3
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_read_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_READ_3_VALUE]

[sensor.TOP_IO_WRITE_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IOWrite
 Index                            = 1
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_WRITE_SCALED_1][!UpdateMeter text.dynamic.TOP_IO_WRITE_1]

[formula.TOP_IO_WRITE_SCALED_1]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_WRITE_1
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_WRITE_1_VALUE]

[sensor.TOP_IO_WRITE_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IOWrite
 Index                            = 2
 DynamicVariables                 = 1
 Disabled                         = #Disk_Write_Top_State#
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_WRITE_SCALED_2][!UpdateMeter text.dynamic.TOP_IO_WRITE_2]

[formula.TOP_IO_WRITE_SCALED_2]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_WRITE_2
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_WRITE_2_VALUE]

[sensor.TOP_IO_WRITE_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = IOWrite
 Index                            = 3
 DynamicVariables                 = 1
 Disabled                         = #Disk_Write_Top_State#
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.TOP_IO_WRITE_SCALED_3][!UpdateMeter text.dynamic.TOP_IO_WRITE_3]

[formula.TOP_IO_WRITE_SCALED_3]
 Measure                          = CALC
 Formula                          = sensor.TOP_IO_WRITE_3
 DynamicVariables                 = 1
 Disabled                         = #Disk_Read_Top_State#
 Group                            = #io_write_top# | #drive_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.TOP_IO_WRITE_3_VALUE]

; --- RAM SENSORS

[terminator.RAM_TOP]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #RAM_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasure sensor.RAM_TOP_1][!UpdateMeasure sensor.RAM_TOP_2][!UpdateMeasure sensor.RAM_TOP_3]
 Group                            = #terminators# | #sensors#

[sensor.RAM_TOP_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = RAM
 Counter                          = Working Set
 Index                            = 1
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.RAM_TOP_SCALED_1][!UpdateMeter text.dynamic.RAM_TOP_1]

[formula.RAM_TOP_SCALED_1]
 Measure                          = CALC
 Formula                          = sensor.RAM_TOP_1
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.RAM_TOP_1_VALUE]

[sensor.RAM_TOP_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = RAM
 Counter                          = Working Set
 Index                            = 2
 DynamicVariables                 = 1
 Disabled                         = #RAM_Top_State#
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.RAM_TOP_SCALED_2][!UpdateMeter text.dynamic.RAM_TOP_2]

[formula.RAM_TOP_SCALED_2]
 Measure                          = CALC
 Formula                          = sensor.RAM_TOP_2
 DynamicVariables                 = 1
 Disabled                         = #RAM_Top_State#
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.RAM_TOP_2_VALUE]

[sensor.RAM_TOP_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = RAM
 Counter                          = Working Set
 Index                            = 3
 DynamicVariables                 = 1
 Disabled                         = #RAM_Top_State#
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.RAM_TOP_SCALED_3][!UpdateMeter text.dynamic.RAM_TOP_3]

[formula.RAM_TOP_SCALED_3]
 Measure                          = CALC
 Formula                          = sensor.RAM_TOP_3
 DynamicVariables                 = 1
 Disabled                         = #RAM_Top_State#
 Group                            = #ram_top# | #ram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.RAM_TOP_3_VALUE]

; --- VRAM SENSORS

[terminator.VRAM_TOP]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = taskkill /IM #VRAM_Top_App#.exe /F
 State                            = Hide
 DynamicVariables                 = 1
 OutputType                       = UTF8
 OutputFile                       = #Log_App_Terminate#
 FinishAction                     = [!UpdateMeasureGroup #vram_top#]
 Group                            = #terminators# | #vram# | #vram_top# | #sensors#

[sensor.VRAM_TOP_1]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = VRAM
 Index                            = 1
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.VRAM_TOP_SCALED_1][!UpdateMeter text.dynamic.VRAM_TOP_1]

[formula.VRAM_TOP_SCALED_1]
 Measure                          = CALC
 Formula                          = sensor.VRAM_TOP_1
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.VRAM_TOP_1_VALUE]

[sensor.VRAM_TOP_2]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = VRAM
 Index                            = 2
 DynamicVariables                 = 1
 Disabled                         = #VRAM_Top_State#
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.VRAM_TOP_SCALED_2][!UpdateMeter text.dynamic.VRAM_TOP_2]

[formula.VRAM_TOP_SCALED_2]
 Measure                          = CALC
 Formula                          = sensor.VRAM_TOP_2
 DynamicVariables                 = 1
 Disabled                         = #VRAM_Top_State#
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.VRAM_TOP_2_VALUE]

[sensor.VRAM_TOP_3]
 Measure                          = PLUGIN
 Plugin                           = UsageMonitor
 Alias                            = VRAM
 Index                            = 3
 DynamicVariables                 = 1
 Disabled                         = #VRAM_Top_State#
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeasure formula.VRAM_TOP_SCALED_3][!UpdateMeter text.dynamic.VRAM_TOP_3]

[formula.VRAM_TOP_SCALED_3]
 Measure                          = CALC
 Formula                          = sensor.VRAM_TOP_3
 DynamicVariables                 = 1
 Disabled                         = #VRAM_Top_State#
 Group                            = #vram_top# | #vram_sensors# | #sensors#
     onChangeAction               = [!UpdateMeter text.dynamic.VRAM_TOP_3_VALUE]

; --- TEXTS

; - CPU TEXTS

[text.dynamic.CPU_TOP_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 540
 Y                                = (#Pad_Top# + 198)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.CPU_TOP_1] :
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_1_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 198)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " [sensor.CPU_TOP_1:1]%"
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 512
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.CPU_TOP_2] :
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_2_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " [sensor.CPU_TOP_2:1]%"
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 484
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.CPU_TOP_3] :
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_3_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " [sensor.CPU_TOP_3:1]%"
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_4]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 456
 Y                                = (#Pad_Top# + 281 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.CPU_TOP_4] :
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_4_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 281 - #Pad_Bottom_CPU_Top#)
 W                                = 70
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " [sensor.CPU_TOP_4:1]%"
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_5]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 428
 Y                                = (#Pad_Top# + 309 - #Pad_Bottom_CPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.CPU_TOP_5] :
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

[text.dynamic.CPU_TOP_5_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 309 - #Pad_Bottom_CPU_Top#)
 W                                = 60
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " [sensor.CPU_TOP_5:1]%"
 Hidden                           = #CPU_Top_State#
 Group                            = #cpu# | #cpu_top# | #cpu_values# | #values#

; --- GPU TEXTS

[text.dynamic.GPU_TOP_1_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1380
 Y                                = (#Pad_Top# + 198)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.GPU_TOP_1:1]%
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 198)
 W                                = 100
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " : [sensor.GPU_TOP_1]"
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_2_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1408
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.GPU_TOP_2:1]%
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " : [sensor.GPU_TOP_2]"
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_3_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1436
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.GPU_TOP_3:1]%
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " : [sensor.GPU_TOP_3]"
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_4_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1464
 Y                                = (#Pad_Top# + 281 - #Pad_Bottom_GPU_Top#)
 W                                = 70
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.GPU_TOP_4:1]%
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_4]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 281 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " : [sensor.GPU_TOP_4]"
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_5_VALUE]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1492
 Y                                = (#Pad_Top# + 309 - #Pad_Bottom_GPU_Top#)
 W                                = 60
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = [sensor.GPU_TOP_5:1]%
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

[text.dynamic.GPU_TOP_5]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 309 - #Pad_Bottom_GPU_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 Text                             = " : [sensor.GPU_TOP_5]"
 Hidden                           = #GPU_Top_State#
 Group                            = #gpu# | #gpu_top# | #gpu_values# | #values#

; --- RAM TEXTS

[text.dynamic.RAM_TOP_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 320
 Y                                = (#Pad_Top# + 10)
 W                                = 100
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = [sensor.RAM_TOP_1] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

[text.dynamic.RAM_TOP_1_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.RAM_TOP_SCALED_1
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 10)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = " %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

[text.dynamic.RAM_TOP_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 292
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = [sensor.RAM_TOP_2] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

[text.dynamic.RAM_TOP_2_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.RAM_TOP_SCALED_2
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = " %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

[text.dynamic.RAM_TOP_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 264
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = [sensor.RAM_TOP_3] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

[text.dynamic.RAM_TOP_3_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.RAM_TOP_SCALED_3
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = " %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #RAM_Top_State#
 Group                            = #ram# | #ram_top# | #ram_values# | #values#

; --- VRAM TEXTS

[text.dynamic.VRAM_TOP_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 320
 Y                                = (#Pad_Top# + 198)
 W                                = 100
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = [sensor.VRAM_TOP_1] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

[text.dynamic.VRAM_TOP_1_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.VRAM_TOP_SCALED_1
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 198)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             = " %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

[text.dynamic.VRAM_TOP_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 292
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_VRAM_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = [sensor.VRAM_TOP_2] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

[text.dynamic.VRAM_TOP_2_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.VRAM_TOP_SCALED_2
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_VRAM_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = " %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

[text.dynamic.VRAM_TOP_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Right_Align
 X                                = 264
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_VRAM_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 Text                             = [sensor.VRAM_TOP_3] :
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

[text.dynamic.VRAM_TOP_3_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.VRAM_TOP_SCALED_3
 MeterStyle                       = style.text.Simple_Font_Left_Align_Value
 X                                = 0r
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_VRAM_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 Text                             =" %1B"
 NumOfDecimals                    = 1
 AutoScale                        = 2
 DynamicVariables                 = 1
 Hidden                           = #VRAM_Top_State#
 Group                            = #vram# | #vram_top# | #vram_values# | #values#

; --- DRIVES TEXTS

[text.dynamic.TOP_IO_READ_1_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_READ_SCALED_1
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1600
 Y                                = (#Pad_Top# + 198)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_READ_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 198)
 W                                = 100
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_READ_1]"
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_READ_2_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_READ_SCALED_2
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1628
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Disk_Read_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_READ_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 225 - #Pad_Bottom_Disk_Read_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_READ_2]"
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_READ_3_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_READ_SCALED_3
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1656
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_Disk_Read_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_READ_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 253 - #Pad_Bottom_Disk_Read_Top#)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_READ_3]"
 Hidden                           = #Disk_Read_Top_State#
 Group                            = #drives# | #io_read_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_1_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_WRITE_SCALED_1
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1600
 Y                                = (#Pad_Top# + 10)
 W                                = 100
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_1]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# + 10)
 W                                = 80
 SolidColor                       = 0,0,0,0
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_WRITE_1]"
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_2_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_WRITE_SCALED_2
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1628
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_2]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# - 19)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_WRITE_2]"
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_3_VALUE]
 Meter                            = STRING
 MeasureName                      = formula.TOP_IO_WRITE_SCALED_3
 MeterStyle                       = style.text.Simple_Font_Right_Align_Value
 X                                = 1656
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = %1B
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#

[text.dynamic.TOP_IO_WRITE_3]
 Meter                            = STRING
 MeterStyle                       = style.text.Simple_Font_Left_Align
 X                                = 0r
 Y                                = (#Pad_Top# - 47)
 W                                = 80
 SolidColor                       = 0,0,0,1
 ClipString                       = 1
 DynamicVariables                 = 1
 AutoScale                        = 1
 NumOfDecimals                    = 1
 Text                             = " : [sensor.TOP_IO_WRITE_3]"
 Hidden                           = #Disk_Write_Top_State#
 Group                            = #drives# | #io_write_top# | #drives_values# | #values#