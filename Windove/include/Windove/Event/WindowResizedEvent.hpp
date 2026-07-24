#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowResizedEvent : public Event
	{
	private:
		unsigned int m_width;
		unsigned int m_height;

	public:
		WindowResizedEvent(unsigned int width, unsigned int height);

		void process(EventHandler& eventHandler) const override;
	};
}