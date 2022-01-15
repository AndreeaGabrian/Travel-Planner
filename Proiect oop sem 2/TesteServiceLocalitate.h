#pragma once
#include"ServiceLocalitati.h"
#include"RepoTemplate.h"

class TesteServiceLocalitate{
private:
	RepoTemplate<Localitate> repo_loc;
	RepoTemplate<ObiectivTuristic> repo_obv;
	RepoTemplate<Ruta> repo_ruta;
	//ServiceLocalitati service_loc;

	void testGetAll();
	void testAdd();
	void testDelete();
	void testUpdate();
	void testFindById();
	void testgetObiectiveDinLocalitate();
	void testgetRuteIncepandDinLocalitate();
	void testgetDistantaIntreLocalitati();
	void testgetObvLocKm();
	void testgetCeaMaiApropiataLoc();
	void testfiltrareLocalitatiDupaRata();
	void testgetRuteCuLungimeMica();
public:
	TesteServiceLocalitate();
	~TesteServiceLocalitate();
	void runAll();
};

