#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowFocusGainedEvent : public Event
	{
	public:
		WINDOVE_API WindowFocusGainedEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}