#include "ServiceObiectivTuristic.h"
#include"ServiceLocalitati.h"
#include "Exceptii.h"

//returneaza obiectivele turistice
vector<ObiectivTuristic> ServiceObiectivTuristic::getAll()
{
    return repo_obv.getAll();
}

//adauga un nou obiectiv turistic
//arunca exceptie daca exista deja un obiectiv turistic cu id-ul dat
void ServiceObiectivTuristic::addObiectiv(int id, string nume, int id_localitate, string tip, double pret_bilet, string patrimoniu_UNESCO, string necesitate_vaccin)
{
    if (repo_obv.findById(id) != -1)
        throw ServiceObiectivExceptie("Exista deja un obiectiv turistic cu id-ul: " + to_string(id));
    if (repo_loc.findById(id_localitate) == -1)
        throw ServiceObiectivExceptie("Nu exista niciun oras cu id-ul: " + to_string(id_localitate) + " pentru a adauga obiectivul");
    ObiectivTuristic obv(id, nume, id_localitate, tip, pret_bilet, patrimoniu_UNESCO, necesitate_vaccin);
    repo_obv.addElem(obv);
}
 
//sterge un obiectiv turistic
//arunca exceptie daca nu exista un obiectiv cu id-ul dat
void ServiceObiectivTuristic::deleteOviectiv(int id)
{
    if (repo_obv.findById(id) == -1)
        throw ServiceObiectivExceptie("Nu exista niciun obiectiv turistic cu id-ul: " + to_string(id) + " pentru a fi sters");
    vector<ObiectivTuristic> obiective = repo_obv.getAll();
    int i = repo_obv.findById(id);
    repo_obv.deleteElem(obiective[i]);
}

//modifica un obiectiv turistic
//arunca exceptie daca nu exista niciun obiectiv cu id-ul dat dau daca nu exista o localitate cu noul id al localitatii
void ServiceObiectivTuristic::updateObiectiv(int id, string nume_nou, int id_localitate_noua, string tip_nou, double pret_bilet_nou, string patrimoniu_UNESCO_nou, string necesitate_vaccin_nou)
{
    int i = repo_obv.findById(id);
    if (i == -1)
        throw ServiceObiectivExceptie("Nu exista niciun obiectiv turistic cu id-ul: " + to_string(id) + " pentru a fi modificat");
    if (repo_loc.findById(id_localitate_noua) == -1)
        throw ServiceObiectivExceptie("Nu exista nicio localitate cu id-ul: " + to_string(id_localitate_noua) + " pentru a modifica obiectivul");

    ObiectivTuristic obv_nou(id, nume_nou, id_localitate_noua, tip_nou, pret_bilet_nou, patrimoniu_UNESCO_nou, necesitate_vaccin_nou);
    repo_obv.updateElem(repo_obv.getAll()[i], obv_nou);
    
}

//cauta un obiectiv turistic dupa id
//returneaza pozitia acestuia din vector sau -1 daca nu se gaseste
int ServiceObiectivTuristic::findById(int id)
{
    return repo_obv.findById(id);
}

//Calculeaza numarul de obiective turistice dintr-o localitate
//return:numarul obiectivelor din localitate
int ServiceObiectivTuristic::countObiectiveByIdLocalitate(int id_loc)
{
    int contor = 0;
    for (int i = 0; i < repo_obv.getAll().size(); i++)
    {
        if (repo_obv.getAll()[i].getIdLocalitate() == id_loc)
            contor++;
    }
    return contor;
}

//sorteaza obiectivele turistice dupa un tip dat
//return: obiectivele sortate
vector<ObiectivTuristic> ServiceObiectivTuristic::sorteazaDupaTip(string tip)
{
    if (tip != "istoric" && tip != "cultural" && tip != "natural" && tip != "altele")
        throw ServiceObiectivExceptie("Tipul trebuie sa fie unul dintre: natural, cultural, istoric, altele \n");

    vector<ObiectivTuristic> sortat;
    vector<ObiectivTuristic> obiective = repo_obv.getAll();
    int size = repo_obv.getSize();
    for (int i = 0; i < size; i++)
    {
        if (obiective[i].getTip().compare(tip) == 0)
            sortat.push_back(obiective[i]);
    }

    return sortat;
}

//sorteaza obiectivele turistice dupa patrimoniu(daca fac parte sau nu)
//return: obiectivele sortate
vector<ObiectivTuristic> ServiceObiectivTuristic::sorteazaDupaPatrimoniu(string patr)
{
    if (patr != "da" && patr != "nu")
        throw ServiceObiectivExceptie("Apartenenta la patrimoniu poate fi doar da sau nu\n");

    vector<ObiectivTuristic> sortat;
    vector<ObiectivTuristic> obiective = repo_obv.getAll();
    int size = repo_obv.getSize();
    for (int i = 0; i < size; i++)
    {
        if (obiective[i].getPatrimoniu().compare(patr) == 0)
            sortat.push_back(obiective[i]);
    }

    return sortat;
}

//sorteaza obiectivele turistice dupa necesitate vaccin(daca necesita sau nu)
//return: obiectivele sortate
vector<ObiectivTuristic> ServiceObiectivTuristic::sorteazaDupaNecesitateVaccin(string necesita)
{
    if (necesita != "da" && necesita != "nu")
        throw ServiceObiectivExceptie("Necesitatea vaccinului poate fi doar da sau nu\n");
    vector<ObiectivTuristic> sortat;
    vector<ObiectivTuristic> obiective = repo_obv.getAll();
    int size = repo_obv.getSize();
    for (int i = 0; i < size; i++)
    {
        if (obiective[i].getNecesitateVaccin().compare(necesita) == 0)
            sortat.push_back(obiective[i]);
    }

    return sortat;
}

//verifica daca id-ul localitatii din cadrul obiectivului exista
//daca nu exista obiectivul va finsters din repo
void ServiceObiectivTuristic::verificareDateObiectivLaPrimaCitire()
{
    vector<ObiectivTuristic> obiective = repo_obv.getAll();
    int size = obiective.size();
    if (size > 0)
    {
        for (int i = 0; i < size; i++) 
        {
            if (repo_loc.findById(obiective[i].getIdLocalitate()) == -1)
            {
                repo_obv.deleteElem(obiective[i]);
                break;
            } 
        }
    }
}




