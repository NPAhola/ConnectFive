#pragma once

#include <vector>

namespace ConnectFive { 

ref class GameLogic
{
public:
	GameLogic();
	
	void setupGame(System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);
	bool checkForWinner(int x, int y, System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);
	bool checkForDraw(System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);
	int countConnected(int x, int y, int dir, System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);
	void disableAllButtons(System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ matrix);

	bool getPlayerTurn();
	unsigned int getTurnNumber();
	void changeTurn();
	unsigned int getGridSize();
	
	
private:
	bool player_turn = true;	// True = X's turn.
	int turn_number = 0;	// Number of the current turn.
	int grid_size = 15;	// Width and height of the square grid.
};

};