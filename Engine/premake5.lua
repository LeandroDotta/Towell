thirdPartyPath = "%{prj.location}/../ThirdParty"

extDir = {}
extDir["SDL2"] = "%{thirdPartyPath}/SDL2"
extDir["glew"] = "%{thirdPartyPath}/glew"
extDir["SOIL2"] = "%{thirdPartyPath}/SOIL2"

project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/out/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	defines { "SHADERS_PATH=\"" .. path.getabsolute("%{prj.location}/Shaders") .. "\"" }

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
	

	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		runtime "Release"
		optimize "on"