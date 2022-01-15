#pragma once
#include"PunctDeVizitare.h"
#include"CoordonateGeo.h"

class Localitate :public PunctDeVizitare {
protected:
	int populatie;
	double rata_incidenta;
	CoordonateGeo coord;

public:
	Localitate();
	Localitate(int id, string nume, int populatie, double rata_incidenta, CoordonateGeo coord);
	Localitate(const Localitate& loc);
	~Localitate();

	int getPopulatie();
	double getRataIncidenta();
	CoordonateGeo getCoord();
	

	void setPopulatie(int p);
	void setRataIncidenta(double rata);
	void setCoord(CoordonateGeo coord);
	
	PunctDeVizitare* clona();
	string toString(bool file = false);

	Localitate& operator=(const Localitate& loc);
	bool operator==(const Localitate& loc);
	friend istream& operator>>(istream& is, Localitate& loc);
	friend ostream& operator<<(ostream& os, const Localitate& loc);

	void valideazaObiectDinFisier();
};