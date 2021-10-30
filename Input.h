#pragma once

#include "SDL.h"

/// <summary>
/// List of presseble keys
/// </summary>
enum KEY_PRESSED_LIST
{
	KEY_ESCAPE, KEY_SPACE, KEY_X, KEY_Z, KEY_C, SIZE_OF_KEYS_PRESSED_ENUM
};

class Input
{
public:

	SDL_Event* event;

	Input();

	void Update();

	/// <summary>
	/// Detect if the key was pressed
	/// </summary>
	bool KeyIsPressed(KEY_PRESSED_LIST key);


private:
	
	/// <summary>
	/// Array of pressed keys
	/// </summary>
	bool m_KeysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};