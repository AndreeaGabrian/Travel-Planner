#pragma once
class Calator {
protected:
	int cod;
	bool vaccinat;
public:
	Calator();
	Calator(int cod, bool vaccinat);
	Calator(const Calator& c);

	int getCod();
	bool getVaccinat();
	void setCod(int cod_nou);
	void setVaccinat(bool vaccinat);
	Calator& operator=(const Calator& c);
	bool operator==(const Calator& c);
};