#include "Windove/Event/CursorEnteredEvent.hpp"

namespace dove
{
	CursorEnteredEvent::CursorEnteredEvent()
	{

	}

	void CursorEnteredEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onCursorEntered();
	}
}