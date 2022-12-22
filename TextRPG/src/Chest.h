#pragma once
#include <string>
#include "Armor.h"
#include "Weapon.h"
enum chest_rarity { common, uncommon, rare, legendary };

class Chest {
public:
	Chest(std::string name, chest_rarity rarity, int cost) {
		this->name = name;
		this->rarity = rarity;
		this->cost = cost;
	};

	int GetPrice()
	{
		return this->cost;
	}

	Weapon OpenWeaponChest() {
		int random = rand() % 100;
		if (rarity == common)
		{
			if (random < 50)
			{
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 75)
			{
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 90)
			{
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 100)
			{
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, 1, 1);
				return weapon;
			}
		}
		else if (rarity == uncommon)
		{
			if (random < 40)
			{
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 65)
			{
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 80)
			{
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 100)
			{
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, 1, 1);
				return weapon;
			}
		}
		else if (rarity == rare)
		{
			if (random < 30)
			{
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 55)
			{
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 70)
			{
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 100)
			{
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, 1, 1);
				return weapon;
			}
		}
		else if (rarity == legendary)
		{
			if (random < 20)
			{
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 35)
			{
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 50)
			{
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, 1, 1);
				return weapon;
			}
			else if (random < 100)
			{
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, 1, 1);
				return weapon;
			}
		}
	}


private:
	std::string name;
	chest_rarity rarity;
	int cost;
};