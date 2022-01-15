#include "TesteServiceRuta.h"
#include"ServiceRuta.h"
#include<assert.h>

void TesteServiceRuta::testaddRuta()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	assert(srv_ruta.getAll().size() == 3);
	try {
		Ruta r4(4, "ruta4", { 4,1 });
		srv_ruta.addRuta(4, "ruta4", { 4,1 });
		assert(false);
	}
	catch (ServiceRutaExceptie& e) {
		assert(true);
	}

	assert(srv_ruta.getAll().size() == 3);
	try {
		Ruta r4(4, "ruta4", { 1,2,3 });
		srv_ruta.addRuta(4, "ruta4", {1,2,3});
		assert(true);
	}
	catch (ServiceRutaExceptie& e) {
		cout << e.getMesaj() << endl;
		assert(false);
	}
	assert(srv_ruta.getAll().size() == 4);
}

void TesteServiceRuta::testdeleteRuta()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	assert(srv_ruta.getAll().size() == 4);
	try {
		srv_ruta.deleteRuta(20);
		assert(false);
	}
	catch (ServiceRutaExceptie& e) {
		assert(true);
	}
	assert(srv_ruta.getAll().size() == 4);

	try {
		srv_ruta.deleteRuta(1);
		assert(true);
	}
	catch (ServiceRutaExceptie& e) {
		assert(false);
	}
	assert(srv_ruta.getAll().size() == 3);
}

void TesteServiceRuta::testupdateRuta()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	assert(srv_ruta.getAll().size() == 3);
	try {
		srv_ruta.updateRuta(20, "nume_nou", {1, 2});
		assert(false);
	}
	catch (ServiceRutaExceptie& e) {
		assert(true);
	}
	assert(srv_ruta.getAll().size() == 3);

	try {
		Ruta r2(2, "ruta2", { 3,2 });
		assert(srv_ruta.getAll()[srv_ruta.findById(2)] == r2);
		Ruta r2_noua(2, "nume_nou", { 2, 3 });
		srv_ruta.updateRuta(2, "nume_nou", { 2, 3 });
		assert(true);
		assert(srv_ruta.getAll()[srv_ruta.findById(2)] == r2_noua);
		
	}
	catch (ServiceRutaExceptie& e) {
		assert(false);
	}
	assert(srv_ruta.getAll().size() == 3);
}

void TesteServiceRuta::testfindById()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	assert(srv_ruta.findById(1) == -1);
	assert(srv_ruta.findById(10) == -1);
	assert(srv_ruta.findById(15) == -1);
	assert(srv_ruta.findById(2) != -1);
	assert(srv_ruta.findById(3) != -1);
	assert(srv_ruta.findById(4) != -1);
}

void TesteServiceRuta::testcountRuteByIdLocalitate()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	try {
		srv_ruta.countRuteByIdLocalitate(10);
		assert(false);
	}
	catch (ServiceRutaExceptie& e) {
		assert(true);
	}

	try {
		int nr = srv_ruta.countRuteByIdLocalitate(3);
		assert(true);
		assert(nr == 3);
	}
	catch (ServiceRutaExceptie& e) {
		assert(false);
	}
}

void TesteServiceRuta::testgetRutePrinLocalitate()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	vector<Ruta> rute_gasite;
	Ruta r2(2, "nume_nou", { 2,3 });
	Ruta r3(3, "ruta3", { 3,1 });
	Ruta r4(4, "ruta4", { 1,2,3 });

	try {
		srv_ruta.getRutePrinLocalitate(10);
		assert(false);
	}
	catch (ServiceRutaExceptie& e) {
		assert(true);
	}
	try {
		rute_gasite = srv_ruta.getRutePrinLocalitate(3);
		assert(true);
		assert(rute_gasite.size() == 3);
		assert(rute_gasite[0] == r2);
		assert(rute_gasite[1] == r3);
		assert(rute_gasite[2] == r4);
	}
	catch (ServiceRutaExceptie& e) {
		assert(false);
	}
}

void TesteServiceRuta::testfiltrareRuteDupaNrLocalitati()
{
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	assert(srv_ruta.getAll().size() == 3);
	assert(srv_ruta.getAll()[2].getLocalitati().size() == 3);

	srv_ruta.filtrareRuteDupaNrLocalitati(2);
	assert(srv_ruta.getAll().size() == 2);
	assert(srv_ruta.getAll()[0].getLocalitati().size() == 2);
	assert(srv_ruta.getAll()[1].getLocalitati().size() == 2);
}

void TesteServiceRuta::testsortareRuteCrescatorDupaLocalitati()
{
	vector<Ruta> rute;
	ServiceRuta srv_ruta(this->repo_ruta, this->repo_loc);
	Ruta r2(2, "nume_nou", { 2,3 });
	Ruta r3(3, "ruta3", { 3,1 });
	Ruta r5(5, "nume5", { 1 });
	Ruta r4(4, "ruta4", { 1,2,3 });
	srv_ruta.addRuta(4, "ruta4", { 1,2,3 });
	srv_ruta.addRuta(5, "nume5", { 1 });
	assert(srv_ruta.getAll().size() == 4);

	rute = srv_ruta.sortareRuteCrescatorDupaLocalitati();
	assert(rute[0] == r5);
	assert(rute[1] == r2);
	assert(rute[2] == r3);
	assert(rute[3] == r4);

}

TesteServiceRuta::TesteServiceRuta()
{
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
}

TesteServiceRuta::~TesteServiceRuta()
{
}

void TesteServiceRuta::runAll()
{
	testaddRuta();
	testdeleteRuta();
	testupdateRuta();
	testfindById();
	testcountRuteByIdLocalitate();
	testgetRutePrinLocalitate();
	testfiltrareRuteDupaNrLocalitati();
	testsortareRuteCrescatorDupaLocalitati();
	cout << "Testele pentru service ruta au fost trecute cu succes!\n";
}
