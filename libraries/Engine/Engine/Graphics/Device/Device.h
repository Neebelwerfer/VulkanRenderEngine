#pragma once
#include "Surface.h"
#include <optional>
#include <vector>
#include <memory>
#include <vulkan/vulkan.h>


class Device {

public:
	Device(VkInstance instance, Surface& surface);
	~Device();

	void Cleanup();

	inline const VkDevice GetHandle() const { return m_deviceHandle; }
	inline const VkQueue GetGraphicsQueueHandle() const { return m_graphicsQueueHandle; }
	inline const VkQueue GetPresentQueueHandle() const { return m_presentQueueHandle; }

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		inline bool isComplete() const {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};
	QueueFamilyIndices FindQueueFamilies() const;

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	SwapChainSupportDetails QuerySwapChainSupport() const;

private:
	void PickPhysicalDevice(VkInstance& instance);
	bool IsDeviceSuitable(VkPhysicalDevice device);
	int RateDeviceSuitability(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);

	void CreateLogicalDevice();

private:
	
	
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device) const;


	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device) const;

private:
	VkInstance m_instanceHandle;
	Surface& m_surface;
	VkPhysicalDevice m_physicalDeviceHandle;
	VkDevice m_deviceHandle;
	VkQueue m_graphicsQueueHandle;
	VkQueue m_presentQueueHandle;
};