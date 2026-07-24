#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class WINDOVE_API MousePressedEvent : public Event
	{
	private:
		MouseEvent m_mouseEvent;

	public:
		MousePressedEvent(const MouseEvent& mouseEvent);

		void process(EventHandler& eventHandler) const override;
	};
}