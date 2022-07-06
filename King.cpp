#include "King.h"
using namespace std;

King::King(char playerID) : Tool(playerID){
	// constructor
}

King::~King(){
	// destructor
}

bool King::isLegal(int currRow, int currCol, int destRow, int destCol, Tool* board[8][8]){
	/* this function checks if the moves the player is trying to make is legal or not.
	input - current row, destination row, current column, destination column.
	output - true if the move is legal, false else.

	*/
	int row = destRow - currRow;
	int col = destCol - currCol;
	if (((row >= -1) && (row <= 1)) &&
		((col >= -1) && (col <= 1)))
	{
		return true;
	}
	return false;
}

char King::GetPiece(){
	return 'K';
}