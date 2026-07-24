#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API CursorLeftEvent : public Event
	{
	public:
		CursorLeftEvent();

		void process(EventHandler& eventHandler) const override;
	};
}