#include "TesteRepoFile.h"
#include<assert.h>

void TesteRepoFile::testLoadFromFile()
{
	this->repo.setFilename(this->filenameIn);
	this->repo.loadFromFile();

	vector<Localitate> localitati = repo.getAll();
	assert(localitati.size() == loc_de_test.size());
	for (int i = 0; i < localitati.size(); i++)
	{
		assert(localitati[i] == loc_de_test[i]);
	}
}

void TesteRepoFile::testSaveToFile()
{
	this->repo.setFilename(this->filenameIn);
	this->repo.loadFromFile();

	this->repo.setFilename(this->filenameOut);
	Localitate l(10, "loc", 2000, 2, CoordonateGeo(23, 45));
	this->repo.addElem(l);

	this->repo.loadFromFile();
	vector<Localitate> localitati = repo.getAll();
	assert(localitati.size() == loc_de_test.size() + 1);
	int size = localitati.size();
	for (int i = 0; i < size-1; i++)
	{
		assert(localitati[i] == loc_de_test[i]);
	}
	assert(localitati[size - 1] == l);
}

void TesteRepoFile::testGetAll()
{
	repo.setFilename(this->filenameIn);
	repo.loadFromFile();
	vector<Localitate> localitati = repo.getAll();
	assert(localitati.size() == loc_de_test.size());
	for (int i = 0; i < localitati.size(); i++)
	{
		assert(localitati[i] == loc_de_test[i]);
	}
}

void TesteRepoFile::testAdd()
{
	this->repo.setFilename(this->filenameIn);
	this->repo.loadFromFile();

	this->repo.setFilename(this->filenameOut);
	int initial_size = repo.getSize();
	Localitate l_noua(11, "noua", 200230, 2.4, CoordonateGeo(29, 25));
	repo.addElem(l_noua);
	assert(repo.getSize() == initial_size + 1);
	assert(repo.getAll()[initial_size] == l_noua);
}

void TesteRepoFile::testGetSize()
{
	repo.setFilename(this->filenameIn);
	repo.loadFromFile();
	assert(repo.getSize() == 3);
}

void TesteRepoFile::testDelete()
{
	this->repo.setFilename(this->filenameIn);
	this->repo.loadFromFile();

	this->repo.setFilename(this->filenameOut);
	assert(repo.getSize() == 3);
	Localitate l(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	repo.deleteElem(l);
	assert(repo.getSize() == 2);
	Localitate loc(10, "sdf", 10, 1.1, CoordonateGeo(10, 10));
	repo.deleteElem(loc);
	assert(repo.getSize() == 2);
}

void TesteRepoFile::testUpdate()
{
	this->repo.setFilename(this->filenameIn);
	this->repo.loadFromFile();
	assert(repo.getSize() == 3);
	this->repo.setFilename(this->filenameOut);
	Localitate l(10, "sdf", 10, 1.1, CoordonateGeo(10, 10));
	Localitate l2(2, "b", 20, 2.1, CoordonateGeo(20, 20));
	repo.updateElem(l, l2);
	assert(repo.getAll()[0] == loc_de_test[0]);
	assert(repo.getAll()[1] == loc_de_test[1]);
	assert(repo.getAll()[2] == loc_de_test[2]);
	repo.updateElem(l2, l);
	assert(repo.getAll()[0] == loc_de_test[0]);
	assert(repo.getAll()[1] == l);
	assert(repo.getAll()[2] == loc_de_test[2]);
}

TesteRepoFile::TesteRepoFile()
{
	Localitate l1(1, "a", 10, 1.1, CoordonateGeo(10, 10));
	Localitate l2(2, "b", 20, 2.1, CoordonateGeo(20, 20));
	Localitate l3(3, "c", 30, 3.1, CoordonateGeo(30, 30));
	loc_de_test.push_back(l1);
	loc_de_test.push_back(l2);
	loc_de_test.push_back(l3);

}

TesteRepoFile::~TesteRepoFile()
{
	loc_de_test.clear();
}

void TesteRepoFile::runAll()
{
	testLoadFromFile();
	testSaveToFile();
	testGetAll();
	testGetSize();
	testAdd();
	testDelete();
	testUpdate();
	cout << "Testele pentru repo file au fost trecute cu succes!\n";
}
