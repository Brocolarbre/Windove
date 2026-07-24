#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class WINDOVE_API MouseReleasedEvent : public Event
	{
	private:
		MouseEvent m_mouseEvent;

	public:
		MouseReleasedEvent(const MouseEvent& mouseEvent);

		void process(EventHandler& eventHandler) const override;
	};
}