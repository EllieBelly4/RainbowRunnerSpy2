//
// Created by Sophie on 28/06/2021.
//

#include "DFCNode.h"
#include "../map.h"

const std::vector<char*> GetEntityProperties()
{
	static const std::vector<char*> properties{
			(char*)"VFTable",
			(char*)"ref",
			(char*)"unk_0",
			(char*)"unk_1",
			(char*)"unk_2",
			(char*)"Parent",
			(char*)"FirstChild",
			(char*)"LastChild",
			(char*)"NextSibling",
			(char*)"PreviousSibling",
			(char*)"unk_8",
			(char*)"unk_9",
			(char*)"VFTableIEventHandler",
			(char*)"GCProperties",
			(char*)"unk_12",
			(char*)"VFTableEventSystem",
			(char*)"unk_14",
			(char*)"unk_15",
			(char*)"unk_16",
			(char*)"unk_17",
			(char*)"unk_18",
			(char*)"SuperClass",
			(char*)"GCClass",
			(char*)"Desc",
			(char*)"unk_22",
			(char*)"unk_23",
			(char*)"unk_24",
			(char*)"unk_25",
			(char*)"ManagerChannel",
			(char*)"unk_27",
			(char*)"unk_28",
			(char*)"EntityList",
			(char*)"unk_30",
			(char*)"unk_31",
	};

	return properties;
}

std::string DFCNode::GetTypeString() const
{
	auto vftable = reinterpret_cast<unsigned int>(VFTable);

	if (!IsBadReadPtr((void*)vftable) && EntityMap.contains(vftable))
	{
		return EntityMap.at(vftable)->Name;
	}

	char hexStr[128];

	sprintf(hexStr, "Unknown VFTable 0x%08X", vftable);

//    logger->Write(hexStr);
	return "";
}

void DFCNode::WalkChildren(const std::function<void(DFCNode*)>& callback) const
{
	auto* currentChild = FirstChild;

	while (currentChild != nullptr && !IsBadReadPtr(currentChild))
	{
		currentChild->WalkChildren(callback);

		callback(currentChild);
		currentChild = currentChild->NextSibling;
	}
}
