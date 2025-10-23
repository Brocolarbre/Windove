#pragma once

#include "Windove/EventHandler.hpp"

namespace dove
{
	class Event
	{
	public:
		WINDOVE_API virtual ~Event() = default;

		virtual void process(EventHandler& eventHandler) const = 0;
	};
}