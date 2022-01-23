//
// Created by Sophie on 06/07/2021.
//

#include "ClientEntityManagerView.h"
#include "../../../common.h"
#include "../../general/structs.h"
#include "../../../gameobjects/map.h"
#include "../../../state.h"


void ClientEntityManagerView::RenderListItem(ClientEntityManager* pEntity, int i)
{
	const char* label = "ClientEntityManager";
	ImGuiID id = ImGui::GetID(label);

	if (RenderSelectableListItem(i, label, id) == ListItemClicked)
	{
		state->SetSelectedEntity(GetEntityWrapper(pEntity->VFTable), pEntity, id);
	}
}

void ClientEntityManagerView::RenderProperties(ClientEntityManager* pEntity)
{
	AddHeading("ClientEntityManager");

	if (BeginFullPropertyTable("ClientEntityManager"))
	{
		RenderPropertyWithHex("TickInterval", (unsigned int*)((unsigned int)pEntity + 0xa80));
		RenderPropertyWithHex("UnkRelatedToTicksMaybe", (unsigned int*)((unsigned int)pEntity + 0xa84));
		RenderPropertyWithHex("something_server_time_related_maybe", (unsigned int*)((unsigned int)pEntity + 0xa88));
		RenderPropertyWithHex("TimeSinceLastTick", (unsigned int*)((unsigned int)pEntity + 0xa8C));
		RenderPropertyWithHex("another_update_number", (unsigned int*)((unsigned int)pEntity + 0xa90));
		RenderPropertyWithHex("update_number", (unsigned int*)((unsigned int)pEntity + 0xa94));

		RenderPropertyWithHex("SystemTime", &pEntity->SystemTime);
		RenderPropertyWithHex("Frame_or_RNG?", &pEntity->FrameThisSecond);
		RenderPropertyWithHex("TicksWithoutServerResponse", &pEntity->TicksWithoutServerResponse);
		RenderPropertyWithHex("ServerTick", &pEntity->ServerTick);
		RenderPropertyWithHex("ProcessedMessagesThisMove", &pEntity->ProcessedMessagesThisMove);
		RenderPropertyWithHex("UpdateMessagesInQueue", &pEntity->UpdateMessagesInQueue);

		RenderPropertyWithHex("Unk0", &pEntity->Unk0);
		RenderPropertyWithHex("Unk1", &pEntity->Unk1);
		RenderPropertyWithHex("Unk2", &pEntity->Unk2);
		RenderPropertyWithHex("World", (unsigned int*)&pEntity->World);
		RenderPropertyWithHex("Unk4", &pEntity->Unk4);
		RenderPropertyWithHex("Unk5", &pEntity->Unk5);
		RenderPropertyWithHex("Unk6", &pEntity->Unk6);
		RenderPropertyWithHex("SoundEnvironment", &pEntity->SoundEnvironment);
		RenderPropertyWithHex("Unk8", &pEntity->Unk8);
		RenderPropertyWithHex("Unk9", &pEntity->Unk9);
		RenderPropertyWithHex("EventSystemVFTable", (unsigned int*)&pEntity->EventSystemVFTable);
		RenderPropertyWithHex("Unk11", &pEntity->Unk11);
		RenderPropertyWithHex("Unk12", &pEntity->Unk12);
		RenderPropertyWithHex("SomeMap", &pEntity->SomeMap);
		RenderPropertyWithHex("Unk14", &pEntity->Unk14);
		RenderPropertyWithHex("LinkBufferVFTable", (unsigned int*)&pEntity->LinkBufferVFTable);
		RenderPropertyWithHex("Unk16", &pEntity->Unk16);
		RenderPropertyWithHex("Unk17", &pEntity->Unk17);
		RenderPropertyWithHex("Unk18", &pEntity->Unk18);
		RenderPropertyWithHex("Unk19", &pEntity->Unk19);
		RenderPropertyWithHex("unk_20", &pEntity->unk_20);
		RenderPropertyWithHex("unk_21", &pEntity->unk_21);
		RenderPropertyWithHex("unk_22", &pEntity->unk_22);
		RenderPropertyWithHex("unk_23", &pEntity->unk_23);
		RenderPropertyWithHex("unk_24", &pEntity->unk_24);
		RenderPropertyWithHex("unk_25", &pEntity->unk_25);
		RenderPropertyWithHex("ManagerChannel", &pEntity->ManagerChannel);
		RenderPropertyWithHex("unk_27", &pEntity->unk_27);
		RenderPropertyWithHex("unk_28", &pEntity->unk_28);
		RenderPropertyWithHex("EntityList", (unsigned int*)&pEntity->EntityList);
		RenderPropertyWithHex("BufferStart", (unsigned int*)&pEntity->Unk);
		RenderPropertyWithHex("ComponentList", (unsigned int*)&pEntity->ComponentList);
		RenderPropertyWithHex("unk_42", &pEntity->unk_42);
		RenderPropertyWithHex("unk_44", &pEntity->unk_44);
		RenderPropertyWithHex("unk_45", &pEntity->unk_45);
		RenderPropertyWithHex("unk_46", &pEntity->unk_46);
		RenderPropertyWithHex("unk_47", &pEntity->unk_47);
		RenderPropertyWithHex("unk_48", &pEntity->unk_48);
		RenderPropertyWithHex("unk_49", &pEntity->unk_49);
		RenderPropertyWithHex("unk_increases_slowly", &pEntity->unk_increases_slowly);
		RenderPropertyWithHex("unk_51", &pEntity->unk_51);
		RenderPropertyWithHex("unk_52", &pEntity->unk_52);
		RenderPropertyWithHex("unk_53", &pEntity->unk_53);
		RenderPropertyWithHex("unk_54", &pEntity->unk_54);
		RenderPropertyWithHex("unk_55", &pEntity->unk_55);
		RenderPropertyWithHex("unk_56", &pEntity->unk_56);
		RenderPropertyWithHex("unk_57", &pEntity->unk_57);
		RenderPropertyWithHex("unk_58", &pEntity->unk_58);
		RenderPropertyWithHex("unk_59", &pEntity->unk_59);
		RenderPropertyWithHex("unk_60", &pEntity->unk_60);
		RenderPropertyWithHex("unk_61", &pEntity->unk_61);
		RenderPropertyWithHex("unk_62", &pEntity->unk_62);
		RenderPropertyWithHex("unk_63", &pEntity->unk_63);
		RenderPropertyWithHex("unk_64", &pEntity->unk_64);
		RenderPropertyWithHex("unk_65", &pEntity->unk_65);
		RenderPropertyWithHex("unk_66", &pEntity->unk_66);
		RenderPropertyWithHex("unk_67", &pEntity->unk_67);
		RenderPropertyWithHex("unk_68", &pEntity->unk_68);
		RenderPropertyWithHex("unk_69", &pEntity->unk_69);
		RenderPropertyWithHex("unk_70", &pEntity->unk_70);
		RenderPropertyWithHex("unk_71", &pEntity->unk_71);
		RenderPropertyWithHex("unk_72", &pEntity->unk_72);
		RenderPropertyWithHex("unk_73", &pEntity->unk_73);
		RenderPropertyWithHex("unk_74", &pEntity->unk_74);
		RenderPropertyWithHex("unk_75", &pEntity->unk_75);
		RenderPropertyWithHex("unk_76", &pEntity->unk_76);
		RenderPropertyWithHex("unk_77", &pEntity->unk_77);
		RenderPropertyWithHex("unk_78", &pEntity->unk_78);
		RenderPropertyWithHex("unk_79", &pEntity->unk_79);
		RenderPropertyWithHex("unk_80", &pEntity->unk_80);
		RenderPropertyWithHex("unk_81", &pEntity->unk_81);
		RenderPropertyWithHex("unk_82", &pEntity->unk_82);
		RenderPropertyWithHex("unk_83", &pEntity->unk_83);
		RenderPropertyWithHex("unk_84", &pEntity->unk_84);
		RenderPropertyWithHex("unk_85", &pEntity->unk_85);
		RenderPropertyWithHex("unk_86", &pEntity->unk_86);
		RenderPropertyWithHex("unk_87", &pEntity->unk_87);
		RenderPropertyWithHex("unk_88", &pEntity->unk_88);
		RenderPropertyWithHex("unk_89", &pEntity->unk_89);
		RenderPropertyWithHex("unk_90", &pEntity->unk_90);
		RenderPropertyWithHex("unk_91", &pEntity->unk_91);
		RenderPropertyWithHex("unk_92", &pEntity->unk_92);
		RenderPropertyWithHex("unk_93", &pEntity->unk_93);
		RenderPropertyWithHex("unk_94", &pEntity->unk_94);
		RenderPropertyWithHex("unk_95", &pEntity->unk_95);
		RenderPropertyWithHex("unk_96", &pEntity->unk_96);
		RenderPropertyWithHex("unk_97", &pEntity->unk_97);
		RenderPropertyWithHex("unk_98", &pEntity->unk_98);
		RenderPropertyWithHex("unk_100", &pEntity->unk_100);
		RenderPropertyWithHex("unk_101", &pEntity->unk_101);
		RenderPropertyWithHex("unk_102", &pEntity->unk_102);
		RenderPropertyWithHex("unk_103", &pEntity->unk_103);
		RenderPropertyWithHex("unk_104", &pEntity->unk_104);
		RenderPropertyWithHex("unk_105", &pEntity->unk_105);
		RenderPropertyWithHex("unk_106", &pEntity->unk_106);
		RenderPropertyWithHex("unk_107", &pEntity->unk_107);
		RenderPropertyWithHex("unk_108", &pEntity->unk_108);
		RenderPropertyWithHex("unk_109", &pEntity->unk_109);
		RenderPropertyWithHex("unk_110", &pEntity->unk_110);
		RenderPropertyWithHex("unk_111", &pEntity->unk_111);
		EndPropertyTable();
	}
}

void ClientEntityManagerView::RenderProperties(void* pVoid)
{
	ClientEntityManagerView::RenderProperties((ClientEntityManager*)pVoid);
}
