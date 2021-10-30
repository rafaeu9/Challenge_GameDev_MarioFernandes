#include "TextureManager.h"

SDL_Renderer* TextureManager::renderer = nullptr;

SDL_Texture* TextureManager::LoadBMPTexture(const char* FileName, SDL_Rect* destRect, bool Transparency)
{
	SDL_Texture* tex = nullptr;
	SDL_Surface* tempSurface = SDL_LoadBMP(FileName);


	//Detect if Surface was created
	if (!tempSurface)
	{
		//bitmap not loaded? Output the error
		printf("SURFACE for bitmap '%s' not loaded! \n", FileName);
		printf("%s\n", SDL_GetError());
	}
	else
	{
		//if we are to use the transparency, going to assume
		//the color key is magenta (r=255, g=0, b=255)
		if (Transparency)
		{
			Uint32 colourKey = SDL_MapRGB(tempSurface->format, 255, 0, 255);
			SDL_SetColorKey(tempSurface, SDL_TRUE, colourKey);
		}

		//Transform in a texture
		tex = SDL_CreateTextureFromSurface(renderer, tempSurface);

		//Detect if Texture was created
		if (!tex)
		{
			//texture not loaded? Output the error
			printf("TEXTURE for bitmap '%s' not loaded! \n", FileName);
			printf("%s\n", SDL_GetError());
		}

		if (destRect)
		{
			destRect->h = tempSurface->h;
			destRect->w = tempSurface->w;
		}
			

		////Clean surface
		SDL_FreeSurface(tempSurface);
	}
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect dest)
{
	SDL_RenderCopy(renderer, tex, NULL, &dest);	
}
