#ifndef __FILTRO_HPP__
#define __FILTRO_HPP__
#include<iostream>
#include <vector>
#include "Tree.hpp"
#include "MenuFiltros.hpp"
using namespace std;
class Filtro
{
private:
    MenuFiltros MenuF;
public:
    void ElegirFiltros(map<string,ArrTree>);
    Filtro();
    ~Filtro();
};

Filtro::Filtro()
{
}
void Filtro::ElegirFiltros(map<string,ArrTree> todo){
    string Col = MenuF.elegirColumna(todo);
    int opcion;
    do
    {
        for (long long i = 0; i < todo[Col].size() ; i++)
        {
        cout<<i+1<<") "<<todo[Col][i].GetNameTrees()<<"\n"; 
        }
        cin>>opcion;   
    } while (opcion<1 || opcion>2);
    string criter;
    cin.ignore();
    cout<<"Dime el criterio:";
    getline(cin,criter);
    todo[Col][opcion - 1].Find(criter);
}
Filtro::~Filtro()
{
}

#endif