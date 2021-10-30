#include "Aplication.h"

#undef main

int main(int argc, char** argv)
{
	Aplication* App = new Aplication();

	App->Init("Challenge GameDev MarioFernandes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);   

	return 0;
}