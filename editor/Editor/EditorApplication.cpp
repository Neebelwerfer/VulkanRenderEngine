#include "EditorApplication.h"
#include <imgui.h>

EditorApplication::EditorApplication(int width, int height)
	: Application(width, height, "Editor")
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Initialize()
{
	m_imgui.Initialize(GetMainWindow());
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
	m_imgui.Cleanup();
}

void EditorApplication::RenderGUI()
{
	//m_imgui.BeginFrame();

	//m_imgui.EndFrame();
}
