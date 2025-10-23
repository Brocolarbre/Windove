#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowClosedEvent : public Event
	{
	public:
		WINDOVE_API WindowClosedEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}