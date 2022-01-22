//
// Created by Sophie on 22/01/2022.
//

#include <string>
#include "DataStream.h"
#include <ctime>
#include <common.h>
#include <chrono>

std::string RRLog::DataStream::OpenTimed()
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	struct tm* parts = std::localtime(&now_c);

	char str[11];

	sprintf(str, "%04d-%02d-%02dT%02d_%02d_%02d",
			1900 + parts->tm_year,
			1 + parts->tm_mon,
			parts->tm_mday,
			parts->tm_hour,
			parts->tm_min,
			parts->tm_sec
	);

	const std::string& fileName = "rr_datastream_" + std::string(str) + ".txt";
	file.open(logRoot + "\\" + fileName, std::ios_base::app | std::ios_base::out);

	return { fileName };
}

void RRLog::DataStream::UpdateTimestamp()
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	struct tm* parts = std::localtime(&now_c);

	char str[20];

	sprintf(str, "%04d-%02d-%02dT%02d:%02d:%02d",
			1900 + parts->tm_year,
			1 + parts->tm_mon,
			parts->tm_mday,
			parts->tm_hour,
			parts->tm_min,
			parts->tm_sec
	);

	currentTimestamp = str;
}

void RRLog::DataStream::Write(const nlohmann::json& json, bool flush)
{
	UpdateTimestamp();

	const nlohmann::json completeJson = {
			{ "event",     json },
			{ "timestamp", currentTimestamp }
	};

	const std::string& jsonString = completeJson.dump() + "\n";
	//TODO check if this works for multibyte chars
	file.write(jsonString.c_str(), jsonString.length());

	if (flush)
	{
		file.flush();
	}
}

void RRLog::DataStream::Flush()
{
	file.flush();
}

void RRLog::DataStream::Close()
{
	file.close();
}
