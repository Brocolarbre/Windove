#pragma once

#include "Windove/Export.hpp"
#include "Event/Event.hpp"

#include <list>
#include <memory>
#include <queue>

namespace dove
{
	class WINDOVE_API EventDispatcher
	{
	private:
		std::queue<std::shared_ptr<Event>> m_events;
		std::list<EventHandler*> m_eventHandlers;

		void processEvent(const Event& event) const;

	public:
		EventDispatcher();

		const std::list<EventHandler*>& getEventHandlers() const;
		void clearEventHandlers();
		void addEventHandler(EventHandler& eventHandler);
		void removeEventHandler(EventHandler& eventHandler);

		template<typename T, typename ...Args>
		void receiveEvent(Args&&... args);
		void processEvents();
	};

	template<typename T, typename ...Args>
	void EventDispatcher::receiveEvent(Args&&... args)
	{
		m_events.push(std::make_shared<T>(std::forward<Args>(args)...));
	}
}