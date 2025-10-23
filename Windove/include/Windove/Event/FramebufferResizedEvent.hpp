#pragma once

#include "Event.hpp"

namespace dove
{
	class FramebufferResizedEvent : public Event
	{
	private:
		unsigned int m_width;
		unsigned int m_height;

	public:
		WINDOVE_API FramebufferResizedEvent(unsigned int width, unsigned int height);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}