#pragma once
#include "lang.h"

namespace Gomoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ranking 摘要
	/// </summary>
	public ref class Ranking : public System::Windows::Forms::Form
	{
	public:
		Ranking(String^ rank)
		{
			InitializeComponent();
			auto arr = rank->Split('_');
			int sharpRank = 1;
			for each (String^ var in arr)
			{
				if (var->Equals("RANKING") || String::IsNullOrEmpty(var)) continue;
				auto user = var->Split('/');
				auto userItem = this->listView1->Items->Add(sharpRank++.ToString());
				userItem->SubItems->Add(user[0]);
				userItem->SubItems->Add(user[1]);
			}
			this->listView1->Sorting;
			this->listView1->Sort();
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Ranking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Ranking::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->listView1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listView1.BackgroundImage")));
			this->listView1->BackgroundImageTiled = true;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader3, this->columnHeader1,
					this->columnHeader2
			});
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listView1->ForeColor = System::Drawing::SystemColors::Window;
			this->listView1->FullRowSelect = true;
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->Location = System::Drawing::Point(14, 158);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(524, 294);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"#";
			this->columnHeader3->Width = 30;
			// 
			// columnHeader1
			// 
			this->columnHeader1->DisplayIndex = 2;
			this->columnHeader1->Text = L"Score";
			this->columnHeader1->Width = 126;
			// 
			// columnHeader2
			// 
			this->columnHeader2->DisplayIndex = 1;
			this->columnHeader2->Text = L"UserName";
			this->columnHeader2->Width = 401;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(0, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(555, 62);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ranking";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Ranking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(550, 464);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView1);
			this->Name = L"Ranking";
			this->Text = L"Ranking";
			this->Load += gcnew System::EventHandler(this, &Ranking::Ranking_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Ranking_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
