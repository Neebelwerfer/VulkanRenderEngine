#pragma once

#include "Window.h"
#include <string>
#include <memory>

class Application {
public:
	Application(int width, int height, const char* title);
	virtual ~Application();

	void run();

private:
	void Initialize();

	void Update();
	void Render();
		
	void Cleanup();

	void UpdateTime(float newCurrentTime);

protected:
	// Get time in seconds from the start of the application
	inline float GetCurrentTime() const { return m_currentTime; }

	// Get time in seconds of the current frame
	inline float GetDeltaTime() const { return m_deltaTime; }

	bool IsRunning() const;

	inline void Close() { Terminate(0); }

	// End the execution of the application and return the exit code (0 for OK)
	// Optionally provide an error message, if the exit code is not 0
	void Terminate(int exitCode, const char* errorMessage = nullptr);	
	
private:
	Window m_mainWindow;
		
	// Time in seconds from the start of the application
	float m_currentTime;
	// Time in seconds of the current frame
	float m_deltaTime;

	// Exit code
	int m_exitCode;
	// Error message to display on exit
	std::string m_errorMessage;
};
