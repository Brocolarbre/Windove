#include "Windove/Input/Monitor.hpp"
#include "Windove/Window.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	Monitor::Monitor(GLFWmonitor* monitor) :
		m_monitor(monitor)
	{

	}

	Monitor Monitor::getPrimaryMonitor()
	{
		return Monitor(glfwGetPrimaryMonitor());
	}

	std::vector<Monitor> Monitor::getMonitors()
	{
		int monitorsCount = 0;
		GLFWmonitor** monitorsData = glfwGetMonitors(&monitorsCount);

		std::vector<Monitor> monitors;
		for (int i = 0; i < monitorsCount; ++i)
			monitors.push_back(Monitor(monitorsData[i]));

		return monitors;
	}

	std::string Monitor::getName(Monitor monitor)
	{
		return std::string(glfwGetMonitorName(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor())));
	}

	std::vector<Monitor::VideoMode> Monitor::getSupportedVideoModes(Monitor monitor)
	{
		int videoModesCount = 0;
		const GLFWvidmode* modes = glfwGetVideoModes(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &videoModesCount);

		std::vector<VideoMode> videoModes;
		for (int i = 0; i < videoModesCount; ++i)
		{
			VideoMode videoMode{};
			videoMode.width = modes[i].width;
			videoMode.height = modes[i].height;
			videoMode.redBits = modes[i].redBits;
			videoMode.greenBits = modes[i].greenBits;
			videoMode.blueBits = modes[i].blueBits;
			videoMode.refreshRate = modes[i].refreshRate;

			videoModes.push_back(videoMode);
		}

		return videoModes;
	}

	Monitor::VideoMode Monitor::getActiveVideoMode(Monitor monitor)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()));

		VideoMode videoMode{};
		videoMode.width = mode->width;
		videoMode.height = mode->height;
		videoMode.redBits = mode->redBits;
		videoMode.greenBits = mode->greenBits;
		videoMode.blueBits = mode->blueBits;
		videoMode.refreshRate = mode->refreshRate;

		return videoMode;
	}

	Vector2 Monitor::getPhysicalSize(Monitor monitor)
	{
		int width = 0, height = 0;
		glfwGetMonitorPhysicalSize(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &width, &height);

		return Vector2{ width, height };
	}

	Vector2 Monitor::getVirtualPosition(Monitor monitor)
	{
		int xpos, ypos;
		glfwGetMonitorPos(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &xpos, &ypos);

		return Vector2{ xpos, ypos };
	}

	Vector2f Monitor::getContentScale(Monitor monitor)
	{
		float xscale = 1.0f, yscale = 1.0f;
		glfwGetMonitorContentScale(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &xscale, &yscale);

		return Vector2f{ xscale, yscale };
	}

	Rectangle Monitor::getWorkArea(Monitor monitor)
	{
		int xpos = 0, ypos = 0, width = 0, height = 0;
		glfwGetMonitorWorkarea(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &xpos, &ypos, &width, &height);

		return Rectangle{ xpos, ypos, width, height };
	}

	void Monitor::setGamma(Monitor monitor, float gamma)
	{
		glfwSetGamma(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), gamma);
	}

	Monitor::GammaRamp Monitor::getGammaRamp(Monitor monitor)
	{
		const GLFWgammaramp* gammaRampData = glfwGetGammaRamp(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()));

		GammaRamp gammaRamp;

		gammaRamp.red.reserve(gammaRampData->size);
		gammaRamp.green.reserve(gammaRampData->size);
		gammaRamp.blue.reserve(gammaRampData->size);

		for (unsigned int i = 0; i < gammaRampData->size; ++i)
		{
			gammaRamp.red.push_back(gammaRampData->red[i]);
			gammaRamp.green.push_back(gammaRampData->green[i]);
			gammaRamp.blue.push_back(gammaRampData->blue[i]);
		}

		return gammaRamp;
	}

	void Monitor::setGammaRamp(Monitor monitor, GammaRamp& gammaRamp)
	{
		if (gammaRamp.red.size() != gammaRamp.green.size() || gammaRamp.red.size() != gammaRamp.blue.size())
			return;

		GLFWgammaramp gammaRampData{};

		gammaRampData.size = static_cast<unsigned int>(gammaRamp.red.size());

		for (unsigned int i = 0; i < gammaRampData.size; ++i)
		{
			gammaRampData.red = gammaRamp.red.data();
			gammaRampData.green = gammaRamp.green.data();
			gammaRampData.blue = gammaRamp.blue.data();
		}

		glfwSetGammaRamp(static_cast<GLFWmonitor*>(monitor.getPlatformMonitor()), &gammaRampData);
	}

	void* Monitor::getPlatformMonitor() const
	{
		return m_monitor;
	}
}