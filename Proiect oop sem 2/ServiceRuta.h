#pragma once
#include"IRepoTemplate.h"
#include"Ruta.h"

class ServiceRuta {
private:
	IRepoTemplate<Ruta>& repo_ruta;
	IRepoTemplate<Localitate>& repo_loc;
public:
	ServiceRuta(IRepoTemplate<Ruta>& repo_ruta, IRepoTemplate<Localitate>& repo_loc) :repo_ruta{ repo_ruta }, repo_loc{ repo_loc } {};
	ServiceRuta(const ServiceRuta& srv_r)=delete;
	~ServiceRuta() {};

	vector<Ruta> getAll();
	void addRuta(int id, string nume, vector<int> locs);
	void deleteRuta(int id);
	void updateRuta(int id, string nume_nou, vector<int> new_locs);
	int findById(int id);

	//functionalitati
	int countRuteByIdLocalitate(int id_loc);
	vector<Ruta> getRutePrinLocalitate(int id_loc);
	int filtrareRuteDupaNrLocalitati(int nr);
	vector<Ruta> sortareRuteCrescatorDupaLocalitati();

	void verificareDateRutaLaPrimaCitire();
	
};