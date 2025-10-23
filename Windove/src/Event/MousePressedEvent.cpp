#include "Windove/Event/MousePressedEvent.hpp"

namespace dove
{
	MousePressedEvent::MousePressedEvent(const MouseEvent& mouseEvent) :
		m_mouseEvent(mouseEvent)
	{

	}

	void MousePressedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMousePressed(m_mouseEvent);
	}
}
