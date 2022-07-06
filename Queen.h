#pragma once
#include "Tool.h"

class Queen : public Tool{
public:
	Queen(char);
	~Queen();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:

};