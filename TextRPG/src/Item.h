#pragma once
#include <string>

enum item_type { weapon, helmet, armor };

class Item {
public:
	Item(std::string name, int id, item_type type) : name(name), id(id), type(type) {}
	const std::string& getName() const { return name; }
	int getID(void) const { return this->id; }

private:
	std::string name;
	item_type type;
	int id;
};