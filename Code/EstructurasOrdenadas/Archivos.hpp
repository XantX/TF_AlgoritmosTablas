#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__
#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include "Index.hpp"
#include "ListaEnlazada.hpp"

using namespace std;

class Archivos {
private:
    string name;
    ifstream archivo;
    string cadena;
    
    
public:
  
    Archivos() {}

    void reading(string nombre, LLS &e, Index& Indexador) {
        archivo.open(nombre);

        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            divideField(ss, e, Indexador);
        }

        
    }
    void divideField(istream& registro, LLS &e, Index &Inde) {
        ListaEnlazada<string>fila;
        string tmp;
        while (getline(registro, tmp, ';'))
        {
            fila.add(tmp);
        }
        e.add(fila);

        if(e.getSize() == 1){
            Inde.IndexarColumnas(fila);
        }else{
            Inde.update(fila);
        }
    }

};


#endif // !__ARCHIVOS_H__
