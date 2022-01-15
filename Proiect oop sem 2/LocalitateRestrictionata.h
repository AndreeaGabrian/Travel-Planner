#pragma once
#include"Localitate.h"
#include"DataCalendaristica.h"

class LocalitateRestrictionata : public Localitate {
private:
	DataCalendaristica inceput_restrictii;
	DataCalendaristica sfarsit_restrictii;
	bool vizitabil;
	string restrictii;

public:
	LocalitateRestrictionata();
	LocalitateRestrictionata(int id, string nume, int populatie, double rata_incidenta,CoordonateGeo coord, DataCalendaristica inceput_restrictii, DataCalendaristica sfarsit_restrictii, bool vizitabil, string restrictii);
	LocalitateRestrictionata(const LocalitateRestrictionata& locr);
	~LocalitateRestrictionata();

	DataCalendaristica getInceputRestrictii();
	DataCalendaristica getSfarsitRestrictii();
	bool getVizitabil();
	string getRestrictii();
	void setInceputRestrictii(DataCalendaristica inceput);
	void setSfarsitRestrictii(DataCalendaristica sfarsit);
	void setVizitabil(bool vizitabil);
	void setRestrictii(string restrictii);

	LocalitateRestrictionata& operator=(const LocalitateRestrictionata& locr);
	bool operator==(const LocalitateRestrictionata& locr);
	friend istream& operator>>(istream& is, LocalitateRestrictionata& locr);
	friend ostream& operator<<(ostream& os, const LocalitateRestrictionata& locr);
};
