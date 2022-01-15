#include "PunctDeVizitare.h"
#include"Validator.h"
#include"Exceptii.h"

PunctDeVizitare::PunctDeVizitare()
{
	this->id = -1;
	this->nume = "";
}

PunctDeVizitare::PunctDeVizitare(int id, string nume)
{
	this->id = id;
	this->nume = nume;
}


PunctDeVizitare::PunctDeVizitare(const PunctDeVizitare& p)
{
	this->id = p.id;
	this->nume = p.nume;
}

PunctDeVizitare::~PunctDeVizitare()
{
	this->nume = "";
}

int PunctDeVizitare::getId()
{
	return this->id;
}

string PunctDeVizitare::getNume()
{
	return this->nume;
}


void PunctDeVizitare::setId(int id)
{
	this->id = id;
}

void PunctDeVizitare::setNume(string nume)
{
	this->nume = nume;
}

PunctDeVizitare* PunctDeVizitare::clona()
{
	return new PunctDeVizitare(this->id, this->nume);
}

string PunctDeVizitare::toString(bool file)
{
	if (file)
	{
		return to_string(id) + " " + nume;
	}
	return "id: "+ to_string(id)+ ", nume: "+ nume;
}


PunctDeVizitare& PunctDeVizitare::operator=(const PunctDeVizitare& p)
{
	this->id = p.id;
	this->nume = p.nume;
	return *this;
}

bool PunctDeVizitare::operator==(const PunctDeVizitare& p)
{
	return this->nume==p.nume;
}

void PunctDeVizitare::valideazaObiectDinFisier()
{
	ValidatorPunctDeVizitare vp;
	try {
		vp.valideaza(*this);
	}
	catch (ExceptiePunctDeVizitare& ex) {
		cout <<ex<< endl;
		throw RepoFileExceptie("Punct de vizitare din fisier invalid, id negativ\n");
	}

}


istream& operator>>(istream& is, PunctDeVizitare& p)
{
	int id;
	string nume;

	if (&is == &cin)
	{
		cout << "Dati id-ul: "; 
		if (is >> id)
		{
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul trebuie sa fie intreg ");
		}
		cout << "Dati numele: "; 
		is >> nume;
	}
	else
		is >> id >> nume;
	p.setId(id);
	p.setNume(nume);
	return is;
}

ostream& operator<<(ostream& os, const PunctDeVizitare& p)
{
	if (&os == &cout)
	{
		os << "id: " << p.id << ", nume: " << p.nume;
	}
	else
		os << p.id << ' ' << p.nume;
	
	return os;
}
