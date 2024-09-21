#include "Log.h"

namespace Towell
{
	Log* Log::s_EngineLogger;
	Log* Log::s_EditorLogger;

	Log::Log(char* name, Level level)
	{
		this->m_Name = name;
		this->m_Level = level;
	}

	Log::~Log() 
	{
		delete Log::m_Name;
	}
	
	void Log::Init(Level level)
	{
		s_EngineLogger = new Log("Towell", level);
		s_EditorLogger = new Log("Editor", level);
	}

}
