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
string MenuFiltros::elegirColumna(map<string,ArrTree> AllTrees){
    string Fcomlum;
    cin.ignore();
    do
    {
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
        cin>>opcion;
    } while (opcion<1 || opcion>2);
    return opcion;
}
void MenuFiltros::dividirCriterios(int op, string cCol,string criterio,map<string,ArrTree> todo){
    if(criterio == "Mayor"){
        int OpcM = opcionesDeNumeros();
        if(OpcM == 1){
            todo[cCol][op - 1].InOrder();
        }else{
            string criter;
            cin.ignore();
            cout<<"Dime el criterio:";
            getline(cin,criter);
            todo[cCol][op - 1].Find(criter);
        }
    }else if(criterio == "Menor"){
        int OpcM = opcionesDeNumeros();
        if(OpcM == 1){
            todo[cCol][op - 1].InOrder();
        }else{
            string criter;
            cin.ignore();
            cout<<"Dime el criterio:";
            getline(cin,criter);
            todo[cCol][op - 1].Find(criter);
        }
    }else{
        string criter;
        cin.ignore();
        cout<<"Dime con que criterio inicia:";
        getline(cin,criter);
        todo[cCol][op - 1].Find(criter);
    }
}
MenuFiltros::~MenuFiltros()
{
}
#endif