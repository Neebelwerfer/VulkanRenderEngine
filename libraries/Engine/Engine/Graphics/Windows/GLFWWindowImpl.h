#pragma once
#include <Engine/Graphics/Base/WindowBase.h>
#include <GLFW/glfw3.h>

class GLFWWindowImpl : public WindowBase
{
public:
	GLFWWindowImpl(int width, int height, const char* title);
	~GLFWWindowImpl();


	inline bool IsValid() const { return m_window != nullptr; }
	bool ShouldClose() const override;

	void GetFramebufferSize(int& width, int& height) const;
	void GetDimensions(int& width, int& height) const;
	float GetAspectRatio() const;

	const std::string& GetWindowTitle() const override;

	void PollEvents() const override;
	void Close() const override;

	NativeWindowHandle GetNativeWindow() const override;

private:
	GLFWwindow* m_window;
};