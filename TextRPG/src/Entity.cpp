#include "Entity.h"

Entity::Entity(std::string name, std::string entity_class, int health,
	int attack, int defense, int level, int gold) {
	

	if (entity_class == "NPC") {
		this->entity_class = entity_class;
		this->health = health;
		this->attack = attack;
		this->defense = defense;

		Weapon weapon("", 1, 5, 1, 1,item_rarity::common);
		weapon.setRandomName();
		inventory.AddWeapon(weapon);
		inventory.equippedWeaponID = 0;
		Armor armor("Newbie Armor", 1, 1, item_rarity::common);
		inventory.AddArmor(armor);
		inventory.equippedArmorID = 0;
	}

	else if (entity_class == "Warrior") {
		this->entity_class = entity_class;
		this->health = 150;
		this->attack = 20;
		this->defense = 20;
		
		Weapon weapon("Newbie Sword", 1, 25, 1, 1, item_rarity::common);
		inventory.AddWeapon(weapon);
		inventory.equippedWeaponID = 0;
		Armor armor("Newbie Armor", 1, 1, item_rarity::common);
		inventory.AddArmor(armor);
		inventory.equippedArmorID = 0;
	}
	

	this->name = name;
	this->level = level;
	this->exp = 0;
	this->gold = gold;
	
	this->maxHealth = this->health;
	this->maxExp = 100;
}