#include "Windove/ControllerManager.hpp"
#include "Windove/Event/ControllerConnectedEvent.hpp"
#include "Windove/Event/ControllerDisconnectedEvent.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	namespace
	{
		void joystick_callback(int jid, int event)
		{
			switch (event)
			{
			case GLFW_CONNECTED: ControllerManager::getEventDispatcher().receiveEvent<ControllerConnectedEvent>(Controller::getController(jid)); break;
			case GLFW_DISCONNECTED: ControllerManager::getEventDispatcher().receiveEvent<ControllerDisconnectedEvent>(Controller::getController(jid)); break;
			}
		}
	}

	EventDispatcher ControllerManager::m_eventDispatcher;

	void ControllerManager::enableEventDispatcher()
	{
		glfwSetJoystickCallback(joystick_callback);
	}

	EventDispatcher& ControllerManager::getEventDispatcher()
	{
		return m_eventDispatcher;
	}
}