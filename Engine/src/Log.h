#pragma once

#include <iostream>

namespace Towell
{
	class Log
	{
	public:
		enum Level {
			LevelTrace, LevelInfo, LevelWarn, LevelError
		};

		static void Init(Level level);

		inline static Log* GetEngineLogger() { return s_EngineLogger; }
		inline static Log* GetEditorLogger() { return s_EditorLogger; }

		void Trace(char* message);
		void Info(char* message);
		void Warn(char* message);
		void Error(char* message);

	private:
		static Log* s_EngineLogger;
		static Log* s_EditorLogger;

		char* m_Name;
		Level m_Level;

		Log(char* name, Level level);
		~Log();

		void LogMessage(Level level, char* message);

		inline static const char* GetLevelText(Level level) {
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

		inline static const char* GetLevelColor(Level level) {
			switch (level)
			{
			case LevelTrace:
				return "\033[36m";
			case LevelInfo:
				return "\033[37m";
			case LevelWarn:
				return "\033[33m";
			case LevelError:
				return "\033[1;31m";
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