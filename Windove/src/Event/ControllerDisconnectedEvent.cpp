#include "Windove/Event/ControllerDisconnectedEvent.hpp"

namespace dove
{
	ControllerDisconnectedEvent::ControllerDisconnectedEvent(Controller::Id controllerId) :
		m_controllerId(controllerId)
	{

	}

	void ControllerDisconnectedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onControllerDisconnected(m_controllerId);
	}
}