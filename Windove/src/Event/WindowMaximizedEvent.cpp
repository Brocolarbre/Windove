#include "Windove/Event/WindowMaximizedEvent.hpp"

namespace dove
{
	WindowMaximizedEvent::WindowMaximizedEvent()
	{

	}

	void WindowMaximizedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowMaximized();
	}
}
