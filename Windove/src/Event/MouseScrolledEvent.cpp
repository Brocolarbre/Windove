#include "Windove/Event/MouseScrolledEvent.hpp"

namespace dove
{
	MouseScrolledEvent::MouseScrolledEvent(int horizontalScroll, int verticalScroll) :
		m_horizontalScroll(horizontalScroll),
		m_verticalScroll(verticalScroll)
	{

	}

	void MouseScrolledEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMouseScrolled(m_horizontalScroll, m_verticalScroll);
	}
}
