#include "Ruta.h"
#include"Validator.h"
#include"Exceptii.h"


vector<int> Ruta::getLocalitati()
{
    return localitati;
}

void Ruta::setLocalitati(vector<int> locs)
{
    localitati = locs;
}

PunctDeVizitare* Ruta::clona()
{
    return new Ruta(id, nume, localitati);
}

string Ruta::toString(bool file)
{
    int size = localitati.size();
    string id_loc;
    for (int i = 0; i < size-1; i++)
    {
        id_loc += to_string(localitati[i]) + " ";
    }
    id_loc += to_string(localitati[size-1]);

    if (file) {
        
        return "R " + PunctDeVizitare::toString(file) + " " + to_string(size) + " " + id_loc;
    }
    return "ruta: "+ PunctDeVizitare::toString() + ", localitati: "+ id_loc;
}



Ruta& Ruta::operator=(const Ruta& ruta)
{
    PunctDeVizitare::operator=(ruta);
    localitati = ruta.localitati;
    return *this;
}
void Ruta::valideazaObiectDinFisier()
{
    ValidatorRuta vr;
    try {
        vr.valideaza(*this);
    }
    catch (ExceptieRuta& ex) {
        cout << ex<<endl;
        throw RepoFileExceptie("ruta din fisier invalida\n");
    }
}
/*
bool Ruta::operator==(const Ruta& ruta)
{
    return PunctDeVizitare::operator==(ruta) && localitati==ruta.localitati;
}
*/

istream& operator>>(istream& is, Ruta& ruta)
{
    vector<int> locs; int nr; int l;
    is >> (PunctDeVizitare&)ruta;
    if (&is == &cin)
    {
        
        cout << "Introduceti nr de localitati ale rutei: "; 
        if (is >> nr)
        {
            cout << "Localitatile: \n";
            for (int i = 0; i < nr; i++)
            {
                cout << "id localitate " << i + 1 << ": "; //cin >> l;
                if (is >> l)
                {
                    locs.push_back(l);
                }
                else
                {
                    is.clear();
                    is.ignore(numeric_limits<streamsize>::max(), '\n');

                    throw ExceptieTipIncorectData("Id-ul localitatii trebuie sa fie intreg ");
                }

            }
        }
        else
        {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');

            throw ExceptieTipIncorectData("Numarul de localitati sa fie intreg ");
        }
       
    }
    else
    {
        is >> nr;
        for (int i = 0; i < nr; i++)
        {
            is >> l;
            locs.push_back(l);
        }
    }
    
    ruta.setLocalitati(locs);
    return is;
}

ostream& operator<<(ostream& os, const Ruta& ruta)
{
    if (&os == &cout) {
        os << (PunctDeVizitare&)ruta << ' ';
        int size = ruta.localitati.size();
        os <<"numar localitati:"<< size << ", "<<"id-uri localitati: ";
        for (int i = 0; i < size - 1; i++)
            os << ruta.localitati[i] << ' ';
        os << ruta.localitati[size - 1];
    }
    else {
        os << (PunctDeVizitare&)ruta << ' ';
        int size = ruta.localitati.size();
        os << size << ' ';
        for (int i = 0; i < size - 1; i++)
            os << ruta.localitati[i] << ' ';
        os << ruta.localitati[size - 1];
    }
    
    return os; 
}

