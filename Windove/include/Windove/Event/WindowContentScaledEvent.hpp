#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API WindowContentScaledEvent : public Event
	{
	private:
		float m_x;
		float m_y;

	public:
		WindowContentScaledEvent(float x, float y);

		void process(EventHandler& eventHandler) const override;
	};
}