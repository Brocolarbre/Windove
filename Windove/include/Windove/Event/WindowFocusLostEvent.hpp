#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowFocusLostEvent : public Event
	{
	public:
		WindowFocusLostEvent();

		void process(EventHandler& eventHandler) const override;
	};
}