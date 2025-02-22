#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Board.h"
#include "Pieces.h"
#include "PiecesManager.h"

namespace GameSystem
{
	class Game
	{
	public:
		Game(const char* p_Title, int P_Width, int p_Height);
		~Game();
		bool isRunning() const;
		void update();
		void render();
		void pollEvent();
	private:
		void init();
		void drawBoard();
		bool m_Running = false;

		Board* m_Board;
		bool m_Is_Selected;
		SDL_Window* m_window;
		SDL_Renderer* m_Renderer;
		SDL_Event* m_Event;

		Pieces* m_WPawn;
		PiecesManger* m_BoardPieces;

	};
};



