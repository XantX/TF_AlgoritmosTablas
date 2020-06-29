#ifndef __TABLASPRIN_HPP__
#define __TABLASPRIN_HPP__
#include "ClassManu.hpp"
#include "Tablamove.hpp"
class TablasPrincipal
{
private:
    ClassMenu MenuPrincipal;
    Tablamove TablaMenu;

    map<string, DB*> Tablas;
    string NombreDeArchivo();
public:
    
    void principal(bool&);
    void crearNewTabla();
    void ImportTabla();
    void Vertablas();
    void elegirTabla();
    TablasPrincipal();
    ~TablasPrincipal();
};
void TablasPrincipal::crearNewTabla(){
    string nombre;
    cin.ignore();
    do
    {
        cout<<"Como se llama la nueva tabla\n";
        getline(cin, nombre);
    } while (Tablas.count(nombre));

    DB* TablaNueva = new DB(nombre);
    TablaNueva->addCOlunmasName();
    Tablas[nombre] = TablaNueva;

}
 string TablasPrincipal::NombreDeArchivo(){
     string NombreArchivo;
     ifstream Archivo;
     cin.ignore();
     do
     {
        cout<<"Parar leer un archivo coloquelo en la carpeta Archivos\n";
        cout<<"Dime el nombre de el archivo \n";
        getline(cin, NombreArchivo);
        Archivo.open("Archivos/"+ NombreArchivo);
     } while (Archivo.fail());
     Archivo.close();
     return NombreArchivo;
}
void TablasPrincipal::ImportTabla(){
    
    string Archivo = NombreDeArchivo();
    DB* TablaNueva = new DB(Archivo);
    TablaNueva->reading("Archivos/"+ Archivo);
    Tablas[Archivo] = TablaNueva;
}
void TablasPrincipal::Vertablas(){
    cout<<"Las tablas que hay son:\n";
    for (auto &i : Tablas)
    {
        cout<<i.first<<"\n";
    }
}
 void TablasPrincipal::elegirTabla(){
     Vertablas();
     string NombreTabla;
     cin.ignore();
     do
     {
         cout<<"Cual de las tablas quiere elegir\n";
         cout<<"Escriba el nombre de la tabla:\n";
         cout<<"------>";
         getline(cin,NombreTabla);
     } while (!Tablas.count(NombreTabla));
     TablaMenu.MenuTabla(Tablas[NombreTabla],MenuPrincipal);
}
void TablasPrincipal::principal(bool& estado){
    int opcion = MenuPrincipal.Principal();
    switch (opcion)
    {
    case 1:
        crearNewTabla();
        break;
    case 2:
        ImportTabla();
        break;
    case 3:
        Vertablas();
        break;
    case 4:
        elegirTabla();
        break;
    case 5:
        estado = false;
        break;
    default:
        break;
    }
        
    
}

TablasPrincipal::TablasPrincipal()
{
}

TablasPrincipal::~TablasPrincipal()
{
}
#endif