#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowMovedEvent : public Event
	{
	private:
		unsigned int m_x;
		unsigned int m_y;

	public:
		WindowMovedEvent(unsigned int x, unsigned int y);

		void process(EventHandler& eventHandler) const override;
	};
}