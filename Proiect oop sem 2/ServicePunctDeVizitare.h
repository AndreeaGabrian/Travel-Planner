#pragma once
#include"PunctDeVizitare.h"
#include"IRepoTemplate.h"
//#include<vector>

class ServicePunctDeVizitare {
private:
	IRepoTemplate<PunctDeVizitare>& repo_punct_de_vizitare;
public:
	//ServicePunctDeVizitare();
	ServicePunctDeVizitare(IRepoTemplate<PunctDeVizitare>& repo) : repo_punct_de_vizitare{ repo } {};
	ServicePunctDeVizitare(const ServicePunctDeVizitare& srv) = delete;
	~ServicePunctDeVizitare();

	void setRepo(IRepoTemplate<PunctDeVizitare>& repo);

	vector<PunctDeVizitare> getAll();
	void addPunctDeVizitare(int id, string nume);
	void deletePunctDeVizitare(int id);
	void updatePunctDeVizitare(int id, string nume_nou);
	int findById(int id);
	
};
