#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class Framebuffer
{
public:
	Framebuffer();
	~Framebuffer();

	enum class AttachmentType
	{
		Color,
		Depth,
		Stencil
	};

	enum class LoadOperation
	{
		DONT_CARE,
		CLEAR,
		NONE,
		LOAD,
	};

	enum class StoreOperation 
	{
		DONT_CARE,
		NONE,
		STORE,
	};

	struct Attachment
	{
		VkImageView texture;
		LoadOperation loadOp;
		StoreOperation storeOp;

	};

	void AttachTexture(VkImageView imageView, AttachmentType type);


private:
	std::vector<Attachment> m_colourAttachments;
	Attachment* m_depthAttachment;
	Attachment* m_stencilAttachment;
};