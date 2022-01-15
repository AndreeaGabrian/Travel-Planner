#include "Exceptii.h"

ostream& operator<<(ostream& os, const ExceptieDomain& ex)
{
    for (int i = 0; i < ex.mesaje.size(); i++)
        os << ex.mesaje[i] << endl;
    return os;
}

string RepoFileExceptie::getMesaj()
{
    return mesaj;
}

string ServiceExceptie::getMesaj()
{
    return mesaj;
}

vector<string> ExceptieDomain::getMesaje()
{
    return mesaje;
}

ExceptieTipIncorectData::ExceptieTipIncorectData(string mesaj)
{
    this->mesaj = mesaj;
}

string ExceptieTipIncorectData::getMesaj()
{
    return mesaj;
}

CalatorieExceptie::CalatorieExceptie(string mesaj)
{
    this->mesaj = mesaj;
}

string CalatorieExceptie::getMesaj()
{
    return mesaj;
}
