#pragma once

#include <string>
#include <Engine/Graphics/Interfaces/IWindow.h>
#include <Engine/Graphics/GraphicsInterface.h>
#include <memory>

class Application {
public:
	Application(int width, int height, const char* title);
	virtual ~Application();

	virtual void Run();

private:

	void UpdateTime(float newCurrentTime);

protected:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Cleanup();

	IWindow& GetMainWindow() { return *m_mainWindow; }
	inline const IWindow& GetMainWindow() const { return *m_mainWindow; }

	// Get time in seconds from the start of the application
	inline float GetCurrentTime() const { return m_currentTime; }

	// Get time in seconds of the current frame
	inline float GetDeltaTime() const { return m_deltaTime; }

	bool IsRunning() const;

	inline void Close() { Terminate(0); }

	// End the execution of the application and return the exit code (0 for OK)
	// Optionally provide an error message, if the exit code is not 0
	void Terminate(int exitCode, const char* errorMessage = nullptr);	

protected:
	std::unique_ptr<GraphicsInterface> m_graphicsInterface;
	
private:
	std::unique_ptr<IWindow> m_mainWindow;
		
	// Time in seconds from the start of the application
	float m_currentTime;
	// Time in seconds of the current frame
	float m_deltaTime;

	// Exit code
	int m_exitCode;
	// Error message to display on exit
	std::string m_errorMessage;


};
