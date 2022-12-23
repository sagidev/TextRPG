#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	Weapon(const std::string& name, int id, int damage, int critChance, int critDamage, item_rarity rar)
		: Item(name, id, weapon, rar), damage(damage), critChance(critChance), critDamage(critDamage), rarity(rar) {}
	
	int getDamage(void) const { 
		if (rarity == common) {
			return damage * 1;
		}
		else if (rarity == uncommon) {
			return damage * 1.2;
		}
		else if (rarity == rare) {
			return damage * 1.3;
		}
		else if (rarity == legendary) {
			return damage * 1.5;
		}
	}
	int getPower() {
		return getDamage() + critChance + critDamage;
	}
	int getLevel() {
		return level;
	}
	item_rarity getRarity() {
		return rarity;
	}
private:
	item_rarity rarity;
	int level = 0;
	int damage;
	int critChance;
	int critDamage;
};