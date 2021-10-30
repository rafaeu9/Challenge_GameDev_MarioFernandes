#include "Sprite.h"
#include <string>



Sprite::Sprite()
{
	

	m_Position.x = 400;
	m_Position.y = 0;

	//sprite position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = m_Position.x;
	destRect.y = m_Position.y;
	destRect.h = destRect.w = 64;
}

Sprite::Sprite(const char* path, bool useTransparency)
{

	m_Position.x = 400;
	m_Position.y = 0;

	//sprite position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = m_Position.x;
	destRect.y = m_Position.y;
	destRect.h = destRect.w = 64;

	setTex(path, useTransparency);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_Texture);
}

//Load Image
void Sprite::setTex(const char* path, bool useTransparency)
{
	m_Texture = TextureManager::LoadBMPTexture(path,&destRect, useTransparency);	
}

void Sprite::SetPostion(int x, int y)
{
	m_Position.x = x; 
	m_Position.y = y; 
	m_MovePosition.x = x; 
	m_MovePosition.y = y;

	destRect.x = m_Position.x;
	destRect.y = m_Position.y;

}


void Sprite::ChangeColor(bool color)
{
	m_Black = color;

	if(!color)
	SDL_SetTextureColorMod(m_Texture, 255, 255, 255);
	else
	SDL_SetTextureColorMod(m_Texture, 0, 0, 0);
}

void Sprite::update(Timer* time)
{
	if (!(m_MovePosition == m_Position))
	{
		m_isMoving = true;

		//Get Delta vector
		Vector2 temp = m_MovePosition - m_Position;

		//Get Magnitude
		float t = sqrt(pow(temp.x, 2) + pow(temp.y, 2));

		//Update the current position based on the unit vector * time and speed 
		m_Position.x += temp.x / t * m_Speed * time->GetDeltaTime();
		m_Position.y += temp.y / t * m_Speed * time->GetDeltaTime();

		//Snap to position if close
		if (t < 5)
			m_Position = m_MovePosition;
	}
	else
		m_isMoving = false;

	//Update texture position
	destRect.x = m_Position.x;
	destRect.y = m_Position.y;
}

///Draw on screen
void Sprite::draw()
{	
	TextureManager::Draw(m_Texture, destRect);
}

