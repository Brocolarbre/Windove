#pragma once

#include "Window.hpp"

typedef struct VkInstance_T* VkInstance;
typedef struct VkSurfaceKHR_T* VkSurfaceKHR;

typedef enum VkResult VkResult;
struct VkAllocationCallbacks;

namespace dove
{
	class Vulkan
	{
	public:
		WINDOVE_API static bool isSupported();
		WINDOVE_API static std::vector<const char*> getRequiredInstanceExtensions();
		WINDOVE_API static VkResult createWindowSurface(VkInstance instance, const Window& window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
	};
}