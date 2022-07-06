#pragma once
#include "Tool.h"

class Bishop : public Tool{
public:
	Bishop(char);
	~Bishop();
	virtual char GetPiece();
	bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);

private:

};