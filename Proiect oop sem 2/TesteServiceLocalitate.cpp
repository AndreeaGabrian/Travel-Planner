#include "TesteServiceLocalitate.h"
#include"RepoTemplate.h"
#include<assert.h>

TesteServiceLocalitate::TesteServiceLocalitate()
{
	Localitate l1(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	Localitate l2(2, "b", 20, 2.1, CoordonateGeo(20, 20));
	Localitate l3(3, "c", 30, 3.1, CoordonateGeo(30, 30));
	repo_loc.addElem(l1);
	repo_loc.addElem(l2);
	repo_loc.addElem(l3);

	ObiectivTuristic o1(1, "parc", 1, "natural", 0, "nu", "nu");
	ObiectivTuristic o2(2, "teatru", 2, "cultural", 10, "nu", "da");
	repo_obv.addElem(o1);
	repo_obv.addElem(o2);

	Ruta r1(1, "ruta1", { 1,2 });
	Ruta r2(2, "ruta2", { 3,2 });
	repo_ruta.addElem(r1);
	repo_ruta.addElem(r2);
}

TesteServiceLocalitate::~TesteServiceLocalitate()
{
}

void TesteServiceLocalitate::runAll()
{
	testGetAll();
	testAdd();
	testDelete();
	testUpdate();
	testFindById();
	testgetObiectiveDinLocalitate();
	testgetRuteIncepandDinLocalitate();
	testgetDistantaIntreLocalitati();
	testgetObvLocKm();
	testgetCeaMaiApropiataLoc();
	testfiltrareLocalitatiDupaRata();
	testgetRuteCuLungimeMica();
	cout << "Testele pentru service localitati au trecut cu succes!\n";
}

void TesteServiceLocalitate::testGetAll()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	vector<Localitate> loc = srv_loc.getAll();
	assert(loc.size() == 3);
	assert(loc[0] == repo_loc.getAll()[0]);
	assert(loc[1] == repo_loc.getAll()[1]);
	assert(loc[2] == repo_loc.getAll()[2]);
}

void TesteServiceLocalitate::testAdd()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	Localitate l(5, "sdf", 3000, 4.1, CoordonateGeo(10, 30));
	assert(srv_loc.getAll().size() == 3);
	try {
		srv_loc.addLocalitate(5, "sdf", 3000, 4.1, CoordonateGeo(10, 30));
		assert(true);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
	
	assert(srv_loc.getAll().size() == 4);
	assert(srv_loc.getAll()[3] == l);

	try {
		srv_loc.addLocalitate(5, "sdf", 3000, 4.1, CoordonateGeo(10, 30));
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}
}

void TesteServiceLocalitate::testDelete()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	assert(srv_loc.getAll().size() == 4);
	assert(srv_loc.getAll()[3].getId() == 5);
	Localitate l(5, "sdf", 3000, 4.1, CoordonateGeo(10, 30));
	try {
		srv_loc.deleteLocalitate(5);
		assert(true);
	}
	catch(ServiceLocalitateExceptie& e){
		assert(false);
	}
	
	assert(srv_loc.getAll().size() == 3);
	assert(srv_loc.getAll()[0].getId() == 1);
	assert(srv_loc.getAll()[1].getId() == 2);
	assert(srv_loc.getAll()[2].getId() == 3);
	
	try {
		srv_loc.deleteLocalitate(50);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}
	assert(srv_loc.getAll().size() == 3);
}

void TesteServiceLocalitate::testUpdate()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	Localitate l1(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	assert(srv_loc.getAll()[0] == l1);
	try {
		srv_loc.updateLocalitate(1, "nume_nou", 100, 2.3, CoordonateGeo(34, 56));
		assert(true);
	}
	catch(ServiceLocalitateExceptie& e) {
		assert(false);
	}
	assert(srv_loc.getAll()[0].getNume() == "nume_nou");
	assert(srv_loc.getAll()[0].getPopulatie() == 100);
	assert(srv_loc.getAll()[0].getRataIncidenta() == 2.3);
	assert(srv_loc.getAll()[0].getCoord() == CoordonateGeo(34, 56));


	try {
		srv_loc.updateLocalitate(100, "nume_nou", 100, 2.3, CoordonateGeo(34, 56));
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}
}

void TesteServiceLocalitate::testFindById()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	assert(srv_loc.findById(1) == 0);
	assert(srv_loc.findById(2) == 1);
	assert(srv_loc.findById(3) == 2);
	assert(srv_loc.findById(56) == -1);
	assert(srv_loc.findById(23) == -1);
}

void TesteServiceLocalitate::testgetObiectiveDinLocalitate()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	try {
		srv_loc.getObiectiveDinLocalitate(10);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		vector<ObiectivTuristic> obiective=srv_loc.getObiectiveDinLocalitate(1);
		assert(true);
		assert(obiective.size() == 1);
		assert(obiective[0].getId() == 1);
		assert(obiective[0].getNume() == "parc");
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}

void TesteServiceLocalitate::testgetRuteIncepandDinLocalitate()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	try {
		srv_loc.getRuteIncepandDinLocalitate(10);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		vector<Ruta> rute_gasite=srv_loc.getRuteIncepandDinLocalitate(1);
		assert(true);
		Ruta r1(1, "ruta1", { 1,2 });
		assert(rute_gasite.size() == 1);
		assert(rute_gasite[0] == r1);

	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}

void TesteServiceLocalitate::testgetDistantaIntreLocalitati()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	try {
		srv_loc.getDistantaIntreLocalitati(10, 2);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		double distanta = srv_loc.getDistantaIntreLocalitati(1, 2);
		assert(true);
		assert(distanta == 3865);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}

void TesteServiceLocalitate::testgetObvLocKm()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	try {
		srv_loc.getObvLocKm(2, 10);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		srv_loc.getObvLocKm(-2, 10);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		vector<pair<ObiectivTuristic, int>> obv_gasite = srv_loc.getObvLocKm(4000, 1);
		assert(true);
		assert(obv_gasite.size() == 2);
		ObiectivTuristic o1(1, "parc", 1, "natural", 0, "nu", "nu");
		ObiectivTuristic o2(2, "teatru", 2, "cultural", 10, "nu", "da");
		assert(obv_gasite[0].first == o1);
		assert(obv_gasite[1].first == o2);
		assert(obv_gasite[0].second == 0);
		assert(obv_gasite[1].second == 3865);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}

void TesteServiceLocalitate::testgetCeaMaiApropiataLoc()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	try {
		srv_loc.getCeaMaiApropiataLoc(100);
		assert(false);

	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	double d1= srv_loc.getDistantaIntreLocalitati(1,2);
	double d2 = srv_loc.getDistantaIntreLocalitati(1, 3);
	assert(d1 == 3865);
	assert(d2 == 2484);
	try {
		pair<Localitate, int> p=srv_loc.getCeaMaiApropiataLoc(1);
		assert(true);
		Localitate l3(3, "c", 30, 3.1, CoordonateGeo(30, 30));
		assert(p.first == l3);
		assert(p.second == 2484);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}

void TesteServiceLocalitate::testfiltrareLocalitatiDupaRata()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	vector<Localitate> loc;
	try {
		srv_loc.filtrareLocalitatiDupaRata(-12);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	assert(srv_loc.getAll().size() == 3);
	try {
		srv_loc.filtrareLocalitatiDupaRata(4);
		assert(true);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
	assert(srv_loc.getAll().size() == 3);

	try {
		srv_loc.filtrareLocalitatiDupaRata(2.2);
		assert(true);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
	assert(srv_loc.getAll().size() == 1);
	assert(repo_obv.getSize() == 1);        //s-au sters si rutele/obv care aveau loc 1 si loc 3
	assert(repo_ruta.getSize() == 0);
}

void TesteServiceLocalitate::testgetRuteCuLungimeMica()
{
	ServiceLocalitati srv_loc(repo_loc, repo_obv, repo_ruta);
	srv_loc.deleteLocalitate(2);
	//acum nu mai e nimic in repo loc si repo ruta
	Localitate l1(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	Localitate l2(2, "b", 20, 2.1, CoordonateGeo(20, 20));
	Localitate l3(3, "c", 30, 3.1, CoordonateGeo(30, 30));
	repo_loc.addElem(l1);
	repo_loc.addElem(l2);
	repo_loc.addElem(l3);

	Ruta r1(1, "ruta1", { 1,2 });
	Ruta r2(2, "ruta2", { 3,2 });
	Ruta r3(3, "ruta3", { 3,1 });
	repo_ruta.addElem(r1);
	repo_ruta.addElem(r2);
	repo_ruta.addElem(r3);

	double d1 = srv_loc.getDistantaIntreLocalitati(1, 2);
	double d2 = srv_loc.getDistantaIntreLocalitati(3, 2);
	double d3 = srv_loc.getDistantaIntreLocalitati(3, 1);

	vector<pair<Ruta, double>> rute_gasite;

	try {
		srv_loc.getRuteCuLungimeMica(-12);
		assert(false);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(true);
	}

	try {
		rute_gasite=srv_loc.getRuteCuLungimeMica(2000);
		assert(true);
		assert(rute_gasite.size() == 1);
		assert(rute_gasite[0].second == 1544);
		assert(rute_gasite[0].first == r1);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}

	try {
		rute_gasite = srv_loc.getRuteCuLungimeMica(4000);
		assert(true);
		assert(rute_gasite.size() == 2);
		assert(rute_gasite[0].second == 1544);
		assert(rute_gasite[0].first == r1);
		assert(rute_gasite[1].second == 3043);
		assert(rute_gasite[1].first == r2);
	}
	catch (ServiceLocalitateExceptie& e) {
		assert(false);
	}
}
