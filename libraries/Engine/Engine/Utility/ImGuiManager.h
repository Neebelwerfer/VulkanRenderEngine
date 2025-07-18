#pragma once
#include <Engine/Graphics/Interfaces/IWindow.h>

class Window;

class ImGuiManager
{
public:
	class Window
	{
	public:
		~Window();
		operator bool() const;
	private:
		friend ImGuiManager;
		Window(const char* name);
	private:
		bool m_open;
	};
public:
	ImGuiManager();
	~ImGuiManager();

	void Initialize(::IWindow& window);
	void Cleanup();

	void BeginFrame();
	void EndFrame();

	Window UseWindow(const char* name);

};