#pragma once
#include "Device/Device.h"
#include "Device/Surface.h"
#include <Engine/Application/Window.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <vulkan/vulkan.h>

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

	const Device GetDevice() const;

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
	Surface m_surface;
	Device m_device;
	VkDebugUtilsMessengerEXT m_debugMessenger;
};