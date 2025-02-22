#pragma once 
#include "Piece.h"
#include <SDL_render.h>
#include <vector>
#include "Board.h"
#include <array>

namespace PIECES_TYPE {
    const int EMPTY = 0;
    const int WHITE_KING = 1;
    const int WHITE_QUEEN = 2;
    const int WHITE_BISHOP = 3;
    const int WHITE_KNIGHT = 4;
    const int WHITE_ROOK = 5;
    const int WHITE_PAWN = 6;
    const int BLACK_KING = -1;
    const int BLACK_QUEEN = -2;
    const int BLACK_BISHOP = -3;
    const int BLACK_KNIGHT = -4;
    const int BLACK_ROOK = -5;
    const int BLACK_PAWN = -6;
};


namespace GameSystem {
    class PiecesManager {
    public:
        PiecesManager(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManager() {}

        void CalculatePieces();
        void drawPieces();
        void updateBoardPieces(int* p_MouseX, int* p_MouseY);
        void isPieceSelect(bool p_state, int* p_MouseX, int* p_MouseY);

        void setSize(int p_PieceSize);
    private:
        void init();
        void initDefaultBoard();
        void addPiece(const char* p_FilePath, int row, int col);

        SDL_Renderer* m_Renderer;

        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;

        Piece** m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };
};