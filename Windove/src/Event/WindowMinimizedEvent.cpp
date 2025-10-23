#include "Windove/Event/WindowMinimizedEvent.hpp"

namespace dove
{
	WindowMinimizedEvent::WindowMinimizedEvent()
	{

	}

	void WindowMinimizedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowMinimized();
	}
}
