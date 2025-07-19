#include "VulkanImGuiContext.h"
#include <vulkan/vulkan.h>
#include <imgui_impl_vulkan.h>
#include <imgui_impl_glfw.h>
#include <stdexcept>

VulkanImGuiContext::VulkanImGuiContext(IWindow& window): ImGuiBase(window)
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	auto windowHandle = window.GetNativeWindow();
	if (windowHandle.type == IWindow::NativeHandleType::GLFW)
	{
		ImGui_ImplGlfw_InitForVulkan(static_cast<GLFWwindow*>(windowHandle.glfw.ptr), true);
	}
	else
	{
		std::runtime_error("Unsupported window given");
	}
}

VulkanImGuiContext::~VulkanImGuiContext()
{
}

void VulkanImGuiContext::Initialize()
{
	ImGui_ImplVulkan_InitInfo initInfo{};
	ImGui_ImplVulkan_Init(&initInfo);
}

void VulkanImGuiContext::Cleanup()
{

}

void VulkanImGuiContext::BeginFrame()
{

}

void VulkanImGuiContext::EndFrame()
{

}

void VulkanImGuiContext::Render()
{
	//VkClearValue clearValue;
	//clearValue.color = VkClearColorValue(std::array<float, 4>({ 0.0f, 0.0f, 0.0f, 1.0f }));
	//cb.begin({ vk::CommandBufferUsageFlags() });
	//cb.beginRenderPass({
	//	imguiRenderPass,
	//	imguiFramebuffers[swapchainCurrentImage],
	//	{{0,0}, swapchainExtent},
	//	1, &clearValue
	//	}, VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);
	//ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), cb);
	//cb.endRenderPass();
	//cb.end();

	//VkSubmitInfo si;
	//si.commandBufferCount = 1;
	//si.pCommandBuffers = &cb;
	//graphicsQueue->submit(si);
}