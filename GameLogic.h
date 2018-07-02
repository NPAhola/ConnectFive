#pragma once

namespace ConnectFive { 

using namespace System::Collections;
using namespace System::Windows::Forms;

/// <summary>
/// This class keeps track of the game's current situation and handles
/// calculations needed for the game.
/// </summary>
ref class GameLogic
{
public:
	GameLogic();	// Constructor.
	
	// Setup the game to default.
	void setupGame(Generic::List<Generic::List<Button^>^>^ matrix);
	// Disable all buttons of the gameboard.
	void disableAllButtons(Generic::List<Generic::List<Button^>^>^ matrix);
	// Check if there's a winner.
	bool checkForWinner(int x, int y, Generic::List<Generic::List<Button^>^>^ matrix);
	// Check if there's a draw.
	bool checkForDraw(Generic::List<Generic::List<Button^>^>^ matrix);
	// Count number of consecutive symbols. Needed by checkForWinner().
	int countConnected(int x, int y, int dir, Generic::List<Generic::List<Button^>^>^ matrix);

	void changeTurn();			// Change turn.
	bool getPlayerTurn();		// Return the current turn.
	int getTurnNumber();		// Return the current turn's number.
	int getGridSize();			// Return the grid size.
	
	
private:
	bool player_turn_ = true;	// True = X's turn.
	int turn_number_ = 0;		// Number of the current turn.
	int grid_size_ = 15;		// Width (and height) of the square grid.
};

};