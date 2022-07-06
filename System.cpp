#include "System.h"
#include <iostream>
#include <string>
using namespace std;


System::System() : player_turn('W'){
	// constructor
}

System::~System(){
	// destructor
}

void System::Start(){
	do {
		Move(game.board);
		switchPlayer();
	} while (!IsGameOver());
	game.Print();
}

void System::Move(Tool* board[8][8]){
	/*
		this function gets input from the user and checks if the input is legal
		after that it checks if the player is not in check and that
		the move the player trying to make is legal
		if so, than move the player piece.
		input - Tool* to board[8][8]
		output - none.
	*/
	using namespace std;
	bool valid = false;
	string move;
	do {
		game.Print();
		// iinput
		cout << player_turn << "'s Move: ";
		cin >> move;
		if (move.length() == 5){
			if (move[0] == 'a') {
				move[0]++;
				move[3]++;
			}
			else{
				move[0]++;
				move[3]++;
			}
			int start_row = int(move[1] - '0') - 1;
			int start_col = int(move[0] - 'a') - 1;

			int end_row = abs(int(move[4] - '0')) - 1;
			int end_col = abs(int(move[3] - 'a')) - 1;

			// Check that the indices are in range
			// and that the source and destination are different
			if ((start_row >= 0 && start_row <= 7) &&
				(start_col >= 0 && start_col <= 7) &&
				(end_row >= 0 && end_row <= 7) &&
				(end_col >= 0 && end_col <= 7)) {

				Tool* currPiece = board[start_row][start_col];
				// Check that the piece is the correct color
				if ((currPiece != 0) && (currPiece->GetColor() == player_turn)) {
					// Check that the destination is a valid destination
					if (currPiece->IsLegalMove(start_row, start_col, end_row, end_col, board)) {
						//move
						Tool* qpTemp = board[end_row][end_col];
						board[end_row][end_col] = board[start_row][start_col];
						board[start_row][start_col] = 0;
						// Make sure that the current player is not in check
						if (!game.IsInCheck(player_turn)) {
							delete qpTemp;
							valid = true;
						}
						else { // Undo the last move
							board[start_row][start_col] = board[end_row][end_col];
							board[end_row][end_col] = qpTemp;
						}
					}
				}
			}
			if (!valid) {
				cout << "Invalid Move!" << endl;
			}
		}
	} while (!valid);
}

void System::switchPlayer(){
	// switch for white to black and visa-versa
	player_turn = (player_turn == 'W') ? 'B' : 'W';
}

bool System::IsGameOver(){
	/*
		this function checks if the current player can make more moves.
		if he cannot, the check or stalemate
		input - none
		output - false if can move, true if cannot.
	*/
		bool bCanMove(false);
		bCanMove = game.CanMove(player_turn);
		if (!bCanMove) {
			if (game.IsInCheck(player_turn)) {
				switchPlayer();
				std::cout << "Checkmate, " << player_turn << " Wins!" << std::endl;
			}
			else {
				std::cout << "Stalemate!" << std::endl;
			}
		}
		return !bCanMove;
}
