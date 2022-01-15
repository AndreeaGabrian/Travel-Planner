#pragma once
//#include <vector>
#include"IRepoTemplate.h"
#include "Exceptii.h"
using namespace std;

template<class T>
class RepoTemplate:public IRepoTemplate<T>{
protected:
	vector<T> elemente;

public:
	RepoTemplate();
	RepoTemplate(vector<T> elem);
	RepoTemplate(const RepoTemplate& repo);
	~RepoTemplate() override;
	vector<T>& getAll() override;
	int getSize() override;
	void setElemente(vector<T>elem);

	void addElem(const T& elem) override;
	void updateElem(const T& oldElem, const T& newElem) override;
	void deleteElem(const T& elem) override;

	int findById(int id) override;
	virtual bool exist(const T& elem) override;
};

template<class T>
RepoTemplate<T>::RepoTemplate()
{
}

template<class T>
RepoTemplate<T>::RepoTemplate(vector<T> elem)
{
	this->elemente = elem;
}

template<class T>
RepoTemplate<T>::RepoTemplate(const RepoTemplate& repo)
{
	this->elemente = repo.elemente;
}

template<class T>
RepoTemplate<T>::~RepoTemplate() 
{
	this->elemente.clear();
}

template<class T>
vector<T>& RepoTemplate<T>::getAll()
{
	return elemente;
}

template<class T>
int RepoTemplate<T>::getSize()
{
	return this->elemente.size();
}

template<class T>
inline void RepoTemplate<T>::setElemente(vector<T> elem)
{
	this->elemente = elem;
}

template<class T>
void RepoTemplate<T>::addElem(const T& elem)
{
	this->elemente.push_back(elem);
}

template<class T>
void RepoTemplate<T>::updateElem(const T& oldElem, const T& newElem)
{
	for (int i = 0; i < this->elemente.size(); i++)
	{
		if (this->elemente[i] == oldElem)
		{
			this->elemente[i] = newElem;
		}
	}
}

template<class T>
void RepoTemplate<T>::deleteElem(const T& elem)
{
	typename vector<T>::iterator it;
	it = find(this->elemente.begin(), this->elemente.end(), elem);
	if (it != this->elemente.end())
	{
		this->elemente.erase(it);
	}
}


template<class T>
int RepoTemplate<T>::findById(int id)
{
	for (int i = 0; i < elemente.size(); i++)
	{
		if (elemente[i].getId() == id)
			return i;
	}
	return -1;
}

template<class T>
inline bool RepoTemplate<T>::exist(const T& elem)
{
	for (int i = 0; i < elemente.size(); i++)
	{
		if (elemente[i] == elem)
			return true;
	}
	return false;
}

