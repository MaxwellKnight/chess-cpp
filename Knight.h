#pragma once
#include "Tool.h"

class Knight : public Tool{
public:
	Knight(char);
	~Knight();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:

};