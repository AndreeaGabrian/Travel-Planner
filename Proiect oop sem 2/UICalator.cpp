#include "UICalator.h"
#include"FunctiiUtile.h"
#include "Exceptii.h"
using std::cout;

void UICalator::meniuCalator()
{
	cout << " ______________________________\n";
	cout << "|                              |\n";
	cout << "|           MENIU              |\n";
	cout << "|______________________________|\n";
	cout << " ------------------------------\n";
	cout << "|1.Afisare Localitati          |\n";
	cout << "|2.Afisare Obiective turistice |\n";
	cout << "|3.Afisare Rute turistice      |\n";
	cout << "|4.Statistici & sortari        |\n";
	cout << "|5.Alcatuire calatorie         |\n";
	cout << "|x.Logout                      |\n";
	cout << " ------------------------------ \n";
	cout << endl;

}


void UICalator::meniuFunctionalitatiCalator()
{
	cout << " ----------------------------------------------------------------------------------------------\n";
	cout << "|1.Afisarea obiectivelor turistice dintr-o localitate data                                     |\n";
	cout << "|2.Afisarea rutelor care incep dintr-o localitate data                                         |\n";
	cout << "|3.Afisarea tuturor rutelor care trec printr-o localitate data                                 |\n";
	cout << "|4.Afisarea distantei dintre doua localitati date                                              |\n";
	cout << "|5.Afisarea obiectivelor turistice aflate pe o raza de x kilometri fata de o localitate data   |\n";
	cout << "|6.Afisarea celei mai apropiate localitati fata de o localitate data                           |\n";
	cout << "|7.Sortare obiective turistice dupa tipul acestora                                             |\n";
	cout << "|8.Sortare obiective turistice care apartin sau nu patrimoniul UNESCO                          |\n";
	cout << "|9.Sortare obiective turistice dupa necesitate vaccin                                          |\n";
	cout << "|10.Sortare rute crescator dupa numarul de localitati                                          |\n";
	cout << "|11.Afisare rute cu lungimea in km mai mica decat o valoare data                               |\n";
	cout << "|b.Inapoi                                                                                      |\n";
	cout << " ----------------------------------------------------------------------------------------------\n";
}

UICalator::UICalator(ServicePunctDeVizitare& srv, ServiceLocalitati& srv_loc, ServiceRuta& srv_ruta, ServiceObiectivTuristic& srv_obv, Calatorie& calatorie): UI(srv, srv_loc, srv_ruta, srv_obv, calatorie)
{
}

void UICalator::runAllMeniuCalator()
{
	bool ok = true; bool ok2;
	string optiune;
	while (ok) 
	{
		this->meniuCalator();
		ok2 = true;
		cout << "Optiunea: "; cin >> optiune;
		switch (esteOptiune(optiune))
		{
		case opt1:
			this->uiAfiseazaLocalitati();
			break;
		case opt2:
			this->uiAfiseazaObiective();
			break;
		case opt3:
			this->uiAfiseazaRute();
			break;
		case opt4:
			this->meniuFunctionalitatiCalator();
			
			while (ok2) 
			{
				cout << "Optiunea: "; cin >> optiune;
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
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
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
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
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
						changeColor(12);
						cout << e.getMesaj() << endl;
						changeColor(14);
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
				case opt8: {
					string patr;
					cout << "Aparteneta la patrimoniul UNESCO(da, nu): \n"; cin >> patr;
					uiSorteazaDupaPatrimoniu(patr);
					cout << endl;
					break; }
				case opt9: {
					string vaccin;
					cout << "Necesitate vaccin(da, nu)\n"; cin >> vaccin;
					uiSorteazaDupaNecesitateVaccin(vaccin);
					cout << endl;
					break; }
				case opt10:
				{
					uiSortareRuteCrescatorDupaLocalitati();
					cout << endl;
					break;
				}
				case opt11:
				{
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
				}
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
		{
			this->meniuCalatorie();
			cout << endl;
			while (ok2) {
				cout << "Dati optiunea: "; cin >> optiune;
				switch (esteOptiune(optiune))
				{
				case opt1:
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
		}
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
