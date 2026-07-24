#pragma once

#include "Windove/EventHandler.hpp"

namespace dove
{
	class WINDOVE_API Event
	{
	public:
		virtual ~Event() = default;

		virtual void process(EventHandler& eventHandler) const = 0;
	};
}