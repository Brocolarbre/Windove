#pragma once

#include "Event.hpp"
#include "Windove/Input/Controller.hpp"

namespace dove
{
	class ControllerDisconnectedEvent : public Event
	{
	private:
		Controller::Id m_controllerId;

	public:
		WINDOVE_API ControllerDisconnectedEvent(Controller::Id controllerId);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}