#pragma once
#include"ServicePunctDeVizitare.h"
#include"ServiceLocalitati.h"
#include"ServiceRuta.h"
#include"ServiceObiectivTuristic.h"
#include "Calatorie.h"

class UI {
private:
	ServicePunctDeVizitare& srv_pct;
	ServiceLocalitati& srv_loc;
	ServiceRuta& srv_ruta;
	ServiceObiectivTuristic& srv_obv;
	Calatorie& calatorie;

	void meniuPunctVizitare();
	void meniuLocalitate();
	void meniuObiectivTuristic();
	void meniuRuta();
	void meniuFunctionalitati();
	
	void showMenu();

	void uiAddPunctDeVizitare();
	void uiDeletePunctDeVizitare();
	void uiUpdatePunctDeVizitare();
	void uiAfiseazaPuncteDeVizitare();

	void uiAddLocalitate();
	void uiDeleteLocalitate();
	void uiModificaLocalitate();
	

	void uiAddRuta();
	void uiDeleteRuta();
	void uiModificaRuta();
	

	void uiAddObiectiv();
	void uiDeleteObiectiv();
	void uiModificaObiectiv();
	

	//functionalitati service localitati
	void uiFiltrareLocalitatiDupaRata(double rata);
	
	//functionalitati service ruta
	void uiFiltrareRuteDupaNrLocalitati(int nr);

protected:
	
	void uiAfiseazaLocalitati();
	void uiAfiseazaRute();
	void uiAfiseazaObiective();

	void meniuCalatorie();

	//functionalitati service localitati
	void uiGetObiectiveDinLocalitate(int& id_loc);
	void uiGetRuteIncepandDinLocalitate(int& id_loc);
	void uiGetDistantaIntreLocalitati(int& id1, int& id2);
	void uiGetObvLocKm(double& km, int& id);
	void uiGetCeaMaiApropiataLoc(int& id);
	void uiGetRuteCuLungimeMica(int km);

	//functionalitati service ruta
	void uiGetRutePrinLocalitate(int id_loc);
	void uiSortareRuteCrescatorDupaLocalitati();

	//functionalitati service obiectiv turistic
	void uiSorteazaDupaTip(string tip);
	void uiSorteazaDupaPatrimoniu(string patrimoniu);
	void uiSorteazaDupaNecesitateVaccin(string vaccin);

	//calatoria
	void uiAddElemInCalatorie();
	void uiDeleteElemDinCalatorie();
	void uiAfiseazaCalatorie();
	void uiSalveazaCalatorieInFisier();
	void uiAfiseazaCalatorieDinFisier();
	void uiSugerareCalatorie();
public:
	//UI();
	UI(ServicePunctDeVizitare& srv, ServiceLocalitati& srv_loc, ServiceRuta& srv_ruta, ServiceObiectivTuristic& srv_obv, Calatorie& calatorie);
	virtual ~UI() {};

	void runMenu();
};
