#pragma once
#include<iostream>
#include<string.h>
#include <string>
using std::string;
using std::cout;

string convertDoubleToString(double x);

enum optiuni {
	opt1, opt2, opt3, opt4, opt5, opt6, opt7, opt8, opt9, opt10, opt11, opt12, opt13, optx, optb, noopt
};

optiuni esteOptiune(string const& string_opt);

void changeColor(int val);
void invalidOption();