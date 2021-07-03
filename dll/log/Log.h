//
// Created by Arisu on 03/07/2021.
//

#ifndef PACKERC___LOG_H
#define PACKERC___LOG_H

#include <memory>
#include <iomanip>
#include <utility>
#include <fstream>
#include <ctime>

namespace log {
    enum TLogLevel {
        logERROR, logWARNING, logINFO, logDEBUG
    };

    static const char *StringLogLevel[] = {
            "ERROR", "WARNING", "INFO", "DEBUG"
    };

    class Log {
    private:
        std::string logFilePath;
        std::ofstream logFilePointer;
    public:
        explicit Log(std::string path) :
                logFilePath(std::move(path)) {};

        ~Log() {
            this->logFilePointer.close();
        }

        template<typename T>
        void Write(const T &toLog, TLogLevel logLevel = TLogLevel::logDEBUG);
    };

    template<typename T>
    void Log::Write(const T &toLog, TLogLevel logLevel) {
        this->template Write(std::to_string(toLog), logLevel);
    }

    template<>
    inline void Log::Write(const std::string& toLog, TLogLevel logLevel) {
        if (!this->logFilePointer.is_open()) {
            this->logFilePointer.open(this->logFilePath,std::ios_base::app);
        }

        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        this->logFilePointer << "[ " << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << " ]";

        this->logFilePointer << " [ " << log::StringLogLevel[logLevel] << " ]";
        this->logFilePointer << " - " << toLog << std::endl;
    }
}

extern std::shared_ptr<log::Log> Logger;

#endif //PACKERC___LOG_H
