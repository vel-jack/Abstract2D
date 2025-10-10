#pragma once

#include <spdlog/spdlog.h>
#include <memory>
#include <string>

namespace Abstract2D {
	class Logger {
	public:
		static void Init(std::string& logName);
		static std::shared_ptr<spdlog::logger> Get();
	private:
		static std::shared_ptr<spdlog::logger> m_Logger;
	};
}

#ifdef ENABLE_LOGGING
	#define DEBUG_INFO(...) ::Abstract2D::Logger::Get()->info(__VA_ARGS__)
	#define DEBUG_WARN(...) ::Abstract2D::Logger::Get()->warn(__VA_ARGS__)
	#define DEBUG_ERROR(...) ::Abstract2D::Logger::Get()->error(__VA_ARGS__)
#else
	#define DEBUG_INFO(...) (void)0
	#define DEBUG_WARN(...) (void)0
	#define DEBUG_ERROR(...) (void)0
#endif