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

typedef function<bool(LS,LS)> Criterio;
class Index
{
private:

    vector<Tree<LS>> ListaDeArboles;
    map<string,long long> IndiceDeArbol;
    map<string, Criterio> MapaDeCriterios;
public:
    Index();
    ~Index();
    void IndexarPorCriterioColumna(map<string,long long>, LLS&);
    void SetCriterioTree(Tree<LS>&);
    void StarIndex(long long);
    vector<Tree<LS>> GetARREGLO();
};

Index::Index()
{
    MapaDeCriterios["CriterioMayor"] = CriterioMa;
    MapaDeCriterios["CriterioMenor"] = CriterioMen;
}
vector<Tree<LS>> Index::GetARREGLO(){
    return ListaDeArboles;
}
void Index::SetCriterioTree(Tree<LS>& arbolito){
    string criterio;
    
    do
    {
        for (auto i : MapaDeCriterios)
        {
        //imprime todos los criterios 
        cout<<i.first<<endl;
        }
        cout<<"Escriba el criterio:\n";
        cout<<"----->";
        cin>>criterio;   
        cin.ignore();
    } while (!MapaDeCriterios.count(criterio));
    arbolito.setCriterio(MapaDeCriterios[criterio]);
    
    arbolito.setImpresion(ImpriLS);
}

void Index::IndexarPorCriterioColumna(map<string,long long>NombresDeColumnas, LLS& DataB){
    string Columna;
    do{//Existe esa columna?
        
        cout<<"Dime la columna por la que quiere indexar:";
        cin>>Columna;
        cin.ignore();
    }while(!NombresDeColumnas.count(Columna));

    Tree<LS> ArbolNuevo(Columna);
    cout<<"Dime el criterio con el que quiere indexar:\n";
    SetCriterioTree(ArbolNuevo);
    Setcolum(NombresDeColumnas[Columna]);
    for (long long i = 1; i < DataB.getSize(); i++)
    {
        ArbolNuevo.Add(DataB[i]);
    }
    ListaDeArboles.push_back(ArbolNuevo);
}

Index::~Index()
{
}

#endif