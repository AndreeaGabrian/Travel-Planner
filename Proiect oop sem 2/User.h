#pragma once
#include<string>
using std::string;

class User
{
protected:
	string username;
	string password;
public:
	User() {};
	User(string username, string password);
	virtual ~User() {};
	string getUsername();
	string getPassword();
	void setUsername(string username);
	void setPasword(string password);
};

