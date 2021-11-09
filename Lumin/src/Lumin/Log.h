#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lumin {

	class LUMIN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
		inline static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#define LUM_CORE_TRACE(...)  ::Lumin::Log::s_CoreLogger->trace(__VA_ARGS__)
#define LUM_CORE_INFO(...)   ::Lumin::Log::s_CoreLogger->info(__VA_ARGS__)
#define LUM_CORE_WARN(...)   ::Lumin::Log::s_CoreLogger->warn(__VA_ARGS__)
#define LUM_CORE_ERROR(...)  ::Lumin::Log::s_CoreLogger->error(__VA_ARGS__)
#define LUM_CORE_CRITICAL(...)  ::Lumin::Log::s_CoreLogger->critical(__VA_ARGS__)

#define LUM_TRACE(...)  ::Lumin::Log::s_ClientLogger->trace(__VA_ARGS__)
#define LUM_INFO(...)   ::Lumin::Log::s_ClientLogger->info(__VA_ARGS__)
#define LUM_WARN(...)   ::Lumin::Log::s_ClientLogger->warn(__VA_ARGS__)
#define LUM_ERROR(...)  ::Lumin::Log::s_ClientLogger->error(__VA_ARGS__)
#define LUM_CRITICAL(...)  ::Lumin::Log::s_ClientLogger->critical(__VA_ARGS__)

