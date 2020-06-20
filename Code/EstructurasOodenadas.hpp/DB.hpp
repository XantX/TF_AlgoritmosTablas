#ifndef __DB_HPP__
#define __DB_HPP__
#include <iostream>
#include "ListaEnlazada.hpp"
#include "iterador.hpp"
#include "Tree.hpp"
#include "criterios.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
class DB
{
private:
    ifstream archivo;
    LLS DataB;
    string cadena;
    long long Columnas;
    long long filas;
    map<string,long long> ColumnasName;
    vector<Tree<LS>> ArbolesFilasIN;
    vector<Tree<string>> ArbolesColumIN;
    
    void NonbreColum();
public:
    DB();
    void IndexarFila(string);
    void IndexarColumna(string, int);
    vector<Tree<string>> GetVectorColumnas();
    vector<Tree<LS>> GetVectorFilas();
    
    map<string,long long> getMapa(){return ColumnasName;}
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
        Columnas = DataB[0].getSize();
        NonbreColum();

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
void DB::NonbreColum(){
     for (int i = 0; i < Columnas; i++)
    {
        ColumnasName[DataB[0][i]] = i;
    }
}
long long DB::getFilas(){
    return filas;
}
long long DB::getColumnas(){
    return Columnas;
    
}
void DB::IndexarFila(string columna){
    if(ColumnasName.count(columna)){
        ColumnasName[columna];
        Tree<LS> ArbolesFIlas(columna);
        ArbolesFIlas.setCriterio(CriterioMen);
        ArbolesFIlas.setImpresion(ImpriLS);

        Setcolum(ColumnasName[columna]);
        for (long long i = 1; i <filas; i++)
        {
            ArbolesFIlas.Add(DataB[i]);
        }
        ArbolesFilasIN.push_back(ArbolesFIlas);
    }else{
        cout<<"No existe esa columna";
    }
}
void DB::IndexarColumna(string columna,int Id){
    if(ColumnasName.count(columna)){
        Tree<string> ArbolColumna(DataB[Id][1]);
        ArbolColumna.setCriterio(CriterioMenS);
        ArbolColumna.setImpresion(printString);
        for (long long i = 2; i <Columnas; i++)
        {
            ArbolColumna.Add(DataB[Id][i]);
        }
        ArbolesColumIN.push_back(ArbolColumna);
    }else{
        cout<<"No existe esa columna";
    }
}
 vector<Tree<LS>> DB::GetVectorFilas(){
     return ArbolesFilasIN;
 }
 vector<Tree<string>> DB::GetVectorColumnas(){
     return ArbolesColumIN;
 }
DB::~DB()
{
}

#endif 