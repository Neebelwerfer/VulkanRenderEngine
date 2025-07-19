#include "GLFWWindowImpl.h"

static void FramebufferResizeCallback(GLFWwindow* window, int width, int height)
{
	auto windowHandler = reinterpret_cast<GLFWWindowImpl*>(glfwGetWindowUserPointer(window));
	windowHandler->SetResizedFlag();
}

GLFWWindowImpl::GLFWWindowImpl(int width, int height, const char* title) : WindowBase()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, FramebufferResizeCallback);
}

GLFWWindowImpl::~GLFWWindowImpl()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
	}
	glfwTerminate();
}

void GLFWWindowImpl::GetDimensions(int& width, int& height) const
{
	glfwGetWindowSize(m_window, &width, &height);
}

void GLFWWindowImpl::GetFramebufferSize(int& width, int& height) const
{
	glfwGetFramebufferSize(m_window, &width, &height);
}

float GLFWWindowImpl::GetAspectRatio() const
{
	int width, height;
	GetDimensions(width, height);
	return static_cast<float>(width) / height;
}

const std::string& GLFWWindowImpl::GetWindowTitle() const
{
	return std::string(glfwGetWindowTitle(m_window));
}

void GLFWWindowImpl::Close() const
{
	glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

bool GLFWWindowImpl::ShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void GLFWWindowImpl::PollEvents() const
{
	glfwPollEvents();
}

NativeWindowHandle GLFWWindowImpl::GetNativeWindow() const
{
	NativeWindowHandle handle;
	handle.type = NativeWindowHandleType::GLFW;
	handle.glfw.ptr = m_window;
	return handle;
}
