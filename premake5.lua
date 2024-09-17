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