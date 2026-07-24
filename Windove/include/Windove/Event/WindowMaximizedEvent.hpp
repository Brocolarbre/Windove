#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowMaximizedEvent : public Event
	{
	public:
		WindowMaximizedEvent();

		void process(EventHandler& eventHandler) const override;
	};
}