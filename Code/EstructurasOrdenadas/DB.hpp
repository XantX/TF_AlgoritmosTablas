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
#include "ClassMenuDB.hpp"
using namespace std;
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
class DB
{
private:
    //Menu controlador
    ClassMenuDB Menu;
    //Archivo de lectura
    ifstream archivo;
    //Base de datos---tabla
    LLS DataB;
    //
    string cadena;
    //columnas y filas de la tabla
    long long Columnas;
    long long filas;
    //nombre de las columnas con indice
    map<string,long long> ColumnasName;
    //LLena los nombres de las columnas 
    void NonbreColum();
    //Solo nombre de las columnas en orden
    vector<string> Columanss;
    //Arboles para indexar
    vector<Tree<LS>> ArbolesFilasIN;
    vector<Tree<string>> ArbolesColumIN;
    
public:
    DB();
    //INdexaFilas
    void IndexarFila(string);
    void IndexarColumna(string, int);
    //Arreglos de arboles indexados
    vector<Tree<string>> GetVectorColumnas();
    vector<Tree<LS>> GetVectorFilas();
    //Metodos para setar el nombre de las columnas y agregar una fila
    void addFila();
    void addCOlunmasName();
    //retorna el nombre de las columnas
    map<string,long long> getMapa();
    vector<string> getColumss();
    //retorna Toda la tabla
    LLS& GetDB();
    //Obtiene la cantidad de filas y columnas
    long long getFilas();
    long long getColumnas();
    //Leer de un archivo CSV
    void reading(string );
    void divideField(istream &);

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
map<string,long long> DB::getMapa(){return ColumnasName;}

vector<string> DB::getColumss(){
    return Columanss;
}
LLS& DB::GetDB(){
    return DataB;
}
vector<Tree<LS>> DB::GetVectorFilas(){
     return ArbolesFilasIN;
 }
void DB::reading(string nombre){
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
void DB::divideField(istream &registro){
ListaEnlazada<string>fila;
        string tmp;
        while (getline(registro,tmp,';'))
        {
           fila.add(tmp);
        }
        DataB.add(fila);
}
void DB::NonbreColum(){
    string nombres;
     for (int i = 0; i < Columnas; i++)
    {
        nombres = DataB[0][i];
        ColumnasName[DataB[0][i]] = i;
        
        Columanss.push_back(nombres);
    }
}
 vector<Tree<string>> DB::GetVectorColumnas(){
     return ArbolesColumIN;
 }

 void DB::addFila(){
    DataB.add(Menu.AddFilaM(Columanss));
 }
 void DB::addCOlunmasName(){
     DataB.add(Menu.AddCOlumnas(Columanss,ColumnasName));
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
 

DB::~DB()
{
}

#endif 