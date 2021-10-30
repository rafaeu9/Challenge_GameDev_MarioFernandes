#pragma once

#include "TextureManager.h"
#include "MathMario.h"
#include "timer.h"


class Sprite
{
private:
	
	//Current Position
	Vector2 m_Position;
	
	Vector2 m_MovePosition;
	int m_Speed = 500;

	SDL_Texture* m_Texture;	

	//Chip State
	bool m_Black = false;	

	bool m_isMoving = false;

public:

	SDL_Rect srcRect, destRect;	

	Sprite();
	/// <summary>
	/// Set up sprite
	/// </summary>
	/// <param name="path"> Path to the image</param>
	/// <param name="useTransparency"> Set transparency</param>
	Sprite(const char* path, bool useTransparency = false);

	~Sprite();

	/// <summary>
	/// Load Texture
	/// </summary>
	/// <param name="path"> Path to the image</param>
	/// <param name="useTransparency"> Set transparency</param>
	void setTex(const char* path, bool useTransparency = false);
	
	void SetPostion(int x, int y);
	void SetMovePosition(int x, int y) { m_MovePosition.x = x; m_MovePosition.y = y;}
	
	/// <summary>
	/// Get Moving State
	/// </summary>
	/// <returns></returns>
	bool GetMoving() { return m_isMoving; }
	Vector2 GetPosition() { return m_Position; }

	bool GetBlack() { return m_Black; }

	/// <summary>
	/// Change Chip color:
	/// Black - true
	/// White - false
	/// </summary>
	/// <param name="color"></param>
	void ChangeColor(bool color);

	void update(Timer* time);
	void draw();

};
