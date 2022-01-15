#include<assert.h>
#include"TesteDomain.h"
#include"PunctDeVizitare.h"
#include"ObiectivTuristic.h"
#include"Ruta.h"
#include"Localitate.h"

void TesteDomain::testPunctDeVizitare()
{
	PunctDeVizitare p(1, "nume");
	assert(p.getId() == 1);
	assert(p.getNume() == "nume");
}

void TesteDomain::testLocalitate()
{
	Localitate l(1, "oradea", 200000, 2.3, CoordonateGeo(43.123, 27.342));
	assert(l.getId() == 1);
	assert(l.getNume() == "oradea");
	assert(l.getPopulatie() == 200000);
	assert(l.getRataIncidenta() == 2.3);
	assert(l.getCoord() == CoordonateGeo(43.123, 27.342));
	l.setNume("sibiu");
	assert(l.getNume() == "sibiu");
	l.setRataIncidenta(1.2);
	assert(l.getRataIncidenta() == 1.2);
}

void TesteDomain::testObiectiv()
{
	ObiectivTuristic o(1, "parc", 1, "natural", 0, "nu", "nu");
	assert(o.getId() == 1);
	assert(o.getNume() == "parc");
	assert(o.getTip() == "natural");
	assert(o.getIdLocalitate() == 1);
	assert(o.getPretBilet() == 0);
	assert(o.getNecesitateVaccin() == "nu");
	assert(o.getPatrimoniu() == "nu");

	o.setPretBilet(2);
	assert(o.getPretBilet() == 2);
	o.setNecesitateVaccin("da");
	assert(o.getNecesitateVaccin() == "da");
}

void TesteDomain::testRuta()
{
	Ruta r(1, "ruta", { 1,2,3 });
	assert(r.getId() == 1);
	assert(r.getNume() == "ruta");
	assert(r.getLocalitati()[0]==1);
	assert(r.getLocalitati()[1]==2);
	assert(r.getLocalitati()[2]==3);
	r.setLocalitati({ 4,5,6 });
	assert(r.getLocalitati()[0] == 4);
	assert(r.getLocalitati()[1] == 5);
	assert(r.getLocalitati()[2] == 6);
}

TesteDomain::TesteDomain()
{
}

TesteDomain::~TesteDomain()
{
}

void TesteDomain::runAll()
{
	testPunctDeVizitare();
	testLocalitate();
	testObiectiv();
	testRuta();
	cout << "Testele domain au trecut cu succes!\n";
}
