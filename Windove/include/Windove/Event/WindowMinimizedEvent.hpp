#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowMinimizedEvent : public Event
	{
	public:
		WINDOVE_API WindowMinimizedEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}