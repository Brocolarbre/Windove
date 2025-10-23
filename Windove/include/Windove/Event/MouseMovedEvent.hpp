#pragma once

#include "Event.hpp"

namespace dove
{
	class MouseMovedEvent : public Event
	{
	private:
		unsigned int m_x;
		unsigned int m_y;

	public:
		WINDOVE_API MouseMovedEvent(unsigned int x, unsigned int y);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}