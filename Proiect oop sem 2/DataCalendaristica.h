#pragma once
#include<iostream>
using namespace std;

class DataCalendaristica {
private:
	int zi;
	int luna;
	int an;
public:
	DataCalendaristica();
	DataCalendaristica(int zi, int luna, int an);
	DataCalendaristica(const DataCalendaristica& data);
	~DataCalendaristica();

	int getZi();
	int getLuna();
	int getAn();
	void setZi(int zi);
	void setLuna(int luna);
	void setAn(int an);

	DataCalendaristica& operator=(const DataCalendaristica& data);
	bool operator==(const DataCalendaristica& data);
	friend istream& operator>>(istream& is, DataCalendaristica& data);
	friend ostream& operator<<(ostream& os, const DataCalendaristica& data);

};