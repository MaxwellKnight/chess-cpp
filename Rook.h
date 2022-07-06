#pragma once
#include "Tool.h"

class Rook : public Tool{
public:
	Rook(char);
	~Rook();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:

};