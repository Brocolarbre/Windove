#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowRefreshedEvent : public Event
	{
	public:
		WindowRefreshedEvent();

		void process(EventHandler& eventHandler) const override;
	};
}