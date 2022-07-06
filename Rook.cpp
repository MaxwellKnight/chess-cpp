#pragma once
#include "Rook.h"
using namespace std;


Rook::Rook(char playerID) : Tool(playerID){
	// constructor
}

Rook::~Rook(){
	// destructor
}

char Rook::GetPiece(){
	return 'R';
}

bool Rook::isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]){
	/* this function checks if the moves the player is trying to make is legal or not.
	input - current row, destination row, current column, destination column.
	output - true if the move is legal, false else.

	*/
	if (currRow == destRow) {
		int offset2 = (destCol - currCol > 0) ? 1 : -1;
		for (int j = currCol + offset2; j != destCol; j = j + offset2) {
			if (board[currRow][j] != 0) {
				return false;
			}
		}
		return true;
	}
	else if (destCol == currCol) {
		int offset = (destRow - currRow > 0) ? 1 : -1;
		for (int i = currRow + offset; i != destRow; i = i + offset) {
			if (board[i][currCol] != 0) {
				return true;
			}
		}
		return true;
	}
	return false;
}