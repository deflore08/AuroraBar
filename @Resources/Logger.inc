[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.2b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Logger module. This thing makes a sensor's logs.

[Variables]
 Logger_Frequence                 = 6
 Logger_CPU                       = 3
 Logger_GPU                       = 6

[logger.HANDLER]
 Measure                          = Loop
 StartValue                       = 1
 EndValue                         = #Logger_Frequence#
 Increment                        = 1
 LoopCount                        = 0
 DynamicVariables                 = 1
     ifCondition                  = logger.HANDLER = #Logger_CPU#
          ifTrueAction            = [!CommandMeasure logger.CPU "run"]
     ifCondition2                 = #CURRENTSECTION# = #Logger_GPU#
          ifTrueAction2           = [!CommandMeasure logger.GPU "run"]

; "$(Get-Date -uformat '%D %T') [logger.HANDLER]"

[logger.CPU]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = "$(Get-Date -uformat '%D %T')" + """ [#CPU_Health_State#]""" + """ CPU LOAD: """ + """[sensor.CPU_LOAD]%""" + """  | """ + """CPU TEMP: """ + """[sensor.CPU_TEMPERATURE]C""" + """ | """ + """CPU CLOCK: """ + """[sensor.CPU_CLOCK""" + """ | """ + """THROTTLING: """ + """[sensor.THROTTLING_CPU]""" + """ | """ + """POWER LIMIT: """ + """[sensor.POWER_LIMIT_CPU]""" + """ | """ + """TOP APP: """ + """[sensor.CPU_TOP_1].exe : [sensor.CPU_TOP_1:1]%""" | Out-File #Log_CPU# -Append
 State                            = Hide
 OutputType                       = UTF8
 DynamicVariables                 = 1

[logger.GPU]
 Measure                          = PLUGIN
 Plugin                           = RunCommand
 Program                          = PowerShell
 Parameter                        = """[#GPU_Health_State#] """ + "$(Get-Date -uformat '%D %T')" + """ GPU LOAD: """ + """[m.GPU_Load]%""" + """ | """ + """GPU TEMP: """ + """[m.GPU_Temp]C""" + """ | """ + """CPU CLOCK: """ + """[sensor.GPU_CLOCK]""" + """ | """ + """THROTTLING: """ + """[sensor.THROTTLING_GPU]""" + """ | """ + """POWER LIMIT: """ + """[sensor.POWER_LIMIT_GPU]""" + """ | """ + """TOP APP: """ + """[sensor.GPU_TOP_1].exe : [sensor.GPU_TOP_1:1]%""" | Out-File #Log_GPU# -Append
 State                            = Hide
 OutputType                       = UTF8
 DynamicVariables                 = 1