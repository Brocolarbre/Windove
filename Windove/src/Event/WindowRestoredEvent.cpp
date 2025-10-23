#include "Windove/Event/WindowRestoredEvent.hpp"

namespace dove
{
	WindowRestoredEvent::WindowRestoredEvent()
	{

	}

	void WindowRestoredEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowRestored();
	}
}
