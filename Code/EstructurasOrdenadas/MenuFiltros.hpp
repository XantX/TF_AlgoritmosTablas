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
    void opcionesDeMayores();
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

void MenuFiltros::dividirCriterios(int op, string cCol,string criterio,map<string,ArrTree> todo){
    if(criterio == "Mayor"){
        todo[cCol][op - 1].InOrder();

    }else if(criterio == "Menor"){
        todo[cCol][op - 1].InOrder();

    }else{
        string criter;
        cin.ignore();
        cout<<"Dime el criterio:";
        getline(cin,criter);
        todo[cCol][op - 1].Find(criter);
    }
}
MenuFiltros::~MenuFiltros()
{
}
#endif