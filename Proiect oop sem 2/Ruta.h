#pragma once
#include "PunctDeVizitare.h"
#include "Localitate.h"
#include<vector>
using namespace std;

class Ruta :public PunctDeVizitare {
private:
	vector<int> localitati;
public:
	Ruta():PunctDeVizitare() {};
	Ruta(int id, string nume, vector<int> locs):PunctDeVizitare(id, nume), localitati{ locs } {};
	Ruta(const Ruta& r) : PunctDeVizitare(r), localitati{ r.localitati } {};
	~Ruta() {};

	vector<int> getLocalitati();
	void setLocalitati(vector<int> locs);

	PunctDeVizitare* clona();
	string toString(bool file = false);
	
	Ruta& operator=(const Ruta& ruta);
	//bool operator==(const Ruta& ruta);
	friend istream& operator>>(istream& is, Ruta& ruta);
	friend ostream& operator<<(ostream& os, const Ruta& ruta);
	void valideazaObiectDinFisier();
};
