#pragma once

#include"RepoTemplate.h"
#include"Localitate.h"

class RepoFileLocalitati :public RepoTemplate<Localitate> {
private:
	string filename;
	void loadFromFile();
	void saveToFile();
public:
	RepoFileLocalitati();
	RepoFileLocalitati(string filename);
	RepoFileLocalitati(const RepoFileLocalitati& rfl);
	~RepoFileLocalitati();

	void setFilename(string filename);
	void addElem(const Localitate& elem);
	void updateElem(const Localitate& oldElem, const Localitate& newElem);
	void deleteElem(const Localitate& elem);
};
