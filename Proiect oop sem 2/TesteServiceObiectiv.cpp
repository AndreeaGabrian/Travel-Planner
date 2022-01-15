#include "TesteServiceObiectiv.h"
#include"ServiceObiectivTuristic.h"
#include<assert.h>

void TesteServiceObiectiv::testaddObiectiv()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	assert(srv.getAll().size() == 0);
	ObiectivTuristic o1(1, "parc", 1, "natural", 0, "nu", "nu");
	ObiectivTuristic o2(2, "teatru", 2, "cultural", 10, "nu", "da");

	try {
		srv.addObiectiv(1, "parc", 1, "natural", 0, "nu", "nu");
		assert(true);
		assert(srv.getAll().size() == 1);
		assert(srv.getAll()[0] == o1);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
	
	try {
		srv.addObiectiv(1, "parc", 1, "natural", 0, "nu", "nu");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}
	assert(srv.getAll().size() == 1);

	try {
		srv.addObiectiv(2, "teatru", 200, "cultural", 10, "nu", "da");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}

	try {
		srv.addObiectiv(2, "teatru", 2, "cultural", 10, "nu", "da");
		assert(true);
		assert(srv.getAll().size() == 2);
		assert(srv.getAll()[1] == o2);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
}

void TesteServiceObiectiv::testDeleteObiectiv()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	assert(srv.getAll().size() == 2);
	try {
		srv.deleteOviectiv(12);
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}
	assert(srv.getAll().size() == 2);

	try {
		srv.deleteOviectiv(1);
		assert(true);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
	assert(srv.getAll().size() == 1);
	ObiectivTuristic o2(2, "teatru", 2, "cultural", 10, "nu", "da");
	assert(srv.getAll()[0] == o2);
}

void TesteServiceObiectiv::testupdateObiectiv()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	assert(srv.getAll().size() == 1);
	try {
		srv.updateObiectiv(12, "castel", 3, "cultural", 10, "nu", "da");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}
	assert(srv.getAll().size() == 1);

	try {
		ObiectivTuristic o2(2, "teatru", 2, "cultural", 10, "nu", "da");
		assert(srv.getAll()[0] == o2);
		ObiectivTuristic o2_nou(2, "castel", 3, "cultural", 10, "nu", "da");
		srv.updateObiectiv(2, "castel", 3, "cultural", 10, "nu", "da");
		assert(true);
		assert(srv.getAll()[0] == o2_nou);
		
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
}

void TesteServiceObiectiv::testfindById()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	assert(srv.findById(2) != -1);
	assert(srv.findById(1) == -1);
	assert(srv.findById(10) == -1);
	assert(srv.findById(7) == -1);
}

void TesteServiceObiectiv::testcountObiectiveByIdLocalitate()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	srv.deleteOviectiv(2);
	assert(srv.getAll().size() == 0);
	//nu mai este niciun obiectiv

	ObiectivTuristic o1(1, "parc", 1, "natural", 0, "nu", "nu");
	ObiectivTuristic o2(2, "teatru", 1, "cultural", 10, "nu", "da");
	ObiectivTuristic o3(3, "parc", 1, "natural", 0, "nu", "nu");
	ObiectivTuristic o4(4, "teatru", 2, "cultural", 10, "nu", "da");
	srv.addObiectiv(1, "parc", 1, "natural", 0, "nu", "nu");
	srv.addObiectiv(2, "teatru", 1, "cultural", 10, "nu", "da");
	srv.addObiectiv(3, "parc", 1, "natural", 0, "nu", "nu");
	srv.addObiectiv(4, "teatru", 2, "cultural", 10, "nu", "da");
	assert(srv.getAll().size() == 4);

	assert(srv.countObiectiveByIdLocalitate(10) == 0);
	assert(srv.countObiectiveByIdLocalitate(2) == 1);
	assert(srv.countObiectiveByIdLocalitate(1) == 3);
}

void TesteServiceObiectiv::testsorteazaDupaTip()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	vector<ObiectivTuristic> sortat;
	try {
		srv.sorteazaDupaTip("sdfsd");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}

	try {
		sortat = srv.sorteazaDupaTip("natural");
		assert(true);
		assert(sortat.size() == 2);
		assert(sortat[0].getTip()=="natural");
		assert(sortat[1].getTip()=="natural");
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}

	try {
		sortat = srv.sorteazaDupaTip("cultural");
		assert(true);
		assert(sortat.size() == 2);
		assert(sortat[0].getTip() == "cultural");
		assert(sortat[1].getTip() == "cultural");
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}

	try {
		sortat = srv.sorteazaDupaTip("istoric");
		assert(true);
		assert(sortat.size() == 0);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
}

void TesteServiceObiectiv::testsorteazaDupaPatrimoniu()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	vector<ObiectivTuristic> sortat;
	try {
		srv.sorteazaDupaPatrimoniu("poate");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}

	try {
		sortat = srv.sorteazaDupaPatrimoniu("da");
		assert(true);
		assert(sortat.size() == 0);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}

	try {
		sortat = srv.sorteazaDupaPatrimoniu("nu");
		assert(true);
		assert(sortat.size() == 4);
		assert(sortat[0].getPatrimoniu() == "nu");
		assert(sortat[1].getPatrimoniu() == "nu");
		assert(sortat[2].getPatrimoniu() == "nu");
		assert(sortat[3].getPatrimoniu() == "nu");
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
}

void TesteServiceObiectiv::testsorteazaDupaNecesitateVaccin()
{
	ServiceObiectivTuristic srv(this->repo_obv, this->repo_loc);
	vector<ObiectivTuristic> sortat;
	try {
		srv.sorteazaDupaNecesitateVaccin("poate");
		assert(false);
	}
	catch (ServiceObiectivExceptie& e) {
		assert(true);
	}

	try {
		sortat = srv.sorteazaDupaNecesitateVaccin("da");
		assert(true);
		assert(sortat.size() == 2);
		assert(sortat[0].getNecesitateVaccin() == "da");
		assert(sortat[1].getNecesitateVaccin() == "da");
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}

	try {
		sortat = srv.sorteazaDupaNecesitateVaccin("nu");
		assert(true);
		assert(sortat.size() == 2);
		assert(sortat[0].getNecesitateVaccin() == "nu");
		assert(sortat[1].getNecesitateVaccin() == "nu");
	}
	catch (ServiceObiectivExceptie& e) {
		assert(false);
	}
}

TesteServiceObiectiv::TesteServiceObiectiv()
{
	Localitate l1(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	Localitate l2(2, "b", 20, 2.1, CoordonateGeo(20, 20));
	Localitate l3(3, "c", 30, 3.1, CoordonateGeo(30, 30));
	repo_loc.addElem(l1);
	repo_loc.addElem(l2);
	repo_loc.addElem(l3);
}

TesteServiceObiectiv::~TesteServiceObiectiv()
{
}

void TesteServiceObiectiv::runAll()
{
	testaddObiectiv();
	testDeleteObiectiv();
	testupdateObiectiv();
	testfindById();
	testcountObiectiveByIdLocalitate();
	testsorteazaDupaTip();
	testsorteazaDupaPatrimoniu();
	testsorteazaDupaNecesitateVaccin();
	cout << "Testele pentru service obiectiv au trecut cu succes!\n";
}
