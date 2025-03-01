#pragma once 
#include "Piece.h"
#include <SDL.h>
#include <vector>
#include "Board.h"
#include <array>
#include <string>
#include "PiecesDef.h"
#include "Moves.h"


namespace GameSystem {
    class PiecesManager {

        //const int MAX_PIECES_LINE = 8; // Size of the board (8x8)
        //const int WHITE_KING = 1; // Representing the white king as 1

    public:
        //std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;

        // constructor and destoryer
        PiecesManager(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManager() {}

        // Public Functions (main funtions)
        void drawPieces();
        void resetPieces();
        void updateBoardPieces(int* p_MouseX, int* p_MouseY);
        void isPieceSelect(bool p_state, int* p_MouseX, int* p_MouseY);

    public:
        // Setter
        void setSize(int p_PieceSize);
        std::string GameOver();

        // Getter
        Player getPlayer() const;

        // Add the declaration of swapRandomWhitePieces() here
        bool swapRandomWhitePieces();

    private:
        // Private Functions 
        void init();
        void initDefaultBoard();
        bool isBlack();
        void addPiece(const char* p_FilePath, int row, int col);
        void CalculatePieces();


    private:
        // Private Variables
        SDL_Renderer* m_Renderer;
        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;
        bool m_IsLastBlackMove = 1;
        Piece** m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };


};