#pragma once
#include "Localitate.h"
#include "Ruta.h"
#include"RepoTemplate.h"

class TesteServiceRuta{
private:
	RepoTemplate<Ruta> repo_ruta;
	RepoTemplate<Localitate> repo_loc;
	void testaddRuta();
	void testdeleteRuta();
	void testupdateRuta();
	void testfindById();
	void testcountRuteByIdLocalitate();
	void testgetRutePrinLocalitate();
	void testfiltrareRuteDupaNrLocalitati();
	void testsortareRuteCrescatorDupaLocalitati();

public:
	TesteServiceRuta();
	~TesteServiceRuta();
	void runAll();
};

