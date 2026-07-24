#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API CursorEnteredEvent : public Event
	{
	public:
		CursorEnteredEvent();

		void process(EventHandler& eventHandler) const override;
	};
}