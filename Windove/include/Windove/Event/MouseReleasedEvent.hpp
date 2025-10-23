#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class MouseReleasedEvent : public Event
	{
	private:
		MouseEvent m_mouseEvent;

	public:
		WINDOVE_API MouseReleasedEvent(const MouseEvent& mouseEvent);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}