#pragma once

#include "Event.hpp"

namespace dove
{
	class TextEnteredEvent : public Event
	{
	private:
		unsigned int m_keyCode;

	public:
		WINDOVE_API TextEnteredEvent(unsigned int keyCode);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}