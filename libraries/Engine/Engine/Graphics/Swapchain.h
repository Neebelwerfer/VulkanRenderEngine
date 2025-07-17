#include <vulkan/vulkan.h>
#include "Device/Device.h"
#include <memory>
#include <vector>


class Swapchain
{
public:
	Swapchain(std::shared_ptr<Device> Device, std::shared_ptr<Surface> surface);
	~Swapchain();

	void Cleanup();

	inline const VkSwapchainKHR GetHandle() const { return m_swapChainHandle; }
	inline const VkExtent2D GetExtent() const { return m_swapChainExtent; }
	inline const VkFormat& GetImageFormat() const { return m_swapChainImageFormat; }
	inline const std::vector<VkImageView>& GetImageViews() const { return m_swapChainImageViews; }

private:
	const VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) const;
	const VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes) const;
	const VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities) const;
	void CreateSwapChain();
	void CreateImageViews();

private:

	std::shared_ptr<Device> m_device;
	std::shared_ptr<Surface> m_surface;

	VkSwapchainKHR m_swapChainHandle;
	VkExtent2D m_swapChainExtent;
	VkFormat m_swapChainImageFormat;
	std::vector<VkImage> m_swapChainImages;
	std::vector<VkImageView> m_swapChainImageViews;
};