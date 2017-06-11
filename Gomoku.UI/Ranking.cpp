#include "Ranking.h"

using namespace System;
using namespace Gomoku;

System::Void Gomoku::Ranking::Ranking_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	//i18n decl
	this->label1->Text = RANKING_UI;
	return System::Void();
}
