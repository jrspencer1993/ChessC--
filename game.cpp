#include "Game.h"
#include <iostream>

namespace GameSystem
{
    void Game::init()
    {
        m_CurrentmouseX = new int;
        m_CurrentmouseY = new int;
        m_Event = new SDL_Event;
        m_Window = NULL;
        m_Renderer = NULL;
        m_Running = true;
        m_Is_Selected = false;
    }

    // Constructor and Destructor
    Game::Game(const char* p_Title, int p_Width, int p_Height)
    {
        init();
        m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            p_Width, p_Height, SDL_WINDOW_SHOWN);
        m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_BoardPieces = new PiecesManager(m_Renderer, p_Height);
        m_Board = new Board(p_Height, m_Renderer);
        m_BoardPieces->setSize(m_Board->getPieceSize());
        updateMousePosition();
    }
    Game::~Game()
    {
        if (m_CurrentmouseX != NULL || m_CurrentmouseY != NULL)
            delete m_CurrentmouseX, m_CurrentmouseY;
        delete m_Board;
        delete m_Event;
        SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(m_Window);
    }

    // Private Fuction
    void  Game::updateMousePosition()
    {
        SDL_GetMouseState(m_CurrentmouseX, m_CurrentmouseY);
    }

    // Public Functions
    bool  Game::isRunning() const
    {
        return m_Running;
    }
    void Game::resetGame()
    {
        m_Running = true;
        m_BoardPieces->resetPieces();
    }
    void Game::pollEvent()
    {
        while (SDL_PollEvent(m_Event)) {
            switch (m_Event->type) {
            case SDL_QUIT:
                m_Running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (m_Event->button.button == SDL_BUTTON_LEFT) {
                    m_BoardPieces->isPieceSelect(true, m_CurrentmouseX, m_CurrentmouseY);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (m_Event->button.button == SDL_BUTTON_LEFT) {
                    m_BoardPieces->isPieceSelect(false, m_CurrentmouseX, m_CurrentmouseY);
                }
                break;
            default:
                break;
            }
        }

    }
    void Game::update()
    {
        // lets add some movement
        updateMousePosition();
        m_BoardPieces->updateBoardPieces(m_CurrentmouseX, m_CurrentmouseY);
        m_Board->UpdatePlayer(m_BoardPieces->getPlayer());
        if (m_Running)
            m_Running = (m_BoardPieces->GameOver() != "") ? false : true;
    }
    void Game::render()
    {
        // Setting BackGround Winodow Color 
        SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);

        // clearing Winodw from previous drawn objects
        SDL_RenderClear(m_Renderer);

        // draw Objects

        m_Board->drawBoard();
        m_BoardPieces->drawPieces();

        SDL_RenderPresent(m_Renderer);
    }

    SDL_Renderer* Game::getRenderer() const
    {
        return m_Renderer;
    }

    // Getter
    void Game::getMousePosition(int* x, int* y)
    {
        SDL_GetMouseState(x, y);
    }
};