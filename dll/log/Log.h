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

namespace RRLog {
    enum TLogLevel {
        logERROR, logWARNING, logINFO, logDEBUG
    };

    static const char* StringLogLevel[] = {
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

        std::ofstream* Stream(){
            return &logFilePointer;
        }

        void Write(const char* toLog, TLogLevel logLevel = TLogLevel::logDEBUG);
        void Write(const std::string &toLog, TLogLevel logLevel = TLogLevel::logDEBUG);
    };
}

extern std::shared_ptr<RRLog::Log> Logger;

#endif //PACKERC___LOG_H
