#pragma once
#include "Renderer.h"
#include "Framebuffer.h"
#include <vulkan/vulkan.h>

class RenderPass 
{
public:
	RenderPass(std::shared_ptr<const Framebuffer> framebuffer);
	~RenderPass();

	const VkRenderPass GetHandle() const;

	void Render();

protected:
	Renderer& GetRenderer();
	const Renderer& GetRenderer() const;



private:
	friend class Renderer;
	void SetRenderer(Renderer* renderer);

private:
	Renderer* m_renderer;
	VkRenderPass m_handle;

	std::shared_ptr<const Framebuffer> m_targetBuffer;
};