// Background image: http://eskipaper.com/images/snowy-trees-4.jpg
// Size modified and changed to bmp format.

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