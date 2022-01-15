#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class ExceptieDomain {
protected:
	vector<string> mesaje;
public:
	ExceptieDomain(const vector<string> errors) :mesaje{ errors } {};
	vector<string> getMesaje();
	friend ostream& operator<<(ostream& os, const ExceptieDomain& ex);
};

class ExceptiePunctDeVizitare: public ExceptieDomain{
public:
	ExceptiePunctDeVizitare(const vector<string> errors) :ExceptieDomain(errors) {}
};

class ExceptieLocalitate:public ExceptieDomain {
public:
	ExceptieLocalitate(const vector<string> errors) :ExceptieDomain(errors){}
};

class ExceptieCoordonateGeo :public ExceptieDomain {
public:
	ExceptieCoordonateGeo(const vector<string> errors) :ExceptieDomain(errors) {}
};

class ExceptieObiectivTuristic:public ExceptieDomain {
public:
	ExceptieObiectivTuristic(const vector<string> errors) :ExceptieDomain(errors){} 
};

class ExceptieRuta :public ExceptieDomain {
public:
	ExceptieRuta(const vector<string> errors) :ExceptieDomain(errors) {}
};

class RepoFileExceptie {
private:
	string mesaj;
public:
	RepoFileExceptie(string m) :mesaj{ m } {};
	string getMesaj();
};

class ServiceExceptie {
protected:
	string mesaj;
public:
	ServiceExceptie(string m) :mesaj{ m } {};
	string getMesaj();
};

class ServicePunctExceptie : public ServiceExceptie {
public:
	ServicePunctExceptie(string m):ServiceExceptie(m){}
};

class ServiceLocalitateExceptie : public ServiceExceptie {
public:
	ServiceLocalitateExceptie(string m) :ServiceExceptie(m) {}
};

class ServiceRutaExceptie : public ServiceExceptie {
public:
	ServiceRutaExceptie(string m) :ServiceExceptie(m) {}
};

class ServiceObiectivExceptie : public ServiceExceptie {
public:
	ServiceObiectivExceptie(string m) :ServiceExceptie(m) {}
};

class ExceptieTipIncorectData {
private:
	string mesaj;
public:
	ExceptieTipIncorectData(string mesaj);
	string getMesaj();
};

class CalatorieExceptie {
private:
	string mesaj;
public:
	CalatorieExceptie(string mesaj);
	string getMesaj();
};
