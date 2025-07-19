#include "Surface.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

Surface::Surface(VkInstance instance, IWindow& window)
	: m_instance(instance)
	, m_surfaceHandle(VK_NULL_HANDLE)
	, m_window(window)
{
	auto nativeWindowHandle = window.GetNativeWindow();

	if (nativeWindowHandle.type == NativeWindowHandleType::GLFW)
	{
		auto glfwWindow = static_cast<GLFWwindow*>(nativeWindowHandle.glfw.ptr);

		if (glfwVulkanSupported() == GLFW_FALSE)
		{
			throw std::runtime_error("Vulkan not supported on this machine");
		}

		if (glfwCreateWindowSurface(instance, glfwWindow, nullptr, &m_surfaceHandle) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface!");
		}
	}
	else {
		throw std::runtime_error("Unsupported window type given");
	}

}

Surface::~Surface()
{
}

void Surface::Cleanup()
{
	vkDestroySurfaceKHR(m_instance, m_surfaceHandle, nullptr);
}
