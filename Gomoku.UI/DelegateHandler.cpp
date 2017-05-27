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
		if (this->gameType == 1) Invoke(gcnew UpdatePanelDelegate(this, &GameField::UpdatePanel), true);
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
		Invoke(gcnew UpdateButtonDelegate(this, &GameField::UpdateButton), gameType, buttonName);
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
	if (message->Contains("USERTYPE_1")) {
		stateIndicator->Text = WAITING_FOR_OPPONENT;
		return;
	}
	if (message->Contains("GAME_START")) {
		stateIndicator->Text = GAME_STARTED;
		wmp->controls->play();
		return;
	}
	if (message->Contains("USERTYPE_2")) {
		stateIndicator->Text = WAITING_OPPONENT_MOVE;
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
	if (message->Contains("DISCONNECTING")) {
		stateIndicator->Text = RESETTING_GAME;
		return;
	}
	stateIndicator->Text = message;
}

void GameField::UpdatePanel(bool toEnable)
{
	isPlaceable = toEnable;
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
		if (winnerType == this->gameType) {
			wmp->URL = "win.mp3";
		}
		else wmp->URL = "fail.mp3";
		wmp->play();
	}
}

void GameField::UpdateButton(int gameType, String ^ buttonName)
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
