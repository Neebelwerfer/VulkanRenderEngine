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
	void Recreate();

	inline const VkSwapchainKHR GetHandle() const { return m_handle; }
	inline const VkExtent2D GetExtent() const { return m_extent; }
	inline const VkFormat GetImageFormat() const { return m_imageFormat; }
	inline const std::vector<VkImageView>& GetImageViews() const { return m_imageViews; }
	inline const VkRenderPass GetRenderPassHandle() const { return m_renderPassHandle; }
	inline const std::vector<VkFramebuffer>& GetFramebuffers() const { return m_framebuffers; }

private:
	const VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) const;
	const VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes) const;
	const VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities) const;
	void CreateSwapChain();
	void CreateImageViews();
	void CreateRenderPass();
	void CreateFramebuffers();

private:

	std::shared_ptr<Device> m_device;
	std::shared_ptr<Surface> m_surface;

	VkSwapchainKHR m_handle;
	VkExtent2D m_extent;
	VkFormat m_imageFormat;
	VkRenderPass m_renderPassHandle;

	std::vector<VkImage> m_images;
	std::vector<VkImageView> m_imageViews;
	std::vector<VkFramebuffer> m_framebuffers;
};