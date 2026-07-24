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

	class WINDOVE_API Monitor
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

		Monitor(GLFWmonitor* monitor);

		static Monitor getPrimaryMonitor();
		static std::vector<Monitor> getMonitors();

		static std::string getName(Monitor monitor);

		static std::vector<VideoMode> getSupportedVideoModes(Monitor monitor);
		static VideoMode getActiveVideoMode(Monitor monitor);

		static Vector2 getPhysicalSize(Monitor monitor);
		static Vector2 getVirtualPosition(Monitor monitor);
		static Vector2f getContentScale(Monitor monitor);
		static Rectangle getWorkArea(Monitor monitor);

		static void setGamma(Monitor monitor, float gamma);
		static GammaRamp getGammaRamp(Monitor monitor);
		static void setGammaRamp(Monitor monitor, GammaRamp& gammaRamp);

		void* getPlatformMonitor() const;
	};
}