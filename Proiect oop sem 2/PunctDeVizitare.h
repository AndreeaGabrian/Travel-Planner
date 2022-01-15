#pragma once
#include <string>
#include<iostream>

using namespace std;

class PunctDeVizitare {
protected:
	int id;
	string nume;

public:
	PunctDeVizitare();
	PunctDeVizitare(int id, string nume);
	PunctDeVizitare(const PunctDeVizitare& p);
	virtual ~PunctDeVizitare();

	int getId();
	string getNume();
	
	void setId(int id);
	void setNume(string nume);
	
	virtual PunctDeVizitare* clona();
	virtual string toString(bool file = false);
	

	PunctDeVizitare& operator=(const PunctDeVizitare& p);
	bool operator==(const PunctDeVizitare& p);
	friend istream& operator>>(istream& is, PunctDeVizitare& p);
	friend ostream& operator<<(ostream& os, const PunctDeVizitare& p);

	void valideazaObiectDinFisier();
};