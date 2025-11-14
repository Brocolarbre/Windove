#include "Windove/Event/MonitorConnectedEvent.hpp"

namespace dove
{
	MonitorConnectedEvent::MonitorConnectedEvent(const Monitor& monitor) :
		m_monitor(monitor)
	{

	}

	void MonitorConnectedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onMonitorConnected(m_monitor);
	}
}