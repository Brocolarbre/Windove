#pragma once

#include "Event.hpp"
#include "Windove/Input/Monitor.hpp"

namespace dove
{
	class MonitorConnectedEvent : public Event
	{
	private:
		Monitor m_monitor;

	public:
		WINDOVE_API MonitorConnectedEvent(const Monitor& monitor);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}