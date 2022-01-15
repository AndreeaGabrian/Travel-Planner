#pragma once
#include"Ruta.h"
#include"RepoTemplate.h"

class RepoFileRuta :public RepoTemplate<Ruta> {
private:
	string filename;
	void loadFromFile();
	void saveToFile();
public:
	RepoFileRuta();
	RepoFileRuta(string filename);
	RepoFileRuta(const RepoFileRuta& rft);
	~RepoFileRuta();

	void setFilename(string filename);
	void addElem(const Ruta& elem);
	void updateElem(const Ruta& oldElem, const Ruta& newElem);
	void deleteElem(const Ruta& elem);
};