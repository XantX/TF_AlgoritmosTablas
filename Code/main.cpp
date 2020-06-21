#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"

int main()
{
    ClassMenu Menu;
    DB database;

    database.addCOlunmasName();

    database.GetDB()[0].ShowAll(printString);
    
    return 0;
}