//
// Created by Sophie on 28/06/2021.
//

#ifndef RRSPY2TESTAPP_DFCNODE_H
#define RRSPY2TESTAPP_DFCNODE_H

#include <vector>
#include <functional>
#include <string>
#include "GCClass.h"
#include "../EntityManager.h"
#include "../../datatypes/GCProperties.h"

class DFCNode
{
public:
	void* VFTable;
	unsigned int ref;
	unsigned int unk_0; // 0x8
	unsigned int unk_1; // 0xc
	unsigned int Inventory; // 0x10
	DFCNode* Parent; // 0x14
	DFCNode* FirstChild; // 0x18
	DFCNode* LastChild; // 0x1c
	DFCNode* NextSibling; // 0x20
	DFCNode* PreviousSibling; // 0x24
	unsigned int unk_8; // 0x28
	unsigned int unk_9; // 0x2c
	unsigned int VFTableIEventHandler; // 0x30
	GCProperties* GCProperties; // 0x34
	unsigned int unk_12; // 0x38
	unsigned int VFTableEventSystem; // 0x3c
	unsigned int unk_14; // 0x40
	unsigned int unk_15; // 0x44
	unsigned int unk_16; // 0x48
	unsigned int unk_17; // 0x4c
	unsigned int unk_18; // 0x50
	DFCNode* SuperClass; // 0x54
	GCClass* GCClass; // 0x58
	DFCNode* Desc; // 0x5c
	unsigned int unk_22; // 0x60
	unsigned int unk_23; // 0x64

	std::string GetTypeString() const;

	void WalkChildren(const std::function<void(DFCNode*)>&) const;
};

const std::vector<char*> GetEntityProperties();

#endif