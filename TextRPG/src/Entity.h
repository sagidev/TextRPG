#pragma once
#include <string>
#include <iostream>
#include "Inventory.h"
#include "../externals/color.h"
class Entity {
public:

	Inventory inventory;

	Entity(std::string name = "", std::string entity_class = "NPC", int health = 0,
		int attack = 0, int defense = 0, int level = 1, int gold = 0);

	/// <summary>
	/// Final hit after defeating enemy
	/// </summary>
	/// <param name="enemy">Enemy</param>
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
		this->gold += enemy.GetGold();
	}

	/// <summary>
	/// Show all the info about entity
	/// </summary>
	void ShowStats() {
		std::cout << "\n ----[" << dye::yellow(GetName()) << "]-[" << dye::green (GetOverallPower()) << "]-[Level:" << dye::green(this->level) << "]-----------------" << std::endl;
		if (entity_class != "NPC")
		{
			ShowExpBar();
		}
			
		std::cout << " Class: " << this->entity_class << std::endl;
		std::cout << " Health: " << dye::red(this->health) << "/" << dye::red(this->maxHealth) << std::endl;
		std::cout << " Damage: " << dye::light_red(GetDamage()) << " | Defense: " << dye::aqua(GetFullDefense()) << std::endl;
		std::cout << " Gold: " << dye::yellow(GetGold()) << std::endl;
		std::cout << "--------------------------------------------" << std::endl;

	}

	void SpendGold(int i) {
		this->gold -= i;
	}

	std::string GetName() {
		return name;
	}
	int GetGold() {
		return gold;
	}
	void SetGold(int i) {
		gold = i;
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
	};
	void SetCrit(int i) {
		this->crit = i;
	}
	int GetCrit() {
		return this->crit;
	}
	bool IsCrit() {
		if (rand() % 100 < this->crit) {
			return true;
		}
		else {
			return false;
		}
	}

	int GetDamage() {
		int damage = this->attack + inventory.GetWeaponDamage();
		if (IsCrit()) {
			damage *= 2;
			std::cout << "CRITICAL HIT!" << std::endl;
		}
		return damage;
	}

	int GetFullDefense() {
		return this->defense + inventory.GetArmorDefense();
	}

	void ShowExpBar() {
		int expBarSize = 20;
		int expBarProgress = (expBarSize * exp) / maxExp;
		std::cout << " Exp: [";
		for (int i = 0; i < expBarSize; i++) {
			if (i < expBarProgress) {
				std::cout << "#";
			}
			else {
				std::cout << "-";
			}
		}
		std::cout << "] " << exp << "/" << maxExp  << std::endl;
	}
	
	void Attack(Entity &enemy)
	{
		int damage = GetDamage();
		enemy.SetHealth(enemy.GetHealth() - (damage - enemy.GetDefense()));
		std::cout << this->name << " attacked " << enemy.GetName() << " for " << (damage - enemy.GetDefense()) << " damage!" << std::endl;
		if (enemy.GetHealth() <= 0) {
			KillEnemy(enemy);
		}
	}

	int GetOverallPower()
	{
		return GetDamage() + GetFullDefense();
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
	int crit;
	int overallPower;
};