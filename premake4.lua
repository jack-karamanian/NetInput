solution "netinput"
	configurations { "Debug", "Release" }

project "netinput"
	kind "ConsoleApp"
	language "C++"
	buildoptions { "-std=gnu++11" }
	links { "POSIXUtil", "LinuxEvent" }
	files {
		"Server.h",
		"Server.cpp",
		"InputSystem.h",
		"InputSystem.cpp",
		"InputPacket.h",
		"InputPacket.cpp",
		"DeviceType.h",
		"EventHandler.h",
		"MouseEvent.h",
		"main.cpp"
	}

project "POSIXUtil"
	kind "SharedLib"
	language "C++"
	buildoptions { "-std=gnu++11" }
	files {
		"FileDesc.h",
		"FileDesc.cpp"
	}	

project "LinuxEvent"
	kind "SharedLib"
	language "C++"
	buildoptions { "-std=gnu++11" }
	links { "POSIXUtil" }
	files {
		"DeviceType.h",
		"OSEventHandlerExport.h",
		"EventHandler.h",
		"LinuxEventHandlerExport.cpp",
		"LinuxEventHandler.cpp",
		"LinuxEventHandler.h",
		"LinuxDevice.h",
		"LinuxDevice.cpp",
		"LinuxMouse.h",
		"LinuxMouse.cpp",
		"MouseEvent.h"
	}
