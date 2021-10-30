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
		m_Window = SDL_CreateWindow(
			title,				//title
			xpos,				//initial x position
			ypos,				//initial y position
			width,				//width, in pixels
			height,				//height, in pixels
			flags				//window behavior flags
		);

		if (!m_Window)
		{
			printf("WINDOW initialization failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return ;
		}

		m_Renderer = SDL_CreateRenderer(
			m_Window,				//link the renderer to our newly created win
			-1,					//index rendering driver (ignore for now)
			0					//renderer behavior flags (ignore for now)
		);

		if (!m_Renderer)
		{
			printf("RENDERER initialization failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return ;
		}

		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(
				m_Renderer,		//our target renderer
				255,			//r
				255,			//g
				255,			//b
				255				//alpha
			);
		}

		m_isRunning = true;
	}
	else
		m_isRunning = false;

#pragma endregion Create Window	


	if (TTF_Init())
	{
		cout << "Could not initialize SDL_TTF, SDL_TTF Error:" << TTF_GetError() << endl;
		m_isRunning = false;
	}

	TextureManager::renderer = m_Renderer;

	m_Input = new Input();	

	m_Game = new Game(m_Renderer);

	m_InsertedCashTxt = new Text(m_Renderer, 20, " ", 0, 0);
	m_RemovedCashTxt = new Text(m_Renderer, 20, " ", 0, 30);
	m_AmountOfTrysTxt = new Text(m_Renderer, 20, " ", 0, 60);
	
	m_StartTxt = new Text(m_Renderer, 20, "Start (Space)", 20, 600);
	m_CreditIn = new Text(m_Renderer, 20, "Credit In (Z) ", 220, 600);
	m_CreditOut = new Text(m_Renderer, 20, "Credit Out (X) ", 420, 600);
	m_BetTxt = new Text(m_Renderer, 20, "Switch Bet (C) ", 620, 600);

	Running();
}

void Aplication::HandleEvents()
{
	//Add cash
	if (m_Input->KeyIsPressed(KEY_Z))
	{
		++m_InsertedCash;
	}

	//Remove cash
	if (m_Input->KeyIsPressed(KEY_X))
	{
		m_RemovedCash += m_InsertedCash;
		m_InsertedCash = 0;
	}

	//Switch bet
	if (m_Input->KeyIsPressed(KEY_C))
	{
		m_Game->ChangeBet();
	}

	//Start/Pause Game
	if (m_Input->KeyIsPressed(KEY_SPACE))
	{
		if (m_InsertedCash > 0 && !m_Game->Runing)
		{
			--m_InsertedCash;
			m_Game->Init();
		}
		else if (m_Game->Runing)
		{
			m_Game->paused = !m_Game->paused;
		}
	}

	//Close Window
	if (m_Input->KeyIsPressed(KEY_ESCAPE))
		m_isRunning = false;
	else if(m_Input->event->type == SDL_QUIT)
		m_isRunning = false;
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

	while (m_isRunning)
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
	m_Input->Update();

	//Update application status on screen
	m_InsertedCashTxt->UpdateText("Inserted Credits: " + to_string(m_InsertedCash));
	m_RemovedCashTxt->UpdateText("Removed Credits: " + to_string(m_RemovedCash));
	m_AmountOfTrysTxt->UpdateText("Amount of Plays: " + to_string(m_AmountOfTrys));
		
	m_Game->Update();

    //Check player result
	if (m_Game->finished)
	{
		++m_AmountOfTrys;

		if (m_Game->Check())
			m_InsertedCash += 50;
	}
}

void Aplication::Draw()
{
	//Clean window
	SDL_RenderClear(m_Renderer);

	SDL_SetRenderDrawColor(m_Renderer, 0, 165, 253, 255);

	//Draw status on screen
	SDL_RenderCopy(m_Renderer, m_InsertedCashTxt->GetTexture(), NULL, &m_InsertedCashTxt->textRect);
	SDL_RenderCopy(m_Renderer, m_RemovedCashTxt->GetTexture(), NULL, &m_RemovedCashTxt->textRect);
	SDL_RenderCopy(m_Renderer, m_AmountOfTrysTxt->GetTexture(), NULL, &m_AmountOfTrysTxt->textRect);
	
	//Draw instructions on screen
	SDL_RenderCopy(m_Renderer, m_StartTxt->GetTexture(), NULL, &m_StartTxt->textRect);
	SDL_RenderCopy(m_Renderer, m_CreditIn->GetTexture(), NULL, &m_CreditIn->textRect);
	SDL_RenderCopy(m_Renderer, m_CreditOut->GetTexture(), NULL, &m_CreditOut->textRect);
	SDL_RenderCopy(m_Renderer, m_BetTxt->GetTexture(), NULL, &m_BetTxt->textRect);			

	m_Game->Draw();

	//Draw on screen
	SDL_RenderPresent(m_Renderer);
}

void Aplication::Clean()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
	printf("GameClean\n");
}

