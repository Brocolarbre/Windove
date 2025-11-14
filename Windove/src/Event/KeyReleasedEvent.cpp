#include "Windove/Event/KeyReleasedEvent.hpp"

namespace dove
{
	KeyReleasedEvent::KeyReleasedEvent(const KeyEvent& keyEvent) :
		m_keyEvent(keyEvent)
	{

	}

	void KeyReleasedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onKeyReleased(m_keyEvent);
	}
}