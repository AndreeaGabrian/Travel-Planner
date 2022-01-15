#pragma once
#include"IRepoTemplate.h"
#include"ObiectivTuristic.h"
#include"Localitate.h"

class ServiceObiectivTuristic {
private:
	IRepoTemplate<ObiectivTuristic>& repo_obv;
	IRepoTemplate<Localitate>& repo_loc;
public:
	ServiceObiectivTuristic(IRepoTemplate<ObiectivTuristic>& repo, IRepoTemplate<Localitate>& repo_loc) :repo_obv{ repo }, repo_loc{ repo_loc } {};
	ServiceObiectivTuristic(const ServiceObiectivTuristic& srv)=delete;
	~ServiceObiectivTuristic() {};

	vector<ObiectivTuristic> getAll();
	void addObiectiv(int id, string nume, int id_localitate, string tip, double pret_bilet, string patrimoniu_UNESCO, string necesitate_vaccin);
	void deleteOviectiv(int id);
	void updateObiectiv(int id, string nume_nou, int id_localitate_noua, string tip_nou, double pret_bilet_nou, string patrimoniu_UNESCO_nou, string necesitate_vaccin_nou);
	int findById(int id);
	int countObiectiveByIdLocalitate(int id_loc);

	//functionalitati  
	vector<ObiectivTuristic> sorteazaDupaTip(string tip);
	vector<ObiectivTuristic> sorteazaDupaPatrimoniu(string patr);
	vector<ObiectivTuristic> sorteazaDupaNecesitateVaccin(string necesita);
	
	void verificareDateObiectivLaPrimaCitire();
};