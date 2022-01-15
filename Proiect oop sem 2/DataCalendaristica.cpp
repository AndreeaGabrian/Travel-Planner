#include "DataCalendaristica.h"

DataCalendaristica::DataCalendaristica()
{
    this->zi = 1;
    this->luna = 1;
    this->an = 1;
}

DataCalendaristica::DataCalendaristica(int zi, int luna, int an)
{
    this->zi = zi;
    this->luna = luna;
    this->an = an;
}

DataCalendaristica::DataCalendaristica(const DataCalendaristica& data)
{
    this->zi = data.zi;
    this->luna = data.luna;
    this->an = data.an;
}

DataCalendaristica::~DataCalendaristica()
{
}

int DataCalendaristica::getZi()
{
    return this->zi;
}

int DataCalendaristica::getLuna()
{
    return this->luna;
}

int DataCalendaristica::getAn()
{
    return this->an;
}

void DataCalendaristica::setZi(int zi)
{
    this->zi = zi;
}

void DataCalendaristica::setLuna(int luna)
{
    this->luna = luna;
}

void DataCalendaristica::setAn(int an)
{
    this->an = an;
}

DataCalendaristica& DataCalendaristica::operator=(const DataCalendaristica& data)
{
    this->zi = data.zi;
    this->luna = data.luna;
    this->an = data.an;

    return*this;
}

bool DataCalendaristica::operator==(const DataCalendaristica& data)
{
    return zi==data.zi&&luna==data.luna&&an==data.an;
}

istream& operator>>(istream& is, DataCalendaristica& data)
{
    int zi, luna, an;
 
    if (&is == &cin)
    {
        cout << "Ziua: "; is >> zi;
        cout << "Luna: "; is >> luna;
        cout << "Anul: "; is >> an;
    }
    else
        is >> zi >> luna >> an;
    data.setZi(zi);
    data.setLuna(luna);
    data.setAn(an);
    return is;
}

ostream& operator<<(ostream& os, const DataCalendaristica& data)
{
    os << data.zi << '/' << data.luna << '/' << data.an;
    return os;
}