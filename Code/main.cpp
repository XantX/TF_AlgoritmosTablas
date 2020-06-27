#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"
#include "EstructurasOrdenadas/ListaEnlazada.hpp"
#include <map>


int main()
{
    DB Database;

    Database.reading("Archivos/Alumnos.csv");

    Database.INDEXAR();

    Database.Getarboles()[0].InOrder();
    return 0;
}