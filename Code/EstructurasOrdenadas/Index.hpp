#ifndef __INDEX_HPP__
#define __INDEX_HPP__
#include <vector>
#include <iostream>
#include "Tree.hpp"
#include "ListaEnlazada.hpp"
#include "criterios.hpp"
#include <string>
#include <map>
using namespace std;
class Index
{
private:

    vector<Tree<LS>> ListaDeArboles;
    map<string,long long> IndiceDeArbol; 
public:
    Index();
    ~Index();
    void IndexarPorCriterioColumna(string,map<string,long long>);
    void SetCriterioTree(string, Tree<LS>&);
};

Index::Index()
{
}
void Index::SetCriterioTree(string Criterio, Tree<LS>&){
    
}
void Index::IndexarPorCriterioColumna(string Columna,map<string,long long>NombresDeColumnas){
    if(NombresDeColumnas.count(Columna)){//Existe esa columna?
        Tree<LS> ArbolNuevo(Columna);

    }else{
        cout<<"No existe esa columna";
    }
}

Index::~Index()
{
}

#endif