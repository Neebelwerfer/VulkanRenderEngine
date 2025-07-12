#pragma once
#include <vulkan/vulkan.h>
#include "Device/Device.h"
#include <vector>

class GraphicsInterface
{
public:
	GraphicsInterface();
	~GraphicsInterface();

	virtual void Initialize();
	virtual void Cleanup();

	const Device* GetDevice() const;

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
	VkInstance m_instance;
	Device* m_device;
	VkDebugUtilsMessengerEXT m_debugMessenger;
};