#pragma once
#include <array>
#include "MoveDef.h"
#include "PiecesDef.h"

class Moves
{
public:
    static bool VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
};
