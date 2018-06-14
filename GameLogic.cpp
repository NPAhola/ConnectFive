#include "GameLogic.h"



GameLogic::GameLogic()
{
}

void GameLogic::setupGame()
{
	// Set default values etc.
	player_turn = true;
	turn_number = 0;

	// Enable all buttons and set text empty.
}

void GameLogic::checkForWinner()
{
	// Check if five in a row or maximum number of turns used.
}

bool GameLogic::getPlayerTurn()
{
	return player_turn;
}

unsigned GameLogic::getTurnNumber()
{
	return turn_number;
}