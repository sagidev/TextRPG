#include "Game.h"

Game::Game() {
	stage = 0;
}

/// <summary>
/// RNG for enemy spawn
/// </summary>
/// <returns>Enemy</returns>
Entity Game::spawnEnemy() {
	Entity enemy("Enemy", "NPC", 100 + (stage * 10), 10, 0, stage, 50);
	enemy.SetHealth(100 + (stage * 10));
	enemy.SetExp(50 + (stage * 10));
	enemy.SetAttack(10 + (stage * 10));
	return enemy;
}


/// <summary>
/// Start a fight with an enemy
/// </summary>
/// <param name="enemy">Enemy</param>
void Game::StartFight(Entity enemy) 
{
	system("cls");
	std::cout << " Tower of Crack - [" << dye::red("STAGE ") << dye::red(GetStage()) << "]" << std::endl << std::endl;

	std::cout << " [" << dye::red("DANGER!") << "] You encountered an enemy!" << std::endl;
	player.ShowStats();
	enemy.ShowStats();
	std::cout << "\n What do you want to do?" << std::endl;
	std::cout << "  1. Attack" << std::endl;
	std::cout << "  2. Run\n\n --> ";
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
		stage--;
		Sleep(1000);
	}
}


/// <summary>
/// End the game when player is dead
/// </summary>
void Game::EndGame() {
	system("cls");
	std::cout << "You died!" << std::endl;
	std::cout << "Your stats:" << std::endl;
	player.ShowStats();
	std::cout << "Press any key to exit..." << std::endl;
	_getch();
	exit(0);
}


/// <summary>
/// Start a new stage
/// </summary>
void Game::StartStage() {
	stage++;
	system("cls");
	Entity enemy = spawnEnemy();

	StartFight(enemy);
	
}

/// <summary>
/// Main Game Frame
/// </summary>
void Game::DrawFrame() {
	system("cls");
	if(GetStage() == 0)
		std::cout << " Tower of Crack - [" << dye::red("STAGE ") << dye::red(GetStage()) << "] - ENTRY" << std::endl << std::endl;
	else
		std::cout << " Tower of Crack - [" << dye::red("STAGE ") << dye::red(GetStage()) << "]" << std::endl << std::endl;

	player.ShowStats();
	
	std::cout << "\n\n Choose action: " << std::endl;
	std::cout << " 1. Start Stage" << std::endl;
	std::cout << " 2. Show EQ" << std::endl;
	std::cout << " 3. Change EQ" << std::endl;
	std::cout << " 4. Shop" << std::endl;
	std::cout << " 5. Exit \n\n --> ";

	switch (GetDecision())
	{
	case 1:
		StartStage();
		break;
	case 2:
		player.inventory.ShowInventory();
		std::cout << " Press any key to exit..." << std::endl;
		_getch();
		break;
	case 3:
		player.inventory.ChangeEquipment();
		std::cout << " Press any key to exit..." << std::endl;
		_getch();
		break;
	case 5:
		for (int i = 3; i > 0; i--)
		{
			std::cout << " Game will be closed in " << i << std::endl;
			Sleep(1000);
		}
		std::cout << " Thanks for playing! " << std::endl;
		Sleep(1000);
		exit(0);
		break;
	default:
		std::cout << " Wrong decision..." << std::endl;
		Sleep(1000);
		break;
	}
}

/// <summary>
/// Game init and main loop
/// </summary>
void Game::StartGame() {
	std::cout << " Enter your " << dye::red("name") << "..\n\n --> ";
	std::string _name;
	std::getline(std::cin, _name);
	Entity _player(_name, "Warrior", 100, 10, 10, 1, 0);
	player = _player;
	isGameRunning = true;
	Weapon sword("Starting Sword", 1, 55, 10, 10);
	Weapon sword1("Newbie Sword", 1, 15, 10, 10);
	Armor armor("Starting Armor", 1, 20);
	player.inventory.AddWeapon(sword);
	player.inventory.AddWeapon(sword1);
	player.inventory.AddArmor(armor);
	
	while (isGameRunning) {
		DrawFrame();
	}
}