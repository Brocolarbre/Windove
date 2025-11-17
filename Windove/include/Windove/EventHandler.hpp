#pragma once

#include "Windove/Input/Controller.hpp"
#include "Windove/Input/Keyboard.hpp"
#include "Windove/Input/Monitor.hpp"
#include "Windove/Input/Mouse.hpp"

#include <vector>
#include <string>

namespace dove
{
	class EventHandler
	{
	public:
		WINDOVE_API virtual ~EventHandler() = default;

		WINDOVE_API virtual void onControllerConnected(Controller::Id controllerId) {};
		WINDOVE_API virtual void onControllerDisconnected(Controller::Id controllerId) {};
		WINDOVE_API virtual void onCursorEntered() {};
		WINDOVE_API virtual void onCursorLeft() {};
		WINDOVE_API virtual void onDragAndDrop(const std::vector<std::string>& paths) {};
		WINDOVE_API virtual void onFramebufferResized(unsigned int width, unsigned int height) {};
		WINDOVE_API virtual void onKeyPressed(KeyEvent keyEvent) {};
		WINDOVE_API virtual void onKeyReleased(KeyEvent keyEvent) {};
		WINDOVE_API virtual void onKeyRepeated(KeyEvent keyEvent) {};
		WINDOVE_API virtual void onMonitorConnected(Monitor monitor) {};
		WINDOVE_API virtual void onMonitorDisconnected(Monitor monitor) {};
		WINDOVE_API virtual void onMouseMoved(unsigned int x, unsigned int y) {};
		WINDOVE_API virtual void onMousePressed(MouseEvent mouseEvent) {};
		WINDOVE_API virtual void onMouseReleased(MouseEvent mouseEvent) {};
		WINDOVE_API virtual void onMouseScrolled(int horizontalScroll, int verticalScroll) {};
		WINDOVE_API virtual void onTextEntered(unsigned int keyCode) {};
		WINDOVE_API virtual void onWindowClosed() {};
		WINDOVE_API virtual void onWindowContentScaled(float x, float y) {};
		WINDOVE_API virtual void onWindowFocusGained() {};
		WINDOVE_API virtual void onWindowFocusLost() {};
		WINDOVE_API virtual void onWindowMinimized() {};
		WINDOVE_API virtual void onWindowMaximized() {};
		WINDOVE_API virtual void onWindowRestored() {};
		WINDOVE_API virtual void onWindowMoved(unsigned int x, unsigned int y) {};
		WINDOVE_API virtual void onWindowRefreshed() {};
		WINDOVE_API virtual void onWindowResized(unsigned int width, unsigned int height) {};
	};
}