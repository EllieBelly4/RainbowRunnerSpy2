//
// Created by Sophie on 22/01/2022.
//

#include "MemoryDataStream.h"
#include "common.h"

#include <utility>

void RRLog::MemoryDataStream::Watch(std::string name, unsigned int address, unsigned int size)
{
	for (auto watch: *watches)
	{
		if (watch->address == address)
		{
			logger->Write("Already streaming " + std::to_string(address));
			return;
		}
	}

	std::shared_ptr<MemoryWatch> watch = std::make_shared<MemoryWatch>();

	watch->name = std::move(name);
	watch->address = address;
	watch->size = size;
	watch->enabled = true;
	watch->initial = true;

	watches->push_back(watch);
}

void RRLog::MemoryDataStream::Tick(unsigned int frame)
{
	std::stringstream hexBuf;

	for (auto i = 0; i < watches->size(); i++)
	{
		hexBuf.str("");
		hexBuf.clear();

		auto watch = watches->at(i);

		if (!watch->enabled)
		{
			continue;
		}

		if (IsBadReadPtr((void*)watch->address))
		{
			watch->enabled = false;
			continue;
		}

		char value[watch->size];

		memcpy(value, (void*)watch->address, watch->size);

		bool different = false;

		for (auto j = 0; j < watch->size; j++)
		{
			if ((!different && watch->initial) || (!watch->initial && value[j] != watch->lastValue[j]))
			{
				different = true;
			}

			hexBuf << std::hex << std::setfill('0') << std::setw(2) << (int)(BYTE)value[j];
		}

		memcpy(watch->lastValue, value, watch->size);

		if (!different)
		{
			continue;
		}

		dataStream->Write({
				{ "name",  watch->name },
				{ "frame", frame },
				{ "value", hexBuf.str() }
		}, false);

		watch->initial = false;
	}

	dataStream->Flush();
}

