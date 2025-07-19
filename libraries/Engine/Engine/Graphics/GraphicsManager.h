#pragma once
#include "Device/Device.h"
#include "Device/Surface.h"
#include "Base/ImGuiBase.h"
#include "Swapchain.h"
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <vulkan/vulkan.h>
#include "Renderer/Renderer.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

class GraphicsManager
{
public:
	GraphicsManager(IWindow& window);
	~GraphicsManager();

	virtual void Initialize();
	virtual void Cleanup();

	Device& GetDevice();
	const Device& GetDevice() const;

	Renderer& GetRenderer();
	const Renderer& GetRenderer() const;

	void Render();

	std::unique_ptr<ImGuiBase> CreateImGuiContext() const;

private:
	void InitVulkan();
	void SetupDebugMessenger();

	std::vector<const char*> GetRequiredExtensions();
	bool CheckValidationLayerSupport();

private:
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

private:
	VkInstance m_instanceHandle;
	IWindow& m_window;
	VkDebugUtilsMessengerEXT m_debugMessenger;

	std::unique_ptr<Surface> m_surface;
	
	// Subsystems
	std::unique_ptr<Device> m_device;
	std::unique_ptr<Swapchain> m_swapchain;
	std::unique_ptr<Renderer> m_renderer;

};