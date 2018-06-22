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
		if (countConnected(x, y, 1, matrix) == 5)
		{
			five_connected = true;
		}
	}
	else if (matrix[x][y]->Text == matrix[x+1][y+1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("BR");
		if (countConnected(x, y, 8, matrix) == 5)
		{
			five_connected = true;
		}
	}
	// Diagonal from bottom left to top right
	if (matrix[x-1][y+1]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("BL");
		if (matrix[x][y]->Text == matrix[x+1][y-1]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Diag BL->TR");
		}
		if (countConnected(x, y, 6, matrix) == 5)
		{
			five_connected = true;
		}
	}
	else if (matrix[x][y]->Text == matrix[x+1][y-1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("TR");
		if (countConnected(x, y, 3, matrix) == 5)
		{
			five_connected = true;
		}
	}
	// Horizontal
	if (matrix[x-1][y]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("L");
		if (matrix[x][y]->Text == matrix[x+1][y]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Horizontal");
		}
		if (countConnected(x, y, 4, matrix) == 5)
		{
			five_connected = true;
		}
	}
	else if (matrix[x][y]->Text == matrix[x+1][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("R");
		if (countConnected(x, y, 5, matrix) == 5)
		{
			five_connected = true;
		}
	}
	// Vertical
	if (matrix[x][y-1]->Text == matrix[x][y]->Text)
	{
		System::Diagnostics::Debug::WriteLine("U");
		if (matrix[x][y]->Text == matrix[x][y+1]->Text)
		{
			System::Diagnostics::Debug::WriteLine("Vertical");
		}
		if (countConnected(x, y, 2, matrix) == 5)
		{
			five_connected = true;
		}
	}
	else if (matrix[x][y]->Text == matrix[x][y+1]->Text)
	{
		System::Diagnostics::Debug::WriteLine("D");
		if (countConnected(x, y, 7, matrix) == 5)
		{
			five_connected = true;
		}
	}
	
	if (five_connected)
	{
		System::Diagnostics::Debug::WriteLine("WINNER");
	}

}

int GameLogic::countConnected(int x, int y, int dir, System::Collections::Generic::List<System::Collections::Generic::List
	<System::Windows::Forms::Button^>^>^ matrix)
{
	int connected = 1;

	// Count consecutive symbols according to direction.			1 2 3
	// 1 = Top Left; 2 = Up; 3 = Top Right; 4 = Left;				4 X 5
	// 5 = Right; 6 = Bottom Left; 7 = Down; 8 = Bottom Right.		6 7 8
	switch (dir)
	{
	case 1: for (int i = 1; matrix[x][y]->Text == matrix[x-i][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 2: for (int i = 1; matrix[x][y]->Text == matrix[x][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 3: for (int i = 1; matrix[x][y]->Text == matrix[x+i][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 4: for (int i = 1; matrix[x][y]->Text == matrix[x-i][y]->Text; i++)
	{
		connected++;
	}break;
	case 5: for (int i = 1; matrix[x][y]->Text == matrix[x+i][y]->Text; i++)
	{
		connected++;
	}break;
	case 6: for (int i = 1; matrix[x][y]->Text == matrix[x-i][y+i]->Text; i++)
	{
		connected++;
	}break;
	case 7: for (int i = 1; matrix[x][y]->Text == matrix[x][y+i]->Text; i++)
	{
		connected++;
	}break;
	case 8: for (int i = 1; matrix[x][y]->Text == matrix[x+i][y+i]->Text; i++)
	{
		connected++;
	}break;
	}

	return connected;
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

