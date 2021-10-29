#include "Sprite.h"
#include <string>



Sprite::Sprite()
{
	//sprte position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = destRect.y = 0;
	destRect.h = destRect.w = 64;
}

Sprite::Sprite(const char* path, bool useTransparency)
{
	//sprte position n screen
	srcRect.x = srcRect.y = 0;
	destRect.x = destRect.y = 0;
	destRect.h = destRect.w = 64;

	setTex(path, useTransparency);
}

//Load Image
void Sprite::setTex(const char* path, bool useTransparency)
{
	Texture = TextureManager::LoadBMPTexture(path,&destRect, useTransparency);	
}


void Sprite::update()
{
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
