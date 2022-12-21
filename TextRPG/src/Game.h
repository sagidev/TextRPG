#pragma once
#include <string>
#include <iostream>
#include "Entity.h"

class Game {
public:
	Game();
	void DrawFrame();
	void StartGame();
	void EndGame();

	Entity player;

private:
	int stage;
	bool isGameRunning;
};