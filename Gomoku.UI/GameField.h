#pragma once
#include "Gomoku.h"
#include "Ranking.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "lang.h"

using namespace System;

namespace Gomoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	using namespace GomokuClient;
	using namespace WMPLib;
	/// <summary>
	/// GameField 摘要
	/// </summary>
	public ref class GameField : public System::Windows::Forms::Form
	{
	public:
		GameField(int serverType, bool isRank, String^ id)
		{
			this->serverType = serverType;
			this->isRank = isRank;
			this->id = id;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~GameField()
		{
			this->wmp->stop(); 
			if (isConnected) {
				GomokuClient::GameFlow::Disconnect();
			}
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::Label^  stateLabel;
	private: System::Windows::Forms::Label^  stateIndicator;
	private: System::Windows::Forms::Panel^  gamePanel;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Button^  rankingButton;
	private: Gomoku::Ranking^ rankingForm;


	protected:
	private:
		/*********************DELEGATES**********************/
		delegate void UpdateUIDelegate(String^ message);
		delegate void UpdatePanelDelegate(bool toEnable);
		delegate void UpdateWinnerDelegate(int winnerType);
		delegate void UpdateButtonByNameDelegate(int gameType, String^ buttonName);
		delegate void MessageChangeCallbackDelegate(std::string msg);
		delegate void UpdateResetDelegate(bool toEnable);
		delegate void UpdateStartDelegate(bool toEnable);
		delegate void UpdateButtonDelegate(Button^ button);
		/*********************DELEGATES**********************/

		/*********************PROPERTIES*********************/
		int serverType;
		int gameType = -1;
		bool isPlaceable, isRank, isConnected;
		String^ id;
		WindowsMediaPlayerClass ^wmp;
		array<Button ^, 2> ^ ButtonArray;
		MessageChangeCallbackDelegate^ managed;
	

			 /*********************PROPERTIES*********************/

	protected:
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameField::typeid));
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->stateLabel = (gcnew System::Windows::Forms::Label());
			this->stateIndicator = (gcnew System::Windows::Forms::Label());
			this->gamePanel = (gcnew System::Windows::Forms::Panel());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->rankingButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// resetButton
			// 
			this->resetButton->Enabled = false;
			this->resetButton->Location = System::Drawing::Point(764, 660);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(66, 42);
			this->resetButton->TabIndex = 2;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &GameField::resetButton_Click);
			// 
			// stateLabel
			// 
			this->stateLabel->AutoSize = true;
			this->stateLabel->BackColor = System::Drawing::Color::Transparent;
			this->stateLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateLabel->Location = System::Drawing::Point(101, 14);
			this->stateLabel->Name = L"stateLabel";
			this->stateLabel->Size = System::Drawing::Size(78, 30);
			this->stateLabel->TabIndex = 9;
			this->stateLabel->Text = L"State: ";
			// 
			// stateIndicator
			// 
			this->stateIndicator->AutoSize = true;
			this->stateIndicator->BackColor = System::Drawing::Color::Transparent;
			this->stateIndicator->Font = (gcnew System::Drawing::Font(L"微软雅黑", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateIndicator->Location = System::Drawing::Point(180, 14);
			this->stateIndicator->Name = L"stateIndicator";
			this->stateIndicator->Size = System::Drawing::Size(113, 30);
			this->stateIndicator->TabIndex = 10;
			this->stateIndicator->Text = L"Loading...";
			// 
			// gamePanel
			// 
			this->gamePanel->BackColor = System::Drawing::Color::NavajoWhite;
			this->gamePanel->Location = System::Drawing::Point(99, 58);
			this->gamePanel->Name = L"gamePanel";
			this->gamePanel->Size = System::Drawing::Size(646, 644);
			this->gamePanel->TabIndex = 22;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(764, 179);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(66, 66);
			this->startButton->TabIndex = 23;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &GameField::startButton_Click);
			// 
			// rankingButton
			// 
			this->rankingButton->Location = System::Drawing::Point(764, 323);
			this->rankingButton->Name = L"rankingButton";
			this->rankingButton->Size = System::Drawing::Size(66, 66);
			this->rankingButton->TabIndex = 24;
			this->rankingButton->Text = L"Ranking";
			this->rankingButton->UseVisualStyleBackColor = true;
			this->rankingButton->Click += gcnew System::EventHandler(this, &GameField::rankButton_Click);
			// 
			// GameField
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(842, 743);
			this->Controls->Add(this->rankingButton);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->stateIndicator);
			this->Controls->Add(this->stateLabel);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->gamePanel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GameField";
			this->Opacity = 0.92;
			this->Text = L"Gomoku";
			this->Load += gcnew System::EventHandler(this, &GameField::GameField_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		/***************DELEGATE_HANDLER**************/
		void MessageChangeCallback(std::string msg);
		void UpdateUI(String^ message);
		void UpdatePanel(bool toEnable);
		void UpdateWinner(int winnerType);
		void UpdateButtonByName(int gameType, String^ buttonName);
		void UpdateButton(Button ^ button);
		void UpdateStartButton(bool toEnable);
		void UpdateResetButton(bool toEnable);
		/***************DELEGATE_HANDLER**************/


	private:
		/***************EVENT_HANDLER**************/
		System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void game_place(System::Object^ sender, System::EventArgs^ e);
		System::Void resetButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void rankButton_Click(System::Object ^ sender, System::EventArgs ^ e);
		System::Void GameField_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void Player_PlayStateChange(int state);
		System::Void Player_MediaError(Object^ pMediaObject);
		/***************EVENT_HANDLER**************/

		/***************UTIL_METHOD**************/
	private: System::Void draw_board();
	private: System::Drawing::Image^ cast_image(String^ str);
		/***************UTIL_METHOD**************/


	};
}