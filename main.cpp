#include "Aplication.h"

#undef main

void main()
{
	Aplication* App = new Aplication();

	App->Init("Challenge GameDev MarioFernandes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	getchar();
}