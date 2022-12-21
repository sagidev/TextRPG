#include "Entity.h"

Entity::Entity(std::string name, std::string entity_class, int health,
	int attack, int defense, int level, int gold) {
	
	this->name = name;
	this->entity_class = entity_class;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->level = level;
	this->exp = 0;
	this->gold = gold;
	
	this->maxHealth = health;
	this->maxExp = 100;
}