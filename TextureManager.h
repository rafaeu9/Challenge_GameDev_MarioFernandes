#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

#ifdef _WIN32
#include "SDL2/include/SDL.h"
#else
#include "SDL2/include/SDL2/SDL.h"
#endif // _WIN32


class TextureManager
{
public:

	static SDL_Renderer* renderer;

	static SDL_Texture* LoadBMPTexture(const char* FileName, SDL_Rect* destRect = nullptr, bool Transparency = false);

	static void Draw(SDL_Texture* tex, SDL_Rect dest);
};

