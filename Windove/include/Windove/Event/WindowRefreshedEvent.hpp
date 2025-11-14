#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowRefreshedEvent : public Event
	{
	public:
		WINDOVE_API WindowRefreshedEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}