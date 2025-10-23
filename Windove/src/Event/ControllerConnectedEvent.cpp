#include "Windove/Event/ControllerConnectedEvent.hpp"

namespace dove
{
	ControllerConnectedEvent::ControllerConnectedEvent(Controller::Id controllerId) :
		m_controllerId(controllerId)
	{

	}

	void ControllerConnectedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onControllerConnected(m_controllerId);
	}
}
