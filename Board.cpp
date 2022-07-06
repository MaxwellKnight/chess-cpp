#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(){
	// constructor
	for (int row2 = 0; row2 < 8; ++row2) {
		for (int col2 = 0; col2 < 8; ++col2) {
			board[row2][col2] = 0;
		}
	}

	for (int col2 = 0; col2 < 8; ++col2) {
		board[6][col2] = new Pawn('B');
	}
	board[7][0] = new Rook('B');
	board[7][1] = new Knight('B');
	board[7][2] = new Bishop('B');
	board[7][3] = new King('B');
	board[7][4] = new Queen('B');
	board[7][5] = new Bishop('B');
	board[7][6] = new Knight('B');
	board[7][7] = new Rook('B');

	for (int col2 = 0; col2 < 8; ++col2) {
		board[1][col2] = new Pawn('W');
	}
	board[0][0] = new Rook('W');
	board[0][1] = new Knight('W');
	board[0][2] = new Bishop('W');
	board[0][3] = new King('W');
	board[0][4] = new Queen('W');
	board[0][5] = new Bishop('W');
	board[0][6] = new Knight('W');
	board[0][7] = new Rook('W');
}

void Board::Print() {
	/*
		this function prints out the board at the current state of the pieces
		input - none
		output - none
	*/
	system("clear");
	using namespace std;
	const int width = 4;
	const int height = 3;
	int bottom = 64;
	for (int row2 = 0; row2 < 8 * height; ++row2) {
		int row_index = row2 / height;
		// Print side border with numbering
		if (row2 % 3 == 1) {
			cout << ' ' << (char)('1' + 7 - row_index) << ' ';
		}
		else {
			cout << "   ";
		}
		// Print the chess board
		for (int col2 = 0; col2 < 8 * width; ++col2) {
			int col_index = col2 / width;
			if (((row2 % 3) == 1) && ((col2 % 4) == 1 || (col2 % 4) == 2) && board[7 - row_index][col_index] != 0) {
				if ((col2 % 4) == 1) {
					cout << board[7 - row_index][col_index]->GetColor();
				}
				else {
					cout << board[7 - row_index][col_index]->GetPiece();
				}
			}
			else {
				if ((row_index + col_index) % 2 == 1) {
					cout << '=';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	// Print the bottom border with numbers
	for (int row2 = 0; row2 < height; ++row2) {
		if (row2 % 3 == 1) {
			cout << "  ";
			for (int col2 = 0; col2 < 8 * width; ++col2) {
				int col_index = col2 / width;
				if ((col2 % 4) == 1) {
					cout << char(bottom + 1);
					bottom++;
				}
				else {
					cout << ' ';
				}
			}
			cout << endl;
		}
		else {
			for (int col2 = 1; col2 < 9 * width; ++col2) {
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool Board::IsInCheck(char playerID){
	// get the king coordinates
	int row;
	int col;
	for (int row2 = 0; row2 < 8; ++row2) {
		for (int col2 = 0; col2 < 8; ++col2) {
			if (board[row2][col2] != 0) {
				if (board[row2][col2]->GetColor() == playerID) {
					if (board[row2][col2]->GetPiece() == 'K') {
						row = row2;
						col = col2;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for (int row2 = 0; row2 < 8; ++row2) {
		for (int col2 = 0; col2 < 8; ++col2) {
			if (board[row2][col2] != 0) {
				if (board[row2][col2]->GetColor() != playerID) {
					if (board[row2][col2]->IsLegalMove(row2, col2, row, col, board)) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Board::CanMove(char playerID) {
	// Run through all pieces
	for (int row2 = 0; row2 < 8; ++row2) {
		for (int col2 = 0; col2 < 8; ++col2) {
			if (board[row2][col2] != 0) {
				// If it is a piece of the current player, see if it has a legal move
				if (board[row2][col2]->GetColor() == playerID) {
					for (int i = 0; i < 8; ++i) {
						for (int j = 0; j < 8; ++j) {
							if (board[row2][col2]->IsLegalMove(row2, col2, i, j, board)) {
								// Make move and check whether king is in check
								Tool* temp = board[i][j];
								board[i][j] = board[row2][col2];
								board[row2][col2] = 0;
								bool bCanMove = !IsInCheck(playerID);
								// Undo the move
								board[row2][col2] = board[i][j];
								board[i][j] = temp;
								if (bCanMove) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

Tool* Board::getBoard(){
	return board[8][8];
}
