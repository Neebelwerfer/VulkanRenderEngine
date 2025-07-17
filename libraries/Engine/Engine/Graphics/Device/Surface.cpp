#include "Surface.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

Surface::Surface(VkInstance instance, Window& window)
	: m_instance(instance)
	, m_surfaceHandle(VK_NULL_HANDLE)
	, m_window(window)
{
	if (glfwCreateWindowSurface(instance, m_window.GetGLFWwindow(), nullptr, &m_surfaceHandle) != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

Surface::~Surface()
{
}

void Surface::Cleanup()
{
	vkDestroySurfaceKHR(m_instance, m_surfaceHandle, nullptr);
}

void Surface::GetFramebufferSize(int& width, int& height) const
{
	m_window.GetFramebufferSize(width, height);
}
