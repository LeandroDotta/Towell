#include "Log.h"
#include <iostream>
#include <ctime>

namespace Towell
{
	Log* Log::s_EngineLogger;
	Log* Log::s_EditorLogger;

	const char* Log::m_ColorTrace = "\033[36m";
	const char* Log::m_ColorInfo = "\033[37m";
	const char* Log::m_ColorWarn = "\033[33m";
	const char* Log::m_ColorError = "\033[1;31m";

	Log::Log(char* name, int level) 
	{
		this->m_Name = name;
		this-> m_Level = level;
	}

	Log::~Log() 
	{
		delete Log::m_Name;
	}

	void Log::Init(int level) 
	{
		s_EngineLogger = new Log("Towell", level);
		s_EditorLogger = new Log("Editor", level);
	}

	void Log::Trace(char* message)
	{
		if (m_Level > LevelTrace)
			return;

		LogMessage(LevelTrace, message);
	}

	void Log::Info(char* message)
	{
		if (m_Level > LevelInfo)
			return;

		Log::LogMessage(LevelInfo, message);
	}

	void Log::Warn(char* message)
	{
		if (m_Level > LevelWarn)
			return;

		Log::LogMessage(LevelWarn, message);
	}

	void Log::Error(char* message)
	{
		if (m_Level > LevelError)
			return;

		LogMessage(LevelError, message);
	}

	void Log::LogMessage(int level, char* message)
	{
		time_t now = time(NULL);
		std::string time = ctime(&now);
		time.erase(time.find("\n", 0), 1);
		std::cout << Log::GetLevelColor(level) << time << " [" << this->m_Name << "] " << "(" << Log::GetLevelText(level) << "): " << message << std::endl;
	}
}
