#include "ConnectFiveGUI.h"

ConnectFive::ConnectFiveGUI::ConnectFiveGUI(void)
{
	// Constructor for the class.
	InitializeComponent();

	// Button matrix init.
	button_matrix = gcnew(Generic::List<Generic::List<Button^>^>);

	// Create the gameboard.
	unsigned int grid_size = current_game.getGridSize();
	createButtonGrid(grid_size);

	// Set labels to default.
	setLabelsToDefault();
}

void ConnectFive::ConnectFiveGUI::setWinnerLabel(bool turn)
{
	// There is a winner.
	if (!turn)
	{
		// X won.
		label_infotext->Text = L"WINNER";
		label_symbol->Text = L"X";
		label_symbol->ForeColor = Color::Blue;
	}
	else
	{
		// O won.
		label_infotext->Text = L"WINNER";
		label_symbol->Text = L"O";
		label_symbol->ForeColor = Color::Red;
	}
}

void ConnectFive::ConnectFiveGUI::setWinnerLabel()
{
	// The game is a draw.
	label_infotext->Text = L"DRAW";
	label_symbol->Text = L"-";
	label_symbol->ForeColor = Color::Black;
}

void ConnectFive::ConnectFiveGUI::setLabelsToDefault()
{
	// The game starts with X's turn.
	label_infotext->Text = L"TURN";
	label_symbol->Text = L"X";
	label_symbol->ForeColor = Color::Blue;
}

void ConnectFive::ConnectFiveGUI::createButtonGrid(unsigned int size)
{
	// Creates a square grid of buttons as the gameboard.
	this->SuspendLayout();
	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < size; j++)
		{
			// Create a new button.
			this->new_button = (gcnew System::Windows::Forms::Button());

			// Set default settings for the button.
			this->new_button->Location = System::Drawing::Point(i * 35, j * 35);
			this->new_button->Name = L"but";
			this->new_button->Size = System::Drawing::Size(35, 35);
			this->new_button->TabIndex = 0;
			this->new_button->Text = L"";
			this->new_button->Font = gcnew System::Drawing::Font("Britannic", 16.0);
			this->new_button->UseVisualStyleBackColor = true;
			this->new_button->BackColor = Color::White;
			this->new_button->TabStop = false;	// Get rid of blue outline.

			// When clicked / hovered.
			this->new_button->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Click);
			this->new_button->MouseHover += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover);
			this->new_button->MouseLeave += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover_Leave);

			// Add the button to Controls.
			this->Controls->Add(this->new_button);

			// Add button to matrix.
			button_matrix->Add(gcnew(System::Collections::Generic::List<System::Windows::Forms::Button^>));
			button_matrix[i]->Add(new_button);

			// Add button to map.
			button_map.Add(new_button, System::Collections::Generic::KeyValuePair<int, int>(i, j));
		}
	}
}