#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"
#include "EstructurasOrdenadas/ListaEnlazada.hpp"
#include <map>
//#include "EstructurasOrdenadas/Tree.hpp"

int main()
{
    
    DB database;
    database.reading("Archivos/Alumnos.csv");

    database.addFila();

    database.getarboles()[0].InOrder();
    return 0;
}