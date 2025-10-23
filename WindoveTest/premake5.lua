project "WindoveTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir (outputdir .. "/%{prj.name}")
	objdir (outputdir .. "/%{prj.name}/intermediates")

	includedirs {
		"%{wks.location}/Windove/include"
	}
	
	links {
		"Windove"
	}
	
	filter "not options:shared-library"
		links {
			"glfw3"
		}
		
		defines {
			"WINDOVE_STATIC"
		}

	filter {}
	
	files {
		"src/**.hpp",
		"src/**.cpp"
	}