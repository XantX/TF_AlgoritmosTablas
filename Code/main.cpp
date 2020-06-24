#include "EstructurasOrdenadas/DB.hpp"
#include "EstructurasOrdenadas/ClassManu.hpp"
#include "EstructurasOrdenadas/criterios.hpp"
#include "EstructurasOrdenadas/ListaEnlazada.hpp"
#include <map>
typedef ListaEnlazada<string>* LSP;
int main()
{
    map<string,function<bool(string,string)>> mapaDecriterios;
    Tree<string> Arbolstrings("Prueba");

    mapaDecriterios["Criterio 1"] = CriterioMenS;
    Arbolstrings.setCriterio(mapaDecriterios["Criterio 1"]);
    Arbolstrings.setImpresion(printString);
    Arbolstrings.Add("21");
    Arbolstrings.Add("43");
    Arbolstrings.Add("50");
    Arbolstrings.InOrder();
    return 0;
}