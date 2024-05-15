#pragma once
#include "pch.h"


struct StackActiveSpells
{
	H3Vector<INT32> activeSpellsId;
};

class CreatureDlgHandler
{
	H3CreatureInfoDlg* dlg = nullptr;
	bool expOn = false;
	H3CombatCreature* stack = nullptr;
public:

	CreatureDlgHandler(H3CreatureInfoDlg* dlg, H3CombatCreature* stack);

	bool SetWitdt;
	bool AlignItems();
	bool AddExperienceButton();
	bool AddSpellEfects();
	bool AddCommanderSkills();
};
