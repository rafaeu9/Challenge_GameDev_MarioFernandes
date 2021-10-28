#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <String>

#include "SDL.h"
#include "Input.h"

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
	int RemovedCash = 0;
	int AmountOfTrys = 0;

	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Input* input;

	

};

