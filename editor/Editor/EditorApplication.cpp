#include "EditorApplication.h"
#include <iostream>
#include <imgui.h>


EditorApplication::EditorApplication()
	: Application(800, 600, "Editor")
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Initialize()
{
	Application::Initialize();
	//m_imgui.Initialize(GetMainWindow());
}

void EditorApplication::Update() 
{

}

void EditorApplication::Render()
{
	Application::Render();
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
