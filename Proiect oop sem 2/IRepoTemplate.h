#pragma once
#include<vector>

template <class T>
class IRepoTemplate {
public:
	virtual ~IRepoTemplate() {};
	virtual void addElem(const T& elem)=0;
	virtual void updateElem(const T& oldElem, const T& newElem)=0;
	virtual void deleteElem(const T& elem)=0;
	virtual std::vector<T>& getAll()=0;
	virtual int getSize() = 0;
	virtual int findById(int id)=0;
	virtual bool exist(const T& elem) = 0;
};


