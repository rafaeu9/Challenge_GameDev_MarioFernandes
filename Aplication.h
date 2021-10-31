#pragma once

#ifdef _WIN32
#include "SDL.h"
#else
#include <SDL2/SDL.h>
#endif // _WIN32


#include <stdio.h>
#include <vector>
#include <string>
#include "Input.h"
#include "Text.h"
#include "TextureManager.h"
#include "Game.h"

using namespace std;


class Aplication
{
public:
	
	/*
	Initialize application
	- Title of the Window
	- Position X on screen
	- Position Y on screen
	- With of the window
	- Height of the window
	- Full-screen
	*/
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);


	/// <summary>
	/// Get Application State
	/// </summary>
	/// <returns></returns>
	bool running() { return m_isRunning; };

private:

	/// <summary>
	/// Update Input
	/// </summary>
	void HandleEvents();

	/// <summary>
	/// Cycle the Game 
	/// </summary>
	void Running();

	/// <summary>
	///Update Components
	/// <summary>
	void Update();

	/// <summary>
	///Draw components
	/// <summary>
	void Draw();

	/// <summary>
	///Close application
	/// <summary>
	void Clean();

	//Current Cash
	int m_InsertedCash = 0;
	Text* m_InsertedCashTxt;

	//Removed Cash
	int m_RemovedCash = 0;
	Text* m_RemovedCashTxt;

	//Amount of tries
	int m_AmountOfTrys = 0;
	Text* m_AmountOfTrysTxt;


	//Instructions txt
	Text* m_StartTxt;
	Text* m_CreditIn;
	Text* m_CreditOut;
	Text* m_BetTxt;

	//Application State
	bool m_isRunning;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	Input* m_Input;

	Game* m_Game;
};

