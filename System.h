#pragma once
#include "Tool.h"
#include "Board.h"

class System{
public:
	System();
	~System();
	void Start();
	void Move(Tool* board[8][8]);
	void switchPlayer();
	bool IsGameOver();

private:
	Board game;
	char player_turn;
};