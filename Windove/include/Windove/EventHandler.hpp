#pragma once

#include "Windove/Input/Controller.hpp"
#include "Windove/Input/Keyboard.hpp"
#include "Windove/Input/Monitor.hpp"
#include "Windove/Input/Mouse.hpp"

#include <vector>
#include <string>

namespace dove
{
	class WINDOVE_API EventHandler
	{
	public:
		virtual ~EventHandler() = default;

		virtual void onControllerConnected(Controller::Id controllerId) {};
		virtual void onControllerDisconnected(Controller::Id controllerId) {};
		virtual void onCursorEntered() {};
		virtual void onCursorLeft() {};
		virtual void onDragAndDrop(const std::vector<std::string>& paths) {};
		virtual void onFramebufferResized(unsigned int width, unsigned int height) {};
		virtual void onKeyPressed(KeyEvent keyEvent) {};
		virtual void onKeyReleased(KeyEvent keyEvent) {};
		virtual void onKeyRepeated(KeyEvent keyEvent) {};
		virtual void onMonitorConnected(Monitor monitor) {};
		virtual void onMonitorDisconnected(Monitor monitor) {};
		virtual void onMouseMoved(unsigned int x, unsigned int y) {};
		virtual void onMousePressed(MouseEvent mouseEvent) {};
		virtual void onMouseReleased(MouseEvent mouseEvent) {};
		virtual void onMouseScrolled(int horizontalScroll, int verticalScroll) {};
		virtual void onTextEntered(unsigned int keyCode) {};
		virtual void onWindowClosed() {};
		virtual void onWindowContentScaled(float x, float y) {};
		virtual void onWindowFocusGained() {};
		virtual void onWindowFocusLost() {};
		virtual void onWindowMinimized() {};
		virtual void onWindowMaximized() {};
		virtual void onWindowRestored() {};
		virtual void onWindowMoved(unsigned int x, unsigned int y) {};
		virtual void onWindowRefreshed() {};
		virtual void onWindowResized(unsigned int width, unsigned int height) {};
	};
}