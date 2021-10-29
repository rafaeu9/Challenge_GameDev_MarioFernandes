#pragma once
#include "TextureManager.h"
#include "MathMario.h"
#include "SDL.h"
#include "timer.h"


class Sprite
{
private:
	
	Vector2 position;
	
	Vector2 MovePosition;
	int Speed = 500;

	SDL_Texture* Texture;	

	bool black = false;

	Timer time;

public:

	SDL_Rect srcRect, destRect;
	
	bool isMoving = false;

	Sprite();
	Sprite(const char* path, bool useTransparency = false);

	void setTex(const char* path, bool useTransparency = false);
	
	void SetPostion(int x, int y) { position.x = x; position.y = y; MovePosition.x = x; MovePosition.y = y; }
	void SetMovePosition(int x, int y) { MovePosition.x = x; MovePosition.y = y; time.Reset(); }

	bool GetBlack() { return black; }

	Vector2 GetPosition() { return position; }
	
	void ChangeColor(bool color);

	void update();

	void draw();

	void rotation();

};
