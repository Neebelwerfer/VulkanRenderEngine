#pragma once
#include <Engine/Graphics/Interfaces/IWindow.h>

class Window;

class ImGuiBase
{
public:
	~ImGuiBase();
	
	class Window
	{
	public:
		~Window();
		operator bool() const;
	private:
		friend ImGuiBase;
		Window(const char* name);
	private:
		bool m_open;
	};
public:

	virtual void Initialize() = 0;
	virtual void Cleanup() = 0;

	virtual void BeginFrame() = 0;
	virtual void EndFrame() = 0;

	Window UseWindow(const char* name);

protected:
	ImGuiBase(::IWindow& window);
	
	IWindow& m_window;

};