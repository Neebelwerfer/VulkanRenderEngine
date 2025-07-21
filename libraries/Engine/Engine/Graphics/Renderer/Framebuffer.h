#pragma once
#include <vulkan/vulkan.h>

class Framebuffer
{
public:
	Framebuffer(VkRenderPass renderPassHandle);
	~Framebuffer();

public:
	struct Attachment
	{

	};

private:
	VkFramebuffer m_handle;
};