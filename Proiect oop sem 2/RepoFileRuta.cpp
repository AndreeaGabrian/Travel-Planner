#include "RepoFileRuta.h"
#include"Localitate.h"
#include<fstream>

void RepoFileRuta::loadFromFile()
{
	ifstream f(this->filename);
	if (f.is_open()) {
		this->elemente.clear();
		while (!f.eof())
		{
			Ruta r;
			f >> r;
			elemente.push_back(r);
			/*f >> id >> nume >> locs;
			string token, sep = " ";
			pos = locs.find(sep);
			token = locs.substr(1, pos);*/

		}
	}
}

void RepoFileRuta::saveToFile()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		for (int i = 0; i < elemente.size() - 1; i++)
		{
			f << elemente[i] << endl;
		}
		f << elemente[elemente.size() - 1];
	}
	else
		cout << "fisierul nu s-a deschis pt scriere\n";
	f.close();
	
}

RepoFileRuta::RepoFileRuta()
{
}

RepoFileRuta::RepoFileRuta(string filename)
{
	this->filename = filename;
	this->loadFromFile();
}

RepoFileRuta::RepoFileRuta(const RepoFileRuta& rft)
{
	this->filename = rft.filename;
	this->elemente = rft.elemente;
}

RepoFileRuta::~RepoFileRuta()
{
}

void RepoFileRuta::setFilename(string filename)
{
	this->filename = filename;
}

void RepoFileRuta::addElem(const Ruta& elem)
{
	RepoTemplate::addElem(elem);
	saveToFile();
}

void RepoFileRuta::updateElem(const Ruta& oldElem, const Ruta& newElem)
{
	RepoTemplate::updateElem(oldElem, newElem);
	saveToFile();
}

void RepoFileRuta::deleteElem(const Ruta& elem)
{
	RepoTemplate::deleteElem(elem);
	saveToFile();
}
