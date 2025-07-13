#include "Surface.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

Surface::Surface()
	: m_instance(VK_NULL_HANDLE)
	, m_surface(VK_NULL_HANDLE)
	, m_window(nullptr)
{
	
}

Surface::~Surface()
{
}

void Surface::Initialize(VkInstance instance, Window& window)
{
	m_window = &window;
	m_instance = instance;
	if (glfwCreateWindowSurface(instance, m_window->GetGLFWwindow(), nullptr, &m_surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

void Surface::Cleanup()
{
	vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
}
