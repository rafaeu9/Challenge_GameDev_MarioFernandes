#include "Sprite.h"
#include <string>



Sprite::Sprite()
{
	

	position.x = 400;
	position.y = 0;

	//sprte position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = position.x;
	destRect.y = position.y;
	destRect.h = destRect.w = 64;
}

Sprite::Sprite(const char* path, bool useTransparency)
{

	position.x = 400;
	position.y = 0;

	//sprte position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = position.x;
	destRect.y = position.y;
	destRect.h = destRect.w = 64;

	setTex(path, useTransparency);
}

//Load Image
void Sprite::setTex(const char* path, bool useTransparency)
{
	Texture = TextureManager::LoadBMPTexture(path,&destRect, useTransparency);	
}

void Sprite::SetPostion(int x, int y)
{
	position.x = x; 
	position.y = y; 
	MovePosition.x = x; 
	MovePosition.y = y;

	destRect.x = position.x;
	destRect.y = position.y;

}


void Sprite::ChangeColor(bool color)
{
	black = color;

	if(!color)
	SDL_SetTextureColorMod(Texture, 255, 255, 255);
	else
	SDL_SetTextureColorMod(Texture, 0, 0, 0);
}

void Sprite::update(Timer* time)
{
	if (!(MovePosition == position))
	{
		isMoving = true;

		

		Vector2 temp = MovePosition - position;

		float t = sqrt(pow(temp.x, 2) + pow(temp.y, 2));

		position.x += temp.x / t * Speed * time->GetDeltaTime();
		position.y += temp.y / t * Speed * time->GetDeltaTime();

		if (t < 5)
			position = MovePosition;
	}
	else
		isMoving = false;

	destRect.x = position.x;
	destRect.y = position.y;
}

///Draw on screen
void Sprite::draw()
{	
	TextureManager::Draw(Texture, destRect);
}

void Sprite::rotation()
{	

}
