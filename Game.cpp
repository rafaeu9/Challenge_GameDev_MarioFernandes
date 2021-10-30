#include "Game.h"

Game::Game(SDL_Renderer* rend)
{
	time = Timer();

	renderer = rend;
	BetSprite = new Sprite("Assets/Circle.bmp", true);
	BetSprite->SetPostion(700,10);

	txt = new Text(renderer, 20, "Your Bet: ", 580, 35);
	result = new Text(renderer, 40, " ", 300, 100);
	WhiteCount = new Text(renderer, 20, " ", 100, 550);
	blackCount = new Text(renderer, 20, " ", 400, 550);
}

void Game::Init()
{
	result->UpdateText(" ");
	WhiteCount->UpdateText(" ");
	blackCount->UpdateText(" ");

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
	time.Update();

	BetSprite->ChangeColor(bet);
	
	if (Sprites[0] != NULL && !paused && Runing)
	{
		if (currentsprite < 50)
		{
			Sprites[currentsprite]->update(&time);
			if (!Sprites[currentsprite]->isMoving)
				currentsprite++;
		}
		else
			finished = true;
	}


}

void Game::Draw()
{

	BetSprite->draw();
	SDL_RenderCopy(renderer, txt->GetTexture(), NULL, &txt->textRect);
	SDL_RenderCopy(renderer, WhiteCount->GetTexture(), NULL, &WhiteCount->textRect);
	SDL_RenderCopy(renderer, blackCount->GetTexture(), NULL, &blackCount->textRect);
	SDL_RenderCopy(renderer, result->GetTexture(), NULL, &result->textRect);
	
	
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

	/*for (int i = 0; i < 3; i++)
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
		
	}*/

	int Whites = 0;
	int Black = 0;

	for (int w = 0; w < 50; w++)
	{
		if (mask[w])
			++Black;
		else
			++Whites;
	}

	WhiteCount->UpdateText("White amount: " + to_string(Whites));
	blackCount->UpdateText("White amount : " + to_string(Black));



	if (bet && Black > Whites || !bet && Black < Whites)
	{
		result->UpdateText("You Win!!!");
		return true;
	}
	
	result->UpdateText("Lost");
	return false;

}

void Game::ChangeBet()
{
	if (!Runing)
	{
		bet = !bet;

		BetSprite->ChangeColor(bet);
	}
}
