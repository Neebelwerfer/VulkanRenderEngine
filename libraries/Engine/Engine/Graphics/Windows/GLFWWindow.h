#pragma once
#include <Engine/Graphics/Interfaces/IWindow.h>
#include <GLFW/glfw3.h>


class GLFWWindow : public IWindow
{
public:
	GLFWWindow(int width, int height, const char* title);
	~GLFWWindow();

	inline bool IsValid() const { return m_window != nullptr; }

	void GetDimensions(int& width, int& height) const;
	void GetFramebufferSize(int& width, int& height) const;
	float GetAspectRatio() const;

	void Close() const override;
	bool ShouldClose() const override;
	void PollEvents() const override;

	NativeHandle GetNativeWindow() const override;

private:
	GLFWwindow* m_window;
};