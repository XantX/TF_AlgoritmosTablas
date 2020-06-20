#ifndef __MENU__HPP__
#define __MENU__HPP__
#include <iostream>
using namespace std;
class ClassMenu
{
private:

public:
    ClassMenu();
    ~ClassMenu();
    void Principal();
    void Tabla();
};

ClassMenu::ClassMenu()
{
}
void ClassMenu::Tabla(){
 cout<<"\t\t\tTabla\n";
 cout<<"\t 1) Ordenar columna por\n";
 cout<<"\t 2) Ordenar por\n";
 cout<<"\t 3) Buscar\n";
 cout<<"\t 4) Exportar tabla a archivo";
 cout<<"\t\t Opcion-->";
}
void ClassMenu::Principal(){
    cout<<"\t\t\tMenu Principal\n";
    cout<<"\t 1) Crear Nueva Tabla\n";
    cout<<"\t 2) Ingresar tabla de archivo\n";
    cout<<"\t 3) Ver lista de tablas existentes\n";
    cout<<"\t 4) Elegir una tabla\n";
    cout<<"\t\t Opcion-->";
}
ClassMenu::~ClassMenu()
{
}





#endif __MENU__HPP__