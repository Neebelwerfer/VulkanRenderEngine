#include "EditorApplication.h"
#include <iostream>
#include <imgui.h>
#include <VulkanGL/Debug/Debug.h>


EditorApplication::EditorApplication()
	: Application(800, 600, "Editor")
	, m_graphicsInterface(std::make_unique<GraphicsInterface>())
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Initialize()
{
	//m_imgui.Initialize(GetMainWindow());
	m_graphicsInterface->Initialize(GetMainWindow());
}

void EditorApplication::Update() 
{

}

void EditorApplication::Render()
{
	m_graphicsInterface->Render();
	RenderGUI();
}

void EditorApplication::Cleanup()
{
	m_graphicsInterface->Cleanup();
	Application::Cleanup();
	//m_imgui.Cleanup();
}

void EditorApplication::RenderGUI()
{
	//m_imgui.BeginFrame();

	//m_imgui.EndFrame();
}
