#include "Aplication.h"


void Aplication::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
#pragma region Create Window


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Check if SDL is initialized
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		//create the window
		window = SDL_CreateWindow(
			title,				//title
			xpos,				//initial x position
			ypos,				//initial y position
			width,				//width, in pixels
			height,				//height, in pixels
			flags				//window behavior flags
		);

		if (!window)
		{
			printf("WINDOW initialization failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return ;
		}

		renderer = SDL_CreateRenderer(
			window,				//link the renderer to our newly created win
			-1,					//index rendering driver (ignore for now)
			0					//renderer behavior flags (ignore for now)
		);

		if (!renderer)
		{
			printf("RENDERER initialization failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return ;
		}

		if (renderer)
		{
			SDL_SetRenderDrawColor(
				renderer,		//our target renderer
				255,			//r
				255,			//g
				255,			//b
				255				//alpha
			);
		}

		isRunning = true;
	}
	else
		isRunning = false;

#pragma endregion Create Window


	input = new Input();		

	Running();
}

void Aplication::HandleEvents()
{
	if (input->KeyIsPressed(KEY_ESCAPE))
		isRunning = false;
	else if(input->event->type == SDL_QUIT)
		isRunning = false;
}

void Aplication::Running()
{

	//Target Frame rate
	const int FPS = 60;
	//Max time between frames
	const int frameDelay = 1000 / FPS;

	int FrameCount = 0;
	Uint32 CountSec = 0;

	Uint32 frameStart;
	int frameTime;

	while (isRunning)
	{	

		//Current game time
		frameStart = SDL_GetTicks();

		Update();
		Draw();

		//How long the cycle took
		frameTime = SDL_GetTicks() - frameStart;

		//check if need to Delay
		if (frameDelay > frameTime)
		{
			//How mush time will delay
			SDL_Delay(frameDelay - frameTime);
		}

		//Add frame count
		FrameCount++;

		//Detect how much time take to update game
		frameTime = SDL_GetTicks() - frameStart;

		//Store time
		CountSec += frameTime;

		//if pass 1 second display frame rate
		if (CountSec >= 1000)
		{
			CountSec = 0;

			std::cout << FrameCount << " FPS" << endl;

			FrameCount = 0;
		}

		HandleEvents();
	}

	Clean();
}

void Aplication::Update()
{
	input->update();
}

void Aplication::Draw()
{
	//Clean window
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 165, 253, 255);

	//Redraw Map


	//Draw on screen
	SDL_RenderPresent(renderer);
}

void Aplication::Clean()
{
	
	SDL_Quit();
	printf("GameClean\n");
}



