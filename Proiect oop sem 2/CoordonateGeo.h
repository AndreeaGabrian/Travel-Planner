#pragma once
#include<iostream>
using namespace std;

class CoordonateGeo {
private:
	double latitudine;
	double longitudine;
	
public:
	CoordonateGeo();
	CoordonateGeo(double lat, double lon);
	CoordonateGeo(const CoordonateGeo& coord);
	~CoordonateGeo() {};

	double getLongitudine();
	double getLatitudine();
	void setLongitudine(double lon);
	void setLatitudine(double lat);

	CoordonateGeo& operator=(const CoordonateGeo& coord);
	bool operator==(const CoordonateGeo& coord);
	friend istream& operator>>(istream& is, CoordonateGeo& coord);
	friend ostream& operator<<(ostream& os, const CoordonateGeo& coord);

	double distantaDouaLocatii(const CoordonateGeo coord);
};