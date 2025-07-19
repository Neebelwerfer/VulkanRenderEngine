#pragma once 

#include <vulkan/vulkan.h>
#include <Engine/Graphics/Swapchain.h>
#include <Engine/Graphics/Device/Device.h>

class Renderer 
{
public:
	Renderer(IWindow& window, const Device& device, Swapchain& swapchain);
	~Renderer();

	void Cleanup();
	void Render();

private:
	void SetupGraphicsPipeline();
	void CreateCommandPool();
	void CreateCommandBuffer();
	void CreateSyncObjects();

	void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

private:
	IWindow& m_window;
	const Device& m_device;
	Swapchain& m_swapchain;

	VkPipeline m_graphicsPipelineHandle;
	VkPipelineLayout m_pipelineLayoutHandle;

	VkCommandPool m_commandPoolHandle;
	std::vector<VkCommandBuffer> m_commandBufferHandles;

	std::vector<VkSemaphore> m_imageAvailableSemaphoreHandles;
	std::vector<VkSemaphore> m_renderFinishedSemaphoreHandles;
	std::vector<VkFence> m_inFlightFenceHandles;

	uint32_t m_currentFrame = 0;
};