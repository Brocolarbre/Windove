#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API TextEnteredEvent : public Event
	{
	private:
		unsigned int m_keyCode;

	public:
		TextEnteredEvent(unsigned int keyCode);

		void process(EventHandler& eventHandler) const override;
	};
}