#pragma once
#include <map>
#include <string>
using namespace std;



class Authenticator
{
	string user= "" ;
	map<string, string> users;
	Authenticator()
	{
		users["vivek"] = "p@ss";
		users["sanjay"] = "p@ss";
	}
public:
	static Authenticator* instance() {
		static Authenticator* _instance = new Authenticator();
		return _instance;
	}

	bool authenticate(string user,  string password)
	{
		int x = 0;
		auto pass = users[user];
		if (password == pass) {
			this->user = user;
			return true;
		}
		else
		{
			this->user = "";
			return false;
		}
	}

	string getUser() { return user; }
	
	bool isAuthenticated() { return user != ""; }

	void logout() { user = ""; }
};
