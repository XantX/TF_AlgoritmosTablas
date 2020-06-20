#ifndef __MENU_DB__
#define __MENU_DB__
#include <iostream>
#include <map>
#include <string>

#include "../TFAlgoritmos/Code/EstructurasOrdenadas/ListaEnlazada.hpp"
using namespace std;
typedef ListaEnlazada<string> LS;
class ClassMenuDB
{
private:
    
public:
    LS AddFilaM(vector<string>&);
    void AddCOlumnas(vector<string>&, map<string,long long>&);
    ClassMenuDB();
    ~ClassMenuDB();
};

ClassMenuDB::ClassMenuDB()
{
}
LS ClassMenuDB::AddFilaM(vector<string> &filasName){
    string Dato;
    LS NUEVAFILA;
    for (long long i = 0; i < filasName.size(); i++)
    {
        cout<<"Ingrese el dato de la columna "<<filasName[0]<<":"<<endl;
        cin>>Dato;
        NUEVAFILA.add(Dato);
        cin.ignore();
    }
    return NUEVAFILA;
}
void ClassMenuDB::AddCOlumnas(vector<string>& Names, map<string,long long>& NameAIndice){
    long long NumColumnas = 0;
    cout<<"Digite el numero de columnas que tendra la tabla :   ";
    cin>>NumColumnas;
    cin.ignore();
    string DAto;
    for (long long i = 0; i < NumColumnas; i++)
    {
        cout<<"Como se llama la columna "<<i<<":";
        cin>>DAto;
        while(NameAIndice.count(DAto)){
            cin.ignore();
            cout<<"Ya existe esa columna en la tabla.\nIndice:"<<NameAIndice[DAto]<<":\n";
            cout<<"Ingrese un nuevo valor:";
            cin>>DAto;
        }
        Names.push_back(DAto);
        NameAIndice[DAto] = i;
    }
    
}
ClassMenuDB::~ClassMenuDB()
{
}

#endif