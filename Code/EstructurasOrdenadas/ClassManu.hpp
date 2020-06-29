#ifndef __MENU__HPP__
#define __MENU__HPP__
#include <iostream>
#include "DB.hpp"
using namespace std;
class ClassMenu
{
private:

public:
    ClassMenu();
    ~ClassMenu();
    int Principal();
    int Tabla(DB*&);
    
};

ClassMenu::ClassMenu()
{
}
int ClassMenu::Tabla(DB*& Tabla){
    int opcion;
 do
 {
     system("cls");
    cout<<"\n";
    cout<<"Tabla: "<<Tabla->getNameTabla()<<"\n";
    cout<<"\n";
    cout<<"\t 1) Filtrar\n";
    cout<<"\t 2) Exportar tabla a archivo\n";
    cout<<"\t 3) Agregar Fila\n";
    cout<<"\t 4) Salir de la tabla\n";
    cout<<"\t\t Opcion-->";
    cin>>opcion;
 } while (opcion < 1 || opcion > 4);
 return opcion;
}
int ClassMenu::Principal(){
     int opcion;
    do
    {
        system("cls");
        cout<<"\n";
        cout<<"\t\t\tMenu Principal\n";
        cout<<"\t 1) Crear Nueva Tabla\n";
        cout<<"\t 2) Importar tabla de archivo\n";
        cout<<"\t 3) Ver lista de tablas existentes\n";
        cout<<"\t 4) Elegir una tabla\n";
        cout<<"\t 5) Salir\n";
        cout<<"\t\t Opcion-->";
        cin>>opcion;
    } while (opcion < 1 || opcion > 5);
    return opcion;
}
ClassMenu::~ClassMenu()
{
}





#endif// __MENU__HPP__