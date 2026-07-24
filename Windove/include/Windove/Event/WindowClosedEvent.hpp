#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent();

		void process(EventHandler& eventHandler) const override;
	};
}