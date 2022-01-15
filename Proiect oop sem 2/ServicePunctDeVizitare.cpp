#include "ServicePunctDeVizitare.h"
#include"Exceptii.h"


ServicePunctDeVizitare::~ServicePunctDeVizitare()
{
}

void ServicePunctDeVizitare::setRepo(IRepoTemplate<PunctDeVizitare>& repo)
{
	this->repo_punct_de_vizitare = repo;
}

//retur: toate punctele de vizitare
vector<PunctDeVizitare> ServicePunctDeVizitare::getAll()
{
	return this->repo_punct_de_vizitare.getAll();
}

//adauga un nou punct de vizitare
//arunca exceptie daca exista deja un punct de vizitare cu id-ul dat
void ServicePunctDeVizitare::addPunctDeVizitare(int id, string nume)
{
	PunctDeVizitare p(id, nume);
	if (repo_punct_de_vizitare.findById(id) != -1)
		throw ServicePunctExceptie("Exista deja un punct de vizitare cu id-ul: " + to_string(id));
	this->repo_punct_de_vizitare.addElem(p);
}

//sterge un punct de vizitare existent
//arunca exceptie daca nu exista un punct de vizitare cu id-ul dat
void ServicePunctDeVizitare::deletePunctDeVizitare(int id)
{
	int size = repo_punct_de_vizitare.getSize();
	if (repo_punct_de_vizitare.findById(id) == -1)
		throw ServicePunctExceptie("Nu exista un punct de vizitare cu id-ul: " + to_string(id));

	for (int i = 0; i < size; i++)
	{
		vector<PunctDeVizitare> pct_vizitare = this->repo_punct_de_vizitare.getAll();
		if (pct_vizitare[i].getId() == id)
		{
			this->repo_punct_de_vizitare.deleteElem(pct_vizitare[i]);
			break;
		}
	}
}

//modifica un punct de vizitare cu id-ul dat
//arunca exceptie daca nu exista un punct de vizitare cu id-ul dat
void ServicePunctDeVizitare::updatePunctDeVizitare(int id, string nume_nou)
{
	int i = repo_punct_de_vizitare.findById(id);
	if (i == -1)
		throw ServicePunctExceptie("Nu exista un punct de vizitare cu id-ul: " + to_string(id));
	PunctDeVizitare new_pct(id, nume_nou);
	repo_punct_de_vizitare.updateElem(repo_punct_de_vizitare.getAll()[i], new_pct);
	
}

//cauta un punct de vizitare dupa id
//return: pozitia din vector a acestuia sau -1 daca nu se gaseste
int ServicePunctDeVizitare::findById(int id)
{
	return this->repo_punct_de_vizitare.findById(id);
}

