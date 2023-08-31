#pragma once

#include <string>
#include <filesystem>


class Logger {
public:
    Logger() = default;
    ~Logger() = default;

    static void Log(const std::string& message, bool append = true);

private:
    static std::string GetCurrentDateTime();
};



