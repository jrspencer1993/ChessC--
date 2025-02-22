#include <SDL.h>
#include <SDL_image.h>
#include "Pieces.h"
#include <SDL_render.h>
#include "TextureManager.h"

namespace GameSystem {
	void Pieces::init()
	{
		m_PieceProperty = new SDL_Rect;
		*m_PieceProperty = {};
		m_PieceTexture = NULL;
	}

	Pieces::Pieces(SDL_Renderer* p_Renderer, const char* p_FilePath, int p_PieceSize)
		: m_Renderer(p_Renderer)
	{
		init();
		
		m_PieceTexture = TextureManager::GetTexture(m_Renderer, p_FilePath); 
		
		m_PieceProperty->w = p_PieceSize;
		m_PieceProperty->h = p_PieceSize;
	}
	Pieces::~Pieces()
	{
		delete m_PieceProperty;
		if(m_PieceTexture != NULL)
		{
			SDL_DestroyTexture(m_PieceTexture);
		}
	}
	void Pieces::setPosition(int p_X, int p_Y) 
	{
		m_PieceProperty->x = p_X;
		m_PieceProperty->y = p_Y;
	}
	void Pieces::draw()
	{
		TextureManager::Render(m_Renderer, m_PieceTexture, m_PieceProperty);
		//SDL_RenderCopy(m_Renderer, m_PieceTexture, NULL, m_PieceProperty);
	}
};