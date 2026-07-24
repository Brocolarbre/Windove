#pragma once

#include "Event.hpp"
#include "Windove/Input/Keyboard.hpp"

namespace dove
{
	class WINDOVE_API KeyPressedEvent : public Event
	{
	private:
		KeyEvent m_keyEvent;

	public:
		KeyPressedEvent(const KeyEvent& keyEvent);

		void process(EventHandler& eventHandler) const override;
	};
}