#include "ServiceRuta.h"
#include"Exceptii.h"
#include<algorithm>

//return: toate rutele
vector<Ruta> ServiceRuta::getAll()
{
    return repo_ruta.getAll();
}


//adauga o ruta noua
//arunca exceptie daca exista deja o ruta cu id-ul dat sau daca nu exista localitati cu id-urile date
void ServiceRuta::addRuta(int id, string nume, vector<int> locs)
{
    if (repo_ruta.findById(id) != -1)
        throw ServiceRutaExceptie("Exista deja o ruta cu id-ul: " + to_string(id));
    for (int i = 0; i < locs.size(); i++)
    {
        if (repo_loc.findById(locs[i]) == -1)
            throw ServiceRutaExceptie("Nu exista nicio localitate cu id-ul: " + to_string(locs[i]) + " pentru a adauga ruta");
    }
    Ruta r(id, nume, locs);
    repo_ruta.addElem(r);
}

//sterge o ruta existenta
//arunca exceptie daca nu exista nicio ruta cu id-ul dat
void ServiceRuta::deleteRuta(int id)
{
    if (repo_ruta.findById(id) == -1)
        throw ServiceRutaExceptie("Nu exista nicio ruta cu id-ul: " + to_string(id) + " pentru a fi stearsa");

    vector<Ruta> rute = repo_ruta.getAll();
    int i = repo_ruta.findById(id);
    repo_ruta.deleteElem(rute[i]);
}

//modifica o ruta existenta
//arunca exceptie daca nu exista id-ul dat sau id-urile localitatilor date
void ServiceRuta::updateRuta(int id, string nume_nou, vector<int> new_locs)
{
    int i = repo_ruta.findById(id);
    if (i == -1)
        throw ServiceRutaExceptie("Nu exista nicio ruta cu id-ul: " + to_string(id) + " pentru a fi stearsa");
    for (int i = 0; i < new_locs.size(); i++)
    {
        if (repo_loc.findById(new_locs[i]) == -1)
            throw ServiceRutaExceptie("Nu exista nicio localitate cu id-ul: " + to_string(i) + " pentru a modifica ruta");
    }

    Ruta ruta_noua(id, nume_nou, new_locs);
    repo_ruta.updateElem(repo_ruta.getAll()[i], ruta_noua);
       
}

//cauta ruta cu id-ul dat
//return: pozitia rutei in vector sau -1 daca nu se gaseste
int ServiceRuta::findById(int id)
{
    return repo_ruta.findById(id);
}

//calculeaza numarul de rute care trec printr-o localitate
//return:nr rute care trec prin localitate
int ServiceRuta::countRuteByIdLocalitate(int id_loc)
{
    if (repo_loc.findById(id_loc) == -1)
        throw ServiceRutaExceptie("Nu exista nicio localitate cu id-ul dat pt a calcula rutele\n");
    int contor = 0;
    vector<Ruta> rute = repo_ruta.getAll();
    for (int i = 0; i < rute.size(); i++)
    {
        vector<int> ruta_loc = rute[i].getLocalitati();
        for (int j = 0; j < ruta_loc.size(); j++)
        {
            if (ruta_loc[j] == id_loc)
            {
               contor++;
               break;
            }
            
        }
    }
    return contor;
}

//Cauta toate rutele care trec printr-o localitate data prin id
//return: rutele gasite
vector<Ruta> ServiceRuta::getRutePrinLocalitate(int id_loc)
{
    if (repo_loc.findById(id_loc) == -1)
        throw ServiceRutaExceptie("Nu exista nicio localitate cu id-ul dat pt a gasi rute\n");
    vector<Ruta> rute_gasite;
    vector<Ruta> rute = repo_ruta.getAll();
    for (int i = 0; i < rute.size(); i++)
    {
        vector<int> ruta_loc = rute[i].getLocalitati();
        for (int j = 0; j < ruta_loc.size(); j++)
        {
            if (ruta_loc[j] == id_loc)
            {
               rute_gasite.push_back(rute[i]);
                break;
            }

        }
    }
    return rute_gasite;
}

//Sterge toate rutele care au un numar de localitati mai mare decat o valoare data
int ServiceRuta::filtrareRuteDupaNrLocalitati(int nr)
{
    vector<Ruta> rute = repo_ruta.getAll();
    int contor = 0;
    for (auto ruta : rute) {
        if (ruta.getLocalitati().size() > nr)
        {
            repo_ruta.deleteElem(ruta);
            contor++;
        }
            
    }
    return contor;
}

bool comparaRute(Ruta& r1, Ruta& r2)
{
    if (r1.getLocalitati().size() < r2.getLocalitati().size())
        return true;
    return false;
}

//sorteaza crescator rutele dupa numarul de localitati
//return: un vector de rute sortate
vector<Ruta> ServiceRuta::sortareRuteCrescatorDupaLocalitati()
{
    vector<Ruta> rute = repo_ruta.getAll();
    if (rute.size() > 0)
    sort(rute.begin(), rute.end(), comparaRute);

    return rute;
}

//verifica daca id-urile localitatilor rutelor citite din fisier exista
//daca nu exista rutele respective vor fi sterse din repo
//daca nu se citesc date din fisier nu se intampla nimic
void ServiceRuta::verificareDateRutaLaPrimaCitire()
{
    vector<Ruta> rute = repo_ruta.getAll();
    int size = rute.size();
    if ( size > 0)
    {
        for (int i = 0; i < size;i++) 
        {
            vector<int> id_locs = rute[i].getLocalitati();
            for (int j = 0; j < id_locs.size(); j++) {
                if (repo_loc.findById(id_locs[j]) == -1) {
                    repo_ruta.deleteElem(rute[i]);
                    break;
                }
            }
        }
    }
 
}


