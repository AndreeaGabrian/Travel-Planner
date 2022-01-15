#pragma once
#include "Localitate.h"
#include "ObiectivTuristic.h"
#include "CoordonateGeo.h"

class ValidatorCoordonateGeo {
public:
	void valideaza(CoordonateGeo& coord);
};

class ValidatorPunctDeVizitare {
public:
	virtual void valideaza(PunctDeVizitare& pct);
};

class ValidatorLocalitate: public ValidatorPunctDeVizitare {
public:
	void valideaza(PunctDeVizitare& loc) override;
};

class ValidatorObiectivTuristic: public ValidatorPunctDeVizitare {
public:
	void valideaza(PunctDeVizitare& obv) override;
};

class ValidatorRuta : public ValidatorPunctDeVizitare {
public:
	void valideaza(PunctDeVizitare& ruta) override;
};