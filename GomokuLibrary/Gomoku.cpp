#include "Gomoku.h"
#include <iostream>
#include <pplawait.h>
#include <string>
#include "Constants.h"
#include "cpprest\ws_client.h"


using namespace std;
using namespace web;
using namespace web::websockets::client;


namespace GomokuUtils {
	std::vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty = true) {
		using namespace std;
		vector<string> result;
		if (delim.empty()) {
			result.push_back(s);
			return result;
		}
		string::const_iterator substart = s.begin(), subend;
		while (true) {
			subend = search(substart, s.end(), delim.begin(), delim.end());
			string temp(substart, subend);
			if (keep_empty || !temp.empty()) {
				result.push_back(temp);
			}
			if (subend == s.end()) {
				break;
			}
			substart = subend + delim.size();
		}
		return result;
	}

}

namespace GomokuClient {
	websocket_callback_client client;
	string clientType;
	bool GameFlow::Contains(string text, string keyword) {
		return (text.find(keyword) != std::string::npos);
	}
	int GameFlow::Start() { 
		websocket_outgoing_message out_msg;
		Send(START_CONNECTION_MESSAGE);
		return 0;
	}
	int GameFlow::Send(std::string msg) {
		websocket_outgoing_message out_msg;
		out_msg.set_utf8_message(msg);
		client.send(out_msg);
		return 0;
	}
	int GameFlow::Action(std::string msg) {
		websocket_outgoing_message out_msg;
		out_msg.set_utf8_message(ACTION_MESSAGE_PREFIX + msg);
		client.send(out_msg);
		return 0;
	}
	int GameFlow::Init(CallbackType callback){
		try
		{
			client.connect(U(SERVER_ADDR)).wait();
			client.set_message_handler([=](websocket_incoming_message msg)
			{
				return msg.extract_string().then([=](string text) {
					callback(text);
				});
			});
			return 0;
		}
		catch (const std::exception&)
		{
			return -1;
		}
		
	}

	int GameFlow::GetClientType() {
		if (clientType == "1") return 1;
		else return 2;
	}

	int GameFlow::Reset() {
		Send(END_CONNECTION_MESSAGE);
		return 0;
	}
	vector<string> GameFlow::SplitArguments(string text) {
		return GomokuUtils::split(text, "_");
	}
}