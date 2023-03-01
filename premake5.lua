workspace "Thease"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Thease"
	location "Thease"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
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
		
		