#include "Entity.h"

Entity::Entity(std::string name, std::string entity_class, int health,
	int attack, int defense, int level, int gold) {
	

	if (entity_class == "NPC") {
		this->entity_class = entity_class;
		this->health = health;
		this->attack = attack;
		this->defense = defense;
	}

	if (entity_class == "warrior") {
		this->entity_class = entity_class;
		this->health = 150;
		this->attack = 10;
		this->defense = 20;
	}
	

	this->name = name;
	this->level = level;
	this->exp = 0;
	this->gold = gold;
	
	this->maxHealth = this->health;
	this->maxExp = 100;
}