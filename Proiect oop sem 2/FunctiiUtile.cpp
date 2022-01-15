#include"FunctiiUtile.h"
#include<windows.h>
using namespace std;

string convertDoubleToString(double x)
{
	string s = to_string(x);
	int decimalSepPos = s.find('.');
	if (decimalSepPos != string::npos)
	{
		int len = s.length() - 1;
		while (s[len] == '0')
		{
			len--;
		}
		if (len == decimalSepPos)
		{
			s = s.substr(0, len);
		}
		else
		{
			s = s.substr(0, len + 1);
		}
	}
	return s;
}



optiuni esteOptiune(string const& string_opt)
{
	if (string_opt == "1")
		return opt1;
	if (string_opt == "2")
		return opt2;
	if (string_opt == "3")
		return opt3;
	if (string_opt == "4")
		return opt4;
	if (string_opt == "5")
		return opt5;
	if (string_opt == "6")
		return opt6;
	if (string_opt == "7")
		return opt7;
	if (string_opt == "8")
		return opt8;
	if (string_opt == "9")
		return opt9;
	if (string_opt == "10")
		return opt10;
	if (string_opt == "11")
		return opt11;
	if (string_opt == "12")
		return opt12;
	if (string_opt == "13")
		return opt13;
	if (string_opt == "b")
		return optb;
	if (string_opt == "x")
		return optx;
	else
		return noopt;
}

void changeColor(int val)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), val);
}

void invalidOption()
{
	changeColor(12);
	cout << "Optiune invalida, reincercati!";
	changeColor(14);
}
