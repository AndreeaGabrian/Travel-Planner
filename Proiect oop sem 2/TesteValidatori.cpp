#include "TesteValidatori.h"
#include"Exceptii.h"
#include<assert.h>
#include"Ruta.h"

void TesteValidatori::testValideazaPct()
{
	PunctDeVizitare p1(-12, "nume");
	try {
		vp.valideaza(p1);
		assert(false);
	}
	catch (ExceptiePunctDeVizitare& e) {
		assert(true);
	}

	PunctDeVizitare p2(12, "nume");
	try {
		vp.valideaza(p2);
		assert(true);
	}
	catch (ExceptiePunctDeVizitare& e) {
		assert(false);
	}
}

void TesteValidatori::testValideazaCoord()
{
	CoordonateGeo c1(12.23, 23.34);
	try {
		vg.valideaza(c1);
		assert(true);
	}
	catch (ExceptieCoordonateGeo& e) {
		assert(false);
	}

	CoordonateGeo c2(1245.23, 23.34);
	try {
		vg.valideaza(c2);
		assert(false);
	}
	catch (ExceptieCoordonateGeo& e) {
		assert(true);
	}

	CoordonateGeo c3(45.23, -223.34);
	try {
		vg.valideaza(c3);
		assert(false);
	}
	catch (ExceptieCoordonateGeo& e) {
		assert(true);
	}
}

void TesteValidatori::testValideazaLoc()
{
	Localitate l1(1, "nume", 234, 2.3, CoordonateGeo(45, 47));
	try {
		vl.valideaza(l1);
		assert(true);
	}
	catch (ExceptieLocalitate& e) {
		assert(false);
	}

	Localitate l2(1, "nume", -234, 2.3, CoordonateGeo(45, 47));
	try {
		vl.valideaza(l2);
		assert(false);
	}
	catch (ExceptieLocalitate& e) {
		assert(true);
	}

	Localitate l3(1, "nume", 234, -2.3, CoordonateGeo(45, 47));
	try {
		vl.valideaza(l3);
		assert(false);
	}
	catch (ExceptieLocalitate& e) {
		assert(true);
	}
}

void TesteValidatori::testValideazaObv()
{
	ObiectivTuristic o1(1, "obv", 1, "istoric", 10, "nu", "da");
	try {
		vo.valideaza(o1);
		assert(true);
	}
	catch (ExceptieObiectivTuristic& e) {
		assert(false);
	}

	ObiectivTuristic o2(1, "obv", 1, "gdfgdf", 10, "nu", "da");
	try {
		vo.valideaza(o2);
		assert(false);
	}
	catch (ExceptieObiectivTuristic& e) {
		assert(true);
	}

	ObiectivTuristic o3(1, "obv", 1, "istoric", -10, "nu", "da");
	try {
		vo.valideaza(o3);
		assert(false);
	}
	catch (ExceptieObiectivTuristic& e) {
		assert(true);
	}

	ObiectivTuristic o4(1, "obv", 1, "istoric", 10, "nbcvu", "da");
	try {
		vo.valideaza(o4);
		assert(false);
	}
	catch (ExceptieObiectivTuristic& e) {
		assert(true);
	}
}

void TesteValidatori::testValideazaRuta()
{
	Ruta r1(1, "ruta1", { 1,2 });
	try {
		vr.valideaza(r1);
		assert(true);
	}
	catch(ExceptieRuta& e){
		assert(false);
	}

	Ruta r2(-11, "ruta1", { 1,2 });
	try {
		vr.valideaza(r2);
		assert(false);
	}
	catch (ExceptieRuta& e) {
		assert(true);
	}
	

	Ruta r3(1, "ruta1", { -1,2 });
	try {
		vr.valideaza(r3);
		assert(false);
	}
	catch (ExceptieRuta& e) {
		assert(true);
	}
}

TesteValidatori::TesteValidatori()
{
}

TesteValidatori::~TesteValidatori()
{
}

void TesteValidatori::runAll()
{
	testValideazaPct();
	testValideazaCoord();
	testValideazaLoc();
	testValideazaObv();
	testValideazaRuta();
	cout <<"Testele pentru validatori au fost trecute cu succes!\n";
}
