#include "pch.h"
#include "CppUnitTest.h"
#include "PiecesManager.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameSystem
{
    TEST_CLASS(PiecesManagerTest)
    {
    public:
        // Test for checking if the default board initializes correctly
        TEST_METHOD(TestInitDefaultBoard)
        {
            PiecesManager pm;

            // Call the init function
            pm.initDefaultBoard();

            // Check if Initital board is build
            auto board = pm.getBoardPieces();

            // Check row 1 (0th index)
            Assert::AreEqual(board[0][0], -5);
            Assert::AreEqual(board[0][1], -4);
            Assert::AreEqual(board[0][2], -3);
            Assert::AreEqual(board[0][3], -2);
            Assert::AreEqual(board[0][4], -1);
            Assert::AreEqual(board[0][5], -3);
            Assert::AreEqual(board[0][6], -4);
            Assert::AreEqual(board[0][7], -5);

            // Check row 2 (1st index)
            for (int i = 0; i < 8; ++i)
            {
                Assert::AreEqual(board[1][i], -6);
            }

            // Check row 7 (6th index) for white pieces
            for (int i = 0; i < 8; ++i)
            {
                Assert::AreEqual(board[6][i], 6);
            }

            // Check row 8 (7th index) for white pieces
            for (int i = 0; i < 8; ++i)
            {
                Assert::AreEqual(board[7][i], 5 - i);  // 5, 4, 3, 2, 1, 3, 4, 5
            }
        }

        // Test for after calling swapRandomWhitePieces (to ensure board is modified)
        TEST_METHOD(TestSwapRandomWhitePieces)
        {
            PiecesManager pm;
            pm.initDefaultBoard();

            // Capture the initial board
            auto initialBoard = pm.getBoardPieces();

            pm.swapRandomWhitePieces();

            // Capture the board after the swap
            auto postSwapBoard = pm.getBoardPieces();

            // Assert that the board has changed. This assumes the board isn't shuffled back
            bool isBoardChanged = false;
            for (int row = 0; row < 8; ++row)
            {
                for (int col = 0; col < 8; ++col)
                {
                    if (initialBoard[row][col] != postSwapBoard[row][col])
                    {
                        isBoardChanged = true;
                        break;
                    }
                }
                if (isBoardChanged)
                    break;
            }

            Assert::IsTrue(isBoardChanged, L"Board should be changed after swapRandomWhitePieces.");
        }
    };
}
