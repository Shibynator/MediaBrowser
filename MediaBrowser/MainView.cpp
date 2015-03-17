#include "MainView.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args){

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MediaBrowser::MainView form;
	Application::Run(%form);

}

