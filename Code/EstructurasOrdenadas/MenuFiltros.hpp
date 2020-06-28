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
MenuFiltros::~MenuFiltros()
{
}
#endif