#pragma once
#include <string>

class Item {
public:
	Item(std::string name, int id) : name(name), id(id) {}
	const std::string& getName() const { return name; }
	int getID(void) const { return this->id; }

private:
	std::string type;
	std::string name;
	int id;
};