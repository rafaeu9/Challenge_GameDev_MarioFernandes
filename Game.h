#pragma once
#include <stdio.h>

#include "SDL.h"
#include "Sprite.h"
#include "Text.h"

using namespace std;

class Game
{
public:
	Game(SDL_Renderer* rend);

	void Init();
	void Update();
	void Draw();

	bool Check();

	void ChangeBet();

	bool Runing = false;

	bool paused = false;

	bool finished = false;

private:

	int currentsprite = 0;

	SDL_Renderer* renderer;
	Timer time;


	Sprite* Sprites[50];

	Sprite* BetSprite;
	bool bet = false;
	Text* txt;
	Text* result;
	Text* WhiteCount;
	Text* blackCount;

	int grid = 100;

	bool mask[50];

	bool maskCheck[3][50] = {
	{
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1
	},
	{
		0,0,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,0,0
	},
	{
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	}
	};



};

