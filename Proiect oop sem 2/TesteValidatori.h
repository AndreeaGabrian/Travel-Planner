#pragma once
#include"Validator.h"

class TesteValidatori{
private:
	ValidatorCoordonateGeo vg;
	ValidatorLocalitate vl;
	ValidatorObiectivTuristic vo;
	ValidatorPunctDeVizitare vp;
	ValidatorRuta vr;

	void testValideazaPct();
	void testValideazaCoord();
	void testValideazaLoc();
	void testValideazaObv();
	void testValideazaRuta();
public:
	TesteValidatori();
	~TesteValidatori();
	void runAll();
};

