#include "Windove/Event/WindowContentScaledEvent.hpp"

namespace dove
{
	WindowContentScaledEvent::WindowContentScaledEvent(float x, float y) :
		m_x(x),
		m_y(y)
	{

	}

	void WindowContentScaledEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowContentScaled(m_x, m_y);
	}
}