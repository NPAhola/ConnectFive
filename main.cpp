#include "ConnectFiveGUI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(array<String^>^ args)
{
	// Run the GUI.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ConnectFive::ConnectFiveGUI form;
	Application::Run(%form);

	return 0;
}