#pragma once

#include "Event.hpp"

namespace dove
{
	class CursorLeftEvent : public Event
	{
	public:
		WINDOVE_API CursorLeftEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}