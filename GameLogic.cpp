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
	bool five_connected = false;
	// Check if five in a row or maximum number of turns used.

	// Diagonal from top left to bottom right
	if (matrix[x-1][y-1]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("TL");
		if (matrix[x][y]->Text == matrix[x+1][y+1]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Diag TL->BR");
			// Call recursively.
		}
		five_connected = true;
	}
	else if (matrix[x][y]->Text == matrix[x+1][y+1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("BR");
		five_connected = true;
	}
	// Diagonal from bottom left to top right
	if (matrix[x-1][y+1]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("BL");
		if (matrix[x][y]->Text == matrix[x+1][y-1]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Diag BL->TR");
		}
		five_connected = true;
	}
	else if (matrix[x][y]->Text == matrix[x+1][y-1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("TR");
		five_connected = true;
	}
	// Horizontal
	if (matrix[x-1][y]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("L");
		if (matrix[x][y]->Text == matrix[x+1][y]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Horizontal");
		}
		five_connected = true;
	}
	else if (matrix[x][y]->Text == matrix[x+1][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("R");
		five_connected = true;
	}
	// Vertical
	if (matrix[x][y-1]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("U");
		if (matrix[x][y]->Text == matrix[x][y+1]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Vertical");
		}
		five_connected = true;
	}
	else if (matrix[x][y]->Text == matrix[x][y+1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("D");
		five_connected = true;
	}
	
	if (!five_connected)
	{
		System::Diagnostics::Debug::WriteLine("No neighbours");
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

