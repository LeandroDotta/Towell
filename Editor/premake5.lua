project "Editor"
	kind "ConsoleApp"
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
		"%{wks.location}/Engine/src"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"
		postbuildcommands 
		{
			-- Copy DLLs to the output directory
			"{COPY} %{extDir.SDL2}/lib/x64/SDL2.dll %{cfg.targetdir}",
			"{COPY} %{extDir.glew}/bin/Release/x64/glew32.dll %{cfg.targetdir}",
		}


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		runtime "Release"
		optimize "on"