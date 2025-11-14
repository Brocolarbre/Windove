#include "Windove/Event/WindowMovedEvent.hpp"

namespace dove
{
	WindowMovedEvent::WindowMovedEvent(unsigned int x, unsigned int y) :
		m_x(x),
		m_y(y)
	{

	}

	void WindowMovedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowMoved(m_x, m_y);
	}
}