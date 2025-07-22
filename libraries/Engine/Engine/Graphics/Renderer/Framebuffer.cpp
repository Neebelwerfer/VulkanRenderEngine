#include "Framebuffer.h"
#include <cassert>

Framebuffer::Framebuffer()
	: m_colourAttachments(0)
	, m_depthAttachment(nullptr)
	, m_stencilAttachment(nullptr)
{
}

Framebuffer::~Framebuffer()
{
}

void Framebuffer::AttachTexture(VkImageView imageView, AttachmentType type)
{
	if (type == AttachmentType::Color)
	{
		assert(m_colourAttachments.size() < 8);
		Attachment attach{

		};

		m_colourAttachments.push_back(attach);
	}
	else if (type == AttachmentType::Depth)
	{
		Attachment attach{

		};
		m_depthAttachment = &attach;
	}
	else
	{
		Attachment attach{

		};
		m_stencilAttachment = &attach;
	}
}
