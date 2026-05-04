#pragma once
#include "Core.h"
#include "memory.h"
#include "spdLog/spdlog.h"

namespace VT {
	class VRITRA_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log Macros
#define VT_Core_Trace(...)        ::VT::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VT_Core_Info(...)         ::VT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VT_Core_Warn(...)         ::VT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VT_Core_Error(...)        ::VT::Log::GetCoreLogger()->err(__VA_ARGS__)
#define VT_Core_Critical(...)     ::VT::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log Macros
#define VT_Trace(...)             ::VT::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VT_Info(...)              ::VT::Log::GetClientLogger()->info(__VA_ARGS__)
#define VT_Warn(...)              ::VT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VT_Error(...)             ::VT::Log::GetClientLogger()->err(__VA_ARGS__)
#define VT_Critical(...)          ::VT::Log::GetClientLogger()->critical(__VA_ARGS__)

