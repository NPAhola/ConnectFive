#include "GameLogic.h"
#include "ConnectFiveGUI.h"

using namespace System::Collections;
using namespace System::Windows::Forms;

ConnectFive::GameLogic::GameLogic()
{
	
}

void ConnectFive::GameLogic::setupGame(Generic::List<Generic::List<Button^>^>^ matrix)
{
	// Set default values concerning game logic and enable all buttons.
	player_turn_ = true;
	turn_number_ = 0;

	for (int i = 0; i < grid_size_; i++)
	{
		for (int j = 0; j < grid_size_; j++)
		{
			matrix[i][j]->Enabled = true;
			matrix[i][j]->Text = L"";
		}
	}
}

void ConnectFive::GameLogic::disableAllButtons(Generic::List<Generic::List<Button^>^>^ matrix)
{
	// Disable all buttons on the gameboard.
	for (int i = 0; i < grid_size_; i++)
	{
		for (int j = 0; j < grid_size_; j++)
		{
			matrix[i][j]->Enabled = false;
		}
	}
}

bool ConnectFive::GameLogic::checkForWinner(int x, int y, Generic::List<Generic::List<Button^>^>^ matrix)
{
	/*
	@brief: Check if the game has ended after the latest button press.
	@param x,y: Coordinates of the button just pressed.
	@param matrix: The gameboard.
	@return: True if there's five same symbols connected, false otherwise.
	*/

	bool five_connected = false;

	// Check if five in a row exists. Possible connect-5's require that 
	// direction starting from (x,y) plus its counter-direction have five
	// same symbols in a row.
		
	// Diagonal from top left to bottom right
	if (x != 0 && y != 0 && matrix[x-1][y-1]->Text == matrix[x][y]->Text)
	{
		if (countConnected(x, y, 1, matrix) == 5)
		{
			// Diagonal to upper left.
			five_connected = true;
		}
		else if (x != grid_size_ - 1 && y != grid_size_ - 1 && matrix[x][y]->Text == matrix[x+1][y+1]->Text)
		{
			if (countConnected(x, y, 1, matrix) + countConnected(x+1, y+1, 8, matrix) == 5)
			{
				// Somewhere middle of a diagonal.
				five_connected = true;
			}
		}
		
	}
	else if (x != grid_size_ - 1 && y != grid_size_ - 1 && matrix[x][y]->Text == matrix[x+1][y+1]->Text)
	{
		if (countConnected(x, y, 8, matrix) == 5)
		{
			// Diagonal to lower right.
			five_connected = true;
		}
	}
	// Diagonal from bottom left to top right
	if (x != 0 && y != grid_size_ - 1 && matrix[x-1][y+1]->Text == matrix[x][y]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 6, matrix) == 5)
		{
			// Diagonal to lower left.
			five_connected = true;
		}
		else if (x != grid_size_ - 1 && y != 0 && matrix[x][y]->Text == matrix[x+1][y-1]->Text)
		{
			if (countConnected(x, y, 3, matrix) + countConnected(x-1, y+1, 6, matrix) == 5)
			{
				// Somewhere middle of a diagonal.
				five_connected = true;
			}
		}
		
	}
	else if (x != grid_size_ - 1 && y != 0 && matrix[x][y]->Text == matrix[x+1][y-1]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 3, matrix) == 5)
		{
			// Diagonal to upper right.
			five_connected = true;
		}
	}
	// Horizontal
	if (x != 0 && matrix[x-1][y]->Text == matrix[x][y]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 4, matrix) == 5)
		{
			// Horizontal line to left.
			five_connected = true;
		}
		else if (x != grid_size_ - 1 && matrix[x][y]->Text == matrix[x+1][y]->Text)
		{
			if (countConnected(x, y, 4, matrix) + countConnected(x+1, y, 5, matrix) == 5)
			{
				// Somewhere middle of a horizontal line.
				five_connected = true;
			}
		}
		
	}
	else if (x != grid_size_ - 1 && matrix[x][y]->Text == matrix[x+1][y]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 5, matrix) == 5)
		{
			// Horizontal line to right.
			five_connected = true;
		}
	}
	// Vertical
	if (y != 0 && matrix[x][y-1]->Text == matrix[x][y]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 2, matrix) == 5)
		{
			// Vertical line upwards.
			five_connected = true;
		}
		else if (y != grid_size_ - 1 && matrix[x][y]->Text == matrix[x][y+1]->Text)
		{
			if (countConnected(x, y, 2, matrix) + countConnected(x, y+1, 7, matrix) == 5)
			{
				// Somewhere middle of a vertical line.
				five_connected = true;
			}
		}
		
	}
	else if (y != grid_size_ - 1 && matrix[x][y]->Text == matrix[x][y+1]->Text
		&& !five_connected)
	{
		if (countConnected(x, y, 7, matrix) == 5)
		{
			// Vertical line downwards.
			five_connected = true;
		}
	}
	
	if (five_connected)
	{
		// There was a connect-5.
		disableAllButtons(matrix);
		return true;
	}
	
	return false;	// No winner found.
}

bool ConnectFive::GameLogic::checkForDraw(Generic::List<Generic::List<Button^>^>^ matrix)
{
	// Check if there's a draw.
	if (turn_number_ == grid_size_ * grid_size_)
	{
		disableAllButtons(matrix);
		return true;
	}
	return false;
}

int ConnectFive::GameLogic::countConnected(int x, int y, int dir, Generic::List<Generic::List<Button^>^>^ matrix)
{
	// Count consecutive symbols according to direction from (x,y).			1 2 3
	// 1 = Top Left; 2 = Up; 3 = Top Right; 4 = Left;						4 X 5
	// 5 = Right; 6 = Bottom Left; 7 = Down; 8 = Bottom Right.				6 7 8

	int connected = 1;
	switch (dir)
	{
	case 1: for (int i = 1; x-i >= 0 && y-i >= 0 && matrix[x][y]->Text == matrix[x-i][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 2: for (int i = 1; y-i >= 0 && matrix[x][y]->Text == matrix[x][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 3: for (int i = 1; x+i <=  grid_size_-1 && y-i >= 0 && matrix[x][y]->Text == matrix[x+i][y-i]->Text; i++)
	{
		connected++;
	}break;
	case 4: for (int i = 1; x-i >= 0 && matrix[x][y]->Text == matrix[x-i][y]->Text; i++)
	{
		connected++;
	}break;
	case 5: for (int i = 1; x+i <= grid_size_-1 && matrix[x][y]->Text == matrix[x+i][y]->Text; i++)
	{
		connected++;
	}break;
	case 6: for (int i = 1; x-i >= 0 && y+i <= grid_size_-1 && matrix[x][y]->Text == matrix[x-i][y+i]->Text; i++)
	{
		connected++;
	}break;
	case 7: for (int i = 1; y+i <= grid_size_-1 && matrix[x][y]->Text == matrix[x][y+i]->Text; i++)
	{
		connected++;
	}break;
	case 8: for (int i = 1; x+i <= grid_size_-1 && y+i <= grid_size_-1 && matrix[x][y]->Text == matrix[x+i][y+i]->Text; i++)
	{
		connected++;
	}break;
	}

	return connected;
}

void ConnectFive::GameLogic::changeTurn()
{
	// Change the turn and increase number of turns played.
	player_turn_ = !player_turn_;
	turn_number_++;
}

bool ConnectFive::GameLogic::getPlayerTurn()
{
	// Return the current turn.
	return player_turn_;
}

int ConnectFive::GameLogic::getTurnNumber()
{
	// Return number of the current turn.
	return turn_number_;
}

int ConnectFive::GameLogic::getGridSize()
{
	// Return width (and height) of the gameboard.
	return grid_size_;
}
