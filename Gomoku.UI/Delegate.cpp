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


void GameField::MessageChangeCallback(std::string msg) {
	if (msg.find("GAME_START") != std::string::npos) {
		Invoke(gcnew UpdateResetDelegate(this, &GameField::UpdateResetButton), true);
		if (this->gameType == 1) Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), true);
		wmp->setMode("loop", true);
		wmp->URL = "title2.mp3";
		wmp->play();
	}

	if (msg.find("GAME_ENDED") != std::string::npos) {
		Invoke(gcnew UpdateStartDelegate(this, &GameField::UpdateStartButton), true);
		Invoke(gcnew UpdateResetDelegate(this, &GameField::UpdateResetButton), false);
		Invoke(gcnew UpdateWinnerDelegate(this, &GameField::UpdateWinner), -1);
		Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), false);
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameField::typeid));
		for each (Button^ btn in this->gamePanel->Controls)
		{
			btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
			btn->UseVisualStyleBackColor = true;
			Invoke(gcnew UpdateButtonDelegate(this, &GameField::UpdateButton), btn);
		}
		draw_board();
		wmp->stop();
	}


	if (msg.find("USERTYPE") != std::string::npos) {
		auto args = GameFlow::SplitArguments(msg);
		int gameType = args[1] == "1" ? 1 : 2;
		this->gameType = gameType;
		if (gameType == 2)
			Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), false);
	}
	if (msg.find("ACTION") != std::string::npos) {
		auto args = GameFlow::SplitArguments(msg);
		System::String^ buttonName = gcnew String((args[2] + "_" + args[3] + "_" + args[4]).c_str());
		int gameType = (args[1] == "1") ? 1 : 2;
		if (gameType != this->gameType)
			Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), true);
		if (gameType == this->gameType)
			Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), false);
		Invoke(gcnew UpdateButtonByNameDelegate(this, &GameField::UpdateButtonByName), gameType, buttonName);
	}
	if (msg.find("WINNER") != std::string::npos) {
		auto args = GameFlow::SplitArguments(msg);
		int gameType = args[1] == "1" ? 1 : 2;
		Invoke(gcnew UpdateWinnerDelegate(this, &GameField::UpdateWinner), gameType);
	}
	System::String^ str = gcnew String(msg.c_str());
	Invoke(gcnew UpdateUIDelegate(this, &GameField::UpdateUI), str);
}

void GameField::UpdateUI(String ^ message)
{
	//i18n decl
	array<wchar_t> ^delim = { '_' };
	if (message->Contains("PING")) {
		return;
	}
	if (message->Contains("SEARCHING")) {
		stateIndicator->Text = WAITING_FOR_OPPONENT;
		return;
	}
	if (message->Contains("GAME_START")) {
		if (this->gameType == 1)
			stateIndicator->Text = GAME_STARTED;
		else
			stateIndicator->Text = WAITING_OPPONENT_MOVE;
		return;
	}
	if (message->Contains("USERTYPE_2")) {
		stateIndicator->Text = GAME_STARTED;
		return;
	}
	if (message->Contains("RANKING_")) {
		if (rankingForm && rankingForm->Created) {
			return;
		}
		rankingForm = gcnew Gomoku::Ranking(message);
		rankingForm->Show();
		return;
	}
	if (message->Contains("ACTION")) {
		auto arr = message->Split(delim);
		stateIndicator->Text = OPPONENT_ACTION + arr[3] + "," + arr[4];
		return;
	}
	if (message->Contains("WINNER")) {
		auto arr = message->Split(delim);
		if (arr[1] == "1")
			stateIndicator->Text = WINNER + USER_1;
		else stateIndicator->Text = WINNER + USER_2;
		return;
	}
	if (message->Contains("GAME_ENDED")) {
		stateIndicator->Text = RESETTING_GAME;
		return;
	}
	stateIndicator->Text = message;
}

void GameField::UpdatePanel(bool toEnable)
{
	isPlaceable = toEnable;
}

void GameField::UpdateStartButton(bool toEnable)
{
	startButton->Enabled = toEnable;
}

void GameField::UpdateResetButton(bool toEnable)
{
	resetButton->Enabled = toEnable;
}

void GameField::UpdateWinner(int winnerType)
{
	isPlaceable = false;
	switch (winnerType)
	{
	case 1:
		gamePanel->BackColor = System::Drawing::Color::Gray;
		break;
	case 2:
		gamePanel->BackColor = System::Drawing::Color::White;
		break;
	default:
		gamePanel->BackColor = System::Drawing::Color::NavajoWhite;
		break;
	}
	wmp->stop();
	if (winnerType != -1) {
		wmp->setMode("loop", false);
		if (winnerType == this->gameType) {
			wmp->URL = "win.mp3";
		}
		else wmp->URL = "fail.mp3";
		wmp->play();
	}
}

void GameField::UpdateButtonByName(int gameType, String ^ buttonName)
{
	String^ buttonColor;
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameField::typeid));
	array<wchar_t> ^delim = { '_' };
	auto btnArg = buttonName->Split(delim);
	auto x = Int32::Parse(btnArg[1]);
	auto y = Int32::Parse(btnArg[2]);
	auto ctrl = ButtonArray[x, y];
	switch (gameType)
	{
	case 1:
		buttonColor = L"black";
		break;
	case 2:
		buttonColor = L"white";
		break;
	default:
		buttonColor = L"cross";
		break;
	}
	ctrl->Enabled = false;
	ctrl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(buttonColor)));
}

void  GameField::UpdateButton(Button^ button) {
	button->Enabled = true;
}
