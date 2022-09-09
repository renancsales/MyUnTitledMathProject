projectName = "MyUntitledMathProject"
workspace "MyUntitledMathProject"
	architecture "x64"
	startproject  "MyUntitledMathProject"
	
	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (sol. directory)
IncludeDir = {}

project "MyUntitledMathProject"
	location "MyUntitledMathProject"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/mpfr/include/**.h",
		"%{prj.name}/vendor/mpir/include/**.h"
	}
	
	
	-- Additional library directories
	libdirs { "%{prj.name}/vendor/mpfr/lib",
				"%{prj.name}/vendor/mpir/lib"}
	

				
	-- OpenMP support
	buildoptions { "/openmp" }
	
	defines 
	{
		"NDEBUG", "_CONSOLE", 
	}
	
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/Eigen",
		"%{prj.name}/vendor/mpfr/include",
		"%{prj.name}/vendor/mpir/include"
	}
							
	-- Filter: Configurations only applied to specific platforms
	filter "system:windows"
		systemversion "latest"	
		postbuildcommands {
		"{COPY} ..\\%{prj.name}\\vendor\\mpfr\\include\\mpfr.dll %{cfg.targetdir}",
		"{COPY} ..\\%{prj.name}\\vendor\\mpir\\include\\mpir.dll %{cfg.targetdir}",
		}
		
		links {"mpir.lib", "mpfr.lib"}
		
	filter "configurations:Debug"
		defines { "_DEBUG" }
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines { "_RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"