#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowRestoredEvent : public Event
	{
	public:
		WINDOVE_API WindowRestoredEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}