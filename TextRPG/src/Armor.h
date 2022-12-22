#pragma once
#include "Item.h"
class Armor : public Item {
public:
	Armor(const std::string& name, int id, int defense)
		: Item(name, id, armor), defense(defense) {}
	int getArmor(void) const { return this->defense; }
private:
	int defense;
};