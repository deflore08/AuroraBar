[Metadata]
 Name                             = AuroraBar
 Version                          = 2.1.4b
 Author                           = deflore08 (deflore08@gmail.com) | https://www.deviantart.com/deflore08
 License                          = Creative Commons Attribution-Non-Commercial-Share Alike 3.0
 Information                      = Animation measures: faders, sliders etc

[Variables]

; --- FADER DELAYS

; - Defines delays between iterations

 FaderDelay_A                     = 1
 FaderDelay_B                     = 2
 FaderDelay_C                     = 20
 FaderDelay_D                     = 30
 FaderDelay_E                     = 40
 FaderDelay_F                     = 50

; - TRIANGLES Alpha

 Alpha_Tri_Top                    = 0
 Alpha_Tri_Left                   = 0
 Alpha_Tri_Right                  = 0
 Alpha_Tri_Bottom                 = 0

; --- CRYSTAL Alpha

 Alpha_Crystal_Shapes             = 0


; --- FADERS BEGINNING

; - TRIANGLES (Left, Top, Right, Bottom)

[animation.fader.TRIANGLES]
 Measure                          = PLUGIN
 Plugin                           = ActionTimer
 DynamicVariables                 = 1
 
 ActionList1                      = Repeat Fade_Alpha_Tri_Top_N, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Top_N             = [!SetVariable Alpha_Tri_Top "(Clamp(#Alpha_Tri_Top#-12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Top-Shape_Faded][!Redraw]
 ActionList2                      = Repeat Fade_Alpha_Tri_Top_P, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Top_P             = [!SetVariable Alpha_Tri_Top "(Clamp(#Alpha_Tri_Top#+12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Top-Shape_Faded][!Redraw]
 
 ActionList3                      = Repeat Fade_Alpha_Tri_Left_N, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Left_N            = [!SetVariable Alpha_Tri_Left "(Clamp(#Alpha_Tri_Left#-12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Left-Shape_Faded][!Redraw]
 ActionList4                      = Repeat Fade_Alpha_Tri_Left_P, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Left_P            = [!SetVariable Alpha_Tri_Left "(Clamp(#Alpha_Tri_Left#+12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Left-Shape_Faded][!Redraw]
 
 ActionList5                      = Repeat Fade_Alpha_Tri_Right_N, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Right_N           = [!SetVariable Alpha_Tri_Right "(Clamp(#Alpha_Tri_Right#-12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Right-Shape_Faded][!Redraw]
 ActionList6                      = Repeat Fade_Alpha_Tri_Right_P, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Right_P           = [!SetVariable Alpha_Tri_Right "(Clamp(#Alpha_Tri_Right#+12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Right-Shape_Faded][!Redraw]
 
 ActionList7                      = Repeat Fade_Alpha_Tri_Bottom_N, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Bottom_N          = [!SetVariable Alpha_Tri_Bottom "(Clamp(#Alpha_Tri_Bottom#-12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Bottom-Shape_Faded][!Redraw]
 ActionList8                      = Repeat Fade_Alpha_Tri_Bottom_P, #FaderDelay_B#, 12
 Fade_Alpha_Tri_Bottom_P          = [!SetVariable Alpha_Tri_Bottom "(Clamp(#Alpha_Tri_Bottom#+12,0,124))"][!UpdateMeasure animation.fader.TRIANGLES][!UpdateMeter shape.Triangle_Bottom-Shape_Faded][!Redraw]

[animation.fader.CRYSTALS]
 Measure                          = PLUGIN
 Plugin                           = ActionTimer
 DynamicVariables                 = 1

 ActionList1                      = Repeat Fade_Crystal_Shapes_N, #FaderDelay_A#, 12
 Fade_Crystal_Shapes_N            = [!SetVariable Alpha_Crystal_Shapes "(Clamp(#Alpha_Crystal_Shapes#-12,0,124))"][!UpdateMeasure animation.fader.CRYSTALS][!UpdateMeterGroup #config#][!Redraw]
 ActionList2                      = Repeat Fade_Crystal_Shapes_P, #FaderDelay_A#, 12
 Fade_Crystal_Shapes_P            = [!SetVariable Alpha_Crystal_Shapes "(Clamp(#Alpha_Crystal_Shapes#+12,0,124))"][!UpdateMeasure animation.fader.CRYSTALS][!UpdateMeterGroup #config#][!Redraw]

; - FADERS END