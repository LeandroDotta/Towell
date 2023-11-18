#pragma once

#include <iostream>

namespace Towell
{
	class Log
	{
	public:
		static const int LevelTrace = 0;
		static const int LevelInfo = 1;
		static const int LevelWarn = 2;
		static const int LevelError = 3;

		static void Init(int level);

		inline static Log* GetEngineLogger() { return s_EngineLogger; }
		inline static Log* GetEditorLogger() { return s_EditorLogger; }

		void Trace(char* message);
		void Info(char* message);
		void Warn(char* message);
		void Error(char* message);

	private:
		static Log* s_EngineLogger;
		static Log* s_EditorLogger;

		static const char* m_ColorTrace;
		static const char* m_ColorInfo;
		static const char* m_ColorWarn;
		static const char* m_ColorError;

		char* m_Name;
		int m_Level;

		Log(char* name, int level);
		~Log();

		void LogMessage(int level, char* message);

		inline char* GetLevelText(int level) {
			switch (level)
			{
			case LevelTrace:
				return "TRACE";
			case LevelInfo:
				return "INFO";
			case LevelWarn:
				return "WARN";
			case LevelError:
				return "ERROR";
			}
		}

		inline const char* GetLevelColor(int level) {
			switch (level)
			{
			case LevelTrace:
				return m_ColorTrace;
			case LevelInfo:
				return m_ColorInfo;
			case LevelWarn:
				return m_ColorWarn;
			case LevelError:
				return m_ColorError;
			}
		}
	};
}

// Engine Log macros
#define TW_TRACE(...)			::Towell::Log::GetEngineLogger()->Trace(__VA_ARGS__)
#define TW_INFO(...)			::Towell::Log::GetEngineLogger()->Info(__VA_ARGS__)
#define TW_WARN(...)			::Towell::Log::GetEngineLogger()->Warn(__VA_ARGS__)
#define TW_ERROR(...)			::Towell::Log::GetEngineLogger()->Error(__VA_ARGS__)

// Editor Log macros
#define TW_EDITOR_TRACE(...)	::Towell::Log::GetEditorLogger()->Trace(__VA_ARGS__)
#define TW_EDITOR_INFO(...)		::Towell::Log::GetEditorLogger()->Info(__VA_ARGS__)
#define TW_EDITOR_WARN(...)		::Towell::Log::GetEditorLogger()->Warn(__VA_ARGS__)
#define TW_EDITOR_ERROR(...)	::Towell::Log::GetEditorLogger()->Error(__VA_ARGS__)