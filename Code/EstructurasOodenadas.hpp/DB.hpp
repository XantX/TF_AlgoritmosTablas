#ifndef __DB_HPP__
#define __DB_HPP__
#include <iostream>
#include "ListaEnlazada.hpp"
#include "iterador.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
typedef ListaEnlazada<ListaEnlazada<string>> LLS;
class DB
{
private:
    ifstream archivo;
    LLS DataB;
    string cadena;
    long long Columnas;
    long long filas;

public:
    DB();
    
    long long GetColSize(){
        return DataB.getSize();
    }
    LLS& GetDB(){
        return DataB;
    }
    long long getFilas();
    long long getColumnas();
     void reading(string nombre)
    {
        archivo.open(nombre);
        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            divideField(ss);
        }

        filas = DataB.getSize();
        Columnas = DataB[0].getSize() ;
    }

    void divideField(istream &registro){
       ListaEnlazada<string>fila;
        string tmp;
        while (getline(registro,tmp,';'))
        {
           fila.add(tmp);
        }
        DataB.add(fila);
    }

    ~DB();
};

DB::DB()
{
    
}
long long DB::getFilas(){
    return filas;
}
long long DB::getColumnas(){
    return Columnas;
}
DB::~DB()
{
}

#endif 