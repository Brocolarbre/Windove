#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowFocusGainedEvent : public Event
	{
	public:
		WindowFocusGainedEvent();

		void process(EventHandler& eventHandler) const override;
	};
}