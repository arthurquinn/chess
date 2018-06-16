#ifndef __LOGGER_H
#define __LOGGER_H

#include <string>
#include <sstream>
#include <map>

class Logger {
private:
    enum class LogLevel {
        DEBUG = 0,
        INFO = 1,
        WARN = 2,
        ERROR = 4,
        FATAL = 5
    };

    const std::string _reset_color { "\033[0m" };
    const std::map<const LogLevel, const std::string> _color_map;

    std::ostream *_ostream;

    std::ostream& color(const LogLevel level) const;

public:
    Logger();
    virtual ~Logger() = default;

    void debug(std::string&& msg) const;
    void info(std::string&& msg) const;
    void warn(std::string&& msg) const;
    void error(std::string&& msg) const;
    void fatal(std::string&& msg) const;

    void set_ostream(std::ostream * const os);
};


#endif