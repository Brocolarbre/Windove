#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowMinimizedEvent : public Event
	{
	public:
		WindowMinimizedEvent();

		void process(EventHandler& eventHandler) const override;
	};
}