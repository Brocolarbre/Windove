#pragma once

#include "Windove/Export.hpp"
#include "Event/Event.hpp"

#include <list>
#include <memory>
#include <queue>

namespace dove
{
	class EventDispatcher
	{
	private:
		std::queue<std::shared_ptr<Event>> m_events;
		std::list<EventHandler*> m_eventHandlers;

		WINDOVE_API void processEvent(const Event& event) const;

	public:
		WINDOVE_API EventDispatcher();

		WINDOVE_API const std::list<EventHandler*>& getEventHandlers() const;
		WINDOVE_API void clearEventHandlers();
		WINDOVE_API void addEventHandler(EventHandler& eventHandler);
		WINDOVE_API void removeEventHandler(EventHandler& eventHandler);

		template<typename T, typename ...Args>
		void receiveEvent(Args&&... args);
		WINDOVE_API void processEvents();
	};

	template<typename T, typename ...Args>
	void EventDispatcher::receiveEvent(Args&&... args)
	{
		m_events.push(std::make_shared<T>(std::forward<Args>(args)...));
	}
}