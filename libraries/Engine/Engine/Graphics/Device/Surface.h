#pragma once
#include <vulkan/vulkan.h>
#include <Engine/Graphics/Interfaces/IWindow.h>
#include <memory>

class Surface
{
public:
	Surface(VkInstance instance, IWindow& window);
	~Surface();

	void Cleanup();

	inline VkSurfaceKHR GetHandle() const { return m_surfaceHandle; }
	inline const IWindow& GetWindow() const { return m_window; }

private:
	IWindow& m_window;
	VkInstance m_instance;
	VkSurfaceKHR m_surfaceHandle;
};