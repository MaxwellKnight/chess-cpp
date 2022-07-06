#pragma once
#include "Tool.h"

class King : public Tool{
public:
	King(char);
	~King();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:

};