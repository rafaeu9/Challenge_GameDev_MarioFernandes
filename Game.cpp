#include "Game.h"

Game::Game(SDL_Renderer* rend)
{
	renderer = rend;
	
}

void Game::Init()
{
	for (int i = 0; i < 50; i++)
	{
		Sprites[i] = new Sprite("Assets/Circle.bmp", true);
		Sprites[i]->ChangeColor(0 == rand() % 2);
		mask[i] = Sprites[i]->GetBlack();
		//Sprites[i]->SetPostion(0, 300);
	}

	int y = 150;
	int o = 0;
	for (int i = 0; i < 5; i++)
	{
		int x = 25;

		for (int w = 0; w < 10; w++)
		{
			Sprites[o]->SetMovePosition(x, y);

			++o;
			x += 75;
		}

		y += 75;
	}

	currentsprite = 0;
	Runing = true;
}

void Game::Update()
{

	
	if (Sprites[0] != NULL && !paused && Runing)
	{
		if (currentsprite < 50)
		{
			Sprites[currentsprite]->update();
			if (!Sprites[currentsprite]->isMoving)
				currentsprite++;
		}
		else
			finished = true;
	}


}

void Game::Draw()
{
	if (Sprites[0] != NULL)
	for (int i = 0; i < 50; i++)
	{
		Sprites[i]->draw();
	}
}

bool Game::Check()
{
	bool tempcheck;

	Runing = false;
	finished = false;
	paused = false;		

	for (int i = 0; i < 3; i++)
	{
		tempcheck = true;
		for (int w = 0; w < 50; w++)
		{
			if (maskCheck[i][w] && maskCheck[i][w] != mask[w])
			{
				tempcheck = false;
				break;
			}			
		}

		if (tempcheck)
			return true;
		
	}

	return false;

}
