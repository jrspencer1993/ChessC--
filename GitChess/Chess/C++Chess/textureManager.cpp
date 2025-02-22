#include <SDL.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include "TextureManager.h"
#include <cstddef>

namespace GameSystem
{
	SDL_Texture* TextureManager::GetTexture(SDL_Renderer* p_Renderer, const char *p_FilePath)
	{
		SDL_Texture* _texture = IMG_LoadTexture(p_Renderer, p_FilePath);
		if (_texture == NULL)
		{
			SDL_Log("Failed to Load the image from %s \n {ERROR: %s } \n", p_FilePath, SDL_GetError());
			return NULL;
		}

		return _texture;
	}

	void TextureManager::Render(SDL_Renderer *p_Renderer, SDL_Texture *p_Texture,
		SDL_Rect* p_DsntRect)
	{
		SDL_RenderCopy(p_Renderer, p_Texture, NULL, p_DsntRect);
	}
		
}