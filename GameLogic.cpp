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

void GameLogic::checkForWinner(int x, int y, System::Collections::Generic::List<System::Collections::Generic::List
	<System::Windows::Forms::Button^>^>^ matrix)
{
	// Check if five in a row or maximum number of turns used.
	if (matrix[x-1][y]->Text == matrix[x][y]->Text && matrix[x][y]->Text == matrix[x+1][y]->Text)
	{
		matrix[0][0]->Text = L"!!!";
	}

}

bool GameLogic::getPlayerTurn()
{
	return player_turn;
}

unsigned GameLogic::getTurnNumber()
{
	return turn_number;
}

void GameLogic::changeTurn()
{
	player_turn = !player_turn;
}

unsigned GameLogic::getGridSize()
{
	return grid_size;
}

