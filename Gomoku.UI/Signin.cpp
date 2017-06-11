#include "Signin.h"
using namespace Gomoku;
using namespace System;


System::Void Signin::Signin_Load(System::Object^  sender, System::EventArgs^  e) {
	//i18n decl
	this->button1->Text = QUICK_MATCH;
	this->toolStripStatusLabel1->Text = SERVER_STATUS;
	this->button2->Text = RANKED_SOLO;
	this->button3->Text = AI_CHALLENGE;
	this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		CN_SERVER, CA_SERVER,
			LOCALHOST
	});
	this->label2->Text = SERVER;
	comboBox1->SelectedIndex = 0;
}
System::Void Signin::button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (gameField && gameField->Created) {
			MessageBox::Show(NO_MULTIPLAYING);
			return;
		}
		gameField = gcnew Gomoku::GameField(comboBox1->SelectedIndex, false, "");
		gameField->Show();
	}
System::Void Signin::rankButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (gameField && gameField->Created) {
			MessageBox::Show(NO_MULTIPLAYING);
			return;
		}
		gameField = gcnew Gomoku::GameField(comboBox1->SelectedIndex, true, textBox1->Text);
		gameField->Show();
	}
System::Void Signin::notImplemented_buttonClick(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(COMING_SOON);
	}

