extDir = {}
extDir["SDL2"] = "%{wks.location}/ThirdParty/SDL2"
extDir["glew"] = "%{wks.location}/ThirdParty/glew"
extDir["SOIL2"] = "%{wks.location}/ThirdParty/SOIL2"

workspace "Towell"
	architecture "x86_64"
	startproject "Editor"

	configurations 
	{ 
		"Debug",
		"Release" 
	}

	externalincludedirs 
	{
		"%{extDir.SDL2}/include",
		"%{extDir.glew}/include",
		"%{extDir.SOIL2}/src/SOIL2",
	}

	libdirs
	{
		"%{extDir.SDL2}/lib/x64",
		"%{extDir.glew}/lib/Release/x64",
		"%{extDir.SOIL2}/lib/windows",
	}

	links
	{
		"SDL2",
		"SDL2main",
		"opengl32",
		"glew32",
		"soil2-debug.lib",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Engine"
include "Editor"