#include "GraphicsManager.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Shaders/Shader.h"
#include "Utility/VulkanImGuiContext.h"


GraphicsManager::GraphicsManager(IWindow& window)
	: m_instanceHandle(nullptr)
	, m_debugMessenger(nullptr)
	, m_surface(nullptr)
	, m_device(nullptr)
	, m_swapchain(nullptr)
	, m_renderer(nullptr)
	, m_window(window)
{
}

GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Cleanup() 
{
	vkDeviceWaitIdle(m_device->GetHandle());

	if (enableValidationLayers) {
		DestroyDebugUtilsMessengerEXT(m_instanceHandle, m_debugMessenger, nullptr);
	}

	
	m_renderer->Cleanup();
	m_swapchain->Cleanup();
	m_device->Cleanup();
	m_surface->Cleanup();

	vkDestroyInstance(m_instanceHandle, nullptr);
}

Device& GraphicsManager::GetDevice()
{
	return *m_device;
}

const Device& GraphicsManager::GetDevice() const
{
	return *m_device;
}


Renderer& GraphicsManager::GetRenderer()
{
	return *m_renderer;
}

const Renderer& GraphicsManager::GetRenderer() const
{
	return *m_renderer;
}

void GraphicsManager::Render() 
{
	m_renderer->Render();
}

std::unique_ptr<ImGuiBase> GraphicsManager::CreateImGuiContext() const
{
	VulkanImGuiContext context(m_window);
	return std::unique_ptr<ImGuiBase>(&context);
}

void GraphicsManager::Initialize()
{
	InitVulkan();
	SetupDebugMessenger();

	m_surface = std::make_unique<Surface>(m_instanceHandle, m_window);
	m_device = std::make_unique<Device>(m_instanceHandle, *m_surface);
	m_swapchain = std::make_unique<Swapchain>(*m_device, *m_surface);
	m_renderer = std::make_unique<Renderer>(m_window, *m_device, *m_swapchain);
}

std::vector<const char*> GraphicsManager::GetRequiredExtensions() {
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (enableValidationLayers) {
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	return extensions;
}

bool GraphicsManager::CheckValidationLayerSupport() {
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}

void GraphicsManager::InitVulkan()
{
	if (enableValidationLayers && !CheckValidationLayerSupport()) {
		throw std::runtime_error("validation layers requested, but not available!");
	}

	//TODO: get application name from the application
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Render Engine";
	appInfo.applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
	appInfo.pEngineName = "Vulkan Render Engine";
	appInfo.engineVersion = VK_MAKE_API_VERSION(0, 0, 1, 0);
	appInfo.apiVersion = VK_API_VERSION_1_3;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	//TODO: Move this?
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	auto extensions = GetRequiredExtensions();
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();

	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();

		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
		populateDebugMessengerCreateInfo(debugCreateInfo);
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instanceHandle);

	if (vkCreateInstance(&createInfo, nullptr, &m_instanceHandle) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}
}

void GraphicsManager::SetupDebugMessenger() {
	if (!enableValidationLayers) return;

	VkDebugUtilsMessengerCreateInfoEXT createInfo;
	populateDebugMessengerCreateInfo(createInfo);

	if (CreateDebugUtilsMessengerEXT(m_instanceHandle, &createInfo, nullptr, &m_debugMessenger) != VK_SUCCESS) {
		throw std::runtime_error("failed to set up debug messenger!");
	}
}

void GraphicsManager::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
	createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	createInfo.pfnUserCallback = debugCallback;
}

//TODO: Maybe look at severity here.
VKAPI_ATTR VkBool32 VKAPI_CALL GraphicsManager::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
{
	std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

	return VK_FALSE;
}

VkResult GraphicsManager::CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	}
	else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void GraphicsManager::DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
	auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
	if (func != nullptr) {
		func(instance, debugMessenger, pAllocator);
	}
}