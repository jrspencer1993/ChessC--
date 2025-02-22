#pragma once
#include <SDL.h>
#include <SDL_image.h>

namespace GameSystem
{
	class TextureManager
	{
	public:
		static SDL_Texture* GetTexture(SDL_Renderer* p_Renderer, const char* p_FilePath);
		//static void Render(SDL_Renderer* p_Renderer, SDL_Texture* p_Texture, int p_SrcPieceSize, int p_DrawPieceSize, int p_x, int p_y);
		static void Render(SDL_Renderer* p_Renderer, SDL_Texture* p_Texture, SDL_Rect* p_DsntRect);

	private:

	};
};
