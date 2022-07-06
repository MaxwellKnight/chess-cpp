#include "Bishop.h"
using namespace std;

Bishop::Bishop(char playerID) : Tool(playerID){
	// constructor 
}

Bishop::~Bishop(){
	// destructor
}

char Bishop::GetPiece() {
	return 'B';
}

bool Bishop::isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]){
	/* this function checks if the moves the player is trying to make is legal or not.
	input - current row, destination row, current column, destination column.
	output - true if the move is legal, false else.

	*/
	if ((destCol - currCol == destRow - currRow) || (destCol - currCol == currRow - destRow)) {
		int offset = (destRow - currRow > 0) ? 1 : -1;
		int offset2 = (destCol - currCol > 0) ? 1 : -1;
		int i;
		int j;
		for (i = currRow + offset, j = currCol + offset2;
			i != destRow;
			i = i + offset, j = j + offset2)
		{
			if (board[i][j] != 0) {
				return true;
			}
		}
		return true;
	}
	return false;
}