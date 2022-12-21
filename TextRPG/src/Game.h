#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "Entity.h"

class Game {
public:
	Game();
	void DrawFrame();
	void StartGame();
	void EndGame();

	Entity spawnEnemy();
	void StartStage();

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