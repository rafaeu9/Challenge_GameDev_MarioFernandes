#include "Game.h"

Game::Game(SDL_Renderer* rend)
{
	renderer = rend;

	

	for (int i = 0; i < 50; i++)
	{
		Sprites[i] = new Sprite("Assets/Circle.bmp", true);
		Sprites[i]->ChangeColor(rand() % 256, rand() % 256, rand() % 256);
	}

	int y = 100;
	int o = 0;
	for (int i = 0; i < 5; i++)
	{
		int x = 0;

		for (int w = 0; w < 10; w++)
		{
			Sprites[o]->SetPostion(x, y);
			cout << to_string(x) << endl;
			++o;
			x += 100;
		}

		y += 100;
	}
}

void Game::Update()
{
	for (int i = 0; i < 50; i++)
	{
		Sprites[i]->update();
	}
}

void Game::Draw()
{
	for (int i = 0; i < 50; i++)
	{
		Sprites[i]->draw();
	}
}
