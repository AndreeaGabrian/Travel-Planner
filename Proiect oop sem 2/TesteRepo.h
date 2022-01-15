#pragma once
#include"RepoTemplate.h"
#include"PunctDeVizitare.h"

class TesteRepo{
private:
	RepoTemplate<PunctDeVizitare> repo;
	vector<PunctDeVizitare> puncte_de_test;
	void testGetAll();
	void testAdd();
	void testDelete();
	void testUpdate();
public:
	TesteRepo();
	~TesteRepo();
	void runAll();
};

