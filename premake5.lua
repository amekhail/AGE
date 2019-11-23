workspace "AGE"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "AGE"
		location "AGE"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin/" .. outputdir .. "/%{prj.name}")

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
				"AGE_PLATFORM_WINDOWS",
				"AGE_BUILD_DLL"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}
		
		filter "configurations:Debug"
			defines "AGE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AGE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AGE_DIST"
			optimize "On"

	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"AGE/vendor/spdlog/include",
			"AGE/src"
		}

		links 
		{
			"AGE"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"AGE_PLATFORM_WINDOWS"
			}

		
		filter "configurations:Debug"
			defines "AGE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AGE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AGE_DIST"
			optimize "On"