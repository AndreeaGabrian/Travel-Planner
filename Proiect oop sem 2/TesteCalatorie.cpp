#include "TesteCalatorie.h"
#include"Localitate.h"
#include"ObiectivTuristic.h"
#include"Ruta.h"
#include"Exceptii.h"
#include<assert.h>

void TesteCalatorie::testAdd()
{
	Calatorie calatorie;
	PunctDeVizitare* p1 = new Localitate(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	assert(calatorie.getAll().size() == 0);
	calatorie.addElem(p1);
	assert(calatorie.getAll().size() == 1);
	PunctDeVizitare* p2 = new ObiectivTuristic(1, "parc", 1, "natural", 0, "nu", "nu");
	calatorie.addElem(p2);
	assert(calatorie.getAll().size() == 2);
	PunctDeVizitare* p3 = new Ruta(1, "nume5", { 1 });
	calatorie.addElem(p3);
	assert(calatorie.getAll().size() == 3);

	calatorie.addElem(p3);
	assert(calatorie.getAll().size() == 3);

}

void TesteCalatorie::testDelete()
{
	Calatorie calatorie;
	PunctDeVizitare* p1 = new Localitate(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	PunctDeVizitare* p2 = new ObiectivTuristic(1, "parc", 1, "natural", 0, "nu", "nu");
	calatorie.addElem(p1);
	calatorie.addElem(p2);
	assert(calatorie.getAll().size() == 2);

	calatorie.deleteElem(4);
	assert(calatorie.getAll().size() == 2);

	calatorie.deleteElem(1);
	assert(calatorie.getAll().size() == 1);
	assert(*calatorie.getAll()[0]==*p1);

	calatorie.deleteElem(0);
	assert(calatorie.getAll().size() == 0);
}


void TesteCalatorie::testFind()
{
	Calatorie calatorie;
	PunctDeVizitare* p1 = new Localitate(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	PunctDeVizitare* p2 = new ObiectivTuristic(1, "parc", 1, "natural", 0, "nu", "nu");
	calatorie.addElem(p1);
	calatorie.addElem(p2);
	assert(calatorie.getAll().size() == 2);

	assert(calatorie.find(p1) != -1);
	assert(calatorie.find(p2) != -1);

	PunctDeVizitare* p3 = new Localitate(2, "afsdf", 1044, 1.1, CoordonateGeo(10, 10));
	assert(calatorie.find(p3) == -1);
}

void TesteCalatorie::testsalvareCalatorieInFisier()
{
	Calatorie calatorie(this->filenameOut);
	PunctDeVizitare* p1 = new Localitate(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	PunctDeVizitare* p2 = new ObiectivTuristic(1, "parc", 1, "natural", 0, "nu", "nu");
	calatorie.addElem(p1);
	calatorie.addElem(p2);
	assert(calatorie.getAll().size() == 2);

	try {
		calatorie.salvareCalatorieInFisier();
		assert(true);
	}
	catch (CalatorieExceptie& e) {
		assert(false);
	}

	elem.push_back(p1);
	elem.push_back(p2);
	vector<PunctDeVizitare*> elem_fisier = calatorie.citireCalatorieDinFisier();
	assert(*elem[0] == *elem_fisier[0]);
	assert(*elem[1] == *elem_fisier[1]);
	
}

void TesteCalatorie::testcitireCalatorieDinFisier()
{
	
	Calatorie calatorie(filenameIn);
	PunctDeVizitare* p2 = new ObiectivTuristic(10, "castel", 1, "istoric", 10, "nu", "nu");
	calatorie.addElem(p2);
	calatorie.salvareCalatorieInFisier();

	try {
		vector<PunctDeVizitare*> elem_fisier = calatorie.citireCalatorieDinFisier();
		assert(true);
		assert(elem_fisier.size() == 1);
		assert(*elem_fisier[0] == *calatorie.getAll()[0]);
	}
	catch (CalatorieExceptie& e) {
		assert(false);
	}
	
}

void TesteCalatorie::testsugerareCalatorie()
{
	Calatorie calatorie;
	PunctDeVizitare* p1 = new Localitate(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	PunctDeVizitare* p2 = new ObiectivTuristic(1, "parc", 1, "natural", 0, "nu", "nu");
	PunctDeVizitare* p3 = new ObiectivTuristic(12, "parc1", 1, "natural", 0, "nu", "nu");
	PunctDeVizitare* p4 = new ObiectivTuristic(13, "parc2", 1, "natural", 0, "nu", "nu");
	PunctDeVizitare* p5 = new ObiectivTuristic(14, "parc3", 1, "natural", 0, "nu", "nu");
	calatorie.addElem(p1);
	calatorie.addElem(p2);
	calatorie.addElem(p3);
	calatorie.addElem(p4);
	calatorie.addElem(p5);
	vector<PunctDeVizitare*> elem = calatorie.sugerareCalatorie();
	assert(elem.size() > 0);
}

TesteCalatorie::TesteCalatorie()
{
}

TesteCalatorie::~TesteCalatorie()
{
}

void TesteCalatorie::runAll()
{
	testAdd();
	testDelete();
	testFind();
	testsalvareCalatorieInFisier();
	testcitireCalatorieDinFisier();
	testsugerareCalatorie();

	cout << "Testele pentru calatorie au fost trecute cu succes!\n";
}
