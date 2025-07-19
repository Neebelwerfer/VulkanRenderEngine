#include "EditorApplication.h"
#include <iostream>

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
	//m_imguiContext = m_graphicsManager->CreateImGuiContext();
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
	//m_imguiContext->Cleanup();
}

void EditorApplication::RenderGUI()
{
	//m_imguiContext->BeginFrame();

	//m_imguiContext->EndFrame();
}
