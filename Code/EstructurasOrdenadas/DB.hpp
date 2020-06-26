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
#include "Archivos.hpp"
#include <map>
#include "ClassMenuDB.hpp"
#include "Index.hpp"
using namespace std;
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
class DB
{
private:
    //Menu de indexacion
    Index Arboles;
 
    //Menu controlador
    ClassMenuDB Menu;
    //Archivo de lectura
    ifstream archivo;
    
    Archivos fichero;
    //Base de datos---tabla
    LLS DataB;
    //
    string cadena;
    //columnas y filas de la tabla
    long long Columnas;
    long long filas;
    //nombre de las columnas con indice
    map<string, long long> ColumnasName;
    //LLena los nombres de las columnas 
    void NonbreColum();
    //Solo nombre de las columnas en orden
    vector<string> Columanss;


public:
    DB();
    //Metodos para setar el nombre de las columnas y agregar una fila
    void addFila();
    void addCOlunmasName();
    
    //retorna el nombre de las columnas
    map<string, long long> getMapa();
    vector<string> getColumss();
    //retorna Toda la tabla
    LLS& GetDB();
    //Obtiene la cantidad de filas y columnas
    long long getFilas();
    long long getColumnas();
    //TODO: pribando filas
    void setfilas(long long a);
    void setcolumnas(long long a);
    //TODO: aca termina
    //Leer de un archivo CSV
    void reading(string);

    //INdexar
    void INDEXAR();
    //Retornar arreglo de arboles
    vector<Tree<LS>> Getarboles();
    ~DB();
};

DB::DB()
{

}
long long DB::getFilas() {
    return filas;
}
long long DB::getColumnas() {
    return Columnas;

}

map<string, long long> DB::getMapa() { return ColumnasName; }

vector<string> DB::getColumss() {
    return Columanss;
}
LLS& DB::GetDB() {
    return DataB;
}
void DB::INDEXAR() {
    Arboles.IndexarPorCriterioColumna(ColumnasName, DataB);
}
vector<Tree<LS>> DB::Getarboles() {
    return Arboles.GetARREGLO();
}



void DB::reading(string nombre){
 
    fichero.reading(nombre, DataB);

    filas = DataB.getSize();
    Columnas = DataB[0].getSize();
    NonbreColum();
}

void DB::NonbreColum() {
    string nombres;
    for (int i = 0; i < Columnas; i++)
    {
        nombres = DataB[0][i];
        ColumnasName[DataB[0][i]] = i;

        Columanss.push_back(nombres);
    }
}

void DB::addFila() {
    DataB.add(Menu.AddFilaM(Columanss));
}
void DB::addCOlunmasName() {
    DataB.add(Menu.AddCOlumnas(Columanss, ColumnasName));
}

DB::~DB()
{
}

//TODO: Probando filas y columnas
void DB::setfilas(long long a) {
    a = filas;
}
void DB::setcolumnas(long long a) {
    a = Columnas;
}


#endif 