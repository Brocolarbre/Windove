#include "Windove/Event/WindowFocusLostEvent.hpp"

namespace dove
{
	WindowFocusLostEvent::WindowFocusLostEvent()
	{

	}

	void WindowFocusLostEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowFocusLost();
	}
}
