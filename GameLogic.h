#pragma once
ref class GameLogic
{
public:
	GameLogic();

	void setupGame();
	void checkForWinner();

	bool getPlayerTurn();
	unsigned int getTurnNumber();

private:
	bool player_turn = true;	// True = X's turn.
	unsigned int turn_number = 0;	// Number of the current turn.
};

