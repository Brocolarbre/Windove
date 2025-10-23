#pragma once

#include "Event.hpp"
#include "Windove/Input/Controller.hpp"

namespace dove
{
	class ControllerConnectedEvent : public Event
	{
	private:
		Controller::Id m_controllerId;

	public:
		WINDOVE_API ControllerConnectedEvent(Controller::Id controllerId);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}