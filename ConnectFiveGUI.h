// Background image: http://eskipaper.com/images/snowy-trees-4.jpg

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

			// Set labels to default.
			setLabelsToDefault();
		}

		void createButtonGrid(unsigned int size);	// Create buttons for gameboard.
		void setWinnerLabel(bool winner);			// There is a winner.
		void setWinnerLabel();						// Game is a draw.
		void setLabelsToDefault();					// Sets text labels to default.

	private: System::Windows::Forms::Button^  but_exit;
	private: System::Windows::Forms::Label^  label_winner;
	private: System::Windows::Forms::Label^  label_turn;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ConnectFiveGUI::typeid));
			this->but_newgame = (gcnew System::Windows::Forms::Button());
			this->but_exit = (gcnew System::Windows::Forms::Button());
			this->label_winner = (gcnew System::Windows::Forms::Label());
			this->label_turn = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// but_newgame
			// 
			this->but_newgame->Location = System::Drawing::Point(714, 586);
			this->but_newgame->Name = L"but_newgame";
			this->but_newgame->Size = System::Drawing::Size(124, 23);
			this->but_newgame->TabIndex = 0;
			this->but_newgame->TabStop = false;
			this->but_newgame->Text = L"New Game";
			this->but_newgame->UseVisualStyleBackColor = true;
			this->but_newgame->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::but_newgame_Click);
			// 
			// but_exit
			// 
			this->but_exit->Location = System::Drawing::Point(715, 615);
			this->but_exit->Name = L"but_exit";
			this->but_exit->Size = System::Drawing::Size(124, 23);
			this->but_exit->TabIndex = 1;
			this->but_exit->TabStop = false;
			this->but_exit->Text = L"Exit";
			this->but_exit->UseVisualStyleBackColor = true;
			this->but_exit->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::but_exit_Click);
			// 
			// label_winner
			// 
			this->label_winner->BackColor = System::Drawing::SystemColors::Control;
			this->label_winner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_winner->Location = System::Drawing::Point(703, 178);
			this->label_winner->Name = L"label_winner";
			this->label_winner->Size = System::Drawing::Size(145, 32);
			this->label_winner->TabIndex = 2;
			this->label_winner->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_turn
			// 
			this->label_turn->BackColor = System::Drawing::SystemColors::Control;
			this->label_turn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_turn->Location = System::Drawing::Point(703, 210);
			this->label_turn->Name = L"label_turn";
			this->label_turn->Size = System::Drawing::Size(145, 90);
			this->label_turn->TabIndex = 3;
			this->label_turn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ConnectFiveGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(850, 650);
			this->Controls->Add(this->label_turn);
			this->Controls->Add(this->label_winner);
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

		// Don't do anything if button already pressed.
		if (this_button->Text != L"") { return; }

		// Set button text according to turn.
		bool turn = current_game.getPlayerTurn();

		if (turn)
		{
			this_button->Text = L"X";
			this_button->ForeColor = Color::Blue;
			label_turn->Text = L"O";
			label_turn->ForeColor = Color::Red;
		}
		else
		{
			this_button->Text = L"O";
			this_button->ForeColor = Color::Red;
			label_turn->Text = L"X";
			label_turn->ForeColor = Color::Blue;
		}

		current_game.changeTurn();

		System::Collections::Generic::KeyValuePair<int, int> coords = button_map[this_button];
		bool winnerFound = current_game.checkForWinner(coords.Key, coords.Value, button_matrix);
		bool gameTied = current_game.checkForDraw(button_matrix);

		if (winnerFound)
		{
			if (!turn) { setWinnerLabel(true); }
			else { setWinnerLabel(false); }
			//label_turn->Text = L"";
		}
		else if (gameTied)
		{
			setWinnerLabel();
			//label_turn->Text = L"";
		}

	}
	private: System::Void new_button_Hover(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ this_button = (Button^)sender;
		if (this_button->Text != L"") { return; }

		this_button->BackColor = System::Drawing::Color::Yellow;
	}
	private: System::Void new_button_Hover_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ this_button = (Button^)sender;

		this_button->BackColor = System::Drawing::Color::White;
	}
	private: System::Void but_newgame_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Setup game's values and text labels.
		current_game.setupGame(button_matrix);
		setLabelsToDefault();
	}
	private: System::Void but_exit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}

};
};
