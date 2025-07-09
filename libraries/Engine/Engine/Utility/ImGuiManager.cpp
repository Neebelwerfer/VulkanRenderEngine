#include "ImGuiManager.h"

#include <Application/Window.h>
#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_vulkan.h>

ImGuiManager::ImGuiManager()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
}

ImGuiManager::~ImGuiManager()
{
	ImGui::DestroyContext();
}

void ImGuiManager::Initialize(::Window& window)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfw_InitForVulkan(window.GetGLFWwindow(), true);
}

void ImGuiManager::Cleanup()
{

	ImGui_ImplVulkan_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiManager::BeginFrame()
{
	ImGui_ImplVulkan_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}
void ImGuiManager::EndFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGui::Render();
	//if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
	//	ImGui::UpdatePlatformWindows();
	//	ImGui::RenderPlatformWindowsDefault();
	//}
}

ImGuiManager::Window ImGuiManager::UseWindow(const char* name)
{
	return name;
}

ImGuiManager::Window::Window(const char* name) : m_open(false)
{
	m_open = ImGui::Begin(name);
}

ImGuiManager::Window::~Window()
{
	ImGui::End();
}

ImGuiManager::Window::operator bool() const
{
	return m_open;
}