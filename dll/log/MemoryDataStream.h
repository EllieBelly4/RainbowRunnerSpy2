//
// Created by Sophie on 22/01/2022.
//

#ifndef RRSPY2TESTAPP_MEMORYDATASTREAM_H
#define RRSPY2TESTAPP_MEMORYDATASTREAM_H

#include "DataStream.h"

namespace RRLog
{
	struct MemoryWatch
	{
		std::string name;
		unsigned int address;
		unsigned int size;
		bool enabled;
		char lastValue[128];
		bool initial;
	};

	class MemoryDataStream
	{
	public:
		MemoryDataStream(
				const std::shared_ptr<DataStream>& dataStream
		) : dataStream(dataStream)
		{
			watches = std::make_unique<std::vector<std::shared_ptr<MemoryWatch>>>();
		};

		void Watch(std::string name, unsigned int address, unsigned int size);

		void Tick(unsigned int frame);

	private:
		std::shared_ptr<DataStream> dataStream;
		std::unique_ptr<std::vector<std::shared_ptr<MemoryWatch>>> watches;
	};
}


#endif //RRSPY2TESTAPP_MEMORYDATASTREAM_H
