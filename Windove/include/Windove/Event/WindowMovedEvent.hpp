#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowMovedEvent : public Event
	{
	private:
		unsigned int m_x;
		unsigned int m_y;

	public:
		WINDOVE_API WindowMovedEvent(unsigned int x, unsigned int y);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}