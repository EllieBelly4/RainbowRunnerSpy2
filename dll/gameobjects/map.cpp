//
// Created by Sophie on 06/07/2021.
//

#include "map.h"
#include "../gui/views/viewhandlers/AvatarView.h"
#include "../gui/views/viewhandlers/UnknownView.h"
#include "gui/views/viewhandlers/StaticObjectView.h"

std::map<unsigned int, std::shared_ptr<RRSpyGUIBaseEntityWrapper>> EntityMap;

void InitialiseEntityMap()
{
	EntityMap[0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("UnknownEntity", new UnknownView());
	EntityMap[0x0089B468] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Player", new DFCNodeView());
	EntityMap[0x0086DE00] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Avatar", new AvatarView());
	EntityMap[0x0089a580] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Waypoint", new DFCNodeView());
	EntityMap[0x0087f228] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Skills", new DFCNodeView());
	EntityMap[0x00893040] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Equipment", new DFCNodeView());
	EntityMap[0x00892a70] = std::make_shared<RRSpyGUIBaseEntityWrapper>("UnitContainer", new DFCNodeView());
	EntityMap[0x008726b0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Modifiers", new DFCNodeView());
	EntityMap[0x008710e8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Manipulators", new DFCNodeView());
	EntityMap[0x00878fb8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("UnitBehavior", new DFCNodeView());
	EntityMap[0x0086f608] = std::make_shared<RRSpyGUIBaseEntityWrapper>("AvatarMetrics", new DFCNodeView());
	EntityMap[0x0089bb70] = std::make_shared<RRSpyGUIBaseEntityWrapper>("DialogManager", new DFCNodeView());
	EntityMap[0x0087ea00] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SkillProfession", new DFCNodeView());
	EntityMap[0x0087c430] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ActiveSkill", new DFCNodeView());
	EntityMap[0x0087d690] = std::make_shared<RRSpyGUIBaseEntityWrapper>("PassiveSkill", new DFCNodeView());
	EntityMap[0x00893490] = std::make_shared<RRSpyGUIBaseEntityWrapper>("MeleeWeapon", new DFCNodeView());
	EntityMap[0x00892050] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemModifier", new DFCNodeView());
	EntityMap[0x00892b88] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Armor", new DFCNodeView());
	EntityMap[0x00890768] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemAttributeModifier", new DFCNodeView());
	EntityMap[0x00871200] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Modifier", new DFCNodeView());
	EntityMap[0x00889eb8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("AttributeModifier", new DFCNodeView());
	EntityMap[0x0088f8c0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Inventory", new DFCNodeView());
	EntityMap[0x0088e158] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ActiveItem", new DFCNodeView());
	EntityMap[0x00869768] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WorldEntity", new DFCNodeView());
	EntityMap[0x008a7ce0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Entity", new DFCNodeView());
	EntityMap[0x008a8a48] = std::make_shared<RRSpyGUIBaseEntityWrapper>("GCObject", new DFCNodeView());
	EntityMap[0x0086e718] = std::make_shared<RRSpyGUIBaseEntityWrapper>("AvatarDesc", new DFCNodeView());
	EntityMap[0x008700c8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("HeroDesc", new DFCNodeView());
	EntityMap[0x00874df8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("UnitDesc", new DFCNodeView());
	EntityMap[0x00869d80] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WorldEntityDesc", new DFCNodeView());
	EntityMap[0x00869e20] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityDesc", new DFCNodeView());
	EntityMap[0x00869ce0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("GCObjectDesc", new DFCNodeView());
	EntityMap[0x0086f9c0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Hero", new DFCNodeView());
	EntityMap[0x00874500] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Unit", new DFCNodeView());
	EntityMap[0x00898160] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Effect", new DFCNodeView());
	EntityMap[0x0086b370] = std::make_shared<RRSpyGUIBaseEntityWrapper>("LOSChecker", new DFCNodeView());
	EntityMap[0x00866bd8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityObject", new DFCNodeView());
	EntityMap[0x008a7dd0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityComponent", new DFCNodeView());
	EntityMap[0x0087f3b0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SkillsDesc", new DFCNodeView());
	EntityMap[0x0087f450] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityComponentDesc", new DFCNodeView());
	EntityMap[0x00879208] = std::make_shared<RRSpyGUIBaseEntityWrapper>("UnitBehaviorDesc", new DFCNodeView());
	EntityMap[0x00877168] = std::make_shared<RRSpyGUIBaseEntityWrapper>("BehaviorDesc", new DFCNodeView());
	EntityMap[0x00877048] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Behavior", new DFCNodeView());
	EntityMap[0x00893130] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EquipmentDesc", new DFCNodeView());
	EntityMap[0x00893240] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EquipmentSlot", new DFCNodeView());
	EntityMap[0x00892cb0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ArmorDesc", new DFCNodeView());
	EntityMap[0x00890b88] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemDesc", new DFCNodeView());
	EntityMap[0x00870a60] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ManipulatorDesc", new DFCNodeView());
	EntityMap[0x00889f98] = std::make_shared<RRSpyGUIBaseEntityWrapper>("AttributeModifierDesc", new DFCNodeView());
	EntityMap[0x0086d3f0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Attribute", new DFCNodeView());
	EntityMap[0x008a2d98] = std::make_shared<RRSpyGUIBaseEntityWrapper>("CurveTable", new DFCNodeView());
	EntityMap[0x008935e0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("MeleeWeaponDesc", new DFCNodeView());
	EntityMap[0x00894100] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WeaponDesc", new DFCNodeView());
	EntityMap[0x00892288] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemModifierDesc", new DFCNodeView());
	EntityMap[0x00890860] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemAttributeModifierDesc", new DFCNodeView());
	EntityMap[0x0088f428] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Container", new DFCNodeView());
	EntityMap[0x0088fc80] = std::make_shared<RRSpyGUIBaseEntityWrapper>("InventoryDesc", new DFCNodeView());
	EntityMap[0x0088e2f8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Item", new DFCNodeView());
	EntityMap[0x008707d8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Manipulator", new DFCNodeView());
	EntityMap[0x0088e4d0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ActiveItemDesc", new DFCNodeView());
	EntityMap[0x0087fda0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SpellEffect", new DFCNodeView());
	EntityMap[0x008838f8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SpellModEffect", new DFCNodeView());
	EntityMap[0x008853c8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SpellSoundEffect", new DFCNodeView());
	EntityMap[0x00871a58] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ModifierDesc", new DFCNodeView());
	EntityMap[0x00867c60] = std::make_shared<RRSpyGUIBaseEntityWrapper>("MountedVisual", new DFCNodeView());
	EntityMap[0x00867bb8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Visual", new DFCNodeView());
	EntityMap[0x0087f500] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SkillSlot", new DFCNodeView());
	EntityMap[0x0087eaa0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SkillProfessionDesc", new DFCNodeView());
	EntityMap[0x00893dd8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("Weapon", new DFCNodeView());
	EntityMap[0x008A8114] = std::make_shared<RRSpyGUIBaseEntityWrapper>("GCClass", new DFCNodeView());
	EntityMap[0x00898370] = std::make_shared<RRSpyGUIBaseEntityWrapper>("EffectDesc", new DFCNodeView());
	EntityMap[0x0089EF18] = std::make_shared<RRSpyGUIBaseEntityWrapper>("QuestManager", new DFCNodeView());
	EntityMap[0x00868cd0] = std::make_shared<RRSpyGUIBaseEntityWrapper>("World", new DFCNodeView());
	EntityMap[0x0086ad58] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WorldMap", new DFCNodeView());
	EntityMap[0x0086bc28] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WorldObjectGroup", new DFCNodeView());
	EntityMap[0x008676e8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("StaticObject", new StaticObjectView());
	EntityMap[0x0086a730] = std::make_shared<RRSpyGUIBaseEntityWrapper>("WorldLight", new DFCNodeView());
	EntityMap[0x00897010] = std::make_shared<RRSpyGUIBaseEntityWrapper>("AmbientSound", new DFCNodeView());
	EntityMap[0x0088da10] = std::make_shared<RRSpyGUIBaseEntityWrapper>("SoundEnvironment", new DFCNodeView());
	EntityMap[0x008a7c18] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ClientEntityManager",
			new ClientEntityManagerView());
	EntityMap[0x00872940] = std::make_shared<RRSpyGUIBaseEntityWrapper>("StockUnit", new EntityView());
	EntityMap[0x00877FD8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("MonsterBehavior2", new DFCNodeView());
	EntityMap[0x00867818] = std::make_shared<RRSpyGUIBaseEntityWrapper>("StaticObjectDesc", new DFCNodeView());
	EntityMap[0x008B4120] = std::make_shared<RRSpyGUIBaseEntityWrapper>("DFC3DNode", new DFCNodeView());
	EntityMap[0x008B46BC] = std::make_shared<RRSpyGUIBaseEntityWrapper>("DFC3DChannelArray", new DFCNodeView());
	EntityMap[0x008B46BC] = std::make_shared<RRSpyGUIBaseEntityWrapper>("DFC3DChannelArray", new DFCNodeView());
	EntityMap[0x008928c8] = std::make_shared<RRSpyGUIBaseEntityWrapper>("ItemObject", new DFCNodeView());
}

std::shared_ptr<RRSpyGUIBaseEntityWrapper> GetEntityWrapper(void* vftable)
{
	if (EntityMap.contains((unsigned int)vftable))
	{
		return EntityMap.at((unsigned int)vftable);
	}

	return EntityMap.at(0);
}