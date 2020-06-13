#ifndef __ARBOLESINDEX_HPP__
#define __ARBOLESINDEX_HPP__
#include <iostream>
#include <map>
#include <vector>
#include "Tree.hpp"
#include "DB.hpp"
using namespace std;
template<typename T>
class Indexar
{
private:
long long ArbolesCant;
map<string, map<string,Tree<T>*>> TreesIndexados;
    
map<string, long long> FilaID;
public:
    Indexar(DB&);
    ~Indexar();
    map<string, long long> GetMAp(); 
    
};

template<typename T>
Indexar<T>::Indexar(DB &database)
{
    ArbolesCant = database.getColumnas();
    string FilaName;
    for (long long i = 0; i < ArbolesCant; i++)
    {
        FilaName = database.GetDB()[0][i];
        if (FilaID.count(FilaName)){
            cout<<"Hay una fila repetida, renombre la "<< FilaName<<" fila y vuelve a ingresar la base de datos.";
        }else{
            FilaID[FilaName] = i;
        }
    }
}

template<typename T>
map<string, long long>Indexar <T>::GetMAp(){
    return FilaID;
}
template<typename T>
Indexar<T>::~Indexar()
{
}

#endif