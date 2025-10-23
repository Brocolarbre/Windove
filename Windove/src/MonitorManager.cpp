#include "Windove/MonitorManager.hpp"
#include "Windove/Event/MonitorConnectedEvent.hpp"
#include "Windove/Event/MonitorDisconnectedEvent.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	namespace
	{
		void monitor_callback(GLFWmonitor* monitor, int event)
		{
			switch (event)
			{
			case GLFW_CONNECTED: MonitorManager::getEventDispatcher().receiveEvent<MonitorConnectedEvent>(Monitor(monitor)); break;
			case GLFW_DISCONNECTED: MonitorManager::getEventDispatcher().receiveEvent<MonitorDisconnectedEvent>(Monitor(monitor)); break;
			}
		}
	}

	EventDispatcher MonitorManager::m_eventDispatcher;

	void MonitorManager::enableEventDispatcher()
	{
		glfwSetMonitorCallback(monitor_callback);
	}

	EventDispatcher& MonitorManager::getEventDispatcher()
	{
		return m_eventDispatcher;
	}
}
