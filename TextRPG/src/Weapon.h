#pragma once
#include "Item.h"
class Weapon : public Item {
public:
	Weapon(const std::string& name, int id, int damage, int critChance, int critDamage)
		: Item(name, id), damage(damage), critChance(critChance), critDamage(critDamage) {}
	int getDamage(void) const { return this->damage; }
private:
	int damage;
	int critChance;
	int critDamage;
};