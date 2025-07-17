#include "GLFWWindow.h"

GLFWWindow::GLFWWindow(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

GLFWWindow::~GLFWWindow()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
	}
	glfwTerminate();
}

void GLFWWindow::GetDimensions(int& width, int& height) const
{
	glfwGetWindowSize(m_window, &width, &height);
}

void GLFWWindow::GetFramebufferSize(int& width, int& height) const
{
	glfwGetFramebufferSize(m_window, &width, &height);
}

float GLFWWindow::GetAspectRatio() const
{
	int width, height;
	GetDimensions(width, height);
	return static_cast<float>(width) / height;
}

void GLFWWindow::Close() const
{
	glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

bool GLFWWindow::ShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void GLFWWindow::PollEvents() const
{
	glfwPollEvents();
}

IWindow::NativeHandle GLFWWindow::GetNativeWindow() const
{
	NativeHandle handle;
	handle.type = NativeHandleType::GLFW;
	handle.glfw.ptr = m_window;
	return handle;
}
