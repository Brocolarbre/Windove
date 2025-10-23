#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class MouseScrolledEvent : public Event
	{
	private:
		int m_horizontalScroll;
		int m_verticalScroll;

	public:
		WINDOVE_API MouseScrolledEvent(int horizontalScroll, int verticalScroll);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}