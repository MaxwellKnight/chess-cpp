#include "Knight.h"
using namespace std;


Knight::Knight(char playerID) : Tool(playerID){
	// constructor
}

Knight::~Knight(){
	// destructor
}

bool Knight::isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]){
	/* this function checks if the moves the player is trying to make is legal or not.
	input - current row, destination row, current column, destination column.
	output - true if the move is legal, false else.

	*/
	if ((currCol == destCol + 1) || (currCol == destCol - 1)) {
		if ((currRow == destRow + 2) || (currRow == destRow - 2)) {
			return true;
		}
	}
	if ((currCol == destCol + 2) || (currCol == destCol - 2)) {
		if ((currRow == destRow + 1) || (currRow == destRow - 1)) {
			return true;
		}
	}
	return false;
}

char Knight::GetPiece(){
	return 'N';
}