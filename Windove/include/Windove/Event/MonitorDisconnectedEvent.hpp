#pragma once

#include "Event.hpp"
#include "Windove/Input/Monitor.hpp"

namespace dove
{
	class MonitorDisconnectedEvent : public Event
	{
	private:
		Monitor m_monitor;

	public:
		WINDOVE_API MonitorDisconnectedEvent(const Monitor& monitor);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}