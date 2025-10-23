#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowResizedEvent : public Event
	{
	private:
		unsigned int m_width;
		unsigned int m_height;

	public:
		WINDOVE_API WindowResizedEvent(unsigned int width, unsigned int height);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}