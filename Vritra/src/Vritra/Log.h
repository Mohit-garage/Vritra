#pragma once
#include "Core.h"
#include "spdLog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <type_traits>

// Template to format fmt operator << for every class having ToString

template <typename T, typename = void>
struct has_to_string : std::false_type {};

template <typename T>
struct has_to_string<T, std::void_t<decltype(std::declval<T>().ToString())>> : std::true_type {};

template <typename T>
struct fmt::formatter<T, std::enable_if_t<has_to_string<T>::value, char>>
{
	constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const T& obj, FormatContext& ctx) const -> decltype(ctx.out()) {
		return fmt::format_to(ctx.out(), "{}", obj.ToString());
	}
};
// Added such that any class can use logging function without having to implement operator overload for specific

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

