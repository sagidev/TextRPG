#pragma once
#include <string>
#include <iostream>
class Entity {
public:
	Entity(std::string name = "", std::string entity_class = "NPC", int health = 0,
		int attack = 0, int defense = 0, int level = 1, int gold = 0);

	void KillEnemy(Entity enemy) {
		this->exp += enemy.GetExp();
		if (this->exp >= this->maxExp) {
			this->level++;
			this->exp = 0;
			this->maxExp += 10;
			this->maxHealth += 10;
			this->health = this->maxHealth;
			this->attack += 1;
			this->defense += 1;
		}
	}

	void ShowStats() {
		std::cout << " Name: " << this->name << std::endl;
		std::cout << " Class: " << this->entity_class << std::endl;
		std::cout << " Health: " << this->health << "/" << this->maxHealth << std::endl;
		std::cout << " Attack: " << this->attack << std::endl;
		std::cout << " Defense: " << this->defense << std::endl;
		std::cout << " Level: " << this->level << std::endl << std::endl;
	}

	std::string GetName() {
		return name;
	}
	int GetLevel() {
		return level;
	}
	void SetLevel(int i) {
		this->level = i;
	}
	int GetHealth() {
		return health;
	}
	void SetHealth(int i) {
		this->health = i;
	}
	int GetMaxHealth() {
		return maxHealth;
	}
	void SetMaxHealth(int i) {
		this->maxHealth = i;
	}
	int GetExp() {
		return exp;
	}
	void SetExp(int i) {
		this->exp = i;
	}
	int GetMaxExp() {
		return maxExp;
	}
	void SetMaxExp(int i) {
		this->maxExp = i;
	}
	
	void SetAttack(int i) {
		this->attack = i;
	}
	int GetAttack() {
		return this->attack;
	}
	void SetDefense(int i) {
		this->defense = i;
	}
	int GetDefense()
	{
		return this->defense;
	}
	void Attack(Entity enemy)
	{
		enemy.SetHealth(enemy.GetHealth() - (this->attack - enemy.GetDefense()));
		std::cout << this->name << " attacked " << enemy.GetName() << " for " << (this->attack - enemy.GetDefense()) << " damage!" << std::endl;
		if (enemy.GetHealth() <= 0) {
			KillEnemy(enemy);
		}
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