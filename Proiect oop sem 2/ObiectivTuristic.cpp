#include "ObiectivTuristic.h"
#include"Validator.h"
#include"Exceptii.h"
#include"FunctiiUtile.h"

ObiectivTuristic::ObiectivTuristic() :PunctDeVizitare()
{
	id_localitate=0;
	tip="";
	pret_bilet=0.0;
	patrimoniu_UNESCO="nu";
	necesitate_vaccin="nu";
}

ObiectivTuristic::ObiectivTuristic(int id, string nume, int id_localitate, string tip, double pret, string patrimoniu_UNESCO, string necesitate_vaccin) :PunctDeVizitare(id, nume)
{
	this->id_localitate=id_localitate;
	this->tip=tip;
	this->pret_bilet=pret;
	this->patrimoniu_UNESCO=patrimoniu_UNESCO;
	this->necesitate_vaccin=necesitate_vaccin;
}

ObiectivTuristic::ObiectivTuristic(const ObiectivTuristic& obv):PunctDeVizitare(obv)
{
	this->id_localitate = obv.id_localitate;
	this->tip = obv.tip;
	this->pret_bilet = obv.pret_bilet;
	this->patrimoniu_UNESCO = obv.patrimoniu_UNESCO;
	this->necesitate_vaccin = obv.necesitate_vaccin;
}

ObiectivTuristic::~ObiectivTuristic()
{
}

int ObiectivTuristic::getIdLocalitate()
{
	return id_localitate;
}

string ObiectivTuristic::getTip()
{
	return tip;
}

double ObiectivTuristic::getPretBilet()
{
	return pret_bilet;
}

string ObiectivTuristic::getPatrimoniu()
{
	return patrimoniu_UNESCO;
}

string ObiectivTuristic::getNecesitateVaccin()
{
	return necesitate_vaccin;
}

void ObiectivTuristic::setIdLocalitate(int id_l)
{
	id_localitate = id_l;
}

void ObiectivTuristic::setTip(string t)
{
	tip = t;
}

void ObiectivTuristic::setPretBilet(double pret)
{
	pret_bilet = pret;
}

void ObiectivTuristic::setPatrimoniu(string patrimoniu)
{
	patrimoniu_UNESCO = patrimoniu;
}

void ObiectivTuristic::setNecesitateVaccin(string vaccin)
{
	necesitate_vaccin = vaccin;
}

PunctDeVizitare* ObiectivTuristic::clona()
{
	return new ObiectivTuristic(id, nume, id_localitate, tip, pret_bilet, patrimoniu_UNESCO, necesitate_vaccin );
}

string ObiectivTuristic::toString(bool file)
{
	if(file)
		return "O "+PunctDeVizitare::toString(file) + " " + to_string(id_localitate) + " " + tip + " " + convertDoubleToString(pret_bilet) + " " + patrimoniu_UNESCO + " " + necesitate_vaccin;
	return "obiectiv "+ PunctDeVizitare::toString() + ", localitate: "+to_string(id_localitate) + ", tip: "+tip+", pret bilet: "+ convertDoubleToString(pret_bilet)+", patrimoniu UNESCO: "+patrimoniu_UNESCO+", necesita vaccin: "+necesitate_vaccin;
}

ObiectivTuristic& ObiectivTuristic::operator=(const ObiectivTuristic& obv)
{
	PunctDeVizitare::operator=(obv);
	this->id_localitate = obv.id_localitate;
	this->tip = obv.tip;
	this->pret_bilet = obv.pret_bilet;
	this->patrimoniu_UNESCO = obv.patrimoniu_UNESCO;
	this->necesitate_vaccin = obv.necesitate_vaccin;
	return *this;
}

bool ObiectivTuristic::operator==(const ObiectivTuristic& obv)
{
	return PunctDeVizitare::operator==(obv) && id_localitate == obv.id_localitate && (tip.compare(obv.tip) == 0) && pret_bilet == obv.pret_bilet && patrimoniu_UNESCO == obv.patrimoniu_UNESCO && necesitate_vaccin == obv.necesitate_vaccin;
}

void ObiectivTuristic::valideazaObiectDinFisier()
{
	ValidatorObiectivTuristic vo;
	try {
		vo.valideaza(*this);
	}
	catch(ExceptieObiectivTuristic& exo){
		cout << exo;
		throw RepoFileExceptie("Obiectivul turistic din fisier cu id-ul "+to_string(id)+ " este invalid");
	}
	catch(...){}
}

istream& operator>>(istream& is, ObiectivTuristic& obv)
{
	is >> (PunctDeVizitare&)obv;
	int id_l; string tip, patrimoniu, vaccin; double pret;
	if (&is == &cin)
	{
		cout << "id localitate: "; 
		if (is >> id_l)
		{
			cout << "tip[natural, istoric, cultural, altele]: "; is >> tip;
			cout << "pret: ";
			if (is >> pret)
			{
				cout << "patrimoniu UNESCO[da,nu]: "; is >> patrimoniu;
				cout << "necesita vaccin[da,nu]: "; is >> vaccin;
			}
			else
			{
				is.clear();
				is.ignore(numeric_limits<streamsize>::max(), '\n');

				throw ExceptieTipIncorectData("Pretul trebuie sa fie numar ");
			}
			
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul localitatii trebuie sa fie intreg ");
		}
		

	}
	else
		is >> id_l >> tip >> pret >> patrimoniu >> vaccin;
	obv.setIdLocalitate(id_l);
	obv.setTip(tip);
	obv.setPretBilet(pret);
	obv.setPatrimoniu(patrimoniu);
	obv.setNecesitateVaccin(vaccin);

	return is;
}

ostream& operator<<(ostream& os, const ObiectivTuristic& obv)
{
	os << (PunctDeVizitare&)obv << ' ';
	if (&os == &cout)
		os << "id localitate:" << obv.id_localitate << ", tip:" << obv.tip << ", pret bilet:" << obv.pret_bilet << ", patrimoniu UNESCO:" << obv.patrimoniu_UNESCO << ", necesita vaccin:" << obv.necesitate_vaccin;
	else
		os << obv.id_localitate << ' ' << obv.tip << ' ' << obv.pret_bilet << ' ' << obv.patrimoniu_UNESCO << ' ' << obv.necesitate_vaccin;
	return os;
}
