function Initialize()
	sFileToWrite = SELF:GetOption('FileToWrite')
end -- function Initialize

function Update()

	hWritingFile = io.open(sFileToWrite)
	if not hWritingFile then
		print('LuaWriteFile: unable to open file at ' .. sFileToWrite)
		return
     end
     
     Contents = SKIN:GetVariable('CPU_Top_App_V_1')
     var = 333


	return sContents
end -- function Update

function writeToFile()

	file = io.open(sFileToWrite, "a+")
     file:write("temp is: ", Contents, "\n")
	file:close()
end