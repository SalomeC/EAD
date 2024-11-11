#include "Logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace EngineNamespace {
    std::shared_ptr<spdlog::logger> coreLogger;

    void Logger::init() {
        coreLogger = spdlog::stdout_color_mt("ENGINE");
        spdlog::set_pattern("[%T] %^[%l]%$ %v");  // Format for time, level, and message
        coreLogger->info("Logger initialized.");
    }

    void Logger::info(const std::string& message) {
        coreLogger->info(message);
    }

    void Logger::warn(const std::string& message) {
        coreLogger->warn(message);
    }

    void Logger::error(const std::string& message) {
        coreLogger->error(message);
    }
}
