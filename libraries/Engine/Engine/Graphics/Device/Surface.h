#pragma once
#include <vulkan/vulkan.h>
#include <Engine/Application/Window.h>

class Surface
{
public:
	Surface();
	~Surface();

	void Initialize(VkInstance instance, Window& window);
	void Cleanup();

	inline VkSurfaceKHR GetInternalSurface() const { return m_surface; }

private:
	Window* m_window;
	VkInstance m_instance;
	VkSurfaceKHR m_surface;
};