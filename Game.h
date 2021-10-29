#pragma once
#include <stdio.h>

#include "SDL.h"
#include "Sprite.h"

using namespace std;

class Game
{
public:
	Game(SDL_Renderer* rend);

	void Update();
	void Draw();


private:

	SDL_Renderer* renderer;

	Sprite* Sprites[50];

	int grid = 100;

};

