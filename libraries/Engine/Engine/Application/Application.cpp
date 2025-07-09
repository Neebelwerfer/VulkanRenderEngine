#include "Application.h"
#include <iostream>
#include <chrono>

Application::Application(int width, int height, const char* title)
	: m_mainWindow(width, height, title)
	, m_currentTime(0)
	, m_deltaTime(0)
	, m_exitCode(0)
{
	if (!m_mainWindow.IsValid())
	{
		Terminate(-1, "Failed to create GLFW window");
		return;
	}
}

Application::~Application()
{
	// If something didn't go as expected, display an error message
	if (m_exitCode)
	{
		std::cout << "Error (" << m_exitCode << "): " << m_errorMessage << std::endl;
	}
}

void Application::Initialize()
{
}


void Application::Run()
{
	if (!m_exitCode)
	{
		Initialize();

		auto startTime = std::chrono::steady_clock::now();

		while (IsRunning())
		{
			std::chrono::duration<float> duration = std::chrono::steady_clock::now() - startTime;
			UpdateTime(duration.count());

			Update();

			Render();

			// Swap buffers and poll events at the end of the frame
			m_mainWindow.SwapBuffers();
			glfwPollEvents();
		}

		Cleanup();
	}
}

void Application::Render()
{

}

void Application::Update()
{
}

void Application::Cleanup()
{
	if (m_mainWindow.IsValid())
	{
		m_mainWindow.Close();
	}
}

void Application::UpdateTime(float newCurrentTime)
{
	m_deltaTime = newCurrentTime - m_currentTime;
	m_currentTime = newCurrentTime;
}

bool Application::IsRunning() const
{
	return m_mainWindow.IsValid() && !m_mainWindow.ShouldClose();
}

void Application::Terminate(int exitCode, const char* errorMessage)
{
	m_exitCode = exitCode;
	if (errorMessage)
	{
		// Ensure that error messages come with exit code different from 0
		assert(exitCode);
		m_errorMessage = errorMessage;
	}

	// If termination is requested and main window is still valid, request to close
	if (m_mainWindow.IsValid())
	{
		m_mainWindow.Close();
	}

	// Force assert here to detect error termination
	assert(!exitCode);
}
