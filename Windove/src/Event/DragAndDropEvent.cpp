#include "Windove/Event/DragAndDropEvent.hpp"

namespace dove
{
	DragAndDropEvent::DragAndDropEvent(const std::vector<std::string>& paths) :
		m_paths(paths)
	{

	}

	void DragAndDropEvent::process(EventHandler& eventHandler) const
	{
		eventHandler.onDragAndDrop(m_paths);
	}
}