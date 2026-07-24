#pragma once

#include "Window.hpp"

typedef struct VkInstance_T* VkInstance;
typedef struct VkSurfaceKHR_T* VkSurfaceKHR;

typedef enum VkResult VkResult;
struct VkAllocationCallbacks;

namespace dove
{
	class WINDOVE_API Vulkan
	{
	public:
		static bool isSupported();
		static std::vector<const char*> getRequiredInstanceExtensions();
		static VkResult createWindowSurface(VkInstance instance, const Window& window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
	};
}