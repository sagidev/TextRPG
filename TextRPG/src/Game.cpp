#include "Game.h"

Game::Game() {
	stage = 0;
}

void Game::DrawFrame() {
	system("cls");
	std::cout << " __TextRPG__ " << std::endl << std::endl;

	std::cout << " Name: " << player.GetName() << std::endl;
	std::cout << " Health: " << player.GetHealth() << "/" << player.GetMaxHealth() << std::endl;
	std::cout << " Exp: " << player.GetExp() << "/" << player.GetMaxExp() << std::endl;
}

void Game::StartGame() {
	std::cout << " Enter your name: ";
	std::string _name;
	std::getline(std::cin, _name);
	Entity _player(_name, "warrior", 100, 10, 10, 1, 0);
	player = _player;
	isGameRunning = true;
	
	while (isGameRunning) {
		DrawFrame();

		std::string _name;
		std::getline(std::cin, _name);
	}
}