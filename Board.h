#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <array>
#include "PiecesDef.h"
#include "MoveDef.h"

namespace GameSystem
{
    class Board {
    public:

        // constructor
        Board(int p_SizeBoard, SDL_Renderer* p_Renderer); // i will only drawSquare 

        int GetBoardSize() const { return m_BoardSize; }
        int GetPiecesSize() const { return m_PiecesSize; }


        // Public Function
        void drawBoard();
        void UpdatePlayer(Player p_Player); // handle player pieces hints
        int getPieceSize() const;
    private:
        // Private Function
        void resetBoardColor();
        void SetHighlight(unsigned const int row, unsigned const int col);
        void showHints(Player p_Player);
        void showPieceHightlight(unsigned const int row, unsigned const int col);

        // hints pieces
        void WhitePawnHint();
        void BlackPawnHint();
        void KingHint();
        void QueenHint();
        void KnightHint();
        void RookHint();
        void BishopHint();
    private:
        // Private Variable 
        SDL_Renderer* m_Renderer;
        std::array<int, MAX_PIECES_SPACE  > m_Pieces;
        std::array<std::array<SDL_Color, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardColor;
        Player m_Player;
        int m_PiecesSize = 75;
        int m_BoardSize;
    };
};
