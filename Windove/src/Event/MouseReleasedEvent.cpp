#include "Windove/Event/MouseReleasedEvent.hpp"

namespace dove
{
	MouseReleasedEvent::MouseReleasedEvent(const MouseEvent& mouseEvent) :
		m_mouseEvent(mouseEvent)
	{

	}

	void MouseReleasedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMouseReleased(m_mouseEvent);
	}
}
