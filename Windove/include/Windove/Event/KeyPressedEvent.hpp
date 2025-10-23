#pragma once

#include "Event.hpp"
#include "Windove/Input/Keyboard.hpp"

namespace dove
{
	class KeyPressedEvent : public Event
	{
	private:
		KeyEvent m_keyEvent;

	public:
		WINDOVE_API KeyPressedEvent(const KeyEvent& keyEvent);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}