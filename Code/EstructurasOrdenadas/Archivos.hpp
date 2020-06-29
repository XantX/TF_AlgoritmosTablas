#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__
#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include "Index.hpp"
#include "ListaEnlazada.hpp"
#include "MenuExport.hpp"

using namespace std;

class Archivos {
private:
    MenuExport MenuSeparador;
    string nameExtencion;
    string separador;
    ifstream archivo;
    string cadena;
public:
  
    Archivos() {}
    
    void reading(string nombre, LLS &e, Index& Indexador) {
        nameExtencion = nombre.substr(nombre.find(".") + 1);
        separador = MenuSeparador.pedirSeparadordecampos(nameExtencion);//obtiene el separador
        archivo.open(nombre);
        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            divideField(ss, e, Indexador,separador[0]);
        }

        
    }
    void divideField(istream& registro, LLS &e, Index &Inde,char sepa) {
        ListaEnlazada<string>fila;
        string tmp;
        while (getline(registro, tmp, sepa))//Criterio Separador
        {
            fila.add(tmp);
        }
        e.add(fila);

        if(e.getSize() == 1){
            Inde.IndexarColumnas(fila);
        }else{
            cout<<"Indexando...";
            Inde.update(fila);
        }
    }

};


#endif // !__ARCHIVOS_H__
