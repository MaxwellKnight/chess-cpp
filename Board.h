#pragma once
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"

class Board{
public:
	Board();
	void Print();
	bool IsInCheck(char);
	bool CanMove(char);
	Tool* getBoard();
	Tool* board[8][8];
};
