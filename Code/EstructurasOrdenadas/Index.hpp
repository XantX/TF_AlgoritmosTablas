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
typedef vector<Tree<LS>> ArrTree;
class Index
{
private:

    
    
    map<string, Criterio> MapaDeCriteriosNum;
    map<string, Criterio> MapaDeCriteriosString;

    map<string, ArrTree> MapaDeArbolXColumnas;

public:
    Index();
    ~Index();
    void IndexarColumnas(LS&);
    void update(LS&);
    int setNumberOrStrings(string);
    void creacionDeArboles(string,long long);
    ArrTree getArboles();
    map<string, ArrTree> getAll();
};

Index::Index()
{
    //criterios para numeros
    MapaDeCriteriosNum["CriterioMayor"] = CriterioMa;
    MapaDeCriteriosNum["CriterioMenor"] = CriterioMen;
    //criterios para letras
    MapaDeCriteriosString["ComienzaCon"] = AlphebeticoINI;
    MapaDeCriteriosString["TerminaCon"] = AlphebeticoFIN;
}

ArrTree Index::getArboles(){
    string C;
    cout<<"De que columna:\n";
    cin>>C;
    return MapaDeArbolXColumnas[C];
}
map<string, ArrTree> Index::getAll(){
    return MapaDeArbolXColumnas;
}
int Index::setNumberOrStrings(string nombre){
    int opcion;
    do
    {
        cout<<"La columna "<<nombre<<" es:\n";
        cout<<"1) Numerico\n";
        cout<<"2) palabras\n";
        cin>>opcion;
    } while (opcion <=0 || opcion >2);
    return opcion;
}
void Index::creacionDeArboles(string name, long long number){
    int opcion = setNumberOrStrings(name);
    if(opcion == 1){
        vector<Tree<LS>> NumMayoryMenor;
        Tree<LS> NuevoMa(name, number);
        NuevoMa.setCriterio(CriterioMa);
        NuevoMa.setImpresion(ImpriLS);
        Tree<LS> NuevoMe(name, number);
        NuevoMe.setCriterio(CriterioMen);
        NuevoMe.setImpresion(ImpriLS);
        
       NumMayoryMenor.push_back(NuevoMa);
       NumMayoryMenor.push_back(NuevoMe);
       MapaDeArbolXColumnas[name] = NumMayoryMenor;

    }else if(opcion == 2){
       ArrTree AlphaINIyFIN;
        Tree<LS> NuevoINI(name, number);
        NuevoINI.setCriterio(AlphebeticoINI);
        NuevoINI.setImpresion(ImpriLS);
        Tree<LS> NuevoFIN(name, number);
        NuevoFIN.setCriterio(AlphebeticoFIN);
        NuevoFIN.setImpresion(ImpriLS);

        AlphaINIyFIN.push_back(NuevoINI);
        AlphaINIyFIN.push_back(NuevoFIN);
        MapaDeArbolXColumnas[name] = AlphaINIyFIN;

    }
}
void Index::update(LS& ListaAINdex){
    
    for (auto &i : MapaDeArbolXColumnas)
    {
        for (long long j = 0; j < i.second.size(); j++)
        {
            i.second[j].Add(ListaAINdex);
        }
    }
    
}
void Index::IndexarColumnas(LS& NombresDeColumnas){
    string nombre;
    for(long long i = 0; i < NombresDeColumnas.getSize();i++){
       nombre = NombresDeColumnas[i];
       creacionDeArboles(nombre,i);
    }
}

Index::~Index()
{
}

#endif