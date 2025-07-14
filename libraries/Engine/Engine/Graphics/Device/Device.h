#pragma once
#include "Surface.h"
#include <optional>
#include <vector>
#include <vulkan/vulkan.h>


class Device {

public:
	Device(Surface& surface);
	~Device();

	void Initialize(VkInstance instance);
	void Cleanup();

private:
	void PickPhysicalDevice(VkInstance& instance);
	bool IsDeviceSuitable(VkPhysicalDevice device);
	int RateDeviceSuitability(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);

	void CreateLogicalDevice();

	const VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) const;
	const VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes) const;
	const VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities) const;
	void CreateSwapChain();
	void CreateImageViews();

private:
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		inline bool isComplete() const {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device) const;


	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

private:
	VkInstance m_instanceHandle;
	Surface& m_surface;
	VkPhysicalDevice m_physicalDeviceHandle;
	VkDevice m_deviceHandle;
	VkQueue m_graphicsQueueHandle;
	VkQueue m_presentQueueHandle;

	VkSwapchainKHR m_swapChainHandle;
	std::vector<VkImage> m_swapChainImages;
	VkExtent2D m_swapChainExtent;
	VkFormat m_swapChainImageFormat;

	std::vector<VkImageView> swapChainImageViews;
};