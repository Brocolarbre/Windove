#include "Windove/Event/KeyRepeatedEvent.hpp"

namespace dove
{
	KeyRepeatedEvent::KeyRepeatedEvent(const KeyEvent& keyEvent) :
		m_keyEvent(keyEvent)
	{

	}

	void KeyRepeatedEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onKeyRepeated(m_keyEvent);
	}
}
