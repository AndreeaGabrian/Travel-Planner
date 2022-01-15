#include "Validator.h"
#include"Exceptii.h"
#include "Ruta.h"

//valideaza o localitate
//arunca exceptie daca populatia nu e intreg pozitiv, rata incidenta negativa sau coordonate geografice invalide
void ValidatorLocalitate::valideaza(PunctDeVizitare& loc)
{
	vector<string> mesaje;
	try {
		ValidatorPunctDeVizitare::valideaza(loc);
	}
	catch (ExceptiePunctDeVizitare& ex) {
		mesaje.push_back(ex.getMesaje()[0]);
	}
	Localitate& loc_cast = (Localitate&)loc;
	if (loc_cast.getPopulatie() < 0)
		mesaje.push_back("Populatia trebuie sa fie intreg pozitiv");
	if (loc_cast.getRataIncidenta() < 0)
		mesaje.push_back("Rata de incidenta nu poate fi negativa");
	if (mesaje.size() > 0)
		throw ExceptieLocalitate(mesaje);
	ValidatorCoordonateGeo v;
	CoordonateGeo c = loc_cast.getCoord();
	v.valideaza(c);
}

//valideaza un obiectiv turistic
void ValidatorObiectivTuristic::valideaza(PunctDeVizitare& obv)
{
	vector<string> mesaje;
	try {
		ValidatorPunctDeVizitare::valideaza(obv);
	}
	catch (ExceptiePunctDeVizitare& ex) {
		mesaje.push_back(ex.getMesaje()[0]);
	}
	ObiectivTuristic& obv_cast = (ObiectivTuristic&)obv;
	string tip = obv_cast.getTip();
	if (obv_cast.getIdLocalitate() <= 0)
		mesaje.push_back("Id-ul localitatii trebuie sa fie strict pozitiv");
	if (tip.compare("natural") != 0 && tip.compare("istoric") != 0 && tip.compare("cultural") && tip.compare("altele") != 0)
		mesaje.push_back("Tipul trebuie sa fie unul dintre: natural, istoric, cultural, altele");
	if (obv_cast.getPretBilet() < 0)
		mesaje.push_back("Pretul nu poate fi negativ");
	if (obv_cast.getPatrimoniu().compare("da") != 0 && obv_cast.getPatrimoniu().compare("nu") != 0)
		mesaje.push_back("Apartenenta la patrimoniul unesco trebuie sa fie da sau nu");
	if (obv_cast.getNecesitateVaccin().compare("da") != 0 && obv_cast.getNecesitateVaccin().compare("nu") != 0)
		mesaje.push_back("Necesitatea vaccinului trebuie sa fie da sau nu");
	if (mesaje.size() > 0)
		throw ExceptieObiectivTuristic(mesaje);
}

//valideaza coordonatele geografice
void ValidatorCoordonateGeo::valideaza(CoordonateGeo& coord)
{
	vector<string> mesaje;
	if (coord.getLatitudine() < -90 || coord.getLatitudine() > 90)
		mesaje.push_back("Latitudinea trebuie sa fie intre -90 si 90");
	if (coord.getLongitudine() < -180 || coord.getLongitudine() > 180)
		mesaje.push_back("Longitudinea trebuie sa fie intre -180 si 180");
	if (mesaje.size() > 0)
		throw ExceptieCoordonateGeo(mesaje);
}

//validator punct de vizitare
void ValidatorPunctDeVizitare::valideaza(PunctDeVizitare& pct)
{
	int id = pct.getId();
	vector<string> mesaje;
	if (id <= 0)
		mesaje.push_back("Id-ul trebuie sa fie strict pozitiv");
	if(mesaje.size()>0)
		throw ExceptiePunctDeVizitare(mesaje);
}

//validator ruta
void ValidatorRuta::valideaza(PunctDeVizitare& ruta)
{
	vector<string> mesaje;
	try {
		ValidatorPunctDeVizitare::valideaza(ruta);
	}
	catch (ExceptiePunctDeVizitare& ex) {
		mesaje.push_back(ex.getMesaje()[0]);
	}

	Ruta& ruta_cast = (Ruta&)ruta;
	vector<int> id_loc = ruta_cast.getLocalitati();
	for (auto id : id_loc) {
		if (id <= 0)
		{
			mesaje.push_back("Id-ul localitatilor trebuie sa fie strict pozitiv");
			break;
		}
	}
	if (mesaje.size() > 0)
		throw ExceptieRuta(mesaje);
}
