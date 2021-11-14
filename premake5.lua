workspace "Lumin"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lumin"
	location "Lumin"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"LUMIN_PLATFORM_WINDOWS",
			"LUMIN_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "LUMIN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LUMIN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LUMIN_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"Lumin/vendor/spdlog/include",
		"Lumin/src"
	}

	links 
	{
		"Lumin"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"LUMIN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LUMIN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LUMIN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LUMIN_DIST"
		optimize "On"
