#include "Game.h"

Game::Game(SDL_Renderer* rend)
{
	//Set up random seed
	srand(time(0));

	m_Time = Timer();

	//Setup bet chip
	m_Renderer = rend;
	m_BetSprite = new Sprite("Assets/Circle.bmp", true);
	m_BetSprite->SetPostion(700,10);


	//Setup text
	m_Txt = new Text(m_Renderer, 20, "Your Bet: ", 580, 35);
	m_Result = new Text(m_Renderer, 40, " ", 300, 100);
	m_WhiteCount = new Text(m_Renderer, 20, " ", 100, 550);
	m_BlackCount = new Text(m_Renderer, 20, " ", 400, 550);
}

void Game::Init()
{
	m_Result->UpdateText(" ");
	m_WhiteCount->UpdateText(" ");
	m_BlackCount->UpdateText(" ");

	for (int i = 0; i < m_AmountOfChips; i++)
	{
		Sprites[i] = new Sprite("Assets/Circle.bmp", true);

		//Give chips a random color
		Sprites[i]->ChangeColor(0 == rand() % 2);

		m_Mask[i] = Sprites[i]->GetBlack();
	}

	//Place chips in the grid position
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

	m_CurrentSprite = 0;

	Runing = true;
}

void Game::Update()
{
	m_Time.Update();

	m_BetSprite->ChangeColor(m_Bet);
	
	if (Sprites[0] != NULL && !paused && Runing)
	{
		if (m_CurrentSprite < m_AmountOfChips)
		{
			Sprites[m_CurrentSprite]->update(&m_Time);
			if (!Sprites[m_CurrentSprite]->GetMoving())
				m_CurrentSprite++;
		}
		else
			finished = true;
	}


}

void Game::Draw()
{

	m_BetSprite->draw();
	SDL_RenderCopy(m_Renderer, m_Txt->GetTexture(), NULL, &m_Txt->textRect);
	SDL_RenderCopy(m_Renderer, m_WhiteCount->GetTexture(), NULL, &m_WhiteCount->textRect);
	SDL_RenderCopy(m_Renderer, m_BlackCount->GetTexture(), NULL, &m_BlackCount->textRect);
	SDL_RenderCopy(m_Renderer, m_Result->GetTexture(), NULL, &m_Result->textRect);
	
	
	if (Sprites[0] != NULL)
	for (int i = 0; i < m_AmountOfChips; i++)
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

	
	int Whites = 0;
	int Black = 0;

	//Count Black and white Chips
	for (int w = 0; w < 50; w++)
	{
		if (m_Mask[w])
			++Black;
		else
			++Whites;
	}

	m_WhiteCount->UpdateText("White amount: " + to_string(Whites));
	m_BlackCount->UpdateText("White amount : " + to_string(Black));

	//Detect if player wins
	if (m_Bet && Black > Whites || !m_Bet && Black < Whites)
	{
		m_Result->UpdateText("You Win!!!");
		return true;
	}
	
	m_Result->UpdateText("Lost");
	return false;

}

void Game::ChangeBet()
{
	if (!Runing)
	{
		m_Bet = !m_Bet;

		m_BetSprite->ChangeColor(m_Bet);
	}
}
