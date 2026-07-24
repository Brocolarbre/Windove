#pragma once

#include "Event.hpp"

namespace dove
{
	class WINDOVE_API DragAndDropEvent : public Event
	{
	private:
		std::vector<std::string> m_paths;

	public:
		DragAndDropEvent(const std::vector<std::string>& paths);

		void process(EventHandler& eventHandler) const override;
	};
}