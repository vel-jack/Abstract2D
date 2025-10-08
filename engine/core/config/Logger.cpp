#include "Logger.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

using namespace Abstract2D;

std::shared_ptr<spdlog::logger> Logger::m_Logger;

void Logger::Init(std::string& logName)
{
	std::vector<spdlog::sink_ptr> lSinks;
	lSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	lSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(logName + ".log", true));

	m_Logger = std::make_shared<spdlog::logger>(logName, begin(lSinks), end(lSinks));
	spdlog::register_logger(m_Logger);
	m_Logger->set_level(spdlog::level::trace);
	m_Logger->flush_on(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> Logger::Get() {
	return m_Logger;
}