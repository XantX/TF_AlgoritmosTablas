#ifndef __INDEX_HPP__
#define __INDEX_HPP__
#include <vector>
#include <iostream>
#include "Tree.hpp"
#include "ListaEnlazada.hpp"
#include "criterios.hpp"
#include <string>
#include <map>
#include "CriteriosDeBusqueda.hpp"
using namespace std;

typedef function<bool(LS&,LS&)> Criterio;
typedef function<bool(LS&,string)> Criteriostring;
typedef vector<Tree<LS>> ArrTree;
class Index //TODO: esta clase tiene los arboles para hacer lo filtros y tal. Indexa la tabla por diferentes criterios
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

ArrTree Index::getArboles(){ //retorna el arbol de la columna cuyo nombre pide 
    string C;
    cin.ignore();
    do
    {
        cout<<"De que columna:\n";
        getline(cin,C);
    } while(!MapaDeArbolXColumnas.count(C));
    return MapaDeArbolXColumnas[C];
}
map<string, ArrTree> Index::getAll(){//retorna todos los arboles con el mismo nombre
    return MapaDeArbolXColumnas;
}
int Index::setNumberOrStrings(string nombre){//funcion para establecer si el dato es de tipo entero o string
    int opcion;
    cout<<"\tCriterios para indexar\n";
    do
    {
        cout<<"La columna "<<nombre<<" es:\n";
        cout<<"Escriba el numero de la opcion\n";
        cout<<"1) Numerico\n";
        cout<<"2) palabras\n";
        cout<<"---->";
        cin>>opcion;
    } while (opcion <=0 || opcion >2);
    return opcion;
}
void Index::creacionDeArboles(string name, long long number){
    int opcion = setNumberOrStrings(name);
    if(opcion == 1){
        //TODO: uno ordena el abrol con criterio mayor y otro con el menor
        //TODO: con el objetivo de que se muestre de mayor a menor o a revez
        vector<Tree<LS>> NumMayoryMenor;
        Tree<LS> NuevoMa("Mayor", number);
        NuevoMa.setCriterio(CriterioMa);
        NuevoMa.setImpresion(ImpriLS);
        NuevoMa.setCriterioB(CriteriBMayor);
        Tree<LS> NuevoMe("Menor", number);
        NuevoMe.setCriterio(CriterioMen);
        NuevoMe.setImpresion(ImpriLS);
        NuevoMe.setCriterioB(CriteriBMenor);
        
       NumMayoryMenor.push_back(NuevoMa);
       NumMayoryMenor.push_back(NuevoMe);
       MapaDeArbolXColumnas[name] = NumMayoryMenor;

    }else if(opcion == 2){
        //TODO: ordena con inicia con y finaliza con 
        //TODO: a la hora de mostrar muestra inicia con o finaliza con 
       ArrTree AlphaINIyFIN;
        Tree<LS> NuevoINI("IniCon", number);
        NuevoINI.setCriterio(AlphebeticoINI);
        NuevoINI.setImpresion(ImpriLS);
        NuevoINI.setCriterioB(CriterioBAlphaIni);
        Tree<LS> NuevoFIN("FinCon", number);
        NuevoFIN.setCriterio(AlphebeticoFIN);
        NuevoFIN.setImpresion(ImpriLS);
        NuevoFIN.setCriterioB(CriterioBAlphaFIN);

        AlphaINIyFIN.push_back(NuevoINI);
        AlphaINIyFIN.push_back(NuevoFIN);
        MapaDeArbolXColumnas[name] = AlphaINIyFIN;

    }
}
void Index::update(LS& ListaAINdex){//indexa lista al arbol
    
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
       nombre = NombresDeColumnas[i];//obtiene el valor de la lista, empezando desde e principio 
       creacionDeArboles(nombre,i);//crea arboles
    }
}

Index::~Index()
{
}

#endif