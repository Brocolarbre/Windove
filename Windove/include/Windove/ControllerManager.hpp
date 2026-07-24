#pragma once

#include "EventDispatcher.hpp"

namespace dove
{
	class WINDOVE_API ControllerManager
	{
	private:
		static EventDispatcher m_eventDispatcher;

	public:
		static void enableEventDispatcher();
		static EventDispatcher& getEventDispatcher();
	};
}