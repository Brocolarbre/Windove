#pragma once

#include "Event.hpp"

namespace dove
{
	class WindowContentScaledEvent : public Event
	{
	private:
		float m_x;
		float m_y;

	public:
		WINDOVE_API WindowContentScaledEvent(float x, float y);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}