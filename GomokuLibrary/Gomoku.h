#pragma once
#include <string>
#include <vector>

namespace GomokuClient {
	class GameFlow {
	public:
		typedef void(__stdcall *CallbackType)(std::string arg);
		static bool Contains(std::string text, std::string keyword);
		static int Start();
		static int Send(std::string msg);
		static int Action(std::string msg);
		static int Init(CallbackType,int serverType);
		static int GetClientType();
		static int Reset();
		static std::vector<std::string> SplitArguments(std::string text);
	};
}