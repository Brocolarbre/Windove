#include "Windove/Event/TextEnteredEvent.hpp"

namespace dove
{
	TextEnteredEvent::TextEnteredEvent(unsigned int keyCode) :
		m_keyCode(keyCode)
	{

	}

	void TextEnteredEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onTextEntered(m_keyCode);
	}
}
