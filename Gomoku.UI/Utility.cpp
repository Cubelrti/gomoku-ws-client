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

System::Void GameField::draw_board()
{

	//process boarder
	for (int i = 0; i < 20; i++)
	{
		auto top = ButtonArray[i, 0];
		top->BackgroundImage = cast_image(L"top");
		auto left = ButtonArray[0, i];
		left->BackgroundImage = cast_image(L"left");
		auto right = ButtonArray[19, i];
		right->BackgroundImage = cast_image(L"right");
		auto bottom = ButtonArray[i, 19];
		bottom->BackgroundImage = cast_image(L"bottom");
	}
	//process corner
	ButtonArray[0, 0]->BackgroundImage = cast_image(L"topleft");
	ButtonArray[19, 19]->BackgroundImage = cast_image(L"bottomright");
	ButtonArray[0, 19]->BackgroundImage = cast_image(L"bottomleft");
	ButtonArray[19, 0]->BackgroundImage = cast_image(L"topright");
}

System::Drawing::Image ^ GameField::cast_image(String ^ str)
{
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameField::typeid));
	return (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(str)));
}