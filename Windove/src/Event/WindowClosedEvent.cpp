#include "Windove/Event/WindowClosedEvent.hpp"

namespace dove
{
	WindowClosedEvent::WindowClosedEvent()
	{

	}

	void WindowClosedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowClosed();
	}
}
