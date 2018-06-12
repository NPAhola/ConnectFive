#include "ConnectFiveGUI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	// Run the GUI.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ConnectFive::ConnectFiveGUI form;
	Application::Run(%form);
}