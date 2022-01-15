
#include "RepoFileLocalitati.h"
#include<fstream>

void RepoFileLocalitati::loadFromFile()
{
	ifstream f(this->filename);
	if (f.is_open()) {
		this->elemente.clear();
		while (!f.eof())
		{
			Localitate l;
			f >> l;
			elemente.push_back(l);
		}
		f.close();
	}
	else
		cout << "fisierul nu s-a deschis pt citire\n";
}

void RepoFileLocalitati::saveToFile()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		for (int i = 0; i < elemente.size() - 1; i++)
		{
			f << elemente[i] << endl;
		}
		f << elemente[elemente.size() - 1];
		f.close();
	}
	else
		cout << "fisierul nu s-a deschis pt scriere\n";
	
}

RepoFileLocalitati::RepoFileLocalitati()
{
}

RepoFileLocalitati::RepoFileLocalitati(string filename)
{
	this->filename = filename;
	this->loadFromFile();
}

RepoFileLocalitati::RepoFileLocalitati(const RepoFileLocalitati& rfl)
{
	this->elemente = rfl.elemente;
	this->filename = rfl.filename;
}

RepoFileLocalitati::~RepoFileLocalitati()
{
}

void RepoFileLocalitati::setFilename(string filename)
{
	this->filename = filename;
}

void RepoFileLocalitati::addElem(const Localitate& elem)
{
	RepoTemplate::addElem(elem);
	saveToFile();
}

void RepoFileLocalitati::updateElem(const Localitate& oldElem, const Localitate& newElem)
{
	RepoTemplate::updateElem(oldElem, newElem);
	saveToFile();
}

void RepoFileLocalitati::deleteElem(const Localitate& elem)
{
	RepoTemplate::deleteElem(elem);
	saveToFile();
}

