#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Board.h"
#include "PiecesManager.h"

namespace GameSystem
{
    class Game
    {
    public:
        Game(const char* p_Title, int p_Width, int p_Height);
        ~Game();
        void update();
        void pollEvent();
        bool isRunning()const;
        void render();
    private:
        void init();
        void drawBoard();
        void updateMousePosition();
        void getMousePosition(int* x, int* y);
        bool m_Running = false;

        Board* m_Board;
        bool m_Is_Selected;
        int* m_CurrentmouseX;
        int* m_CurrentmouseY;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        SDL_Event* m_Event;
        PiecesManager* m_BoardPieces;
    };
};



