#include "ConnectFiveGUI.h"

void ConnectFive::ConnectFiveGUI::setWinnerLabel(bool turn)
{
	if (!turn)
	{
		label_winner->Text = L"WINNER";
		label_turn->Text = L"X";
		label_turn->ForeColor = Color::Blue;
	}
	else
	{
		label_winner->Text = L"WINNER";
		label_turn->Text = L"O";
		label_turn->ForeColor = Color::Red;
	}
}

void ConnectFive::ConnectFiveGUI::setWinnerLabel()
{
	label_winner->Text = L"It's a draw.";
}

void ConnectFive::ConnectFiveGUI::setLabelsToDefault()
{
	label_winner->Text = L"TURN";
	label_turn->Text = L"X";
	label_turn->ForeColor = Color::Blue;
}

void ConnectFive::ConnectFiveGUI::createButtonGrid(unsigned int size)
{
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