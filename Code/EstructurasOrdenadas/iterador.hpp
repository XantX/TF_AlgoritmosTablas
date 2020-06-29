#ifndef __ITERADOR_HPP__
#define __ITERADOR_HPP__
#include <iostream>
#include "Nodo.hpp"
#include "ListaEnlazada.hpp"
using namespace std;
//Solo para la lista en lazada
template<typename T>
class iterador
{//sobrecarga de operadores
private:

    long long pos;
    ListaEnlazada<T> lista;
public:
    Nodo<T>* it;
    iterador(){
        
    }
    void setLista(ListaEnlazada<T> &lista){
        this->lista = lista;
        it = this-> lista.inicio;
    }
    ~iterador(){
    }
    void operator++(int i){
        if(it->Der != nullptr){it = it->Der;
        }else{
        cout<<"ERROR:OverRange";//error
        }
    }
    void operator--(int i){
        if(it->Izq != nullptr){it = it->Izq;
        }else{
        cout<<"ERROR:OverRange";
        }
    }
    T& operator[](long long val){
        return lista.getPos(val);
    }
};

#endif