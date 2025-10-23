#include "Windove/Event/CursorLeftEvent.hpp"

namespace dove
{
	CursorLeftEvent::CursorLeftEvent()
	{

	}

	void CursorLeftEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onCursorLeft();
	}
}
