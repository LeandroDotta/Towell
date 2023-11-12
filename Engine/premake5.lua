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

	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		runtime "Release"
		optimize "on"


-- project "Editor"
-- 	kind "ConsoleApp"
-- 	language "C++"
-- 	cppdialect "C++17"
-- 	staticruntime "off"

-- 	targetdir ("%{wks.location}/out/" .. outputdir .. "/%{prj.name}")
-- 	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

-- 	files
-- 	{
-- 		"src/**.h",
-- 		"src/**.cpp"
-- 	}

-- 	includedirs
-- 	{
-- 		"%{wks.location}/Engine/src"
-- 	}

-- 	links
-- 	{
-- 		"Engine"
-- 	}

-- 	filter "system:windows"
-- 		systemversion "latest"


-- 	filter "configurations:Debug"
-- 		runtime "Debug"
-- 		symbols "on"


-- 	filter "configurations:Release"
-- 		runtime "Release"
-- 		optimize "on"