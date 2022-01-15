#pragma once
#include"IRepoTemplate.h"
#include"Localitate.h"
#include"ObiectivTuristic.h"
#include"Ruta.h"

class ServiceLocalitati {
private:
	IRepoTemplate<Localitate>& repo_loc;
	IRepoTemplate<ObiectivTuristic>& repo_obv;
	IRepoTemplate<Ruta>& repo_ruta;
public:
	//ServiceLocalitati();
	ServiceLocalitati(IRepoTemplate<Localitate>& repo, IRepoTemplate<ObiectivTuristic>& repo_obv, IRepoTemplate<Ruta>& repo_ruta) : repo_loc{ repo }, repo_obv{ repo_obv }, repo_ruta{ repo_ruta }{};
	ServiceLocalitati(const ServiceLocalitati& srv) = delete;
	~ServiceLocalitati();

	//void setRepo(IRepoTemplate<Localitate>& repo) : repo_loc{ repo } {};

	vector<Localitate> getAll();  
	void addLocalitate(int id, string nume, int populatie, double rata_incidenta, CoordonateGeo coord);
	void deleteLocalitate(int id);
	void updateLocalitate(int id, string nume_nou, int populatie_noua, double rata_incidenta_noua, CoordonateGeo coord_noi);
	int findById(int id);

	//functionalitati 
	vector<ObiectivTuristic> getObiectiveDinLocalitate(int id_loc);
	vector<Ruta> getRuteIncepandDinLocalitate(int id_loc);

	double getDistantaIntreLocalitati(const int& id1, const int& id2);
	vector<pair<ObiectivTuristic, int>> getObvLocKm(double km, int id_loc);
	pair<Localitate, int> getCeaMaiApropiataLoc(int id);

	int filtrareLocalitatiDupaRata(double rata);
	vector<pair<Ruta, double>> getRuteCuLungimeMica(int km);

	
	
};