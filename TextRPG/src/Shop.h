#pragma once
#include "Weapon.h"
#include <vector>
#include "Armor.h"
#include "Entity.h"
#include <iostream>
class Shop {
	std::vector<std::pair<Weapon,int>> weapons;
	std::vector<std::pair<Armor, int >> armors;

	Shop() {
		weapons.push_back(std::make_pair(Weapon("Wooden Sword", 0, 5, 5, 5),20));
		weapons.push_back(std::make_pair(Weapon("Iron Sword", 1, 10, 10, 10), 50));
		weapons.push_back(std::make_pair(Weapon("Steel Sword", 2, 15, 15, 15),  20));
		weapons.push_back(std::make_pair(Weapon("Mithril Sword", 3, 20, 20, 20), 20));
		weapons.push_back(std::make_pair(Weapon("Adamantite Sword", 4, 25, 25, 25), 20));
		weapons.push_back(std::make_pair(Weapon("Dragon Sword", 5, 30, 30, 30), 20));
		weapons.push_back(std::make_pair(Weapon("God Sword", 6, 35, 35, 35), 20));
		weapons.push_back(std::make_pair(Weapon("Miecz Szymona", 7, 120, 95, 300), 250));
		weapons.push_back(std::make_pair(Weapon("Harnas Sword", 8, 35, 35, 35), 20));

		weapons.push_back(std::make_pair(Weapon("Miecz Dominika", 155, 30, 30, 30), 50));
		weapons.push_back(std::make_pair(Weapon("Miecz chuj", 155, 30, 30, 30), 50));
		//armors.push_back(std::make_pair(Armor("Wooden Armor", 0, 5));
		//armors.push_back(std::make_pair(Armor("Iron Armor", 1, 10));
		//armors.push_back(std::make_pair(Armor("Steel Armor", 2, 15));
		//armors.push_back(std::make_pair(Armor("Mithril Armor", 3, 20));
		//armors.push_back(std::make_pair(Armor("Adamantite Armor", 4, 25));
		//armors.push_back(std::make_pair(Armor("Dragon Armor", 5, 30));
		//armors.push_back(std::make_pair(Armor("God Armor", 6, 35));
	}

	void BuyItem(Entity player) {
		system("cls");
		std::cout << " Shop: \n" << std::endl;
		std::cout << " Weapons:" << std::endl;
		for (int i = 0; i < weapons.size(); i++) {
			std::cout << " " << i + 1 << ". " << weapons[i].first.getName() << " | AD: " << weapons[i].first.getDamage() << "   [" << weapons[i].first.getPower() << "]" << " | Price: " << weapons[i].second << std::endl;
		}
		std::cout << "\n Armors:" << std::endl;
		for (int i = 0; i < armors.size(); i++) {
			std::cout << " " << i + 1 << ". " << armors[i].first.getName() << " | AD: " << armors[i].first.getArmor() << "   [" << armors[i].first.getPower() << "]" << " | Price: " << armors[i].second << std::endl;
		}
		std::cout << "\n 0. Exit" << std::endl;
		std::cout << "\n Select item to buy: ";
		int itemID;
		std::cin >> itemID;
		if (itemID == 0) {
			return;
		}
		else if (itemID > 0 && itemID <= weapons.size()) {
			if (player.GetGold() >= weapons[itemID - 1].second)
			{
				player.SpendGold(weapons[itemID - 1].second);
				player.inventory.AddWeapon(weapons[itemID - 1].first);
				weapons.erase(weapons.begin() + itemID - 1);
			}
		}
	}

	void ListItems() {
		system("cls");
		std::cout << " Shop: \n" << std::endl;
		std::cout << " Weapons:" << std::endl;
		for (int i = 0; i < weapons.size(); i++) {
			std::cout << " " << i + 1 << ". " << weapons[i].first.getName() << " | AD: " << weapons[i].first.getDamage() << "   [" << weapons[i].first.getPower() << "]" << std::endl;
		}
		//std::cout << "\n Armors:" << std::endl;
		//for (int i = 0; i < armors.size(); i++) {
		//	std::cout << " " << i + 1 << ". " << armors[i].getName() << " | DEF: " << armors[i].getArmor() << "   [" << armors[i].getPower() << "]" << std::endl;
		//}
	}
};