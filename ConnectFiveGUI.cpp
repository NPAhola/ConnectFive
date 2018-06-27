#include "ConnectFiveGUI.h"

void ConnectFive::ConnectFiveGUI::setWinnerLabel(bool turn)
{
	if (turn)
	{
		label_winner->Text = L"Winner: X";
	}
	else
	{
		label_winner->Text = L"Winner: O";
	}
}

void ConnectFive::ConnectFiveGUI::setWinnerLabel()
{
	label_winner->Text = L"It's a draw.";
}