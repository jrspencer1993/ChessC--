#include "Game.h"
#include <SDL_events.h>
#include "TextureManager.h"

namespace GameSystem
{
	void Game::init()
	{
		m_Event = new SDL_Event;
		m_window = NULL;
		m_Renderer = NULL;
		m_Running = true;
		m_Is_Selected = false;

	}

	Game::Game(const char* p_Title, int p_Width, int p_Height)
	{
		init();
		m_window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			p_Width, p_Height, SDL_WINDOW_SHOWN);

		m_Renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_Board = new Board(p_Height, m_Renderer);
		m_WPawn = new Pieces(m_Renderer, WHITE_PAWN_PATH, 75);
		m_WPawn->setPosition(100, 100);
		m_BoardPieces = new PiecesManger(m_Renderer, p_Height);
	}

	Game::~Game()
	{
		delete m_WPawn;
		delete m_Board;
		delete m_Event;
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_window);
	}

	bool Game::isRunning() const
	{
		return m_Running;
	}

	void Game::pollEvent()
	{
		while (SDL_PollEvent(m_Event))
		{
			switch (m_Event->type)
			{
				case SDL_QUIT:
					m_Running = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch (m_Event->button.button)
					{
						case SDL_BUTTON_LEFT:
							m_Is_Selected = true;
							int x, y;
							SDL_GetMouseState(&x, &y);
							m_WPawn->setPosition(x, y);
							break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					m_Is_Selected = false;
			}
			
		}
	}

	void Game::update()
	{
		// lets add some movement
		if (m_Is_Selected)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			x -= 35; // offsetx
			y -= 35; // offsety
			m_WPawn->setPosition(x, y);
		}
	}

	void Game::render()
	{
		//Set Window Background color
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);
		//Clear previous windows
		SDL_RenderClear(m_Renderer);

		//draws the board
		m_Board->drawBoard();
		m_BoardPieces->drawPieces();
		//draws the white pawn
		m_WPawn->draw();

		SDL_RenderPresent(m_Renderer);
		//Draw All Obstacles
	}


};