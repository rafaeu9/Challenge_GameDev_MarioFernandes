#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <String>

#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

class Text
{
public:

	/// <summary>
	/// Set up Text
	/// </summary>
	/// <param name="Renderer"></param>
	/// <param name="Size"></param>
	/// <param name="Text"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Text(SDL_Renderer* r, int size, std::string text, int x, int y);
	~Text();	

	/// <summary>
	/// Change Text
	/// </summary>
	/// <param name="actualText"></param>
	void UpdateText(std::string actualText);
	void UpdateText(std::string actualText, SDL_Color col);

	//Text Attributes
	TTF_Font* font = nullptr;
	int fontSize = 0;
	std::string fonttext = "";

	//Rendering
	SDL_Rect textRect;
	SDL_Texture* fontTexture = nullptr;

	void CreateTextTexture();
	SDL_Texture* GetTexture() { return fontTexture; }

private:
	const char* fontPath = "Assets/font.TTF";

	SDL_Color black = { 0, 0, 0, 255 };
	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Renderer* rend;
};

