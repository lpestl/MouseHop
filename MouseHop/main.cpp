#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "Setting.h"
//#include "GatewayChanger.h"

using namespace MouseHop;
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	//GatewayChanger^ core;
	//core = GatewayChanger::GetInstance();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Setting^ form = gcnew Setting();
	Application::Run(form);

	return 0;
}