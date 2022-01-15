#pragma once
#include"RepoTemplate.h"
#include"Localitate.h"
#include"ObiectivTuristic.h"

class TesteServiceObiectiv{
private:
	RepoTemplate<ObiectivTuristic> repo_obv;
	RepoTemplate<Localitate> repo_loc;
	void testaddObiectiv();
	void testDeleteObiectiv();
	void testupdateObiectiv();
	void testfindById();
	void testcountObiectiveByIdLocalitate();
	void testsorteazaDupaTip();
	void testsorteazaDupaPatrimoniu();
	void testsorteazaDupaNecesitateVaccin();
public:
	TesteServiceObiectiv();
	~TesteServiceObiectiv();
	void runAll();
};

