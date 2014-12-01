#include "../../header/grafo/Vertice.h"

Vertice::Vertice()
{
    this->adjacenciaList = new OrderedList<Adjacencia>();
}

Vertice::~Vertice()
{
    delete this->adjacenciaList;
}

void Vertice::setAdjInsertType(InsertType type)
{
    this->adjInsertType = type;
}

Adjacencia* Vertice::getAdjacencia(int idVertice2)
{
    return this->adjacenciaList->getNodeInfo(idVertice2);
}

float Vertice::getWeight()
{
    return this->weight;
}

void Vertice::setWeight(float weight)
{
    this->weight = weight;
}

int Vertice::getGrau()
{
    return this->adjacenciaList->getLength();
}

void Vertice::addAdjacencia(int idVertice1, int idVertice2, float weight)
{
    if(!existsAdjacencia(idVertice2))
    {
        this->adjacenciaList->insert(idVertice2, weight, new Adjacencia(idVertice1, idVertice2, weight), this->adjInsertType);
    }
    else
    {
        cout << "[ Erro ]: Adjac�ncia j� existe!" << endl;
    }
}

void Vertice::removeAdjacencia(int idVertice2)
{
    this->adjacenciaList->remove(idVertice2, this->adjInsertType);
}

bool Vertice::existsAdjacencia(int idVertice2)
{
    return (this->getAdjacencia(idVertice2) != NULL);
}

OrderedList<Adjacencia>* Vertice::getAdjacenciaList()
{
    return this->adjacenciaList;
}