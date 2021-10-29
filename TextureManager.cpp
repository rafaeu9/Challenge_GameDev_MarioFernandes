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
		//if we are to use the transparecy, going to assume
		//the colour key is magenta (r=255, g=0, b=255)
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
			

		////Cleane surface
		SDL_FreeSurface(tempSurface);
	}
	return tex;
}

//SDL_Texture* TextureManager::LoadIMGTexture(const char* FileName, SDL_Rect* destRect, bool Transparency)
//{
//	//Initialize PNG loading
//	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
//	{
//		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//		
//	}
//	else
//	{
//		SDL_Texture* tex = nullptr;
//		SDL_Surface* tempSurface = IMG_Load(FileName);
//
//
//		//Detect if Surface was created
//		if (!tempSurface)
//		{
//			//bitmap not loaded? Output the error
//			printf("SURFACE for Image '%s' not loaded! \n", FileName);
//			printf("%s\n", SDL_GetError());
//		}
//		else
//		{
//			//if we are to use the transparecy, going to assume
//			//the colour key is magenta (r=255, g=0, b=255)
//			if (Transparency)
//			{
//				Uint32 colourKey = SDL_MapRGB(tempSurface->format, 255, 0, 255);
//				SDL_SetColorKey(tempSurface, SDL_TRUE, colourKey);
//			}
//
//			//Transform in a texture
//			tex = SDL_CreateTextureFromSurface(Aplication::renderer, tempSurface);
//
//			//Detect if Texture was created
//			if (!tex)
//			{
//				//texture not loaded? Output the error
//				printf("TEXTURE for Image '%s' not loaded! \n", FileName);
//				printf("%s\n", SDL_GetError());
//			}
//
//			if (destRect)
//			{
//				destRect->h = tempSurface->h;
//				destRect->w = tempSurface->w;
//			}
//
//
//			////Cleane surface
//			SDL_FreeSurface(tempSurface);
//		}
//		return tex;
//	}
//
//	return NULL;
//	
//}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect dest)
{
	SDL_RenderCopy(renderer, tex, NULL, &dest);

	
}
