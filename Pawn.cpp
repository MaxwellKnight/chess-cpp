#pragma once
#include "Pawn.h"
#include <iostream>
using namespace std;


Pawn::Pawn(char playerID) : Tool(playerID){
	// constructor
}

Pawn::~Pawn(){
	// destructor
}

bool Pawn::isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]) {
	/* this function checks if the moves the player is trying to make is legal or not.
	input - current row, destination row, current column, destination column.
	output - true if the move is legal, false else.
	*/
	Tool* qpDest = board[destRow][destCol];
	if (qpDest == 0) {
		if (currCol == destCol) {
			if (GetColor() == 'W' || GetColor() == 'B') {
				if ((destRow == abs(currRow + 2) || destRow == abs(currRow - 2)) && !_moved) {
					this->_moved = true;
					return true;
				}
				else if (destRow == currRow + 1) {
					return true;
				}
			}
			else {
				if (destRow == currRow - 1) {
					return true;
				}
			}
		}
	}
	if (abs(destCol - currCol) == 1) {
		if (GetColor() == 'W' || GetColor() == 'B') {
			if (destRow == currRow + 1) {
				return true;
			}
		}
		else {
			if (destRow == currRow - 1) {
				return true;
			}
		}
	}
	return false;
}

char Pawn::GetPiece(){
	return 'P';
}