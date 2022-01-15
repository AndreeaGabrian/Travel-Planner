#include "UI.h"
#include<iostream>
#include"Exceptii.h"
#include"Validator.h"
#include"FunctiiUtile.h"
//using namespace std;
using std::cout;
using std::cin;
using std::pair;
using std::vector;
using std::string;


void UI::meniuPunctVizitare()
{
	cout << " ---------------------------------------------\n";
	cout << "|1. Adauga punct de vizitare                  |\n";
	cout << "|2. Sterge punct de vizitare                  |\n";
	cout << "|3. Modifica punct de vizitare                |\n";
	cout << "|4. Afiseaza toate punctele de vizitare       |\n";
	cout << "|b. Inapoi                                    |\n";
	cout << " ---------------------------------------------\n";
}

void UI::meniuLocalitate()
{
	cout << " ---------------------------------------------\n";
	cout << "|1. Adauga localitate                         |\n";
	cout << "|2. Sterge localitate                         |\n";
	cout << "|3. Modifica localitate                       |\n";
	cout << "|4. Afiseaza toate localitatile               |\n";
	cout << "|b. Inapoi                                    |\n";
	cout << " ---------------------------------------------\n";
}

void UI::meniuObiectivTuristic()
{
	cout << " ---------------------------------------------\n";
	cout << "|1. Adauga obiectiv turistic                  |\n";
	cout << "|2. Sterge obiectiv turistic                  |\n";
	cout << "|3. Modifica obiectiv turistic                |\n";
	cout << "|4. Afiseaza toate obiectivele turistice      |\n";
	cout << "|b. Inapoi                                    |\n";
	cout << " ---------------------------------------------\n";
}

void UI::meniuRuta()
{
	cout << " ---------------------------------------------\n";
	cout << "|1. Adauga ruta                               |\n";
	cout << "|2. Sterge ruta                               |\n";
	cout << "|3. Modifica ruta                             |\n";
	cout << "|4. Afiseaza toate rutele                     |\n";
	cout << "|b. Inapoi                                    |\n";
	cout << " ---------------------------------------------\n";
}

void UI::meniuFunctionalitati()
{
	cout << " ---------------------------------------------------------------------------------------------------\n";
	cout << "|1.Afisarea obiectivelor turistice dintr-o localitate data                                          |\n";
	cout << "|2.Afisarea rutelor care incep dintr-o localitate data                                              |\n";
	cout << "|3.Afisarea tuturor rutelor care trec printr-o localitate data                                      |\n";
	cout << "|4.Afisarea distantei dintre doua localitati date                                                   |\n";
	cout << "|5.Afisarea obiectivelor turistice aflate pe o raza de x kilometri fata de o localitate data        |\n";
	cout << "|6.Afisarea celei mai apropiate localitati fata de o localitate data                                |\n";
	cout << "|                                                                                                   |\n";
	cout << "|7. Sortare obiective turistice dupa tipul acestora                                                 |\n";
	cout << "|8. Sortare obiective turistice care apartin sau nu patrimoniul UNESCO                              |\n";
	cout << "|9. Sortare obiective turistice dupa necesitate vaccin                                              |\n";
	cout << "|10. Filtare rute cu mai multe localitati decat o valoare data                                      |\n";
	cout << "|11.Filtrare localitati cu rata de incidenta mai mare decat o valoare data                          |\n";
	cout << "|12. Afisare rute cu lungimea in km mai mica decat o valoare data                                   |\n";
	cout << "|13.Sortare rute crescator dupa numarul de localitati                                               |\n";
	cout << "|                                                                                                   |\n";
	cout << "|b.Inapoi                                                                                           |\n";
	cout << " ---------------------------------------------------------------------------------------------------\n";
}

void UI::meniuCalatorie()
{
	cout << " ---------------------------------------------\n";
	cout << "|1.Afiseaza destinatii favorite               |\n";
	cout << "|2.Adauga destinatie favorita                 |\n";
	cout << "|3.Sterge destinatie favorita                 |\n";
	cout << "|4.Salveaza calatorie                         |\n";
	cout << "|5.Afiseaza calatoria salvata                 |\n";
	cout << "|6.Sugestie de calatorie                      |\n";
	cout << "|b.Inapoi                                     |\n";
	cout << " ---------------------------------------------\n";
}

void UI::showMenu()
{
	cout << " ---------------------------------------------\n";
	cout << "|1.CRUD punct de vizitare                     |\n";
	cout << "|2.CRUD localitate                            |\n";
	cout << "|3.CRUD obiectiv turistic                     |\n";
	cout << "|4.CRUD ruta                                  |\n";
	cout << "|5.Functionalitati                            |\n";
	cout << "|6.Creeaza calatorie                          |\n";
	cout << "|x.Logout                                     |\n";
	cout << " ---------------------------------------------\n";
}

void UI::uiAddPunctDeVizitare()
{
	PunctDeVizitare p;
	cin >> p;
	try {
		ValidatorPunctDeVizitare vp;
		vp.valideaza(p);
		this->srv_pct.addPunctDeVizitare(p.getId(), p.getNume());
		changeColor(10);
		cout << "Punctul a fost adaugat cu succes!\n";
		
	}
	catch (ServiceExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	catch(ExceptiePunctDeVizitare& exp){
		changeColor(12);
		cout << exp << endl;
	}
	changeColor(14);

}

void UI::uiDeletePunctDeVizitare()
{
	try {

		int id;
		cout << "Dati id-ul punctului de sterg: "; 
		if (cin >> id)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
		}
		try {
			this->srv_pct.deletePunctDeVizitare(id);
			changeColor(10);
			cout << "Punctul a fost sters cu succes!\n";
		}
		catch (ServiceExceptie& ex) {
			changeColor(12);
			cout << ex.getMesaj() << endl;
		}
	}
	catch (ExceptieTipIncorectData& e) {
		changeColor(12);
		cout << e.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiUpdatePunctDeVizitare()
{
	PunctDeVizitare p;
	
	try {
		cin >> p;
		ValidatorPunctDeVizitare vp;
		vp.valideaza(p);
		this->srv_pct.updatePunctDeVizitare(p.getId(), p.getNume());
		changeColor(10);
		cout << "Punctul a fost modificat cu succes\n";
	}
	catch (ExceptieTipIncorectData& e)
	{
		changeColor(12);
		cout << e.getMesaj();
	}
	catch (ServiceExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	catch (ExceptiePunctDeVizitare& exp) {
		changeColor(12);
		cout << exp << endl;
	}
	changeColor(14);
}

void UI::uiAfiseazaPuncteDeVizitare()
{
	int size = srv_pct.getAll().size();
	if (size > 0)
	{
		changeColor(9);
		for (int i = 0; i < size; i++)
			cout << srv_pct.getAll()[i] << endl;
	}
	else
	{
		changeColor(12);
		cout << "Nu exista niciun punct adaugat\n";
	}
		
	cout << endl;
	changeColor(14);
	
}

void UI::uiAddLocalitate()
{
	Localitate l;
	
	try {
		cin >> l;
		ValidatorLocalitate v;
		v.valideaza(l);
		this->srv_loc.addLocalitate(l.getId(), l.getNume(), l.getPopulatie(), l.getRataIncidenta(), l.getCoord());
		changeColor(10);
		cout << "Localitatea a fost adaugata cu succes!\n";
	}
	catch (ExceptieLocalitate& exl)
	{
		changeColor(12);
		cout << exl;
	}
	catch (ServiceExceptie& exs)
	{
		changeColor(12);
		cout << exs.getMesaj()<<endl;
	}
	catch (ExceptieDomain& exd)
	{
		changeColor(12);
		cout << exd << endl;
	}
	changeColor(14);
}

void UI::uiDeleteLocalitate()
{
	try {


		int id;
		cout << "Dati id-ul localitatii de sters: "; 
		if (cin >> id)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
		}

		int nr_obv = srv_obv.countObiectiveByIdLocalitate(id);
		int nr_rute = srv_ruta.countRuteByIdLocalitate(id);
		string opt;
		if (nr_obv > 0 || nr_rute > 0)
		{
			cout << "Exista " << nr_obv << " obiective turistice si " << nr_rute << " rute atasate localitatii\n";
			cout << "La stergerea localitatii se vor sterge si acestea. Continuati(da, nu)?"; cin >> opt;
			if (opt.compare("da") == 0)
			{
				try {
					this->srv_loc.deleteLocalitate(id);
					changeColor(10);
					cout << "Localitatea a fost stearsa cu succes\n";
				}
				catch (ServiceExceptie& exs) {
					changeColor(12);
					cout << exs.getMesaj() << endl;
				}
				catch (ServiceRutaExceptie& e) {
					changeColor(12);
					cout << e.getMesaj() << endl;
				}

			}
			else
			{
				changeColor(12);
				cout << "Localitatea nu a fost stearsa\n";
			}
				
		}
		else
		{
			try {
				this->srv_loc.deleteLocalitate(id);
				changeColor(10);
				cout << "Localitatea a fost stearsa cu succes!\n";
			}
			catch (ServiceExceptie& exs) {
				changeColor(12);
				cout << exs.getMesaj() << endl;
			}
		}
	}
	catch (ServiceExceptie& exs) {
		changeColor(12);
		cout << exs.getMesaj() << endl;
	}
	catch (ServiceRutaExceptie& e) {
		changeColor(12);
		cout << e.getMesaj() << endl;
	}
	catch (ServiceObiectivExceptie& eo) {
		changeColor(12);
		cout << eo.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiModificaLocalitate()
{
	Localitate l;
	
	try {
		cin >> l;
		ValidatorLocalitate v;
		v.valideaza(l);
		this->srv_loc.updateLocalitate(l.getId(), l.getNume(), l.getPopulatie(), l.getRataIncidenta(), l.getCoord());
		changeColor(10);
		cout << "Localitatea a fost modificata cu succes!\n";

	}
	catch (ExceptieLocalitate& exl) {
		changeColor(12);
		cout << exl;
	}
	catch (ExceptieCoordonateGeo& exg) {
		changeColor(12);
		cout << exg;
	}
	catch (ServiceExceptie& exs) {
		changeColor(12);
		cout << exs.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiAfiseazaLocalitati()
{
	int size = srv_loc.getAll().size();
	if (size > 0)
	{
		changeColor(9);
		for (int i = 0; i < size; i++)
			cout << srv_loc.getAll()[i] << endl;
		
	}
	else
	{
		changeColor(12);
		cout << "Nu exista nicio localitatate adaugata\n";
	}
		
	cout << endl;
	changeColor(14);
	
}

void UI::uiAddRuta()
{
	
	
	try {
		Ruta r;
		cin >> r;
		this->srv_ruta.addRuta(r.getId(), r.getNume(), r.getLocalitati());
		changeColor(10);
		cout << "Ruta a fost adaugata cu succes\n";
	}
	catch (ServiceExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiDeleteRuta()
{
	
	try {
		int id;
		cout << "Dati id-ul rutei de sters: "; 
		if (cin >> id)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
		}
		this->srv_ruta.deleteRuta(id);
		changeColor(10);
		cout << "Ruta a fost stearsa cu succes\n";
	}
	catch (ServiceExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiModificaRuta()
{
	Ruta r;
	
	try {
		cin >> r;
		this->srv_ruta.updateRuta(r.getId(), r.getNume(), r.getLocalitati());
		changeColor(10);
		cout << "Ruta a fost modificata cu succes!\n";
	}
	catch (ServiceExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiAfiseazaRute()
{
	int size = srv_ruta.getAll().size();
	if (size > 0)
	{
		changeColor(9);
		for (int i = 0; i < size; i++)
		{
			cout << srv_ruta.getAll()[i] << endl;
		}
	}
	else
	{
		changeColor(12);
		cout << "Nu exista nicio ruta adaugata\n";
	}
	changeColor(14);
	cout << endl;
	
}

void UI::uiAddObiectiv()
{
	ObiectivTuristic o;
	
	try {
		cin >> o;
		ValidatorObiectivTuristic v;
		v.valideaza(o);
		this->srv_obv.addObiectiv(o.getId(), o.getNume(), o.getIdLocalitate(), o.getTip(), o.getPretBilet(), o.getPatrimoniu(), o.getNecesitateVaccin());
		changeColor(10);
		cout << "Obiectivul a fost adaugat cu succes\n";

	}
	catch (ExceptieObiectivTuristic& exo) {
		changeColor(12);
		cout << exo;
	}
	catch (ServiceExceptie& exs) {
		changeColor(12);
		cout << exs.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiDeleteObiectiv()
{
	int id;
	cout << "Dati id-ul obiectivului de sters: "; 
	try 
	{
		if (cin >> id)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
		}
		srv_obv.deleteOviectiv(id);
		changeColor(10);
		cout << "Obiectivul a fost sters cu succes!\n";
	}
	catch (ServiceExceptie& exs) {
		changeColor(12);
		cout << exs.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiModificaObiectiv()
{
	ObiectivTuristic o;
	
	try {
		cin >> o;
		ValidatorObiectivTuristic v;
		v.valideaza(o);
		srv_obv.updateObiectiv(o.getId(), o.getNume(), o.getIdLocalitate(), o.getTip(), o.getPretBilet(), o.getPatrimoniu(), o.getNecesitateVaccin());
		changeColor(10);
		cout << "Obiectivul a fost modificat cu succes!\n";
	}
	catch (ExceptieObiectivTuristic& exo) {
		changeColor(12);
		cout << exo;
	}
	catch (ServiceExceptie& exs) {
		changeColor(12);
		cout << exs.getMesaj() << endl;
	}
	catch (ExceptieTipIncorectData& ed) {
		changeColor(12);
		cout << ed.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiAfiseazaObiective()
{
	int size = srv_obv.getAll().size();
	if (size > 0)
	{
		changeColor(9);
		for (int i = 0; i < size; i++)
			cout << srv_obv.getAll()[i] << endl;
	}
	else
	{
		changeColor(12);
		cout << "Nu exista niciun obiectiv adaugat\n";
	}
	cout << endl;
	changeColor(14);
	
}

//functionalitati service localitate

void UI::uiGetObiectiveDinLocalitate(int& id_loc)
{
	try {
		vector<ObiectivTuristic> obiective = srv_loc.getObiectiveDinLocalitate(id_loc);
		int size = obiective.size();
		if (size > 0)
		{
			cout << "Obiectivele turistice din localitatea data sunt:\n";
			changeColor(9);
			for (int i = 0; i < size; i++)
			{
				cout << obiective[i] << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Nu exista niciun obiectiv turistic in localitatea data\n";
		}
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiGetRuteIncepandDinLocalitate(int& id_loc)
{
	try {
		vector<Ruta> rute = srv_loc.getRuteIncepandDinLocalitate(id_loc);
		int size = rute.size();
		if (size > 0)
		{
			cout << "Rutele turistice din care incep din localitatea data sunt:\n";
			changeColor(9);
			for (int i = 0; i < size; i++)
			{
				cout << rute[i] << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Nu exista nicio ruta care sa inceapa din localitatea data\n";
		}
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiGetDistantaIntreLocalitati(int& id1, int& id2)
{
	try {
		double distanta = srv_loc.getDistantaIntreLocalitati(id1, id2);
		cout << "Distanata dintre localitati este: ";
		changeColor(9);
		cout<< distanta << endl;
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiGetObvLocKm(double& km, int& id)
{
	try {
		vector<pair<ObiectivTuristic, int>> gasite = srv_loc.getObvLocKm(km, id);
		int size = gasite.size();
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				changeColor(9);
				pair<ObiectivTuristic, int> p = gasite[i];
				cout << "obiectiv: " << p.first << "  km aproximativi: " << p.second << endl;
			}
		}
		else{
			changeColor(12);
		cout << "Nu s-a gasit niciun obiectiv\n";
		}
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiGetCeaMaiApropiataLoc(int& id)
{
	try {
		pair<Localitate, int> p = srv_loc.getCeaMaiApropiataLoc(id);
		cout << "Cea mai apropiata localitate este:\n";
		changeColor(9);
		cout << p.first << endl;
		changeColor(14);
		cout << "Se afla aproxiamtiv la ";
		changeColor(9);
		cout << p.second;
		changeColor(14);
		cout<< " km\n";
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiFiltrareLocalitatiDupaRata(double rata)
{
	try {
		string opt;
		cout << "\n Daca exista rute sau obiective atasate localitatilor se vor sterge si acestea. Continuati?(da, nu)\n";
		cin >> opt;
		if (opt == "da") {
			int contor = srv_loc.filtrareLocalitatiDupaRata(rata);
			if (contor > 0)
			{
				changeColor(10);
				cout << "S-au sters " << contor << " localitati\n";
			}
				
			else
			{
				changeColor(12);
				cout << "Nu s-a gasit nicio localitate cu rata de incidenta mai mare de " << rata << endl;
			}
				
		}
		else
		{
			changeColor(12);
			cout << "Nu a fost stearsa nicio localitate\n";
		}
			
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiGetRuteCuLungimeMica(int km)
{
	try {
		double lungime_ruta = 0;
		vector<pair<Ruta, double>> rute = srv_loc.getRuteCuLungimeMica(km);
		if (rute.size() > 0)
		{
			cout << "Rutele gasite sunt:\n";
			changeColor(9);
			for (auto& ruta : rute) {
				cout << ruta.first <<", nr km aproximativi: "<<ruta.second<< endl;
			}
		}
		else
		{
			changeColor(12);
			cout << "Nu s-a gasit nicio ruta cu lungimea mai mica de " << km << " km\n";
		}
			
	}
	catch (ServiceLocalitateExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiGetRutePrinLocalitate(int id_loc)
{
	try {
		vector<Ruta> rute_gasite = srv_ruta.getRutePrinLocalitate(id_loc);
		int size = rute_gasite.size();
		if (size > 0)
		{
			cout << "Rutele care trec prin localitate sunt: \n";
			changeColor(9);
			for (auto& ruta : rute_gasite) {
				cout << ruta << endl;
			}
		}
		else{
			changeColor(12);
		cout << "Nu s-a gasit nicio ruta care sa treaca prin localitate\n";
		}
	}
	catch (ServiceRutaExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiSortareRuteCrescatorDupaLocalitati()
{
	
	vector<Ruta> rute_sortate = srv_ruta.sortareRuteCrescatorDupaLocalitati();
	int size = rute_sortate.size();
	if (size > 0)
	{
		cout << "Rutele sortare sunt: \n";
		changeColor(9);
		for (int i = 0; i < size; i++)
		{
			cout << rute_sortate[i] << endl;
		}
	}
	else {
		changeColor(12);
		cout << "Nu exista rute pentru a fi sortate\n";
	}
	
	cout << endl;
	changeColor(14);
}

void UI::uiFiltrareRuteDupaNrLocalitati(int nr)
{
	int nr_rute = srv_ruta.filtrareRuteDupaNrLocalitati(nr);
	if (nr_rute > 0) {
		changeColor(10);
		cout << "Au fost sterse " << nr_rute << " rute\n";
	}
	else {
		changeColor(12);
		cout << "Nicio ruta nu are mai mult de " << nr << "localitati, nu s-a sters nimic\n";
	}
	changeColor(14);
}

void UI::uiSorteazaDupaTip(string tip)
{
	try {
		vector<ObiectivTuristic> sortat = srv_obv.sorteazaDupaTip(tip);
		int size = sortat.size();
		if (size > 0)
		{
			cout << "Obiectivele sortate sunt: \n";
			changeColor(9);
			for (int i = 0; i < size; i++)
			{
				cout << sortat[i] << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Nu exista obiective de acest tip pentru a fi sortate\n";
		}
		
	}
	catch (ServiceObiectivExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiSorteazaDupaPatrimoniu(string patrimoniu)
{
	try {
		vector<ObiectivTuristic> sortat = srv_obv.sorteazaDupaPatrimoniu(patrimoniu);
		int size = sortat.size();
		if (size > 0)
		{
			cout << "Obiectivele sortate sunt: \n";
			changeColor(9);
			for (int i = 0; i < size; i++)
			{
				cout << sortat[i] << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Nu exista obiective pentru a fi sortate\n";
		}
		
	}
	catch (ServiceObiectivExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);
}

void UI::uiSorteazaDupaNecesitateVaccin(string vaccin)
{
	try {
		vector<ObiectivTuristic> sortat = srv_obv.sorteazaDupaNecesitateVaccin(vaccin);
		int size = sortat.size();
		if (size > 0)
		{
			cout << "Obiectivele sortate sunt: \n";
			changeColor(9);
			for (int i = 0; i < size; i++)
			{
				cout << sortat[i] << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Nu exista obiective pentru a fi sortate\n";
		}
		
	}
	catch (ServiceObiectivExceptie& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	catch(...){}
	changeColor(14);
}

void UI::uiAddElemInCalatorie()
{
	try 
	{
		int id; string tip_elem;
		cout << "Dati tipul punctului de vizitare(localitate, obiectiv, ruta): ";
		cin >> tip_elem;
		cout << "Dati id-ul: ";
		if (cin >> id)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Id-ul destinatiei trebuie sa fie intreg ");
		}

		if (tip_elem == "localitate")
		{
			int idl = srv_loc.findById(id);
			if (idl != -1)
			{
				Localitate l = srv_loc.getAll()[idl];
				Localitate* lp = new Localitate(l.getId(), l.getNume(), l.getPopulatie(), l.getRataIncidenta(), l.getCoord());
				calatorie.addElem(lp);
				if (calatorie.find(lp) != -1) {
					changeColor(10);
					cout << "Destinatia a fost adaugata la favorite!\n";
				}
				else {
					changeColor(12);
					cout << "Destinatia se afla deja in favorite\n";
				}
			}
			else {
				changeColor(12);
				cout << "Nu exista nicio localitate cu id-ul " + to_string(id);
			}
		}
		else if (tip_elem == "obiectiv")
		{
			int ido = srv_obv.findById(id);
			if (ido != -1)
			{
				ObiectivTuristic o = srv_obv.getAll()[ido];
				ObiectivTuristic* op = new ObiectivTuristic(o.getId(), o.getNume(), o.getIdLocalitate(), o.getTip(), o.getPretBilet(), o.getPatrimoniu(), o.getNecesitateVaccin());
				calatorie.addElem(op);
				if (calatorie.find(op) != -1) {
					changeColor(10);
					cout << "Destinatia a fost adaugata la favorite!\n";
				}
				else {
					changeColor(12);
					cout << "Destinatia se afla deja in favorite\n";
				}
			}
			else {
				changeColor(12);
				cout << "Nu exista niciun obiectiv turistic cu id-ul " + to_string(id);
			}
		}
		else if (tip_elem == "ruta")
		{
			int idr = srv_ruta.findById(id);
			if (idr != -1)
			{
				Ruta r = srv_ruta.getAll()[idr];
				Ruta* rp = new Ruta(r.getId(), r.getNume(), r.getLocalitati());
				calatorie.addElem(rp);
				if (calatorie.find(rp) != -1) {
					changeColor(10);
					cout << "Destinatia a fost adaugata la favorite!\n";
				}
				else {
					changeColor(12);
					cout << "Destinatia se afla deja in favorite\n";
				}
			}
			else {
				changeColor(12);
				cout << "Nu exista nicio ruta turistica cu id-ul " + to_string(id) << endl;
			}
		}
		else {
			changeColor(12);
			cout << "Tipul punctului de vizitare invalid, nu este unul dintre: localitate, ruta, obiectiv\n";
		}
	}
	catch (ExceptieTipIncorectData& ex) {
		changeColor(12);
		cout << ex.getMesaj()<<endl;
	}
	changeColor(14);

}

void UI::uiDeleteElemDinCalatorie()
{
	try 
	{
		int poz;
		cout << "Al catelea element din calatorie doriti sa fie sters?(numaratoarea incepe de la 0)\n";
		if (cin >> poz)
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Pozitia elementului trebuie sa fie intreaga");
		}
		int size = calatorie.getAll().size();
		if (size > 0)
		{
			if (poz < size && poz >= 0)
			{
				calatorie.deleteElem(poz);
				changeColor(10);
				cout << "Sters din favorite!\n";
			}
			else {
				changeColor(12);
				cout << "Pozitia introdusa este invalida\n";
			}
		}
		else {
			changeColor(12);
			cout << "Nu aveti nicio destinatie favorita pentru a fi stearsa\n";
		}
		
	}
	catch (ExceptieTipIncorectData& e) {
		changeColor(12);
		cout << e.getMesaj() << endl;
	}
	changeColor(14);
}

void UI::uiAfiseazaCalatorie()
{
	int size = calatorie.getAll().size();
	if (size > 0)
	{
		vector<PunctDeVizitare*> elem = calatorie.getAll();
		changeColor(9);
		for (int i = 0; i < size; i++)
			cout << elem[i]->toString() << endl;
		cout << endl;
	}
	else {
		changeColor(12);
		cout << "Momentan nu aveti nicio destinatie favorita\n";
	}
	changeColor(14);
}

void UI::uiSalveazaCalatorieInFisier()
{
	try {
		calatorie.salvareCalatorieInFisier();
		changeColor(10);
		cout << "Calatoria a fost salvata\n";
		changeColor(14);
	}
	catch (CalatorieExceptie& e) {
		cout << e.getMesaj() << endl;
	}
}

void UI::uiAfiseazaCalatorieDinFisier()
{
	try {
		vector<PunctDeVizitare*> elem_calatorie_salvata = calatorie.citireCalatorieDinFisier();
		int size = elem_calatorie_salvata.size();
		if (size > 0)
		{
			changeColor(9);
			for (int i = 0; i < size; i++)
				cout << elem_calatorie_salvata[i]->toString() << endl;
			cout << endl;
		}
		else {
			changeColor(12);
			cout << "Calatoria salvata este momentan goala\n";
		}
		changeColor(14);
	}
	catch (CalatorieExceptie& e) {
		cout << e.getMesaj()<<endl;
	}
}

void UI::uiSugerareCalatorie()
{
	vector<PunctDeVizitare*> pct = calatorie.sugerareCalatorie();
	cout << endl;
	if (pct.size() > 0)
	{
		changeColor(9);
		for (int i = 0; i < pct.size(); i++)
			cout << pct[i]->toString() << endl;
	}
	else {
		changeColor(12);
		cout << "Se poate sa aveti prea putine destinatii favorite sau niciuna\n";
	}
	changeColor(14);
}

//functionalitati service obiectiv turistic


UI::UI(ServicePunctDeVizitare& srv, ServiceLocalitati& srv_loc, ServiceRuta& srv_ruta, ServiceObiectivTuristic& srv_obv, Calatorie& calatorie) : srv_pct{ srv }, srv_loc{ srv_loc }, srv_ruta{ srv_ruta }, srv_obv{ srv_obv }, calatorie{calatorie}
{
	srv_ruta.verificareDateRutaLaPrimaCitire();
	srv_obv.verificareDateObiectivLaPrimaCitire();
}



void UI::runMenu()
{
	bool ok = true; bool ok2;
	string optiune, optiune2;
	while (ok) 
	{
		this->showMenu();
		ok2 = true;
		cout << "Dati optiunea: "; cin >> optiune;
		switch (esteOptiune(optiune))
		{
		case opt1:
			cout << endl;
			this->meniuPunctVizitare();
			while (ok2) {
				
				cout << "\nDati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
					uiAddPunctDeVizitare();
					cout << endl;
					break;
				case opt2:
					uiDeletePunctDeVizitare();
					cout << endl;
					break;
				case opt3:
					uiUpdatePunctDeVizitare();
					cout << endl;
					break;
				case opt4:
					uiAfiseazaPuncteDeVizitare();
					cout << endl;
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case opt2:
			this->meniuLocalitate();
			cout << endl;
			while (ok2) {
				
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
					uiAddLocalitate();
					cout << endl;
					break;
				case opt2:
					uiDeleteLocalitate();
					cout << endl;
					break;
				case opt3:
					uiModificaLocalitate();
					cout << endl;
					break;
				case opt4:
					uiAfiseazaLocalitati();
					cout << endl;
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case opt3:
			this->meniuObiectivTuristic();
			cout << endl;
			while (ok2) {
				
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
					uiAddObiectiv();
					cout << endl;
					break;
				case opt2:
					uiDeleteObiectiv();
					cout << endl;
					break;
				case opt3:
					uiModificaObiectiv();
					cout << endl;
					break;
				case opt4:
					uiAfiseazaObiective();
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case opt4:
			this->meniuRuta();
			cout << endl;
			while (ok2) {
				
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
					uiAddRuta();
					cout << endl;
					break;
				case opt2:
					uiDeleteRuta();
					cout << endl;
					break;
				case opt3:
					uiModificaRuta();
					cout << endl;
					break;
				case opt4:
					uiAfiseazaRute();
					cout << endl;
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case opt5:
			this->meniuFunctionalitati();
			cout << endl;
			while (ok2) {
				
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
				{
					int id;
					cout << "Dati id-ul localitatii: "; 
					try 
					{
						if (cin >> id)
						{
							uiGetObiectiveDinLocalitate(id);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
							
						}
						
					}
					catch (ExceptieTipIncorectData& e) {
						cout << e.getMesaj()<<endl;
					}
					
					break;
				}
				case opt2:
				{
					try {
						int id;
						cout << "Dati id-ul localitatii: "; 
						if (cin >> id)
						{
							uiGetRuteIncepandDinLocalitate(id);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
							
						}
						
					}
					catch (ExceptieTipIncorectData& e) {
						cout << e.getMesaj() << endl;
					}
					
					break;
				}
				case opt3:
				{
					try {
						int id;
						cout << "Dati id-ul localitatii: ";
						if (cin >> id)
						{
							uiGetRutePrinLocalitate(id);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
							
						}
						
					}
					catch (ExceptieTipIncorectData& e) {
						cout << e.getMesaj() << endl;
					}
					break;
				}
				case opt4:
				{
					try 
					{
						int id1, id2;
						cout << "Dati id-ul primei localitati: "; 
						if (cin >> id1) {
							cout << "Dati id-ul localitatii a doua: ";
							if (cin >> id2)
							{
								uiGetDistantaIntreLocalitati(id1, id2);
								cout << endl;
							}
							else
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');

								throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
							}
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
						}
					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					
					break;
					
				}
				case opt5:
				{
					try 
					{
						int id; double km;
						cout << "Dati id-ul localitatii: "; 
						if (cin >> id)
						{
							cout << "Dati nr de kilometri: ";
							if (cin >> km)
							{
								uiGetObvLocKm(km, id);
								cout << endl;
							}
							else {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');

								throw ExceptieTipIncorectData("Kilometri trebuie sa fie numar");
							}
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
						}
					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					break;
				}
				case opt6:
				{
					try {
						int id;
						cout << "Dati id-ul localitatii: ";
						if (cin >> id)
						{
							uiGetCeaMaiApropiataLoc(id);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Id-ul trebuie sa fie numar intreg");
							
						}

					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					break;
				}
				case opt7:
				{
					string tip;
					cout << "Introduceti tipul(natural, istoric, cultural, altele)\n"; cin >> tip;
					uiSorteazaDupaTip(tip);
					cout << endl;
					break;
				}
				case opt8:
				{
					string patr;
					cout << "Aparteneta la patrimoniul UNESCO(da, nu): \n"; cin >> patr;
					uiSorteazaDupaPatrimoniu(patr);
					cout << endl;
					break;
				}
				case opt9:
				{
					string vaccin;
					cout << "Necesitate vaccin(da, nu)\n"; cin >> vaccin;
					uiSorteazaDupaNecesitateVaccin(vaccin);
					cout << endl;
					break;
				}
				case opt10:
				{
					try {
						int nr;
						cout << "Dati numarul de kilometri: ";
						if (cin >> nr)
						{
							uiFiltrareRuteDupaNrLocalitati(nr);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Kilometri trebuie sa fie numar intreg");
							
						}

					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					break;
				}
				case opt11:
				{
					try {
						double rata;
						cout << "Dati rata de incidenta: ";
						if (cin >> rata)
						{
							uiFiltrareLocalitatiDupaRata(rata);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Rata trebuie sa fie numar");
							
						}

					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					break;
				}
				case opt12:
					try {
						int km;
						cout << "Dati numarul de kilometri: ";
						if (cin >> km)
						{
							uiGetRuteCuLungimeMica(km);
							cout << endl;
						}
						else
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw ExceptieTipIncorectData("Kilometri trebuie sa fie numar intreg");
							
						}

					}
					catch (ExceptieTipIncorectData& e) {
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
					}
					break;
				case opt13:
					uiSortareRuteCrescatorDupaLocalitati();
					cout << endl;
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case opt6:
			this->meniuCalatorie();
			cout << endl;
			while (ok2) {
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1 :
					uiAfiseazaCalatorie();
					cout << endl;
					break;
				case opt2:
					uiAddElemInCalatorie();
					cout << endl;
					break;
				case opt3:
					uiDeleteElemDinCalatorie();
					cout << endl;
					break;
				case opt4:
					uiSalveazaCalatorieInFisier();
					break;
				case opt5:
					uiAfiseazaCalatorieDinFisier();
					break;
				case opt6:
					uiSugerareCalatorie();
					break;
				case optb:
					ok2 = false;
					cout << endl;
					break;
				default:
					invalidOption();
					cout << endl;
					break;
				}
			}
			break;
		case optx:
			ok = false;
			break;
		default:
			invalidOption();
			cout << endl;
			break;
		}
	}
}
