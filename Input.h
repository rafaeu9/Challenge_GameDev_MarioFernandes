#pragma once

#include "SDL.h"

//Global vars
enum KEY_PRESSED_LIST
{
	KEY_ESCAPE, KEY_SPACE, KEY_X, KEY_Z, SIZE_OF_KEYS_PRESSED_ENUM
};

class Input
{
public:

	SDL_Event* event;

	Input();


	void update();
	bool KeyIsPressed(KEY_PRESSED_LIST key);

private:

	
	bool m_KeysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};