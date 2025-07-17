#pragma once
#include <vulkan/vulkan.h>
#include <Engine/Application/Window.h>

class Surface
{
public:
	Surface(VkInstance instance, Window& window);
	~Surface();

	void Cleanup();

	inline VkSurfaceKHR GetHandle() const { return m_surfaceHandle; }
	inline const Window& GetWindow() const { return m_window; }

	void GetFramebufferSize(int& width, int& height) const;

private:
	Window& m_window;
	VkInstance m_instance;
	VkSurfaceKHR m_surfaceHandle;
};