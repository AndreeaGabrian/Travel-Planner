#include "TesteRepo.h"
#include<assert.h>

void TesteRepo::testGetAll()
{
	repo.setElemente(puncte_de_test);
	assert(repo.getSize() == 3);
	vector<PunctDeVizitare> pct = repo.getAll();
	assert(pct[0] == puncte_de_test[0]);
	assert(pct[1] == puncte_de_test[1]);
	assert(pct[2] == puncte_de_test[2]);

}

void TesteRepo::testAdd()
{
	assert(repo.getSize() == 3);
	PunctDeVizitare p(10, "nou");
	repo.addElem(p);
	assert(repo.getSize() == 4);
	assert(repo.getAll()[3] == p);
}

void TesteRepo::testDelete()
{
	assert(repo.getSize() == 4);
	PunctDeVizitare p1(1, "a");
	repo.deleteElem(p1);
	assert(repo.getSize() == 3);
	assert(repo.getAll()[0].getId() == 2);
	assert(repo.getAll()[1].getId() == 3);
	assert(repo.getAll()[2].getId() == 10);
	repo.deleteElem(PunctDeVizitare(2, "b"));
	assert(repo.getSize() == 2);
}

void TesteRepo::testUpdate()
{
	assert(repo.getSize() == 2);
	PunctDeVizitare p_nou(3, "nume_nou");
	PunctDeVizitare p_vechi(3, "c");
	assert(repo.getAll()[0].getId() == 3);
	assert(repo.getAll()[0].getNume() == "c");
	repo.updateElem(p_vechi, p_nou);
	assert(repo.getAll()[0].getId() == 3);
	assert(repo.getAll()[0].getNume() == "nume_nou");
}

TesteRepo::TesteRepo()
{
	PunctDeVizitare p1(1, "a");
	PunctDeVizitare p2(2, "b");
	PunctDeVizitare p3(3, "c");
	puncte_de_test.push_back(p1);
	puncte_de_test.push_back(p2);
	puncte_de_test.push_back(p3);
}

TesteRepo::~TesteRepo()
{
	puncte_de_test.clear();
}

void TesteRepo::runAll()
{
	testGetAll();
	testAdd();
	testDelete();
	testUpdate();
	cout << "Testele pentru repo au fost trecute cu succes!\n";
}
