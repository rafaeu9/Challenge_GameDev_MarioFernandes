#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <String>

#include "SDL.h"
#include "Input.h"
#include "Text.h"

using namespace std;


class Aplication
{
public:
	

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	bool running() { return isRunning; };

private:

	void HandleEvents();
	void Running();
	void Update();
	void Draw();
	void Clean();


	int InsertedCash = 0;
	Text* InsertedCashTxt;

	int RemovedCash = 0;
	Text* RemovedCashTxt;

	int AmountOfTrys = 0;
	Text* AmountOfTrysTxt;

	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Input* input;

};

