#pragma once
#include "GameField.h"
#include "lang.h"

namespace Gomoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Signin 摘要
	/// </summary>
	public ref class Signin : public System::Windows::Forms::Form
	{
	public:
		Signin(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Signin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: Gomoku::GameField^ gameField;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Signin::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(748, 296);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(462, 344);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(281, 63);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Quick Match";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Signin::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(117, 418);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(246, 29);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Aspire";
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 497);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(772, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(179, 17);
			this->toolStripStatusLabel1->Text = L"Server Status: OK";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(462, 415);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(281, 58);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Ranked Solo";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Signin::rankButton_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(667, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 28);
			this->button3->TabIndex = 5;
			this->button3->Text = L"AI Challenge";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Signin::notImplemented_buttonClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(51, 428);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 12);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID:";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(117, 362);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(246, 29);
			this->comboBox1->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(53, 369);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 12);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Server:";
			// 
			// Signin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(772, 519);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Signin";
			this->Text = L"Signin";
			this->Load += gcnew System::EventHandler(this, &Signin::Signin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/***************EVENT_HANDLER****************/
	private: System::Void Signin_Load(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rankButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void notImplemented_buttonClick(System::Object^  sender, System::EventArgs^  e);
		/***************EVENT_HANDLER****************/
};
}
