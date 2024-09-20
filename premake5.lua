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

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Engine"
include "Editor"