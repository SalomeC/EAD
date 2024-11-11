#ifndef ENGINE_LOGGER_H
#define ENGINE_LOGGER_H

#include <string>

namespace EngineNamespace {
    class Logger {
    public:
        static void init();   // Initialize the logging system
        static void info(const std::string& message);
        static void warn(const std::string& message);
        static void error(const std::string& message);

    private:
        Logger() = default;  // Prevent instantiation
    };
}

#endif // ENGINE_LOGGER_H

