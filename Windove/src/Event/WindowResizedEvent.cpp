#include "Windove/Event/WindowResizedEvent.hpp"

namespace dove
{
	WindowResizedEvent::WindowResizedEvent(unsigned int width, unsigned int height) :
		m_width(width),
		m_height(height)
	{

	}

	void WindowResizedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onWindowResized(m_width, m_height);
	}
}
