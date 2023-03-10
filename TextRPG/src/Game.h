#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>
#include "Shop.h"
#include "../externals/color.h"

class Game {
public:
	Game();
	void DrawFrame();
	void StartGame();
	void EndGame();
	void StartFight(Entity enemy);
	Entity spawnEnemy();
	void StartStage();
	Shop shop;
	int GetDecision() {
		int dec;
		std::cin >> dec;
		return dec;
	};
	int GetStage() {
		return stage;
	}

	Entity player;

private:
	int stage;
	bool isGameRunning;
};