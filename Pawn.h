#pragma once
#include "Tool.h"

class Pawn : public Tool{
public:
	Pawn(char);
	~Pawn();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:
	bool _moved = false;
};