#pragma once

#include "Event.hpp"

namespace dove
{
	class DragAndDropEvent : public Event
	{
	private:
		std::vector<std::string> m_paths;

	public:
		WINDOVE_API DragAndDropEvent(const std::vector<std::string>& paths);

		WINDOVE_API void process(EventHandler& eventHandler) const override;
	};
}