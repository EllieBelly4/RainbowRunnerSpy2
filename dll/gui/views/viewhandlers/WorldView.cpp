//
// Created by Sophie on 06/07/2021.
//

#include "WorldView.h"
#include <gameobjects/World.h>
#include "DFCNodeView.h"

void WorldView::RenderProperties(World* pEntity)
{
	if (BeginFullPropertyTable("world"))
	{
		if (!IsBadReadPtr(pEntity->MapName))
		{
			RenderProperty("MapName", pEntity->MapName->ToString());
		}
		else
		{
			RenderProperty("MapName", "Unknown");
		}

		ImGui::TableNextRow();

		RenderPropertyWithHex("Unk25", &pEntity->Unk25);
		RenderPropertyWithHex("Unk26", &pEntity->Unk26);
		RenderPropertyWithHex("Unk27", &pEntity->Unk27);
		RenderPropertyWithHex("Unk28", &pEntity->Unk28);
		RenderPropertyWithHex("Unk29", &pEntity->Unk29);
		RenderPropertyWithHex("Unk30", &pEntity->Unk30);
		RenderPropertyWithHex("Unk31", &pEntity->Unk31);
		RenderPropertyWithHex("Unk32", &pEntity->Unk32);
		RenderPropertyWithHex("Unk33", &pEntity->Unk33);
		RenderPropertyWithHex("Unk34", &pEntity->Unk34);
		RenderPropertyWithHex("Unk35", &pEntity->Unk35);
		RenderPropertyWithHex("Unk36", &pEntity->Unk36);
		RenderPropertyWithHex("Unk37", &pEntity->Unk37);
		RenderPropertyWithHex("Unk38", &pEntity->Unk38);
		RenderPropertyWithHex("Unk39", &pEntity->Unk39);
		RenderPropertyWithHex("Unk40", &pEntity->Unk40);
		RenderPropertyWithHex("Unk41", &pEntity->Unk41);
		RenderPropertyWithHex("Unk42", &pEntity->Unk42);
		RenderPropertyWithHex("Unk43", &pEntity->Unk43);
		RenderPropertyWithHex("Unk44", &pEntity->Unk44);
		RenderPropertyWithHex("Unk45", &pEntity->Unk45);
		RenderPropertyWithHex("Unk46", &pEntity->Unk46);
		RenderPropertyWithHex("Unk47", &pEntity->Unk47);
		RenderPropertyWithHex("Unk48", &pEntity->Unk48);
		RenderPropertyWithHex("Unk49", &pEntity->Unk49);
		RenderPropertyWithHex("Unk50", &pEntity->Unk50);
		RenderPropertyWithHex("Unk51", &pEntity->Unk51);
		RenderPropertyWithHex("Unk52", &pEntity->Unk52);
		RenderPropertyWithHex("Unk53", &pEntity->Unk53);
		RenderPropertyWithHex("Unk54", &pEntity->Unk54);
		RenderPropertyWithHex("Unk55", &pEntity->Unk55);
		RenderPropertyWithHex("Unk56", &pEntity->Unk56);
		RenderPropertyWithHex("Unk57", &pEntity->Unk57);
		RenderPropertyWithHex("Unk58", &pEntity->Unk58);

		EndPropertyTable();
	}
}

void WorldView::RenderListItem(World* pEntity, int)
{
}

void WorldView::RenderProperties(void* pVoid)
{
	pVoid = GetCurrentSuperclassNode((DFCNode*)pVoid);
	RenderProperties((World*)pVoid);
	DFCNodeView::RenderProperties((DFCNode*)pVoid);
}
