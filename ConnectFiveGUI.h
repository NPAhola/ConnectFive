#include <iostream>
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

			// Create the gameboard.
			unsigned int grid_size = current_game.getGridSize();
			createButtonGrid(grid_size);
		}

		void createButtonGrid(unsigned int size)
		{
			this->SuspendLayout();
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
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

					// When clicked / hovered.
					this->new_button->Click += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Click);
					this->new_button->MouseHover += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover);
					this->new_button->MouseLeave += gcnew System::EventHandler(this, &ConnectFiveGUI::new_button_Hover_Leave);

					// Add the button to Controls.
					this->Controls->Add(this->new_button);
				}
			}
		}

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
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  new_button;
	private: GameLogic current_game;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(386, 288);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// ConnectFiveGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(522, 400);
			this->Controls->Add(this->button1);
			this->Name = L"ConnectFiveGUI";
			this->Text = L"ConnectFiveGUI";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void new_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Set button text according to turn.
		bool turn = current_game.getPlayerTurn();
		Button^ this_button = (Button^)sender;

		if (turn)
		{
			this_button->Text = L"X";
		}
		else
		{
			this_button->Text = L"O";
		}

		current_game.changeTurn();
		//checkForWinner();
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
	};

	
	

	
}
