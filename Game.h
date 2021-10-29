#pragma once
#include "SDL.h"
#include "Sprite.h"

class Game
{
public:
	Game(SDL_Renderer* rend);

	void Update();
	void Draw();


private:

	SDL_Renderer* renderer;

	Sprite* first;



};

