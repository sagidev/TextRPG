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
	int power = enemy.GetOverallPower();
	int random = rand() % 100 + (power/10);
	enemy.SetGold(random);
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
			Sleep(1000);
			if (enemy.GetHealth() > 0) {
				system("cls");
				std::cout << "The enemy attacked you!" << std::endl;
				enemy.Attack(player);
				enemy.ShowStats();
				player.ShowStats();
			}
			Sleep(1000);
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
		int random = rand() % 100;
		if(random > 50)
			std::cout << "You ran away!" << std::endl;
		else
		{
			std::cout << "You got robbed!" << std::endl;
			player.SpendGold(enemy.GetGold() * 2);
		}
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
	std::cout << " 5. Dryad" << std::endl;
	std::cout << " 6. Exit \n\n --> ";

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
	case 4:
		shopxd.OpenChest(player);
		_getch();
		break;
	case 5:
		std::cout << " Do you want to get healed for 100$? \n 1. Yes\n 2. No" << std::endl;
		int decision;
		std::cin >> decision;
		switch (decision) {
		case 1:
			if(player.GetGold() >= 100)
			{
				player.SetHealth(player.GetMaxHealth());
				player.SpendGold(100);
				std::cout << " You got healed!" << std::endl;
			}
			else
			{
				std::cout << " You don't have enough money!" << std::endl;
			}
			break;
		case 2:
			break;
		default:
			break;
		}
		_getch();
		break;
	case 6:
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
	Weapon sword("Warrior's Sword", 1, 15, 5, 10, item_rarity::common);
	Armor armor("Warrior's Armor", 1, 20, item_rarity::common);
	player.inventory.AddWeapon(sword);
	player.inventory.AddArmor(armor);
	
	while (isGameRunning) {
		DrawFrame();
	}
}