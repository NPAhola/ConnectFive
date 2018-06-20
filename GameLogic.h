#include <vector>

#pragma once
ref class GameLogic
{
public:
	GameLogic();

	void setupGame();
	void checkForWinner(int x, int y, System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);

	bool getPlayerTurn();
	unsigned int getTurnNumber();
	void changeTurn();
	unsigned int getGridSize();


private:
	bool player_turn = true;	// True = X's turn.
	unsigned int turn_number = 0;	// Number of the current turn.
	unsigned int grid_size = 5;	// Width and height of the square grid.
};

