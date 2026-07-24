#pragma once

#include "Event.hpp"
#include "Windove/Input/Controller.hpp"

namespace dove
{
	class WINDOVE_API ControllerDisconnectedEvent : public Event
	{
	private:
		Controller::Id m_controllerId;

	public:
		ControllerDisconnectedEvent(Controller::Id controllerId);

		void process(EventHandler& eventHandler) const override;
	};
}