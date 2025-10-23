project "Windove"
	language "C++"
	cppdialect "C++17"

	targetdir (outputdir .. "/%{prj.name}")
	objdir (outputdir .. "/%{prj.name}/intermediates")
	
	filter "options:shared-library"
		kind "SharedLib"
		
		filter { "options:shared-library", "configurations:Debug" }
			postbuildcommands "{COPY} %{cfg.buildtarget.relpath} %{wks.location}/external/bin/debug"
		filter { "options:shared-library", "configurations:Release" }
			postbuildcommands "{COPY} %{cfg.buildtarget.relpath} %{wks.location}/external/bin/release"
		filter "options:shared-library"
		
		links {
			"glfw3"
		}
		
		defines	{
			"WINDOVE_EXPORT"
		}
		
	filter "not options:shared-library"
		kind "StaticLib"
		
		defines	{
			"WINDOVE_STATIC"
		}
		
	filter {}

	includedirs {
		"include"
	}
	
	defines {
	
	}

	files {
		"include/**.hpp",
		"src/**.cpp"
	}

	filter "not options:vulkan-support"
		removefiles {
			"include/Windove/Vulkan.hpp",	
			"src/Vulkan.cpp"
		}

	filter {}