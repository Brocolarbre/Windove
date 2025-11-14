#include "Windove/EventDispatcher.hpp"

namespace dove
{
	void EventDispatcher::processEvent(const Event& event) const
	{
		for (EventHandler* eventHandler : m_eventHandlers)
			event.process(*eventHandler);
	}

	EventDispatcher::EventDispatcher() :
		m_events(),
		m_eventHandlers()
	{

	}

	const std::list<EventHandler*>& EventDispatcher::getEventHandlers() const
	{
		return m_eventHandlers;
	}

	void EventDispatcher::clearEventHandlers()
	{
		m_eventHandlers.clear();
	}

	void EventDispatcher::addEventHandler(EventHandler& eventHandler)
	{
		m_eventHandlers.push_back(&eventHandler);
	}

	void EventDispatcher::removeEventHandler(EventHandler& eventHandler)
	{
		m_eventHandlers.remove(&eventHandler);
	}

	void EventDispatcher::processEvents()
	{
		while (!m_events.empty())
		{
			processEvent(*m_events.front());
			m_events.pop();
		}
	}
}