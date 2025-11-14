#include "Windove/Event/WindowRefreshedEvent.hpp"

namespace dove
{
	WindowRefreshedEvent::WindowRefreshedEvent()
	{

	}

	void WindowRefreshedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowRefreshed();
	}
}