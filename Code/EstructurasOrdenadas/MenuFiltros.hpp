#ifndef __MENU_FILTROS__
#define __MENU_FILTROS__
#include <iostream>
#include "Index.hpp"
#include <map>
using namespace std;
class MenuFiltros
{
private:
    
public:
    void verCOlumnas(map<string,ArrTree>);
    string elegirColumna(map<string,ArrTree>);
    void dividirCriterios(int,string,string,map<string,ArrTree>);
    int opcionesDeNumeros();
    void opcionesDeMenores();
    MenuFiltros();
    ~MenuFiltros();
};

MenuFiltros::MenuFiltros()
{
}
void MenuFiltros::verCOlumnas(map<string,ArrTree> alltrees){
    cout<<"\tColumnas de la tabla\n";
    cout<<"\t\t";
    for (auto &i : alltrees)
    {
        cout<<i.first<<" ";
    }
    cout<<"\n";
}
string MenuFiltros::elegirColumna(map<string,ArrTree> AllTrees){
    string Fcomlum;
    cin.ignore();
    do
    {
        verCOlumnas(AllTrees);
        cout<<"Dime que columna quieres filtrar\n";
        getline(cin,Fcomlum);    
    } while (!AllTrees.count(Fcomlum));
    return Fcomlum;
}
int MenuFiltros::opcionesDeNumeros(){
    int opcion;
    cin.ignore();
    do
    {
        cout<<"Dime que opcion muestro:\n";
        cout<<"1) listar segun criterio.\n";
        cout<<"2) Buscar todas las concurrencias de un criterio\n";
        cout<<"Escriba el numero de la opcion-->";
        cin>>opcion;
    } while (opcion<1 || opcion>2);
    return opcion;
}
void MenuFiltros::dividirCriterios(int op, string cCol,string criterio,map<string,ArrTree> todo){
    if(criterio == "Ordenamiento Mayor"){
        int OpcM = opcionesDeNumeros();
        if(OpcM == 1){//si pone "listar segun criterio"
            todo[cCol][op - 1].InOrder();
        }else{//caso contrario deberá buscar todas las concurrencias 
            string criter;
            cin.ignore();
            cout<<"Dime que criterio debo buscar:";
            getline(cin,criter);
            todo[cCol][op - 1].Find(criter);
        }
    }else if(criterio == "Ordenamiento Menor"){
        int OpcM = opcionesDeNumeros();
        if(OpcM == 1){
            todo[cCol][op - 1].InOrder();
        }else{
            string criter;
            cin.ignore();
            cout<<"Dime que criterio debo buscar:";
            getline(cin,criter);
            todo[cCol][op - 1].Find(criter);
        }
    }else{
        string criter;
        cin.ignore();
        cout<<"Dime que caracter debo buscar:";
        getline(cin,criter);
        todo[cCol][op - 1].Find(criter);
    }
}
MenuFiltros::~MenuFiltros()
{
}
#endif