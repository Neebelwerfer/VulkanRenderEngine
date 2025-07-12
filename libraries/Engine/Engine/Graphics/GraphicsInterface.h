#pragma once
#include <vulkan/vulkan.h>
#include <Engine/Application/Window.h>
#include "Device/Device.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

class GraphicsInterface
{
public:
	GraphicsInterface();
	~GraphicsInterface();

	virtual void Initialize(Window& window);
	virtual void Cleanup();

	const std::shared_ptr<Device> GetDevice() const;

private:
	void InitVulkan();
	void SetupDebugMessenger();
	void CreateSurface(GLFWwindow* window);

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
	VkInstance m_instance;
	VkSurfaceKHR m_surface;
	std::shared_ptr<Device> m_device;
	VkDebugUtilsMessengerEXT m_debugMessenger;
};