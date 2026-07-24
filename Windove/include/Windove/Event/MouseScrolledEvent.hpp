#pragma once

#include "Event.hpp"
#include "Windove/Input/Mouse.hpp"

namespace dove
{
	class WINDOVE_API MouseScrolledEvent : public Event
	{
	private:
		int m_horizontalScroll;
		int m_verticalScroll;

	public:
		MouseScrolledEvent(int horizontalScroll, int verticalScroll);

		void process(EventHandler& eventHandler) const override;
	};
}