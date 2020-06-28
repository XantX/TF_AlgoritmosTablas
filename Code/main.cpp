#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"
#include "EstructurasOrdenadas/ListaEnlazada.hpp"
#include <map>
//#include "EstructurasOrdenadas/Tree.hpp"

int main()
{  
   DB Database;
   Database.reading("Archivos/Alumnos.csv");
   //Database.getarboles()[0].InOrder();
   Database.FiltroView();
   return 0;
}