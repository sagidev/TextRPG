#pragma once
#include <string>
#include "Armor.h"
#include "Weapon.h"
enum chest_rarity { starter, advanced, premium, legend };

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
		if (rarity == starter)
		{
			if (random < 50)
			{
				int dmg = rand() % 10 + 1;
				int critChance = rand() % 5 + 1;
				Weapon weapon("Common Sword", 1, dmg, critChance, 1, item_rarity::common);
				return weapon;
			}
			else if (random < 75)
			{
				int critChance = rand() % 7 + 3;
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, critChance, 1, item_rarity::uncommon);
				return weapon;
			}
			else if (random < 90)
			{
				int critChance = rand() % 13 + 7;
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, critChance, 1, item_rarity::rare);
				return weapon;
			}
			else if (random < 100)
			{
				int critChance = rand() % 15 + 10;
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, critChance, 1, item_rarity::legendary);
				return weapon;
			}
		}
		else if (rarity == advanced)
		{
			if (random < 40)
			{
				int critChance = rand() % 5 + 1;
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, critChance, 1, item_rarity::common);
				return weapon;
			}
			else if (random < 65)
			{
				int critChance = rand() % 7 + 3;
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, critChance, 1, item_rarity::uncommon);
				return weapon;
			}
			else if (random < 80)
			{
				int critChance = rand() % 13 + 7;
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, critChance, 1, item_rarity::rare);
				return weapon;
			}
			else if (random < 100)
			{
				int critChance = rand() % 15 + 10;
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, critChance, 1, item_rarity::legendary);
				return weapon;
			}
		}
		else if (rarity == premium)
		{
			if (random < 30)
			{
				int critChance = rand() % 5 + 1;
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, critChance, 1, item_rarity::common);
				return weapon;
			}
			else if (random < 55)
			{
				int critChance = rand() % 7 + 3;
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, critChance, 1, item_rarity::uncommon);
				return weapon;
			}
			else if (random < 70)
			{
				int critChance = rand() % 13 + 7;
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, critChance, 1, item_rarity::rare);
				return weapon;
			}
			else if (random < 100)
			{
				int critChance = rand() % 15 + 10;
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, critChance, 1, item_rarity::legendary);
				return weapon;
			}
		}
		else if (rarity == legend)
		{
			if (random < 20)
			{
				int critChance = rand() % 5 + 1;
				int dmg = rand() % 10 + 1;
				Weapon weapon("Common Sword", 1, dmg, critChance, 1, item_rarity::common);
				return weapon;
			}
			else if (random < 35)
			{
				int critChance = rand() % 7 + 3;
				int dmg = rand() % 20 + 10;
				Weapon weapon("Uncommon Sword", 1, dmg, critChance, 1, item_rarity::uncommon);
				return weapon;
			}
			else if (random < 50)
			{
				int critChance = rand() % 13 + 7;
				int dmg = rand() % 20 + 30;
				Weapon weapon("Rare Sword", 1, dmg, critChance, 1, item_rarity::rare);
				return weapon;
			}
			else if (random < 100)
			{
				int critChance = rand() % 15 + 10;
				int dmg = rand() % 50 + 50;
				Weapon weapon("Legendary Sword", 1, dmg, critChance, 1, item_rarity::legendary);
				return weapon;
			}
		}
	}


private:
	std::string name;
	chest_rarity rarity;
	int cost;
};