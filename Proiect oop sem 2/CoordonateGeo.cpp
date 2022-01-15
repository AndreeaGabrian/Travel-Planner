#include "CoordonateGeo.h"
#include<cmath>
#include<string.h>
#include <string>
#include "Exceptii.h"


CoordonateGeo::CoordonateGeo()
{
	latitudine = 0.0;
	longitudine = 0.0;
}

CoordonateGeo::CoordonateGeo(double lat, double lon)
{
	latitudine = lat;
	longitudine = lon;
}

CoordonateGeo::CoordonateGeo(const CoordonateGeo& coord)
{
	latitudine = coord.latitudine;
	longitudine = coord.longitudine;
}

double CoordonateGeo::getLongitudine()
{
	return longitudine;
}

double CoordonateGeo::getLatitudine()
{
	return latitudine;
}

void CoordonateGeo::setLongitudine(double lon)
{
	longitudine = lon;
}

void CoordonateGeo::setLatitudine(double lat)
{
	latitudine = lat;
}

CoordonateGeo& CoordonateGeo::operator=(const CoordonateGeo& coord)
{
	latitudine = coord.latitudine;
	longitudine = coord.longitudine;
	return *this;
}

bool CoordonateGeo::operator==(const CoordonateGeo& coord)
{
	return latitudine==coord.latitudine && longitudine==coord.longitudine;
}

double CoordonateGeo::distantaDouaLocatii(const CoordonateGeo coord)
{
	double raza = 6371000.0;
	double delta_lat = (coord.latitudine - latitudine) * (3.14159/180);
	double delta_lon = (coord.longitudine - longitudine) *(3.14159/180);
	double lat1_radians = latitudine * (3.14159 / 180);
	double lat2_radians = coord.latitudine * (3.14159 / 180);

	double a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(lat1_radians) * cos(lat2_radians) * sin(delta_lon / 2) * sin(delta_lon / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double distance = floor((raza * c) / 1000);
	//string distance_to_string = to_string(distance);
	//int pos = distance_to_string.find('.');
	//distance = stod(distance_to_string.substr(0, pos + 3));
	
	return distance;
}

istream& operator>>(istream& is, CoordonateGeo& coord)
{
	double lat, lon;
	if (&is == &cin)
	{
		cout << "Dati latitudinea: "; 
		if (is >> lat)
		{
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Latitudinea trebuie sa fie numar ");
		}
		cout << "Dati longitudinea: "; 
		if (is >> lon)
		{
		}
		else
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');

			throw ExceptieTipIncorectData("Longitudinea trebuie sa fie numar ");
		}
	}
	else
		is >> lat >> lon;
	coord.setLatitudine(lat);
	coord.setLongitudine(lon);
	return is;
}

ostream& operator<<(ostream& os, const CoordonateGeo& coord)
{
	if (&os == &cout)
		os << "lat: " << coord.latitudine << " long: " << coord.longitudine;
	else
		os << coord.latitudine << ' ' << coord.longitudine;
	return os;
}
