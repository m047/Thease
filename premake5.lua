workspace "Thease"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Thease/vendor/GLFW/include"

include "Thease/vendor/GLFW"

project "Thease"
	location "Thease"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "thpch.h"
	pchsource "Thease/src/thpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines 
		{
			"THEA_PLATFORM_WINDOWS",
			"THEA_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "TH_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "TH_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "TH_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Thease/vendor/spdlog/include",
		"Thease/src"
	}
	
	links
	{
		"Thease"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines 
		{
			"THEA_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "TH_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "TH_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "TH_DIST"
		optimize "On"
		
		