//
// Created by Arisu on 03/07/2021.
//
#include <ctime>
#include <iomanip>
#include "Log.h"

namespace log {
    void Log::Write(const char* toLog, TLogLevel logLevel) {
        std::string logString(toLog);
        this->Write(logString, logLevel);
    }

    void Log::Write(const std::string &toLog, TLogLevel logLevel) {
        if (!this->logFilePointer.is_open()) {
            this->logFilePointer.open(this->logFilePath, std::ios_base::app);
        }

        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        this->logFilePointer << "[ " << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << " ]";

        this->logFilePointer << " [ " << log::StringLogLevel[logLevel] << " ]";
        this->logFilePointer << " - " << toLog << std::endl;
    }
}