#include "Game.h"

Game::Game(SDL_Renderer* rend)
{
	renderer = rend;

	first = new Sprite("Assets/Circle.bmp", true);
	first->SetPostion(250, 250);
}

void Game::Update()
{
	first->update();
}

void Game::Draw()
{
	first->draw();
}
