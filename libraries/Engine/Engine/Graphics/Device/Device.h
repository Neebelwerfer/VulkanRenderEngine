#pragma once
#include <vulkan/vulkan.h>
#include <optional>
#include <vector>


class Device {

public:
	Device();
	~Device();

	void Initialize(VkInstance& instance, VkSurfaceKHR& surface);
	void Cleanup() const;

private:
	void PickPhysicalDevice(VkInstance& instance, VkSurfaceKHR& surface);
	bool IsDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR& surface);
	int RateDeviceSuitability(VkPhysicalDevice device, VkSurfaceKHR& surface);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);

	void CreateLogicalDevice(VkSurfaceKHR& surface);

private:
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR& surface);

	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR& surface);
private:
	VkPhysicalDevice m_physicalDevice;
	VkDevice m_device;
	VkQueue m_graphicsQueue;
	VkQueue m_presentQueue;
};