#include "ServiceLocalitati.h"
#include "Exceptii.h"

ServiceLocalitati::~ServiceLocalitati()
{
}

//return: toate localitatile
vector<Localitate> ServiceLocalitati::getAll()
{
	return repo_loc.getAll();
}

//adauga o noua localitate
//arunca exceptie daca exista deja o localitate cu id-ul dat
void ServiceLocalitati::addLocalitate(int id, string nume, int populatie, double rata_incidenta, CoordonateGeo coord)
{
	if (repo_loc.findById(id) != -1)
		throw ServiceLocalitateExceptie("Exista deja o localitate cu id-ul: " + to_string(id));
	Localitate l(id, nume, populatie, rata_incidenta, coord);
	this->repo_loc.addElem(l);
}

//sterge o localitate existenta
//daca localitatea face parte dintr-o ruta sau exista cel putin un obiectiv turistic atasat localitatii se vor sterge toate aceste rute si obiective
//arunca exceptie daca nu exista o localitate cu id-ul dat)
void ServiceLocalitati::deleteLocalitate(int id)
{
	if (repo_loc.findById(id) == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul: " + to_string(id));

	vector<ObiectivTuristic> obiective = repo_obv.getAll();
	for (int i = 0; i < obiective.size(); i++)
	{
		if (obiective[i].getIdLocalitate() == id)
		{
			repo_obv.deleteElem(obiective[i]);
		}	
	}
	vector<Ruta> rute = repo_ruta.getAll();
	for (int i = 0; i < rute.size(); i++)
	{
		vector<int> ruta_loc = rute[i].getLocalitati();
		for (int j = 0; j < ruta_loc.size(); j++)
		{
			if (ruta_loc[j] == id)
			{
				repo_ruta.deleteElem(rute[i]);
			}
		}
	}
	vector<Localitate> localiatati = repo_loc.getAll();
	int i = repo_loc.findById(id);
	repo_loc.deleteElem(localiatati[i]);
}

//modifica o localitate existenta
//arunca exceptie daca nu exista nicio localitate cu id-ul dat
void ServiceLocalitati::updateLocalitate(int id, string nume_nou, int populatie_noua, double rata_incidenta_noua, CoordonateGeo coord_noi)
{
	int i = repo_loc.findById(id);
	if (i == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul: " + to_string(id));

	Localitate l_noua(id, nume_nou, populatie_noua, rata_incidenta_noua, coord_noi);
	Localitate l_veche = repo_loc.getAll()[i];
	repo_loc.updateElem(l_veche, l_noua);
}

//cauta o localitate dupa id
//return: pozitia in vector a localitatii sau -1 daca nu se gaseste
int ServiceLocalitati::findById(int id)
{
	return repo_loc.findById(id);
}

//Cauta obiectivele turistice dint-o localitate cu id-ul dat
//return: obiectivele gasite
vector<ObiectivTuristic> ServiceLocalitati::getObiectiveDinLocalitate(int id_loc)
{
	int index = repo_loc.findById(id_loc);
	if (index == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul " + to_string(id_loc) + " \n");
	vector<ObiectivTuristic> obiective_loc;
	vector<ObiectivTuristic> obiective = repo_obv.getAll();
	for (int i = 0; i < obiective.size(); i++)
	{
		if (obiective[i].getIdLocalitate() == id_loc)
		{
			obiective_loc.push_back(obiective[i]);
		}
	}
	return obiective_loc;
}

//cauta rutele care incep dintr-o localitate cu id-ul dat
//return: rutele gasite
vector<Ruta> ServiceLocalitati::getRuteIncepandDinLocalitate(int id_loc)
{
	int index = repo_loc.findById(id_loc);
	if (index == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul " + to_string(id_loc) + " \n");
	vector<Ruta> rute_gasite;
	vector<Ruta> rute = repo_ruta.getAll();
	for (int i = 0; i < rute.size(); i++)
	{
		vector<int> ruta_loc = rute[i].getLocalitati();
		if (ruta_loc[0] == id_loc)
			rute_gasite.push_back(rute[i]);
	}
	return rute_gasite;
}

//calculeaza distanta intre doua localitati date
//return: distanta
double ServiceLocalitati::getDistantaIntreLocalitati(const int& id1, const int& id2)
{
	int index_l1 = repo_loc.findById(id1);
	if (index_l1 == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul " + to_string(id1) + " \n");

	int index_l2 = repo_loc.findById(id2);
	if (index_l2 == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul " + to_string(id2) + " \n");
	
	Localitate l1 = repo_loc.getAll()[index_l1];
	Localitate l2 = repo_loc.getAll()[index_l2];
	CoordonateGeo c1 = l1.getCoord();
	CoordonateGeo c2 = l2.getCoord();
	double distanta = c1.distantaDouaLocatii(c2);

	return distanta;
}

//cauta toate obiectivele turistice care se afla pe o raza de x km dati fata de o localitate data
//return: obiectivele gasite si distanta aproximativa pana la ele
vector<pair<ObiectivTuristic, int>> ServiceLocalitati::getObvLocKm(double km, int id_loc)
{
	int index = repo_loc.findById(id_loc);
	if (index == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul introdus");
	if (km <= 0)
		throw ServiceLocalitateExceptie("Kilometrii trebuie sa fie strict pozitivi");

	vector<pair<ObiectivTuristic, int>> obv_gasite;
	vector<ObiectivTuristic> toate_obv = repo_obv.getAll();
	int size_toate_obv = repo_obv.getSize();
	vector<Localitate> loc_gasite;
	vector<Localitate> toate_loc = repo_loc.getAll();
	int size_toate_loc = repo_loc.getSize();
	vector<int> distante;

	for (int i = 0; i < size_toate_loc; i++)
	{
		int distanta = getDistantaIntreLocalitati(toate_loc[index].getId(), toate_loc[i].getId());
		if (distanta < km)
		{
			loc_gasite.push_back(toate_loc[i]);
			distante.push_back(distanta);
		}		
	}
	if (loc_gasite.size() > 0)
	{
		for (int i = 0; i < loc_gasite.size(); i++)
		{
			for (int j = 0; j < size_toate_obv; j++)
			{
				if (toate_obv[j].getIdLocalitate() == loc_gasite[i].getId())
				{
					pair<ObiectivTuristic, int> p(toate_obv[j], distante[i]);
					obv_gasite.push_back(p);
				}
			}
		}
	}
	return obv_gasite;
}

//cauta cea mai apropiata localitate de o localitate data
//return: localitatea gasita si nr de km aproximativi
pair<Localitate, int> ServiceLocalitati::getCeaMaiApropiataLoc(int id)
{
	int index = repo_loc.findById(id);
	if (index == -1)
		throw ServiceLocalitateExceptie("Nu exista nicio localitate cu id-ul dat\n");

	vector<Localitate> toate_loc = repo_loc.getAll();
	Localitate l = toate_loc[index];
	Localitate gasita;
	int size_toate_loc = repo_loc.getSize();

	if (size_toate_loc == 1)
		throw ServiceLocalitateExceptie("Exista doar o localitate in lista, nu se poate calcula distanta pana la alta localitate\n");

	int distanta_min=getDistantaIntreLocalitati(l.getId(), toate_loc[0].getId());
	if (distanta_min == 0)
	{
		distanta_min= getDistantaIntreLocalitati(l.getId(), toate_loc[1].getId());
		gasita = toate_loc[1];
	}

	for (int i = 0; i < size_toate_loc; i++)
	{
		if (toate_loc[i].getId() != l.getId())
		{
			int distanta = getDistantaIntreLocalitati(l.getId(), toate_loc[i].getId());
			if (distanta < distanta_min)
			{
				distanta_min = distanta;
				gasita = toate_loc[i];
			}
		}
	}
	pair<Localitate, int> p(gasita, distanta_min);
	return p;
}

//filtreaza localitatile care au o rata de incidenta mai mare decat o valoare data
//daca exista obiective turistice sau rute atasate localitatii se vor sterge si acestea
int ServiceLocalitati::filtrareLocalitatiDupaRata(double rata)
{
	int contor = 0;
	if (rata <= 0)
		throw ServiceLocalitateExceptie("Rata de incidenta trebuie sa fie strict pozitiva\n");
	vector<Localitate> localitati = repo_loc.getAll();
	for (auto& loc : localitati) {
		if (loc.getRataIncidenta() > rata)
		{
			this->deleteLocalitate(loc.getId());
			contor++;
		}
			
	}
	return contor;
}

//cauta rutele care au o lungime in km mai mica decat o valoare data
//return: rutele gasite
vector<pair<Ruta, double>> ServiceLocalitati::getRuteCuLungimeMica(int km)
{
	if (km <= 0)
		throw ServiceLocalitateExceptie("Lungimea in km trebuie sa fie strict ppozitiva\n");

	vector<pair<Ruta, double>> rute_gasite;
	vector<Ruta> rute = repo_ruta.getAll();
	double lungime_ruta = 0;
	for (auto& ruta : rute)
	{
		vector<int> locs = ruta.getLocalitati();
		for (int i = 0; i < locs.size() - 1; i++)
		{
			double distanta = this->getDistantaIntreLocalitati(locs[i],locs[i+1]);
			lungime_ruta += distanta;
		}
		if (lungime_ruta < km) {
			pair<Ruta, double> p(ruta, lungime_ruta);
			rute_gasite.push_back(p);
		}
	}
	return rute_gasite;
}



