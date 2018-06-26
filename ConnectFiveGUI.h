#include <iostream>
#include <ctime>
#include "GameLogic.h"

#pragma once

namespace ConnectFive {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ConnectFiveGUI
	/// </summary>
	public ref class ConnectFiveGUI : public System::Windows::Forms::Form
	{
	public:
		ConnectFiveGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Button matrix init.
			button_matrix = gcnew(System::Collections::Generic::List<System::Collections::Generic::List<System::Windows::Forms::Button^>^>);

			// Create the gameboard.
			unsigned int grid_size = current_game.getGridSize();
			createButtonGrid(grid_size);
		}

		void createButtonGrid(unsigned int size)
		{
			this->SuspendLayout();
			for (unsigned int i = 0; i < size; i++)
			{
				for (unsigned int j = 0; j < size; j++)
				{
					// Create a new button.
					this->new_button = (gcnew System::Windows::Forms::Button());

					// Set default settings for the button.
					this->new_button->Location = System::Drawing::Point(i * 45, j * 45);
					this->new_button->Name = L"but";
					this->new_button->Size = System::Drawing::Size(45, 45);
					this->new_button->TabIndex = 0;
					this->new_button->Text = L"";
					this->new_button->UseVisualStyleBackColor = true;
					this->new_button->BackColor = System::Drawing::Color::White;
					this->new_button->TabStop = false;	// Get rid of blue outline.

					// When clicked / hovered.
					this->new_button->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Click);
					this->new_button->MouseHover += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover);
					this->new_button->MouseLeave += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover_Leave);

					// Add the button to Controls.
					this->Controls->Add(this->new_button);

					// Add button to matrix.
					button_matrix->Add( gcnew(System::Collections::Generic::List<System::Windows::Forms::Button^>) );
					button_matrix[i]->Add(new_button);

					// Add button to map.
					button_map.Add(new_button, System::Collections::Generic::KeyValuePair<int, int>(i, j));
				}
			}
		}
	private: System::Windows::Forms::Button^  but_exit;
	public:
		System::Collections::Generic::Dictionary<Button^, System::Collections::Generic::KeyValuePair<int, int> > button_map;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConnectFiveGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  but_newgame;
	protected:


	private: System::Windows::Forms::Button^  new_button;
	private: GameLogic current_game;
	private: System::Collections::Generic::List<System::Collections::Generic::List
		<System::Windows::Forms::Button^>^>^ button_matrix;
			 
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->but_newgame = (gcnew System::Windows::Forms::Button());
			this->but_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// but_newgame
			// 
			this->but_newgame->Location = System::Drawing::Point(715, 396);
			this->but_newgame->Name = L"but_newgame";
			this->but_newgame->Size = System::Drawing::Size(124, 23);
			this->but_newgame->TabIndex = 0;
			this->but_newgame->TabStop = false;
			this->but_newgame->Text = L"New Game";
			this->but_newgame->UseVisualStyleBackColor = true;
			this->but_newgame->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::button1_Click);
			// 
			// but_exit
			// 
			this->but_exit->Location = System::Drawing::Point(715, 436);
			this->but_exit->Name = L"but_exit";
			this->but_exit->Size = System::Drawing::Size(124, 23);
			this->but_exit->TabIndex = 1;
			this->but_exit->TabStop = false;
			this->but_exit->Text = L"Exit";
			this->but_exit->UseVisualStyleBackColor = true;
			this->but_exit->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::but_exit_Click);
			// 
			// ConnectFiveGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(851, 608);
			this->Controls->Add(this->but_exit);
			this->Controls->Add(this->but_newgame);
			this->Name = L"ConnectFiveGUI";
			this->Text = L"ConnectFiveGUI";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void new_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ this_button = (Button^)sender;

		// Set button text according to turn.
		bool turn = current_game.getPlayerTurn();

		if (turn)
		{
			this_button->Text = L"X";
		}
		else
		{
			this_button->Text = L"O";
		}

		current_game.changeTurn();
		this_button->Enabled = false;	// Disable button until next game.

		System::Collections::Generic::KeyValuePair<int, int> coords = button_map[this_button];
		current_game.checkForWinner(coords.Key, coords.Value, button_matrix);

	}
	private: System::Void new_button_Hover(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ this_button = (Button^)sender;
		this_button->BackColor = System::Drawing::Color::Yellow;
	}
	private: System::Void new_button_Hover_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ this_button = (Button^)sender;
		this_button->BackColor = System::Drawing::Color::White;;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		current_game.setupGame(button_matrix);
	}
private: System::Void but_exit_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
};

	
	

	
}
