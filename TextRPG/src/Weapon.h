#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	std::string names[6] = { "Copper", "Stone", "Wooden","Cobalt","Dirt","Grass", };
	std::string namestype[3] = {"Sword", "Blade", "Axe"};

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
	int getCritChance() {
		return critChance;
	}
	int getCritDamage(){
		return critDamage; 
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
	void setRandomName() {
		int na = rand() % 5 + 0;
		int na1 = rand() % 2 + 0;
		this->setName(names[na] + " " + namestype[na1]);
	}
private:
	item_rarity rarity;
	int level = 0;
	int damage;
	int critChance;
	int critDamage;
};