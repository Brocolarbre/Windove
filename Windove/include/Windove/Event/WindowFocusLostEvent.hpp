#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowFocusLostEvent : public Event
	{
	public:
		WINDOVE_API WindowFocusLostEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}