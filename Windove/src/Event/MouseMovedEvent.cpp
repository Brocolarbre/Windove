#include "Windove/Event/MouseMovedEvent.hpp"

namespace dove
{
	MouseMovedEvent::MouseMovedEvent(unsigned int x, unsigned int y) :
		m_x(x),
		m_y(y)
	{

	}

	void MouseMovedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMouseMoved(m_x, m_y);
	}
}
