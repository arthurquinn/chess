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

    const std::string _reset_color = "\033[0m";
    const std::map<const LogLevel, const std::string> _color_map;

    std::ostream *_ostream;

    std::ostream& color(const LogLevel level);

public:
    Logger();
    virtual ~Logger() = default;

    std::ostream& debug(std::string&& msg);
    std::ostream& info(std::string&& msg);
    std::ostream& warn(std::string&& msg);
    std::ostream& error(std::string&& msg);
    std::ostream& fatal(std::string&& msg);

    void set_ostream(std::ostream * const os);
};


#endif
