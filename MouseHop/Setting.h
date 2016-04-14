#include <ctime>
#include <string>
#include "windows.h"

#pragma once

namespace MouseHop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Setting
	/// </summary>
	public ref class Setting : public System::Windows::Forms::Form
	{
	public:
		Setting(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ShowInTaskbar = false;
			this->WindowState = FormWindowState::Minimized;
			Hide();

			m_mouseSetting = checkBoxMouseSetting->Checked;
			m_display = checkBoxDisplay->Checked;

			notifyIconTray->Icon = gcnew System::Drawing::Icon("ico.ico");

			textBoxMsMain->Text = "119000";
			m_ms = 119000;
			timerChangePos->Interval = m_ms;

			POINT cp;
			GetCursorPos(&cp);
			lastX = cp.x;
			lastY = cp.y;
			mouseChangedPos = true;

			fromLastMove = checkBoxLastMove->Checked;

			if (m_mouseSetting) {
				timerMouse->Start();
				if (!fromLastMove) timerChangePos->Start();
			}
			else {
				textBoxMsMain->Enabled = false;
				checkBoxLastMove->Enabled = false;
			}

			if (m_display) {
				SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
			}
			//SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
			//SystemParametersInfo(SPI_SETPOWEROFFTIMEOUT, 1, NULL, 0);
			//SystemParametersInfo(SPI_SETLOWPOWERACTIVE, 0, NULL, 0);    // Low Screen фаза
			//SystemParametersInfo(SPI_SETPOWEROFFACTIVE, 0, NULL, 0);    // Фаза выключения экрана
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Setting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripTray;
	private: System::Windows::Forms::ToolStripMenuItem^  settingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::NotifyIcon^  notifyIconTray;
	private: System::Windows::Forms::GroupBox^  groupBoxMouse;
	private: System::Windows::Forms::Label^  labelMouseMsgMain;

	private: System::Windows::Forms::Label^  labelMsMain;
	private: System::Windows::Forms::TextBox^  textBoxMsMain;
	private: System::Windows::Forms::Label^  labelM;

	private: System::Windows::Forms::Label^  labelH;
	private: System::Windows::Forms::TextBox^  textBoxMs;
	private: System::Windows::Forms::TextBox^  textBoxS;
	private: System::Windows::Forms::TextBox^  textBoxM;
	private: System::Windows::Forms::TextBox^  textBoxH;
	private: System::Windows::Forms::Label^  labelMs;
	private: System::Windows::Forms::Label^  labelSec;
	private: System::Windows::Forms::CheckBox^  checkBoxLastMove;
	private: System::Windows::Forms::Button^  buttonAutoLoad;
	private: System::Windows::Forms::Timer^  timerMouse;
	private: System::Windows::Forms::Button^  buttonAccept;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool mouseChangedPos;
		int lastX, lastY;
		unsigned int m_ms;
		bool fromLastMove;
		bool m_mouseSetting;
		bool m_display;

	private: System::Windows::Forms::CheckBox^  checkBoxMouseSetting;
	private: System::Windows::Forms::CheckBox^  checkBoxDisplay;

	private: System::Windows::Forms::Timer^  timerChangePos;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->contextMenuStripTray = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->settingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->notifyIconTray = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->groupBoxMouse = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxMouseSetting = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxLastMove = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxMs = (gcnew System::Windows::Forms::TextBox());
			this->textBoxS = (gcnew System::Windows::Forms::TextBox());
			this->textBoxM = (gcnew System::Windows::Forms::TextBox());
			this->textBoxH = (gcnew System::Windows::Forms::TextBox());
			this->labelMs = (gcnew System::Windows::Forms::Label());
			this->labelSec = (gcnew System::Windows::Forms::Label());
			this->labelM = (gcnew System::Windows::Forms::Label());
			this->labelH = (gcnew System::Windows::Forms::Label());
			this->labelMsMain = (gcnew System::Windows::Forms::Label());
			this->textBoxMsMain = (gcnew System::Windows::Forms::TextBox());
			this->labelMouseMsgMain = (gcnew System::Windows::Forms::Label());
			this->buttonAutoLoad = (gcnew System::Windows::Forms::Button());
			this->timerMouse = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonAccept = (gcnew System::Windows::Forms::Button());
			this->timerChangePos = (gcnew System::Windows::Forms::Timer(this->components));
			this->checkBoxDisplay = (gcnew System::Windows::Forms::CheckBox());
			this->contextMenuStripTray->SuspendLayout();
			this->groupBoxMouse->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStripTray
			// 
			this->contextMenuStripTray->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->settingToolStripMenuItem,
					this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->contextMenuStripTray->Name = L"contextMenuStripTray";
			this->contextMenuStripTray->Size = System::Drawing::Size(135, 54);
			// 
			// settingToolStripMenuItem
			// 
			this->settingToolStripMenuItem->Name = L"settingToolStripMenuItem";
			this->settingToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->settingToolStripMenuItem->Text = L"Настройки";
			this->settingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Setting::settingToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(131, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->exitToolStripMenuItem->Text = L"Выход";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Setting::exitToolStripMenuItem_Click);
			// 
			// notifyIconTray
			// 
			this->notifyIconTray->ContextMenuStrip = this->contextMenuStripTray;
			this->notifyIconTray->Text = L"notifyIconTray";
			this->notifyIconTray->Visible = true;
			// 
			// groupBoxMouse
			// 
			this->groupBoxMouse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxMouse->Controls->Add(this->checkBoxMouseSetting);
			this->groupBoxMouse->Controls->Add(this->checkBoxLastMove);
			this->groupBoxMouse->Controls->Add(this->textBoxMs);
			this->groupBoxMouse->Controls->Add(this->textBoxS);
			this->groupBoxMouse->Controls->Add(this->textBoxM);
			this->groupBoxMouse->Controls->Add(this->textBoxH);
			this->groupBoxMouse->Controls->Add(this->labelMs);
			this->groupBoxMouse->Controls->Add(this->labelSec);
			this->groupBoxMouse->Controls->Add(this->labelM);
			this->groupBoxMouse->Controls->Add(this->labelH);
			this->groupBoxMouse->Controls->Add(this->labelMsMain);
			this->groupBoxMouse->Controls->Add(this->textBoxMsMain);
			this->groupBoxMouse->Controls->Add(this->labelMouseMsgMain);
			this->groupBoxMouse->Location = System::Drawing::Point(12, 35);
			this->groupBoxMouse->Name = L"groupBoxMouse";
			this->groupBoxMouse->Size = System::Drawing::Size(375, 160);
			this->groupBoxMouse->TabIndex = 1;
			this->groupBoxMouse->TabStop = false;
			this->groupBoxMouse->Text = L"Мышь";
			// 
			// checkBoxMouseSetting
			// 
			this->checkBoxMouseSetting->AutoSize = true;
			this->checkBoxMouseSetting->Location = System::Drawing::Point(13, 25);
			this->checkBoxMouseSetting->Name = L"checkBoxMouseSetting";
			this->checkBoxMouseSetting->Size = System::Drawing::Size(180, 17);
			this->checkBoxMouseSetting->TabIndex = 12;
			this->checkBoxMouseSetting->Text = L"Задействовать курсор мышки";
			this->checkBoxMouseSetting->UseVisualStyleBackColor = true;
			this->checkBoxMouseSetting->CheckedChanged += gcnew System::EventHandler(this, &Setting::checkBoxMouseSetting_CheckedChanged);
			// 
			// checkBoxLastMove
			// 
			this->checkBoxLastMove->AutoSize = true;
			this->checkBoxLastMove->Checked = true;
			this->checkBoxLastMove->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxLastMove->Location = System::Drawing::Point(98, 115);
			this->checkBoxLastMove->Name = L"checkBoxLastMove";
			this->checkBoxLastMove->Size = System::Drawing::Size(180, 17);
			this->checkBoxLastMove->TabIndex = 11;
			this->checkBoxLastMove->Text = L"только если мышь не активна";
			this->checkBoxLastMove->UseVisualStyleBackColor = true;
			// 
			// textBoxMs
			// 
			this->textBoxMs->Location = System::Drawing::Point(288, 75);
			this->textBoxMs->Name = L"textBoxMs";
			this->textBoxMs->ReadOnly = true;
			this->textBoxMs->Size = System::Drawing::Size(45, 20);
			this->textBoxMs->TabIndex = 10;
			// 
			// textBoxS
			// 
			this->textBoxS->Location = System::Drawing::Point(203, 75);
			this->textBoxS->Name = L"textBoxS";
			this->textBoxS->ReadOnly = true;
			this->textBoxS->Size = System::Drawing::Size(45, 20);
			this->textBoxS->TabIndex = 9;
			// 
			// textBoxM
			// 
			this->textBoxM->Location = System::Drawing::Point(116, 75);
			this->textBoxM->Name = L"textBoxM";
			this->textBoxM->ReadOnly = true;
			this->textBoxM->Size = System::Drawing::Size(45, 20);
			this->textBoxM->TabIndex = 8;
			// 
			// textBoxH
			// 
			this->textBoxH->Location = System::Drawing::Point(9, 75);
			this->textBoxH->Name = L"textBoxH";
			this->textBoxH->ReadOnly = true;
			this->textBoxH->Size = System::Drawing::Size(80, 20);
			this->textBoxH->TabIndex = 7;
			// 
			// labelMs
			// 
			this->labelMs->AutoSize = true;
			this->labelMs->Location = System::Drawing::Point(344, 78);
			this->labelMs->Name = L"labelMs";
			this->labelMs->Size = System::Drawing::Size(23, 13);
			this->labelMs->TabIndex = 6;
			this->labelMs->Text = L"ms.";
			// 
			// labelSec
			// 
			this->labelSec->AutoSize = true;
			this->labelSec->Location = System::Drawing::Point(254, 78);
			this->labelSec->Name = L"labelSec";
			this->labelSec->Size = System::Drawing::Size(28, 13);
			this->labelSec->TabIndex = 5;
			this->labelSec->Text = L"сек.";
			// 
			// labelM
			// 
			this->labelM->AutoSize = true;
			this->labelM->Location = System::Drawing::Point(167, 78);
			this->labelM->Name = L"labelM";
			this->labelM->Size = System::Drawing::Size(30, 13);
			this->labelM->TabIndex = 4;
			this->labelM->Text = L"мин.";
			this->labelM->Click += gcnew System::EventHandler(this, &Setting::label2_Click);
			// 
			// labelH
			// 
			this->labelH->AutoSize = true;
			this->labelH->Location = System::Drawing::Point(95, 78);
			this->labelH->Name = L"labelH";
			this->labelH->Size = System::Drawing::Size(15, 13);
			this->labelH->TabIndex = 3;
			this->labelH->Text = L"ч.";
			// 
			// labelMsMain
			// 
			this->labelMsMain->AutoSize = true;
			this->labelMsMain->Location = System::Drawing::Point(285, 51);
			this->labelMsMain->Name = L"labelMsMain";
			this->labelMsMain->Size = System::Drawing::Size(82, 13);
			this->labelMsMain->TabIndex = 2;
			this->labelMsMain->Text = L"миллисекунды";
			// 
			// textBoxMsMain
			// 
			this->textBoxMsMain->Location = System::Drawing::Point(141, 48);
			this->textBoxMsMain->Name = L"textBoxMsMain";
			this->textBoxMsMain->Size = System::Drawing::Size(138, 20);
			this->textBoxMsMain->TabIndex = 1;
			this->textBoxMsMain->TextChanged += gcnew System::EventHandler(this, &Setting::textBoxMsMain_TextChanged);
			// 
			// labelMouseMsgMain
			// 
			this->labelMouseMsgMain->AutoSize = true;
			this->labelMouseMsgMain->Location = System::Drawing::Point(6, 51);
			this->labelMouseMsgMain->Name = L"labelMouseMsgMain";
			this->labelMouseMsgMain->Size = System::Drawing::Size(126, 13);
			this->labelMouseMsgMain->TabIndex = 0;
			this->labelMouseMsgMain->Text = L"Дёргать мышь каждые";
			// 
			// buttonAutoLoad
			// 
			this->buttonAutoLoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonAutoLoad->Location = System::Drawing::Point(12, 201);
			this->buttonAutoLoad->Name = L"buttonAutoLoad";
			this->buttonAutoLoad->Size = System::Drawing::Size(189, 23);
			this->buttonAutoLoad->TabIndex = 2;
			this->buttonAutoLoad->Text = L"Добавить в автозагрузку";
			this->buttonAutoLoad->UseVisualStyleBackColor = true;
			this->buttonAutoLoad->Click += gcnew System::EventHandler(this, &Setting::buttonAutoLoad_Click);
			// 
			// timerMouse
			// 
			this->timerMouse->Tick += gcnew System::EventHandler(this, &Setting::timerMouse_Tick);
			// 
			// buttonAccept
			// 
			this->buttonAccept->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAccept->Location = System::Drawing::Point(207, 201);
			this->buttonAccept->Name = L"buttonAccept";
			this->buttonAccept->Size = System::Drawing::Size(180, 23);
			this->buttonAccept->TabIndex = 3;
			this->buttonAccept->Text = L"Применить";
			this->buttonAccept->UseVisualStyleBackColor = true;
			this->buttonAccept->Click += gcnew System::EventHandler(this, &Setting::buttonAccept_Click);
			// 
			// timerChangePos
			// 
			this->timerChangePos->Tick += gcnew System::EventHandler(this, &Setting::timerChangePos_Tick);
			// 
			// checkBoxDisplay
			// 
			this->checkBoxDisplay->AutoSize = true;
			this->checkBoxDisplay->Checked = true;
			this->checkBoxDisplay->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxDisplay->Location = System::Drawing::Point(21, 12);
			this->checkBoxDisplay->Name = L"checkBoxDisplay";
			this->checkBoxDisplay->Size = System::Drawing::Size(141, 17);
			this->checkBoxDisplay->TabIndex = 4;
			this->checkBoxDisplay->Text = L"Не отключать дисплей";
			this->checkBoxDisplay->UseVisualStyleBackColor = true;
			this->checkBoxDisplay->CheckedChanged += gcnew System::EventHandler(this, &Setting::checkBoxDisplay_CheckedChanged);
			// 
			// Setting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(399, 234);
			this->Controls->Add(this->checkBoxDisplay);
			this->Controls->Add(this->buttonAccept);
			this->Controls->Add(this->buttonAutoLoad);
			this->Controls->Add(this->groupBoxMouse);
			this->Name = L"Setting";
			this->Text = L"Настройки";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Setting::Setting_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Setting::Setting_FormClosed);
			this->contextMenuStripTray->ResumeLayout(false);
			this->groupBoxMouse->ResumeLayout(false);
			this->groupBoxMouse->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void settingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Show();
		this->WindowState = FormWindowState::Normal;
	}
	private: System::Void Setting_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (e->CloseReason == CloseReason::UserClosing)
		{
			e->Cancel = true;
			this->WindowState = FormWindowState::Minimized;
			Hide();
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBoxMsMain_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	unsigned int ms = 0, s = 0, m = 0, h = 0;

	try {
		unsigned int msMain = Int32::Parse(textBoxMsMain->Text);
		ms = msMain % 1000;
		while (ms >= 1000) ms = ms % 1000;
		s = msMain / 1000;
		while (s >= 60) s = s % 60;
		m = msMain / (60 * 1000);
		while (m >= 60) m = m % (60);
		h = msMain / (60 * 60 * 1000);

		textBoxH->Text = System::Convert::ToString(h);
		textBoxM->Text = System::Convert::ToString(m);
		textBoxS->Text = System::Convert::ToString(s);
		textBoxMs->Text = System::Convert::ToString(ms);
	}
	catch (/*FormatException^ ArgumentNullException^ OverflowException^	*/ ...)
	{
		System::Windows::Forms::MessageBox::Show("Введен неправильный формат времени в миллисекундах. Время устанавливается по умолчанию 119000 ms.", "Внимание!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
		textBoxMsMain->Text = "119000";
	}
}
private: System::Void textBoxMsMain_TabStopChanged(System::Object^  sender, System::EventArgs^  e) {
	printf("StopChange\n");
}

private: System::Void timerMouse_Tick(System::Object^  sender, System::EventArgs^  e) {
	POINT cp;
	GetCursorPos(&cp);

	if ((cp.x == lastX) && (cp.y == lastY)) {
		if (!mouseChangedPos) {
			if (fromLastMove) {
				if (!timerChangePos->Enabled) {
					timerChangePos->Start();
					printf("Mouse not muve. Timer start.\n");
				}
			}
		}
		mouseChangedPos = false;
	}
	else {
		if (!mouseChangedPos) {
			if (fromLastMove) {
				if (timerChangePos->Enabled) {
					timerChangePos->Stop();
					printf("Mouse move. Timer stop.\n");
				}
			}
		}
		mouseChangedPos = true;
	}

	lastX = cp.x;
	lastY = cp.y;
	//printf("X: %d; Y: %d\n", cp.x, cp.y);
}
private: System::Void buttonAccept_Click(System::Object^  sender, System::EventArgs^  e) {
	//printf("Change timer for mouse on %d ms\n", Int32::Parse(textBoxMsMain->Text));
	m_mouseSetting = checkBoxMouseSetting->Checked;
	
	if (m_mouseSetting) {
		m_ms = Int32::Parse(textBoxMsMain->Text);
		fromLastMove = checkBoxLastMove->Checked;

		timerChangePos->Stop();
		printf("Timer stop. Change interval.\n");
		timerChangePos->Interval = m_ms;

		if (!fromLastMove) {
			printf("Timer start whith out mouse  moving.\n");
			timerChangePos->Start();
		}
	}

	if (m_display) {
		SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
	}
	else {
		SetThreadExecutionState(ES_CONTINUOUS);
	}

}
private: System::Void timerChangePos_Tick(System::Object^  sender, System::EventArgs^  e) {
	printf("Change mouse pos and back\n");
	SetCursorPos(0, 0);
	SetCursorPos(lastX, lastY);
	PostMessage(GetDesktopWindow(), WM_MOUSEMOVE, NULL, NULL);
}
private: System::Void Setting_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	//System::Windows::Forms::MessageBox::Show("Closed");
	//SystemParametersInfo(SPI_SETPOWEROFFTIMEOUT, 0, NULL, 0);
	//SystemParametersInfo(SPI_SETLOWPOWERACTIVE, 1, NULL, 0);    // Low Screen фаза
	//SystemParametersInfo(SPI_SETPOWEROFFACTIVE, 1, NULL, 0);    // Фаза выключения экрана
	SetThreadExecutionState(ES_CONTINUOUS);
}
private: System::Void checkBoxMouseSetting_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	//m_mouseSetting = checkBoxMouseSetting->Checked;
	if (checkBoxMouseSetting->Checked) {
		textBoxMsMain->Enabled = true;
		checkBoxLastMove->Enabled = true;
		timerMouse->Start();
		if (!fromLastMove) timerChangePos->Start();
	}
	else {
		textBoxMsMain->Enabled = false;
		checkBoxLastMove->Enabled = false;
		timerMouse->Stop();
		timerChangePos->Stop();
	}
}
private: System::Void checkBoxDisplay_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	m_display = checkBoxDisplay->Checked;
}
private: System::Void buttonAutoLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	HKEY hKey;
	wchar_t  szPath[0x100];
	GetModuleFileName(NULL, szPath, sizeof(szPath));
	RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		NULL,
		L"",
		REG_OPTION_NON_VOLATILE,
		KEY_SET_VALUE,
		NULL,
		&hKey,
		NULL);

	LONG lResult = 0;
	lResult = RegOpenKey(
		HKEY_LOCAL_MACHINE,
		L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		&hKey);

	if (ERROR_SUCCESS != lResult) {
		return;
	}

	if (hKey)
	{
		RegSetValueEx(hKey, L"MouseHop", NULL, REG_SZ, (PBYTE)szPath, lstrlen(szPath)*sizeof(wchar_t) + 1);
		RegCloseKey(hKey);
	}
}
};
}
