#pragma once
#include"PunctDeVizitare.h"

class ObiectivTuristic : public PunctDeVizitare {
private:
	int id_localitate;
	string tip;
	double pret_bilet;
	string patrimoniu_UNESCO;
	string necesitate_vaccin;

public:
	ObiectivTuristic();
	ObiectivTuristic(int id, string nume, int id_localitate, string tip, double pret, string patrimoniu_UNESCO, string necesitate_vaccin);
	ObiectivTuristic(const ObiectivTuristic& obv);
	~ObiectivTuristic();

	int    getIdLocalitate();
	string getTip();
	double getPretBilet();
	string getPatrimoniu();
	string getNecesitateVaccin();

	void setIdLocalitate(int id_l);
	void setTip(string t);
	void setPretBilet(double pret);
	void setPatrimoniu(string patrimoniu);
	void setNecesitateVaccin(string vaccin);

	PunctDeVizitare* clona();
	string toString(bool file=false);

	ObiectivTuristic& operator=(const ObiectivTuristic& obv);
	bool operator==(const ObiectivTuristic& obv);
	friend istream& operator>>(istream& is, ObiectivTuristic& obv);
	friend ostream& operator<<(ostream& os, const ObiectivTuristic& obv);

	void valideazaObiectDinFisier();

};