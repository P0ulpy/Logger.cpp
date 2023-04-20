//
// Created by Flo on 02/12/2022.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "ConsoleColor.hpp"

#include <thread>
#include <string>
#include <string_view>
#include <mutex>
#include <unordered_map>
#include <sstream>

enum LogType {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

struct LogEntry
{
    LogType type;
    std::thread::id threadId;
    std::string message;
};

template <LogType type> struct LogTypeLabel;
template <> struct LogTypeLabel<LOG_INFO>       { static constexpr std::string_view value = "INFO"; };
template <> struct LogTypeLabel<LOG_WARNING>    { static constexpr std::string_view value = "WARN"; };
template <> struct LogTypeLabel<LOG_ERROR>      { static constexpr std::string_view value = "ERR"; };

template <LogType type> struct LogTypeColor;
template <> struct LogTypeColor<LOG_INFO>       { static constexpr auto value = LoggerConsoleColor::blue; };
template <> struct LogTypeColor<LOG_WARNING>    { static constexpr auto value = LoggerConsoleColor::yellow; };
template <> struct LogTypeColor<LOG_ERROR>      { static constexpr auto value = LoggerConsoleColor::red; };


/** @brief A simple logger class that can be used to log messages to the console.
 *  @details This class is thread-safe and can be used to log messages from multiple threads.
 *  It also allows to set a label for each thread, which will be displayed in the log messages.
 *  @note This class is Static and should never be instantiated.
 */
class Logger
{
public:
    Logger() = delete;

    template<typename ...Args>
    static void Log(Args... args);

    template<typename ...Args>
    static void Warn(Args... args);

    template<typename ...Args>
    static void Err(Args... args);

    static void SetThreadLabel(const std::string_view& label);
    static void SetThreadLabel(const std::string_view& label, std::thread::id threadID);

private:
    static std::string CurrentDateTimeToString();

    template<LogType logType, typename ...Args>
    static LogEntry PrintMessage(std::ostream& ostream, Args... args);

    template <LogType logType>
    static LogEntry ConstructEntry();

    template<typename FirstMessage, typename ...Args>
    static void BuildMessage(std::stringstream& out, const FirstMessage& first, Args... args);

    static std::mutex _mutex;
    static std::unordered_map<std::thread::id, std::string> _threadsLabels;
};

#include "Logger.tpp"

#endif //LOGGER_HPP