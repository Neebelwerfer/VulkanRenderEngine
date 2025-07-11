#include "EditorApplication.h"
#include <iostream>
#include <imgui.h>
#include <vulkan/vulkan.h>>

EditorApplication::EditorApplication()
	: Application(800, 600, "Editor")
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Initialize()
{
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << extensionCount << " extensions supported\n";


	glm::mat4 matrix{};
	glm::vec4 vec{};
	auto test = matrix * vec;
	//m_imgui.Initialize(GetMainWindow());
}

void EditorApplication::Update() 
{

}

void EditorApplication::Render()
{
	RenderGUI();
}

void EditorApplication::Cleanup()
{
	Application::Cleanup();
	//m_imgui.Cleanup();
}

void EditorApplication::RenderGUI()
{
	//m_imgui.BeginFrame();

	//m_imgui.EndFrame();
}
