project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/out/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src"
	}

	externalincludedirs 
	{
		"%{extDir.SDL2}/include",
		"%{extDir.glew}/include",
	}

	libdirs
	{
		"%{extDir.SDL2}/lib/x64",
		"%{extDir.glew}/lib/Release/x64",
	}

	links
	{
		"SDL2",
		"SDL2main",
		"opengl32",
		"glew32",
	}


	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		runtime "Release"
		optimize "on"