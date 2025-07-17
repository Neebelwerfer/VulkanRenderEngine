#pragma once
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	inline bool IsValid() const { return m_window != nullptr; }

	void GetDimensions(int& width, int& height) const;
	void GetFramebufferSize(int& width, int& height) const;

	float GetAspectRatio() const;

	void Close() const;
	bool ShouldClose() const;


	inline GLFWwindow* GetGLFWwindow() const { return m_window; }

private:
	// Pointer to a GLFW window object. Its lifetime should match the lifetime of this object
	GLFWwindow* m_window;
};