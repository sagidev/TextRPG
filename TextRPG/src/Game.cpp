#include "Game.h"

Game::Game() {
	stage = 0;
}


Entity Game::spawnEnemy() {
	Entity enemy("Enemy", "NPC", 100 + (stage * 10), 10, 0, stage, 50);
	//enemy.SetLevel(stage);
	enemy.SetHealth(100 + (stage * 10));
	//enemy.SetMaxHealth(100 + (stage * 10));
	enemy.SetExp(50 + (stage * 10));
	enemy.SetAttack(10 + (stage * 10));
	return enemy;
}

void Game::StartFight(Entity enemy) 
{
	system("cls");
	std::cout << "You encountered an enemy!" << std::endl;
	enemy.ShowStats();
	player.ShowStats();
	std::cout << "\nWhat do you want to do?" << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Run" << std::endl;
	int decision = GetDecision();
	if (decision == 1) {
		while (player.GetHealth() > 0 && enemy.GetHealth() > 0) {
			system("cls");
			std::cout << "You attacked the enemy!" << std::endl;
			player.Attack(enemy);
			enemy.ShowStats();
			player.ShowStats();
			Sleep(500);
			system("cls");
			std::cout << "Enemy attacked you!" << std::endl;
			enemy.Attack(player);
			enemy.ShowStats();
			player.ShowStats();
			Sleep(500);
		}
		if (player.GetHealth() <= 0) {
			EndGame();
		}
		else if (enemy.GetHealth() <= 0) {
			system("cls");
			std::cout << "You killed the enemy!" << std::endl;
			player.ShowStats();
			Sleep(1000);
		}
	}
	else if (decision == 2) {
		std::cout << "You ran away!" << std::endl;
		Sleep(1000);
		StartStage();
	}
}

void Game::EndGame() {
	system("cls");
	std::cout << "You died!" << std::endl;
	std::cout << "Your stats:" << std::endl;
	player.ShowStats();
	std::cout << "Press any key to exit..." << std::endl;
	_getch();
	exit(0);
}

void Game::StartStage() {
	stage++;
	system("cls");
	Entity enemy = spawnEnemy();

	StartFight(enemy);
	
}

void Game::DrawFrame() {
	system("cls");
	std::cout << " Tower of Crack - [STAGE " << GetStage() << "]" << std::endl << std::endl;

	player.ShowStats();
	
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
	isGameRunning = true;
	
	while (isGameRunning) {
		DrawFrame();
	}
}