#pragma once

#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Thease {

	class THEASE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define TH_CORE_ERROR(...)    ::Thease::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TH_CORE_INFO(...)     ::Thease::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TH_CORE_WARN(...)     ::Thease::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TH_CORE_TRACE(...)    ::Thease::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TH_CORE_CRITICAL(...) ::Thease::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define TH_ERROR(...)         ::Thease::Log::GetClientLogger()->error(__VA_ARGS__)
#define TH_INFO(...)          ::Thease::Log::GetClientLogger()->info(__VA_ARGS__)
#define TH_WARN(...)          ::Thease::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TH_TRACE(...)         ::Thease::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TH_CRITICAL(...)      ::Thease::Log::GetClientLogger()->critical(__VA_ARGS__)

