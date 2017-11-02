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
	std::vector<std::string> GomokuClient::GameFlow::split(const std::string & s, const std::string & delim, const bool keep_empty)
	{
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
