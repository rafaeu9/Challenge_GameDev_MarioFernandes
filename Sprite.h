#pragma once
#include "TextureManager.h"
#include "MathMario.h"
#include "SDL.h"

/*
Change Log
08/04/2020 - Ad an image to the Entity

*/

class Sprite
{
private:
	
	Vector2 position;
	   
	SDL_Texture* Texture;	

public:

	SDL_Rect srcRect, destRect;
	

	Sprite();
	Sprite(const char* path, bool useTransparency = false);

	void setTex(const char* path, bool useTransparency = false);
	
	void SetPostion(int x, int y) { position.x = x; position.y = y; }

	Vector2 GetPosition() { return position; }

	void init();

	void update();

	void draw();

	void rotation();

};
