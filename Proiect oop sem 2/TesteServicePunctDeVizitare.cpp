#include "TesteServicePunctDeVizitare.h"
#include"ServicePunctDeVizitare.h"
#include<assert.h>

void TesteServicePunctDeVizitare::testAdd()
{
	ServicePunctDeVizitare srv(this->repo);
	assert(srv.getAll().size() == 0);
	PunctDeVizitare p1(1, "nume1");
	try {
		srv.addPunctDeVizitare(1, "nume1");
		assert(true);
		assert(srv.getAll().size() == 1);
		assert(srv.getAll()[0] == p1);
	}
	catch (ServicePunctExceptie& e) {
		assert(false);
	}

	try {
		srv.addPunctDeVizitare(1, "nume1");
		assert(false);
	}
	catch (ServicePunctExceptie& e) {
		assert(true);
	}
	assert(srv.getAll().size() == 1);
}

void TesteServicePunctDeVizitare::testDelete()
{
	ServicePunctDeVizitare srv(this->repo);
	assert(srv.getAll().size() == 1);
	try {
		srv.deletePunctDeVizitare(1);
		assert(true);
		assert(srv.getAll().size() == 0);
	}
	catch (ServicePunctExceptie& e) {
		assert(false);
	}

	try {
		srv.deletePunctDeVizitare(1);
		assert(false);
	}
	catch (ServicePunctExceptie& e) {
		assert(true);
	}
}

void TesteServicePunctDeVizitare::testUpdate()
{
	ServicePunctDeVizitare srv(this->repo);
	assert(srv.getAll().size() == 0);
	srv.addPunctDeVizitare(1, "nume1");
	assert(srv.getAll().size() == 1);
	try {
		srv.updatePunctDeVizitare(10, "nume_nou");
		assert(false);
	}
	catch (ServicePunctExceptie& e) {
		assert(true);
	}
	try {
		srv.updatePunctDeVizitare(1, "nume_nou");
		assert(true);
		assert(srv.getAll()[0].getNume()== "nume_nou");
	}
	catch (ServicePunctExceptie& e) {
		assert(false);
	}
}

void TesteServicePunctDeVizitare::testFindById()
{
}

TesteServicePunctDeVizitare::TesteServicePunctDeVizitare()
{
}

TesteServicePunctDeVizitare::~TesteServicePunctDeVizitare()
{
	ServicePunctDeVizitare srv(this->repo);
	assert(srv.findById(1) != -1);
	assert(srv.findById(10) == -1);
	assert(srv.findById(45) == -1);
	assert(srv.findById(2) == -1);
}

void TesteServicePunctDeVizitare::runAll()
{
	testAdd();
	testDelete();
	testUpdate();
	testFindById();
	cout << "Testele pentru service punct de vizitare au fost trecute cu succes!\n";
}
