#include "Windove/Event/MonitorDisconnectedEvent.hpp"

namespace dove
{
	MonitorDisconnectedEvent::MonitorDisconnectedEvent(const Monitor& monitor) :
		m_monitor(monitor)
	{

	}

	void MonitorDisconnectedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMonitorDisconnected(m_monitor);
	}
}
