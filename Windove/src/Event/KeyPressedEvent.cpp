#include "Windove/Event/KeyPressedEvent.hpp"

namespace dove
{
	KeyPressedEvent::KeyPressedEvent(const KeyEvent& keyEvent) :
		m_keyEvent(keyEvent)
	{

	}

	void KeyPressedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onKeyPressed(m_keyEvent);
	}
}