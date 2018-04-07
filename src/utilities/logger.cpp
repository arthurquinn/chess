#include "utilities/logger.h"



Logger::Logger() : _color_map({
    { LogLevel::DEBUG, "\033[0;90m" },
    { LogLevel::INFO, "\033[0;37m" },
    { LogLevel::WARN, "\033[1;35m" },
    { LogLevel::ERROR, "\033[1;31m" },
    { LogLevel::FATAL, "\033[1;96m" },
}) {

}

std::ostream& Logger::color(const LogLevel level) const {
    return *_ostream << _color_map.at(level);
}

void Logger::debug(std::string&& msg) const {
    color(LogLevel::DEBUG) << "[DEBUG]: " << std::forward<std::string>(msg) << _reset_color << std::endl;
}

void Logger::info(std::string&& msg) const {
    color(LogLevel::INFO) << "[INFO]: " << std::forward<std::string>(msg) << _reset_color << std::endl;
}

void Logger::warn(std::string&& msg) const {
    color(LogLevel::WARN) << "[WARN]: " << std::forward<std::string>(msg) << _reset_color << std::endl;
}

void Logger::error(std::string&& msg) const {
    color(LogLevel::ERROR) << "[ERROR]: " << std::forward<std::string>(msg) << _reset_color << std::endl;
}

void Logger::fatal(std::string&& msg) const {
    color(LogLevel::FATAL) << "[FATAL]: " << std::forward<std::string>(msg) << _reset_color << std::endl;
}

void Logger::set_ostream(std::ostream * const os) {
    _ostream = os;
}