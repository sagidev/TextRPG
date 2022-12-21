#pragma once
#include <string>
class Entity {
public:
	Entity(std::string name = "", std::string entity_class = "NPC", int health = 0,
		int attack = 0, int defense = 0, int level = 1, int gold = 0);
	std::string GetName() {
		return name;
	}
	int GetLevel() {
		return level;
	}
	int SetLevel(int i) {
		this->level = i;
	}
	int GetHealth() {
		return health;
	}
	int SetHealth(int i) {
		this->health = i;
	}
	int GetMaxHealth() {
		return maxHealth;
	}
	int SetMaxHealth(int i) {
		this->maxHealth = i;
	}
	int GetExp() {
		return exp;
	}
	int SetExp(int i) {
		this->exp = i;
	}
	int GetMaxExp() {
		return maxExp;
	}
	int SetMaxExp(int i) {
		this->maxExp = i;
	}
private:
	std::string name;
	std::string entity_class;
	int health;
	int maxHealth;
	int attack;
	int defense;
	int speed;
	int level;
	int exp;
	int maxExp;
	int gold;
};