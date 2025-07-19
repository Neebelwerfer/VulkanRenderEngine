#pragma once
#include "Device/Device.h"
#include "Device/Surface.h"
#include "Base/ImGuiBase.h"
#include "Swapchain.h"
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

class GraphicsManager
{
public:
	GraphicsManager(IWindow& window);
	~GraphicsManager();

	virtual void Initialize(const char* title);
	virtual void Cleanup();

	void Render();
	
	std::shared_ptr<Device> GetDevice();
	const std::shared_ptr<Device> GetDevice() const;


	std::unique_ptr<ImGuiBase> CreateImGuiContext() const;

private:
	void InitVulkan(const char* title);
	void SetupDebugMessenger();
	void SetupGraphicsPipeline();
	void CreateCommandPool();
	void CreateCommandBuffer();
	void CreateSyncObjects();

	void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

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
	std::shared_ptr<Surface> m_surface;
	std::shared_ptr<Device> m_device;
	std::unique_ptr<Swapchain> m_swapchain;

	VkPipeline m_graphicsPipelineHandle;
	VkPipelineLayout m_pipelineLayoutHandle;
	VkDebugUtilsMessengerEXT m_debugMessenger;

	VkCommandPool m_commandPoolHandle;
	std::vector<VkCommandBuffer> m_commandBufferHandles;

	std::vector<VkSemaphore> m_imageAvailableSemaphoreHandles;
	std::vector<VkSemaphore> m_renderFinishedSemaphoreHandles;
	std::vector<VkFence> m_inFlightFenceHandles;

	uint32_t m_currentFrame = 0;
};