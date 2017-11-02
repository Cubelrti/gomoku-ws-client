#include "Gomoku.h"
#include <iostream>
#include <pplawait.h>
#include <string>
#include "Gomoku.Constants.h"
#include "cpprest\ws_client.h"

using namespace std;
using namespace web;
using namespace web::websockets::client;

namespace GomokuClient {
	websocket_callback_client client;
	string clientType;
	bool GameFlow::Contains(string text, string keyword) {
		return (text.find(keyword) != std::string::npos);
	}
	int GameFlow::Start() {
		websocket_outgoing_message out_msg;
		Send(START_GAME_MESSAGE);
		return 0;
	}
	int GameFlow::StartRanking(string Id) {
		Send("RANKING_" + Id);
		return 0;
	}
	int GameFlow::GetRanking() {
		Send("GET_RANK");
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
	int GameFlow::Init(CallbackType callback, int serverType) {
		websocket_callback_client _client;
		try
		{
			switch (serverType)
			{
			case 0:
				_client.connect(U(CN_SERVER_ADDR)).wait();
				break;
			case 1:
				_client.connect(U(CA_SERVER_ADDR)).wait();
			case 2:
				_client.connect(U(LOCAL_SERVER_ADDR)).wait();
			default:
				break;
			}
			_client.set_message_handler([=](websocket_incoming_message msg)
			{
				return msg.extract_string().then([=](string text) {
					callback(text);
				});
			});
			client = _client;
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
		Send(RESET_GAME_MESSAGE);
		return 0;
	}
	int GameFlow::Disconnect() {
		client.close().wait();
		return 0;

	}
	vector<string> GameFlow::SplitArguments(string text) {
		return split(text, "_");
	}
}