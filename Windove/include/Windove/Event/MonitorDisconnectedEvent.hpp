#pragma once

#include "Event.hpp"
#include "Windove/Input/Monitor.hpp"

namespace dove
{
	class WINDOVE_API MonitorDisconnectedEvent : public Event
	{
	private:
		Monitor m_monitor;

	public:
		MonitorDisconnectedEvent(const Monitor& monitor);

		void process(EventHandler& eventHandler) const override;
	};
}