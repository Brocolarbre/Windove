#pragma once

#include "Windove/Export.hpp"

#include <string>
#include <vector>

struct GLFWmonitor;

namespace dove
{
	class Window;
	struct Vector2;

	struct Vector2f
	{
		float x;
		float y;
	};

	struct Rectangle
	{
		int x;
		int y;
		int width;
		int height;
	};

	class Monitor
	{
	private:
		GLFWmonitor* m_monitor;

	public:
		struct VideoMode
		{
			int width;
			int height;
			int redBits;
			int greenBits;
			int blueBits;
			int refreshRate;
		};

		struct GammaRamp
		{
			std::vector<unsigned short> red;
			std::vector<unsigned short> green;
			std::vector<unsigned short> blue;
		};

		WINDOVE_API Monitor(GLFWmonitor* monitor);

		WINDOVE_API static Monitor getPrimaryMonitor();
		WINDOVE_API static std::vector<Monitor> getMonitors();

		WINDOVE_API static std::string getName(Monitor monitor);

		WINDOVE_API static std::vector<VideoMode> getSupportedVideoModes(Monitor monitor);
		WINDOVE_API static VideoMode getActiveVideoMode(Monitor monitor);

		WINDOVE_API static Vector2 getPhysicalSize(Monitor monitor);
		WINDOVE_API static Vector2 getVirtualPosition(Monitor monitor);
		WINDOVE_API static Vector2f getContentScale(Monitor monitor);
		WINDOVE_API static Rectangle getWorkArea(Monitor monitor);

		WINDOVE_API static void setGamma(Monitor monitor, float gamma);
		WINDOVE_API static GammaRamp getGammaRamp(Monitor monitor);
		WINDOVE_API static void setGammaRamp(Monitor monitor, GammaRamp& gammaRamp);

		WINDOVE_API void* getPlatformMonitor() const;
	};
}