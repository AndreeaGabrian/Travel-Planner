#pragma once
#include"RepoTemplate.h"
#include"PunctDeVizitare.h"

class TesteServicePunctDeVizitare{
private:
	RepoTemplate< PunctDeVizitare> repo;
	void testAdd();
	void testDelete();
	void testUpdate();
	void testFindById();
public:
	TesteServicePunctDeVizitare();
	~TesteServicePunctDeVizitare();
	void runAll();
};


