#pragma once
#include "Tool.h"
using namespace std;


Tool::Tool(char color) : _color(color){
	// constructor
}

Tool::~Tool(){
	// destructor
}

char Tool::GetColor(){
	return _color;
}

bool Tool::IsLegalMove(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]) {
	Tool* dst = board[destRow][destCol];
	if ((dst == 0) || (_color != dst->GetColor())) {
		return isLegal(currRow, currCol, destRow, destCol, board);
	}
	return false;
}
