#pragma once

#include <string>


namespace Application
{
	class Application {
	public:
		// Construct the application specifying the dimensions of the window and its title
		Application(int width, int height, const char* title);

		// Destroy de application
		virtual ~Application();

		void run();

	private:
		void Initialize();

		void Update();
		void Render();
		
		void Cleanup();
	
	protected:
		// End the execution of the application and return the exit code (0 for OK)
		// Optionally provide an error message, if the exit code is not 0
		void Terminate(int exitCode, const char* errorMessage = nullptr);	
	
	private:
		// Time in seconds from the start of the application
		float m_currentTime;
		// Time in seconds of the current frame
		float m_deltaTime;

		// Exit code
		int m_exitCode;
		// Error message to display on exit
		std::string m_errorMessage;
	};

}