#include "WindowBase.h"
#include <GLFW/glfw3.h>

WindowBase::WindowBase()
	: m_resized(false)
{
}

WindowBase::~WindowBase()
{
}

bool WindowBase::IsMinimized() const
{
	int width, height;
	GetFramebufferSize(width, height);
	return width == 0 || height == 0;
}
