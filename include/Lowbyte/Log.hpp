#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Lowbyte/Core.hpp"

namespace lowbyte
{
	class LOWBYTE_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#define LB_CORE_FATAL(...) lowbyte::Log::getCoreLogger()->critical(__VA_ARGS__)
#define LB_CORE_ERROR(...) lowbyte::Log::getCoreLogger()->error(__VA_ARGS__)
#define LB_CORE_WARN(...) lowbyte::Log::getCoreLogger()->warn(__VA_ARGS__)
#define LB_CORE_INFO(...) lowbyte::Log::getCoreLogger()->info(__VA_ARGS__)
#define LB_CORE_TRACE(...) lowbyte::Log::getCoreLogger()->trace(__VA_ARGS__)

#define LB_FATAL(...) lowbyte::Log::getClientLogger()->critical(__VA_ARGS__)
#define LB_ERROR(...) lowbyte::Log::getClientLogger()->error(__VA_ARGS__)
#define LB_WARN(...) lowbyte::Log::getClientLogger()->warn(__VA_ARGS__)
#define LB_INFO(...) lowbyte::Log::getClientLogger()->info(__VA_ARGS__)
#define LB_TRACE(...) lowbyte::Log::getClientLogger()->trace(__VA_ARGS__)