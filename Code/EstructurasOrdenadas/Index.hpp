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

typedef function<bool(LS&,LS&)> Criterio;
typedef function<bool(LS&,string)> Criteriostring;
class Index
{
private:

    vector<Tree<LS>> ListaDeArboles;
    map<string,long long> IndiceDeArbol;
    map<string, Criterio> MapaDeCriteriosNum;
    map<string, Criteriostring> MapaDeCriteriosString;
public:
    Index();
    ~Index();
    void IndexarPorCriterioColumna(map<string,long long>, LLS&);
    void SetCriterioTree(Tree<LS>&);
    void StarIndex(long long);
    void VerCriterios(Tree<LS>&);
    int ElegirCriterios();
    vector<Tree<LS>> GetARREGLO();
};

Index::Index()
{
    //criterios para numeros
    MapaDeCriteriosNum["CriterioMayor"] = CriterioMa;
    MapaDeCriteriosNum["CriterioMenor"] = CriterioMen;
    //criterios para letras
    MapaDeCriteriosString["ComienzaCon"] = IniciaCon;
}
vector<Tree<LS>> Index::GetARREGLO(){
    return ListaDeArboles;
}
int Index::ElegirCriterios(){
    int opcion;
    do
    {
        cout<<"Elige un tipo de criterio:\n";
        cout<<"1) CriteriosNumericos\n";
        cout<<"2) CriteriosStrings\n";
        cout<<"Escriba el numero de la opcion";
        cout<<"----->";
        cin>>opcion;
    } while (opcion <=0 || opcion > 2);
    return opcion;
}
void Index::VerCriterios(Tree<LS>& arbol){
    string criterio;
    switch (ElegirCriterios())
    {
    case 1:
        do
        {
            cout<<"Criterios:\n";
            cout<<"\n";
            for(auto i: MapaDeCriteriosNum){
            cout<<i.first<<"\n";
            }
            cout<<"Escriba el criterio:\n";
            cout<<"----->";
            cin>>criterio;   
            cin.ignore();
        } while (!MapaDeCriteriosNum.count(criterio));

        arbol.setCriterio(MapaDeCriteriosNum[criterio]);
        break;
    case 2:
        
        do
        {
            cout<<"Criterios:\n";
            cout<<"\n";
            for(auto e: MapaDeCriteriosString){
            cout<<e.first<<"\n";
            }
            cout<<"Escriba el criterio:\n";
            cout<<"----->";
            cin>>criterio;   
            cin.ignore(); 
        } while (!MapaDeCriteriosString.count(criterio));
        arbol.setCriterio(MapaDeCriteriosString[criterio]);
        break;
    default:
        break;
    }
        
}
void Index::SetCriterioTree(Tree<LS>& arbolito){
    
    VerCriterios(arbolito);
    arbolito.setImpresion(ImpriLS);
}

void Index::IndexarPorCriterioColumna(map<string,long long>NombresDeColumnas, LLS& DataB){
    string Columna;
    do{//Existe esa columna?
        
        cout<<"Dime la columna por la que quiere indexar:";
        cin>>Columna;
        cin.ignore();
    }while(!NombresDeColumnas.count(Columna));

    Tree<LS> ArbolNuevo(Columna, NombresDeColumnas[Columna]);
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