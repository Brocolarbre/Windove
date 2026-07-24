#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowRestoredEvent : public Event
	{
	public:
		WindowRestoredEvent();

		void process(EventHandler& eventHandler) const override;
	};
}