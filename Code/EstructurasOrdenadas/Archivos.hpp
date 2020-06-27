#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__
#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include "ListaEnlazada.hpp"

using namespace std;

class Archivos {
private:
    string name;
    ifstream archivo;
  
    string cadena;
    
    
public:
  
    Archivos() {}

    void reading(string nombre, LLS &e) {
        archivo.open(nombre);

        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            divideField(ss, e);
        }

        
    }
    void divideField(istream& registro, LLS &e) {
        ListaEnlazada<string>fila;
        string tmp;
        while (getline(registro, tmp, ';'))
        {
            fila.add(tmp);
        }
        e.add(fila);
    }

};


#endif // !__ARCHIVOS_H__
