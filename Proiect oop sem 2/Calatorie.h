#pragma once
#include"PunctDeVizitare.h"
#include"vector"

using std:: vector;

class Calatorie
{
private:
	vector<PunctDeVizitare*> elem;
	string filename;
public:
	Calatorie();
	Calatorie(string filename);
	~Calatorie();
	void empty();
	void setFilename(string filename);
	int find(PunctDeVizitare* p);
	void addElem(PunctDeVizitare* p);
	void deleteElem(int poz);
	vector<PunctDeVizitare*> getAll();

	void salvareCalatorieInFisier();
	vector<PunctDeVizitare*> citireCalatorieDinFisier();
	vector<PunctDeVizitare*> sugerareCalatorie();
	
};

