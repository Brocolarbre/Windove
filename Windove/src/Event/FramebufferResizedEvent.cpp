#include "Windove/Event/FramebufferResizedEvent.hpp"

namespace dove
{
	FramebufferResizedEvent::FramebufferResizedEvent(unsigned int width, unsigned int height) :
		m_width(width),
		m_height(height)
	{

	}

	void FramebufferResizedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onFramebufferResized(m_width, m_height);
	}
}
