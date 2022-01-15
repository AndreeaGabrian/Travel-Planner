#include "LocalitateRestrictionata.h"

LocalitateRestrictionata::LocalitateRestrictionata():Localitate()
{
    this->inceput_restrictii = DataCalendaristica();
    this->sfarsit_restrictii = DataCalendaristica();
    this->vizitabil = true;
    this->restrictii = "";
}

LocalitateRestrictionata::LocalitateRestrictionata(int id, string nume, int populatie, double rata_incidenta, CoordonateGeo coord, DataCalendaristica inceput_restrictii, DataCalendaristica sfarsit_restrictii, bool vizitabil, string restrictii) :Localitate(id, nume, populatie, rata_incidenta, coord)
{
    this->inceput_restrictii = inceput_restrictii;
    this->sfarsit_restrictii = sfarsit_restrictii;
    this->vizitabil = vizitabil;
    this->restrictii = restrictii;
}

LocalitateRestrictionata::LocalitateRestrictionata(const LocalitateRestrictionata& locr):Localitate(locr)
{
    this->inceput_restrictii = locr.inceput_restrictii;
    this->sfarsit_restrictii = locr.sfarsit_restrictii;
    this->vizitabil = locr.vizitabil;
    this->restrictii = locr.restrictii;
}

LocalitateRestrictionata::~LocalitateRestrictionata()
{
    this->restrictii = "";
}

DataCalendaristica LocalitateRestrictionata::getInceputRestrictii()
{
    return inceput_restrictii;
}

DataCalendaristica LocalitateRestrictionata::getSfarsitRestrictii()
{
    return sfarsit_restrictii;
}

bool LocalitateRestrictionata::getVizitabil()
{
    return vizitabil;
}

string LocalitateRestrictionata::getRestrictii()
{
    return restrictii;
}

void LocalitateRestrictionata::setInceputRestrictii(DataCalendaristica inceput)
{
    inceput_restrictii = inceput;
}

void LocalitateRestrictionata::setSfarsitRestrictii(DataCalendaristica sfarsit)
{
    sfarsit_restrictii = sfarsit;
}

void LocalitateRestrictionata::setVizitabil(bool vizitabil)
{
    this->vizitabil = vizitabil;
}

void LocalitateRestrictionata::setRestrictii(string restrictii)
{
    this->restrictii = restrictii;
}

LocalitateRestrictionata& LocalitateRestrictionata::operator=(const LocalitateRestrictionata& locr)
{
    Localitate::operator=(locr);
    inceput_restrictii = locr.inceput_restrictii;
    sfarsit_restrictii = locr.sfarsit_restrictii;
    vizitabil = locr.vizitabil;
    restrictii = locr.restrictii;
    return *this;
}

bool LocalitateRestrictionata::operator==(const LocalitateRestrictionata& locr)
{
    return Localitate::operator==(locr) && inceput_restrictii == locr.inceput_restrictii && sfarsit_restrictii == locr.sfarsit_restrictii && vizitabil == locr.vizitabil && restrictii == locr.restrictii;
}

istream& operator>>(istream& is, LocalitateRestrictionata& locr)
{
    DataCalendaristica inceput, sfarsit; bool vizitabil; string restrictii;
    is >> (Localitate&)locr;
    if (&is == &cin)
    {
        cout << "Data inceput restrictii: "; is >> inceput;
        cout << "Data sfarsit restrictii: "; is >> sfarsit;
        cout << "Vizitabil(da/nu): "; is >> vizitabil;
        cout << "Restrictii: "; is >> restrictii;
    }
    else
        is >> inceput >> sfarsit >> vizitabil >> restrictii;
    locr.setInceputRestrictii(inceput);
    locr.setSfarsitRestrictii(sfarsit);
    locr.setVizitabil(vizitabil);
    locr.setRestrictii(restrictii);
    return is;
}

ostream& operator<<(ostream& os, const LocalitateRestrictionata& locr)
{
    os << (Localitate&)locr << " inceput restrictii: " << locr.inceput_restrictii << " sfarsit restrictii: " << locr.sfarsit_restrictii << " vizitabil: " << locr.vizitabil << " restrictii: " << locr.restrictii;
    return os;
}
