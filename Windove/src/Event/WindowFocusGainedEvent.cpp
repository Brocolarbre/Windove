#include "Windove/Event/WindowFocusGainedEvent.hpp"

namespace dove
{
	WindowFocusGainedEvent::WindowFocusGainedEvent()
	{

	}

	void WindowFocusGainedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowFocusGained();
	}
}
