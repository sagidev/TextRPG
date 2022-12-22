#pragma once
#include "Weapon.h"
#include <vector>

class Inventory {
public:
	std::vector<Weapon> weapons;

	void AddWeapon(Weapon weapon) {
		weapons.push_back(weapon);
	}
	
	Weapon getWeapon(int id) {
		return weapons[id];
	}
	void ShowInventory() {
		system("cls");
		std::cout << " Inventory: \n" << std::endl;
		for (int i = 0; i < weapons.size(); i++) {
			std::cout << " " << i + 1 << ". " << weapons[i].getName() << " | AD: " << weapons[i].getDamage() << std::endl;
		}
		std::cout << std::endl;
	}
	
};