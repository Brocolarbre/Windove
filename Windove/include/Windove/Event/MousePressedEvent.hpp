#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class MousePressedEvent : public Event
	{
	private:
		MouseEvent m_mouseEvent;

	public:
		WINDOVE_API MousePressedEvent(const MouseEvent& mouseEvent);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}