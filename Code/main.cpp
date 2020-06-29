#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"
#include "EstructurasOrdenadas/ListaEnlazada.hpp"
#include "EstructurasOrdenadas/TablasPrincipal.hpp"
#include <string>

#include <map>
//#include "EstructurasOrdenadas/Tree.hpp"

int main()
{  
   TablasPrincipal nuevas;
   bool estado = true;
   while (estado)
   {
      nuevas.principal(estado);   
   }
   
   return 0;
}