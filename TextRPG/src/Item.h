#pragma once
#include <string>

enum item_rarity { common, uncommon, rare, legendary };
enum item_type { weapon, helmet, armor };

class Item {
public:
	Item(std::string name, int id, item_type type, item_rarity rr) : name(name), id(id), type(type), rarity(rr) {}
	const std::string& getName() const { return name; }
	int getID(void) const { return this->id; }
	void setName(std::string _name) {
		this->name = _name;
	}
private:
	std::string name;
	item_type type;
	item_rarity rarity;
	int id;
};