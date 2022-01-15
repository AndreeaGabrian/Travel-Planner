#pragma once
#include"User.h"
#include<vector>
using std::vector;

class Login{
private:
	vector<User> users;
	string file_in;
public:
	Login(string file_in);
	~Login() {};
	void loadUsersFromFile();
	bool login(User& user);
	bool signin();
};

