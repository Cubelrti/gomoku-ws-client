#include "GameField.h"
#include "Gomoku.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace Gomoku;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Gomoku::GameField form;
	Application::Run(%form);
}