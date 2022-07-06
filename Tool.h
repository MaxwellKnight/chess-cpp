#pragma once

class Tool{
public:
	Tool(char);
	~Tool();
	virtual char GetPiece() = 0;
	char GetColor();
	bool IsLegalMove(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]);
	virtual bool isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]) = 0;
	char _color;

private:

};