#pragma once
#include"string.h"
#include"Calatorie.h"
#include<iostream>
using std::string;

class TesteCalatorie{
private:
	string filenameIn = "testCalatorieIn.txt";
	string filenameOut = "testCalatorieOut.txt";
	vector<PunctDeVizitare*> elem;

	void testAdd();
	void testDelete();
	void testFind();

	void testsalvareCalatorieInFisier();
	void testcitireCalatorieDinFisier();
	void testsugerareCalatorie();
public:
	TesteCalatorie();
	~TesteCalatorie();
	void runAll();
};

