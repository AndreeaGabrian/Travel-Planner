#pragma once
#include"RepoTemplate.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template<class T>
class RepoTemplateFile :public RepoTemplate<T> {
private:
	string filename;
	void loadFromFile();
	void saveToFile();
public:
	RepoTemplateFile();
	RepoTemplateFile(string filename);
	RepoTemplateFile(const RepoTemplateFile& rf);
	~RepoTemplateFile();

	void setFilename(string filename);
	void addElem(const T& elem);
	void updateElem(const T& oldElem, const T& newElem);
	void deleteElem(const T& elem);
	friend class TesteRepoFile;
};

template<class T>
inline void RepoTemplateFile<T>::loadFromFile()
{
	ifstream f(this->filename);
	if (f.is_open())
	{
		this->elemente.clear();

		while (!f.eof())
		{
			T t;
			f >> t;

			try {
				t.valideazaObiectDinFisier();
				this->elemente.push_back(t);
			}
			catch (RepoFileExceptie& ex) {
				cout << ex.getMesaj()<<endl;
			}
			catch(...){}
			
		}
		f.close();
	}
	else
		throw RepoFileExceptie("Fisierul nu s-a deschis pentru citire\n");
	
}

template<class T>
inline void RepoTemplateFile<T>::saveToFile()
{
	ofstream f(this->filename);
	if (f.is_open())
	{
		int size = this->elemente.size();
		for (int i = 0; i < size-1; i++)
		{
			f << this->elemente[i] << endl;
		}
		f << this->elemente[size - 1];
		f.close();
	}
	else
		throw RepoFileExceptie("Fisierul nu s-a deschis pentru scriere\n");
}

template<class T>
inline RepoTemplateFile<T>::RepoTemplateFile()
{
}

template<class T>
inline RepoTemplateFile<T>::RepoTemplateFile(string filename)
{
	this->filename = filename;
	try {
		loadFromFile();
	}
	catch (RepoFileExceptie& exf) {
		cout << exf.getMesaj() << endl;
	}
	
}

template<class T>
inline RepoTemplateFile<T>::RepoTemplateFile(const RepoTemplateFile& rf)
{
	filename = rf.filename;
}

template<class T>
inline RepoTemplateFile<T>::~RepoTemplateFile()
{
}

template<class T>
inline void RepoTemplateFile<T>::setFilename(string filename)
{
	this->filename = filename;
}

template<class T>
inline void RepoTemplateFile<T>::addElem(const T& elem)
{
	RepoTemplate<T>::addElem(elem);
	try {
		saveToFile();
	}
	catch (RepoFileExceptie& exf) {
		cout << exf.getMesaj() << endl;
	}
}

template<class T>
inline void RepoTemplateFile<T>::updateElem(const T& oldElem, const T& newElem)
{
	RepoTemplate<T>::updateElem(oldElem, newElem);
	try {
		saveToFile();
	}
	catch (RepoFileExceptie& exf) {
		cout << exf.getMesaj() << endl;
	}
}

template<class T>
inline void RepoTemplateFile<T>::deleteElem(const T& elem)
{
	RepoTemplate<T>::deleteElem(elem);
	try {
		saveToFile();
	}
	catch (RepoFileExceptie& exf) {
		cout << exf.getMesaj() << endl;
	}
}
