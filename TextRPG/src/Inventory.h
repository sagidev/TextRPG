#pragma once
#include "Weapon.h"
#include <vector>
#include "Armor.h"
#include <Windows.h>

class Inventory {
public:
	std::vector<Item> items;
	std::vector<Weapon> weapons;
	std::vector<Armor> armors;

	int equippedWeaponID;
	int equippedArmorID;

	void AddArmor(Armor armor) {
		armors.push_back(armor);
	}

	Armor getArmor(int id) {
		return armors[id];
	}

	void AddWeapon(Weapon weapon) {
		weapons.push_back(weapon);
	}
	
	Weapon getWeapon(int id) {
		return weapons[id];
	}

	int GetWeaponDamage()
	{
		if (weapons.size() > 0)
			return weapons[equippedWeaponID].getDamage();
		else
			return 0;
	}

	int GetArmorDefense()
	{
		if (armors.size() > 0)
			return armors[equippedArmorID].getArmor();
		else
			return 0;
	}
	
	void ShowInventory() {
		system("cls");
		std::cout << " Inventory: \n" << std::endl;
		std::cout << " Weapons:" << std::endl;
		for (int i = 0; i < weapons.size(); i++) {
			if(i == equippedWeaponID)
				std::cout << " " << i + 1 << ". " << weapons[i].getName() << " | AD: " << weapons[i].getDamage() << "   ["<< weapons[i].getPower() << "]" << " [EQIPPED]" << std::endl;
			else
				std::cout << " " << i + 1 << ". " << weapons[i].getName() << " | AD: " << weapons[i].getDamage() << "   [" << weapons[i].getPower() << "]" << std::endl;
		}
		std::cout << "\n Armors:" << std::endl;
		for (int i = 0; i < armors.size(); i++) {
			if(i == equippedArmorID)
				std::cout << " " << i + 1 << ". " << armors[i].getName() << " | DEF: " << armors[i].getArmor() << " [EQIPPED]" << std::endl;
			else
				std::cout << " " << i + 1 << ". " << armors[i].getName() << " | DEF: " << armors[i].getArmor() << std::endl;
		}
		std::cout << std::endl;
	}

	void ChangeEquipment() {
		system("cls");
		std::cout << " Change Equipment: \n 1.Weapon\n 2.Armor" << std::endl;
		int dec;
		std::cin >> dec;
		switch (dec) {
		case 1:
			std::cout << " Choose weapon: " << std::endl;
			for (int i = 0; i < weapons.size(); i++) {
				std::cout << " " << i + 1 << ". " << weapons[i].getName() << " | AD: " << weapons[i].getDamage() << "   [" << weapons[i].getPower() << "]" << std::endl;
			}
			int weaponID;
			std::cin >> weaponID;
			equippedWeaponID = weaponID - 1;
			std::cout << "\n Weapon changed to " << weapons[equippedWeaponID].getName() << " [" << weapons[equippedWeaponID].getPower() << "]" << std::endl;
			break;
		case 2:
			std::cout << " Choose armor: " << std::endl;
			for (int i = 0; i < armors.size(); i++) {
				std::cout << " " << i + 1 << ". " << armors[i].getName() << " | DEF: " << armors[i].getArmor() << std::endl;
			}
			int armorID;
			std::cin >> armorID;
			equippedArmorID = armorID - 1;
			std::cout << "\n Armor changed to " << armors[equippedArmorID].getName() << std::endl;
			break;
		default:
			std::cout << " Wrong decision..." << std::endl;
			Sleep(1000);
			break;
		}
	}
	
};