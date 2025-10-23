#pragma once

#include "EventDispatcher.hpp"

namespace dove
{
	class ControllerManager
	{
	private:
		static EventDispatcher m_eventDispatcher;

	public:
		WINDOVE_API static void enableEventDispatcher();
		WINDOVE_API static EventDispatcher& getEventDispatcher();
	};
}