#include "Log.h"
#include <iostream>
#include <ctime>

namespace Towell
{
	Log* Log::s_EngineLogger;
	Log* Log::s_EditorLogger;

	Log::Log(char* name) 
	{
		this->name = name;
	}

	Log::~Log() 
	{
		delete Log::name;
	}

	void Log::Init() 
	{
		s_EngineLogger = new Log("Towell");
		s_EditorLogger = new Log("Editor");
	}

	void Log::Trace(char* message)
	{
		LogMessage("TRACE", message);
	}

	void Log::Info(char* message)
	{
		Log::LogMessage("INFO", message);
	}

	void Log::Warn(char* message)
	{
		Log::LogMessage("WARN", message);
	}

	void Log::Error(char* message)
	{
		LogMessage("ERROR", message);
	}

	void Log::LogMessage(char* level, char* message)
	{
		time_t now = time(NULL);
		std::string time = ctime(&now);
		time.erase(time.find("\n", 0), 1);
		std::cout << time << " [" << this->name << "] " << "(" << level << "): " << message << std::endl;
	}
}
