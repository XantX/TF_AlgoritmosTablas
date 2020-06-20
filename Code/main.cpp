#include "Estructuras/MiniDB.h"
#include "Menu/ClassManu.hpp"

int main()
{
    ClassMenu Menu;
    MiniDB dbupc;
    //dbupc.reading("Archivos/covid.csv", 's');
    //dbupc.ShowValues();
    Menu.Principal();
    Menu.Tabla();
    return 0;
}