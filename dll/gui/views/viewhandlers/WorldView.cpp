//
// Created by Sophie on 06/07/2021.
//

#include "WorldView.h"
#include <gameobjects/World.h>
#include "DFCNodeView.h"

void WorldView::RenderProperties(World* pEntity)
{
	if (BeginFullPropertyTable("entity"))
	{
		RenderPropertyWithHex("unk_0", &pEntity->unk_0);

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
