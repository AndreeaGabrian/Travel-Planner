#include<iostream>
#include<fstream>
#include<random>
#include "Calatorie.h"
#include"Localitate.h"
#include"Validator.h"
#include"Exceptii.h"
#include"Ruta.h"
using namespace std;

Calatorie::Calatorie()
{
}

Calatorie::Calatorie(string filename)
{
	this->filename = filename;
}

Calatorie::~Calatorie()
{
	this->empty();
}

void Calatorie::empty()
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (this->elem[i] != NULL)
		{
			delete this->elem[i];
			this->elem[i] = NULL;
		}
	}
	this->elem.clear();
}

void Calatorie::setFilename(string filename)
{
	this->filename = filename;
}

int Calatorie::find(PunctDeVizitare* p)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (*this->elem[i] == *p)
		{
			return i;
		}
	}
	return -1;
}

void Calatorie::addElem(PunctDeVizitare* p)
{
	if (find(p) == -1)
		this->elem.push_back(p->clona());	
}

void Calatorie::deleteElem(int poz)
{
	if (poz >= 0 && poz < elem.size())
	{
		delete this->elem[poz];
		this->elem.erase(this->elem.begin() + poz);
	}
}

vector<PunctDeVizitare*> Calatorie::getAll()
{
	vector<PunctDeVizitare*> puncte_clona;
	int size = elem.size();
	
	for (int i = 0; i < size; i++)
	{
		puncte_clona.push_back(elem[i]->clona());
	}
		
	return puncte_clona;
}

void Calatorie::salvareCalatorieInFisier()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		int size = elem.size();
		if (size > 0)
		{
			for (int i = 0; i < size - 1; i++)
			{
				f << elem[i]->toString(true) << endl;
			}
			f << elem[size - 1]->toString(true);
		}

		f.close();
	}
	else
		throw CalatorieExceptie("Fisierul nu s-a deschis pentru scriere/n");
}

vector<PunctDeVizitare*> Calatorie::citireCalatorieDinFisier()
{
	vector<PunctDeVizitare*> calatorie_din_fisier;
	ifstream f(this->filename);
	if (f.is_open())
	{
		
		string linie;
		string sep = " ";

		try {
			while (getline(f, linie))
			{
				if (linie.substr(0, 1) == "L")
				{
					linie = linie.erase(0, 2);

					int pos = linie.find(sep);
					int id = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					int populatie = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					double rata = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					double lat = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);
					
					double lon = stod(linie);

					Localitate l(id, nume, populatie, rata, CoordonateGeo(lat, lon));
					ValidatorLocalitate v;
					v.valideaza(l);
					Localitate* lp = new Localitate(id, nume, populatie, rata, CoordonateGeo(lat, lon));
					calatorie_din_fisier.push_back(lp);

				}
				else if (linie.substr(0, 1) == "O")
				{
					linie = linie.erase(0, 2);

					int pos = linie.find(sep);
					int id = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					int id_localitate = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					string tip = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					string patrimoniu = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					string vaccin = linie;

					ObiectivTuristic o(id, nume, id_localitate, tip, pret, patrimoniu, vaccin);
					ValidatorObiectivTuristic vo;
					vo.valideaza(o);
					ObiectivTuristic* op = new ObiectivTuristic(id, nume, id_localitate, tip, pret, patrimoniu, vaccin);
					calatorie_din_fisier.push_back(op);
				}
				else if (linie.substr(0, 1) == "R")
				{
					linie = linie.erase(0, 2);

					int pos = linie.find(sep);
					int id = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(sep);
					int nr_loc = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					vector<int> id_uri;
					for (int i = 0; i < nr_loc - 1; i++)
					{
						pos = linie.find(sep);
						int id_l = stoi(linie.substr(0, pos));
						id_uri.push_back(id_l);
						linie = linie.erase(0, pos + 1);
					}
					id_uri.push_back(stoi(linie));

					Ruta r(id, nume, id_uri);
					ValidatorRuta vr;
					vr.valideaza(r);
					Ruta* rp = new Ruta(id, nume, id_uri);
					calatorie_din_fisier.push_back(rp);

				}
			}
		}
		catch (ExceptieLocalitate& exl) {
			cout << exl << endl;
		}
		catch (ExceptieObiectivTuristic& exo) {
			cout << exo<<endl;
		}
		catch (ExceptieRuta& exr) {
			cout << exr << endl;
		}
		f.close();
	}
	else
		throw CalatorieExceptie("Fisierul nu s-a deschis pentru citire/n");
	return calatorie_din_fisier;
}

vector<PunctDeVizitare*> Calatorie::sugerareCalatorie()
{
	vector< PunctDeVizitare*> calatorie_sugerata;
	if (elem.size() > 1)
	{
		int max_size = elem.size()-1;
		int nr_puncte = 0;
		
		nr_puncte = rand() % max_size;
		if (nr_puncte == 0) {
			nr_puncte = 2;
		}

		for (int i = 0; i < nr_puncte; i++)
		{
			
			int nr_random = rand() % nr_puncte;
			if (nr_random == 0) {
				nr_random = i;
			}

			PunctDeVizitare* p = elem[nr_random]->clona();
			if (i == 0) {
				calatorie_sugerata.push_back(p);
			}
			else {
				int contor = 0;
				for (int j = 0; j < calatorie_sugerata.size(); j++)
				{
					if (!(*calatorie_sugerata[j] == *p))
					{
						contor++;
						
					}
				}
				if (contor == calatorie_sugerata.size()) {
					calatorie_sugerata.push_back(p);
				}
			}
		}
	}
	return calatorie_sugerata;
}
