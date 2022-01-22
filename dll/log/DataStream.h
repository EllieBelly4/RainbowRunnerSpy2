//
// Created by Sophie on 22/01/2022.
//

#include <fstream>
#include <nlohmann/json.hpp>

#ifndef RRSPY2TESTAPP_DATASTREAM_H
#define RRSPY2TESTAPP_DATASTREAM_H

namespace RRLog
{
	class DataStream
	{

	public:
		explicit DataStream(const char* logRoot) : logRoot(std::move(logRoot))
		{
		};

		~DataStream(){
		}

		void Write(const nlohmann::json& json, bool flush = true);
		void Flush();
		void Close();

		std::string OpenTimed();

	private:
		std::string logRoot;
		std::ofstream file;
		std::string currentTimestamp{};

		void UpdateTimestamp();
	};
}

#endif //RRSPY2TESTAPP_DATASTREAM_H
