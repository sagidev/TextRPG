#include "Game.h"

Game::Game() {
	stage = 0;
}


Entity Game::spawnEnemy() {
	Entity enemy("Enemy", "NPC", 100 + (stage * 10), 10, 10, stage, 50);
	//enemy.SetLevel(stage);
	enemy.SetHealth(100 + (stage * 10));
	//enemy.SetMaxHealth(100 + (stage * 10));
	enemy.SetExp(50 + (stage * 10));
	enemy.SetAttack(10 + (stage * 10));
	enemy.SetDefense(10);
	return enemy;
}

void Game::StartStage() {
	stage++;
	system("cls");
	Entity enemy = spawnEnemy();

	while (enemy.GetHealth() > 0)
	{
		system("cls");
		enemy.ShowStats();
		player.ShowStats();
		
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Run" << std::endl;
		
		int decision = GetDecision();
		switch (decision) {
		case 1:
			player.Attack(enemy);
			break;
		}
		Sleep(1000);
	}
	
}

void Game::DrawFrame() {
	system("cls");
	std::cout << " __TextRPG__ " << std::endl << std::endl;

	std::cout << " Name: " << player.GetName() << std::endl;
	std::cout << " Health: " << player.GetHealth() << "/" << player.GetMaxHealth() << std::endl;
	std::cout << " Exp: " << player.GetExp() << "/" << player.GetMaxExp() << std::endl;

	std::cout << "\n Stage: " << GetStage() << std::endl;
	
	std::cout << "\n\n Choose action: " << std::endl;
	std::cout << " 1. Start Stage" << std::endl;
	std::cout << " 2. Shop" << std::endl;
	std::cout << " 3. Exit" << std::endl;

	switch (GetDecision())
	{
	case 1:
		StartStage();
	}
}

void Game::StartGame() {
	std::cout << " Enter your name: ";
	std::string _name;
	std::getline(std::cin, _name);
	Entity _player(_name, "warrior", 100, 10, 10, 1, 0);
	player = _player;
	player.SetAttack(10);
	player.SetDefense(10);
	isGameRunning = true;
	
	while (isGameRunning) {
		DrawFrame();

		int xd = GetDecision();
	}
}