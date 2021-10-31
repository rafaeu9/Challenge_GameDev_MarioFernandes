#pragma once
#include <stdio.h>
#include <string>

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

	/// <summary>
	/// Check if player lost or win
	/// </summary>
	/// <returns></returns>
	bool Check();

	/// <summary>
	/// Switch the betting color 
	/// </summary>
	void ChangeBet();

	//Game States
	bool Runing = false;
	bool paused = false;
	bool finished = false;

private:

	

	SDL_Renderer* m_Renderer;
	Timer m_Time;

	int m_AmountOfChips = 50;
	//List Of chips
	Sprite* Sprites[50];
	//List of chips in true or false
	bool m_Mask[50];

	int m_CurrentSprite = 0;

	//Space Between chips
	int m_Grid = 100;

	//Bet Chip
	Sprite* m_BetSprite;
	bool m_Bet = false;

	//Game text
	Text* m_Txt;
	Text* m_Result;
	Text* m_WhiteCount;
	Text* m_BlackCount;

	

	

	
};

