#pragma once

#include "Event.hpp"

namespace dove
{
	class CursorEnteredEvent : public Event
	{
	public:
		WINDOVE_API CursorEnteredEvent();

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}