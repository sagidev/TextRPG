#pragma once
#include "Item.h"
class Armor : public Item {
public:
	Armor(const std::string& name, int id, int defense, item_rarity rr)
		: Item(name, id, armor, rr), defense(defense) {}
	int getArmor(void) const { return this->defense; }
	int getPower() {
		return defense;
	}
private:
	int defense;
};