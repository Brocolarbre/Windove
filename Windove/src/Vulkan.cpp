#include "Windove/Vulkan.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace dove
{
	bool Vulkan::isSupported()
	{
		return glfwVulkanSupported();
	}

	std::vector<const char*> Vulkan::getRequiredInstanceExtensions()
	{
		unsigned int extensionCount{};
		const char** extensions = glfwGetRequiredInstanceExtensions(&extensionCount);

		std::vector<const char*> requiredInstanceExtensions;
		for (unsigned int i = 0; i < extensionCount; ++i)
			requiredInstanceExtensions.push_back(extensions[i]);

		return requiredInstanceExtensions;
	}

	VkResult Vulkan::createWindowSurface(VkInstance instance, const Window& window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface)
	{
		return glfwCreateWindowSurface(instance, static_cast<GLFWwindow*>(window.getPlatformWindow()), allocator, surface);
	}
}
