#include "Login.h"
#include"fstream"
#include<iostream>
#include "FunctiiUtile.h"
using namespace std;
using std::cout;
using std::cin;

Login::Login(string file_in)
{
	this->file_in = file_in;
	loadUsersFromFile();
}

void Login::loadUsersFromFile()
{
	ifstream f(this->file_in);
	string user_name;
	string passw;
	bool is_logged = false;
	if (f.is_open())
	{
		users.clear();
		string linie;
		while (getline(f, linie)) {
			int pos = linie.find(" ");
			user_name = linie.substr(0, pos);
			linie = linie.erase(0, pos + 1);
			passw = linie;
			User u(user_name, passw);
			users.push_back(u);
		}
		f.close();
	}
	else {
		changeColor(12);
		cout << "Fisierul cu useri nu s-a deschis pentru citire\n";
		changeColor(14);
	}
}

bool Login::login(User &user)
{
	bool is_logged = false;
	for (int i=0; i < users.size(); i++)
	{
		string user_name = users[i].getUsername();;
		string passw=users[i].getPassword();

		if (user_name == user.getUsername() && passw == user.getPassword())
		{
			is_logged = true;
			break;
		}
		else if (user_name == user.getUsername() && !(passw == user.getPassword()))
		{
			changeColor(12);
			cout << "Parola incorecta, reincercati!\n";
			return false;
		}
	}
	
	if (!is_logged) {
		changeColor(12);
		cout << "Autentificare esuata! Nu sunteti inregistrat, va rugam sa urmati procedura de sign in\n";
	}
	changeColor(14);
	return is_logged;
}

bool Login::signin()
{
	bool is_signed = false;
	string username;
	string password;
	cout << "Introduceti un nume de utilizator(nu se accepta spatii): \n";
	cin >> username;
	cout << "Introduceti o parola(nu se accepta spatii): \n";
	cin >> password;

	int size = users.size();
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (users[i].getUsername() == username)
			{
				changeColor(12);
				cout << "Username-ul introdus este deja folosit, va rugam alegeti alt nume\n";
				return false;
			}
		}
		
	}
	changeColor(14);
	users.push_back(User(username, password));

	ofstream f(this->file_in);
	if (f.is_open())
	{
		int size = users.size();
		for (int i = 0; i < size - 1; i++)
		{
			f << users[i].getUsername() << " " << users[i].getPassword()<<endl;
		}
		f << users[size-1].getUsername() << " " << users[size-1].getPassword();
		f.close();
	}
	return true;
}
