#pragma once

#include <iostream>

namespace Towell
{
	class Log
	{
	public:
		static void Init();

		inline static Log* GetEngineLogger() { return s_EngineLogger; }
		inline static Log* GetEditorLogger() { return s_EditorLogger; }

		void Trace(char* message);
		void Info(char* message);
		void Warn(char* message);
		void Error(char* message);

	private:
		static Log* s_EngineLogger;
		static Log* s_EditorLogger;

		char* name;

		Log(char* name);
		~Log();

		void LogMessage(char* level, char* message);
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