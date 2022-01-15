#include "Calator.h"

Calator::Calator()
{
	cod = 0;
	vaccinat = false;
}

Calator::Calator(int cod, bool vaccinat)
{
	this->cod = cod;
	this->vaccinat = vaccinat;
}

Calator::Calator(const Calator& c)
{
	this->cod = c.cod;
	this->vaccinat = c.vaccinat;
}

int Calator::getCod()
{
	return cod;
}

bool Calator::getVaccinat()
{
	return vaccinat;
}

void Calator::setCod(int cod_nou)
{
	cod = cod_nou;
}

void Calator::setVaccinat(bool vaccinat)
{
	this->vaccinat = vaccinat;
}

Calator& Calator::operator=(const Calator& c)
{
	cod = c.cod;
	vaccinat = c.vaccinat;
	return *this;
}

bool Calator::operator==(const Calator& c)
{
	return cod == c.cod && vaccinat == c.vaccinat;
}
