#include "ImGuiBase.h"
#include <imgui.h>

ImGuiBase::ImGuiBase(::IWindow& window)
	: m_window(window)
{
	IMGUI_CHECKVERSION();
	//ImGui::CreateContext();

	//ImGui::StyleColorsDark();
}

ImGuiBase::~ImGuiBase()
{
	//ImGui::DestroyContext();
}

ImGuiBase::Window ImGuiBase::UseWindow(const char* name)
{
	return name;
}

ImGuiBase::Window::Window(const char* name) : m_open(false)
{
	m_open = ImGui::Begin(name);
}

ImGuiBase::Window::~Window()
{
	ImGui::End();
}

ImGuiBase::Window::operator bool() const
{
	return m_open;
}