#include "Window.h"

Window::Window(int width, int height, const char* title) : m_window(nullptr)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

Window::~Window()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
	}
	glfwTerminate();
}

void Window::GetDimensions(int& width, int& height) const
{
	glfwGetWindowSize(m_window, &width, &height);
}

float Window::GetAspectRatio() const
{
	int width, height;
	GetDimensions(width, height);
	return static_cast<float>(width) / height;
}

void Window::Close() const
{
	glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_window);
}
