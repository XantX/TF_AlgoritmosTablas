#ifndef __EXPORT_HPP__
#define __EXPORT_HPP__
#include <fstream>
#include <string>
#include "ListaEnlazada.hpp"
#include "MenuExport.hpp"
#include "iterador.hpp"
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
using namespace std;

class Export
{
private:
    MenuExport opcions;
    ofstream Archivo;
    string ArchNameComplete;
    string extencion;
    string separador;
    iterador<LS> it;
    iterador<string> it2;
public:
    Export(){}
    void exportOn(string name,LLS& DataB){
        nombreArch(name);
        Archivo.open("Archivos/"+ArchNameComplete,ios::trunc);
        //trunc: significa que cuando se abre el archivo, el contenido antiguo se elimina inmediatamente.
        it.setLista(DataB);//la establesco para poder usar los operadores sobrecargados
        for (long long i = 0; i < DataB.getSize(); i++)
        {
            it2.setLista(it.it->data);//establesco otro iterador para usar los operadores, uno para la fila y otro para columnas
            for (long long j = 0; j < DataB[0].getSize(); j++)
            {
                Archivo<< it2.it->data;
                if(j<DataB[0].getSize()-1){
                    Archivo<<separador;
                }
                it2++;
            }
            Archivo<<"\n";
            it++;
        }
        
        Archivo.close();
    }
    void nombreArch(string name){
        if(_Format(name)){//si se sabe a que formato exportar
            extencion = name.substr(name.find(".") + 1);//estrae lo que etsa despues del .
            separador = opcions.pedirSeparadordecampos(extencion);//pide tipo de separador
            ArchNameComplete = name;
        }else{
            extencion = opcions.pedirExtencion();//le pido que dijite una extension
            separador = opcions.pedirSeparadordecampos(extencion);//le pido que dijiste tipo de seprador
            ArchNameComplete = name + "." + extencion;
        }
    }
    bool _Format(string name)
    {
        if (name.find(".") != string::npos)
        {
           return true;
        }
        else
        {
           return false;
        }
    }
    
};
#endif // !__EXPORT_HPP__