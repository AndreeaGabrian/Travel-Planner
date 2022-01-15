#pragma once
#include"RepoTemplateFile.h"
#include"Localitate.h"
#include"IRepoTemplate.h"

class TesteRepoFile{
private:
	RepoTemplateFile<Localitate> repo;
	vector<Localitate> loc_de_test;
	string filenameIn = "testLocalitatiRepoIn.txt";
	string filenameOut = "testLocalitatiRepoOut.txt";

	void testLoadFromFile();
	void testSaveToFile();
	void testGetAll();
	void testGetSize();
	void testAdd();
	void testDelete();
	void testUpdate();
public:
	TesteRepoFile();
	~TesteRepoFile();
	void runAll();
};

