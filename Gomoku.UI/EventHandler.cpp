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

System::Void GameField::startButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	GameFlow::Start();
	startButton->Enabled = false;
}

System::Void GameField::game_place(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!isPlaceable) return;
	String^ msg = (this->gameType).ToString() + "_" + safe_cast<Button^>(sender)->Name;
	GameFlow::Action(msclr::interop::marshal_as<std::string>(msg));
	isPlaceable = false;

	System::Media::SoundPlayer ^simpleSound = gcnew
		System::Media::SoundPlayer("down.wav");
	simpleSound->Play();

}

System::Void GameField::resetButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	GameFlow::Reset();
}

System::Void GameField::GameField_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	this->stateIndicator->Text = READY;
	managed = gcnew MessageChangeCallbackDelegate(this, &GameField::MessageChangeCallback);
	GC::KeepAlive(managed);
	IntPtr stubPointer = Marshal::GetFunctionPointerForDelegate(managed);
	GameFlow::CallbackType functionPointer = static_cast<GameFlow::CallbackType>(stubPointer.ToPointer());
	if (GameFlow::Init(functionPointer,serverType) != 0) { //failed when existed?
		MessageBox::Show("Failed to connect server.");
		this->startButton->Enabled = false;
		this->resetButton->Enabled = false;
	};
	//dynamically create button
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameField::typeid));
	ButtonArray = gcnew array<Button ^, 2>(20, 20);
	const int x_default = 3, y_default = 3;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			auto btn = gcnew Button();
			ButtonArray[i, j] = btn;
			this->gamePanel->Controls->Add(btn);
			btn->Location = System::Drawing::Point(x_default + 32 * i, y_default + 32 * j);
			btn->Name = (L"c_" + i + L"_" + j);
			btn->Size = System::Drawing::Size(33, 33);
			btn->TabIndex = 3;
			btn->UseVisualStyleBackColor = true;
			btn->BackColor = System::Drawing::Color::Transparent;
			btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderColor = System::Drawing::Color::NavajoWhite;
			btn->FlatAppearance->BorderSize = 0;
			btn->Click += gcnew System::EventHandler(this, &GameField::game_place);
		}
	}
	draw_board();
	wmp = gcnew WindowsMediaPlayerClass();
	wmp->URL = "title2.mp3";
	wmp->volume = 35;
	wmp->PlayStateChange += gcnew _WMPOCXEvents_PlayStateChangeEventHandler(this, &GameField::Player_PlayStateChange);
	wmp->MediaError += gcnew _WMPOCXEvents_MediaErrorEventHandler(this, &GameField::Player_MediaError);
	wmp->controls->stop();

}

System::Void GameField::Player_PlayStateChange(int state)
{
	return;
}

System::Void GameField::Player_MediaError(Object ^ pMediaObject)
{
	MessageBox::Show("Error processing media.");
}