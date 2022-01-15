#include "Localitate.h"
#include "Validator.h"
#include"Exceptii.h"
#include"FunctiiUtile.h"

Localitate::Localitate():PunctDeVizitare()
{
	this->populatie = 0;
	this->rata_incidenta = 0.0;
	this->coord = CoordonateGeo();
}

Localitate::Localitate(int id, string nume, int populatie, double rata_incidenta, CoordonateGeo coord):PunctDeVizitare(id, nume)
{
	this->populatie = populatie;
	this->rata_incidenta = rata_incidenta;
	this->coord = coord;
}

Localitate::Localitate(const Localitate& loc):PunctDeVizitare(loc)
{
	this->populatie = loc.populatie;
	this->rata_incidenta = loc.rata_incidenta;
	this->coord = loc.coord;
}

Localitate::~Localitate()
{
	
}

int Localitate::getPopulatie()
{
	return this->populatie;
}

double Localitate::getRataIncidenta()
{
	return this->rata_incidenta;
}

CoordonateGeo Localitate::getCoord()
{
	return coord;
}


void Localitate::setPopulatie(int p)
{
	this->populatie = p;
}

void Localitate::setRataIncidenta(double rata)
{
	this->rata_incidenta = rata;
}

void Localitate::setCoord(CoordonateGeo coord)
{
	this->coord = coord;
}

PunctDeVizitare* Localitate::clona()
{
	return new Localitate(this->id, this->nume, this->populatie, this->rata_incidenta, this->coord);
}

string Localitate::toString(bool file)
{
	if(file)
		return "L " + PunctDeVizitare::toString(file) + " " + to_string(populatie) + " " + convertDoubleToString(rata_incidenta) + " " + convertDoubleToString(coord.getLatitudine()) + " " + convertDoubleToString(coord.getLongitudine());
	return "localitate: "+PunctDeVizitare:: toString() + ", populatie: " + to_string(populatie) + ", rata incidenta: "+ convertDoubleToString(rata_incidenta)+ ", lat: "+ convertDoubleToString(coord.getLatitudine())+", long: "+ convertDoubleToString(coord.getLongitudine());
}


Localitate& Localitate::operator=(const Localitate& loc)
{
	PunctDeVizitare::operator=(loc);
	this->populatie = loc.populatie;
	this->rata_incidenta = loc.rata_incidenta;
	this->coord = loc.coord;
	
	return *this;
}

bool Localitate::operator==(const Localitate& loc)
{
	return PunctDeVizitare::operator==(loc) && this->populatie == loc.populatie && this->rata_incidenta == loc.rata_incidenta && this->coord==loc.coord;

}

void Localitate::valideazaObiectDinFisier()
{
	ValidatorLocalitate vl;
	try {
		vl.valideaza(*this);
	}
	catch (ExceptieLocalitate& exl) {
		cout << exl;
		throw RepoFileExceptie("Localitatea din fisier cu id-ul " +to_string(id)+ " este invalida\n");
	}
	catch (ExceptieCoordonateGeo& exc) {
		cout << exc;
		throw RepoFileExceptie("Coordonatele localitatii din fisier cu id-ul "+to_string(id)+ " sunt invalide\n");
	}
	catch(...){}
	
}

istream& operator>>(istream& is, Localitate& loc)
{
	int populatie; double rata; CoordonateGeo coord;
	is >> (PunctDeVizitare&)loc;
	if (&is == &cin)
	{
		cout << "Introduceti populatia: "; 
		if (is >> populatie)
		{
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			
			throw ExceptieTipIncorectData("Populatia trebuie sa fie intreg ");
		}
			
			
		cout << "Introduceti rata de incidenta: "; 
		if (is >> rata)
		{
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Rata trebuie sa fie numar ");
		}
		cout << "Introduceti coordonatele geografice: "; 
		is >> coord;
			
	}
	else
		is >> populatie >> rata >> coord;
	loc.setPopulatie(populatie);
	loc.setRataIncidenta(rata);
	loc.setCoord(coord);  
	
	return is;
}

ostream& operator<<(ostream& os, const Localitate& loc)
{
	if (&os == &cout)
	{
		os << (PunctDeVizitare&)loc << ", populatie: " << loc.populatie << ", rata incidenta: " << loc.rata_incidenta << ' ' << loc.coord;
	}
	else
		os << (PunctDeVizitare&)loc << ' ' << loc.populatie << ' ' << loc.rata_incidenta << ' ' << loc.coord;
	
	return os;
}
