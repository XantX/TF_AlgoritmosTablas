#ifndef __LISTAENLAZADA_HPP__
#define __LISTAENLAZADA_HPP__
#include "Nodo.hpp"
#include <functional>
using namespace std;
template<typename T>
class ListaEnlazada
{
private:
    long long Size;
    T& getPos(long long pos);
public:
    Nodo<T>*fin;
    Nodo<T>*inicio;
    ListaEnlazada();
    ~ListaEnlazada();
    void add(T data);
    void ShowAll(function<void(T)>Print);
    long long getSize();

    T& operator[](long long val){
        return getPos(val);
    }
    
};
template<typename T>
ListaEnlazada<T>::ListaEnlazada()
{
    inicio = fin = nullptr;
    Size = 0;
}
template<typename T>
T& ListaEnlazada<T>::getPos(long long pos){
    Nodo<T>*aux = inicio;
    if(pos >= Size){
        return inicio->data;
    }
    for (int i = 0; i < pos; i++)
    {
        aux = aux->Der;
    }
    return aux->data;
}
template<typename T>
void ListaEnlazada<T>::add(T data){
    Nodo<T> *nuevo = new Nodo<T>(data);
    if(Size == 0){
        inicio = fin = nuevo;
    }else{
        nuevo->Izq = fin;
        fin->Der = nuevo;
        fin = nuevo;
    }
    Size++;
}

template<typename T>
void ListaEnlazada<T>::ShowAll(function<void(T)>Print){
    Nodo<T>*aux = inicio;
    for (int i = 0; i < Size; i++)
    {
        Print(aux->data);
        aux = aux->Der;
    }
}
template<typename T>
long long ListaEnlazada<T>::getSize(){
    return Size;
}

template<typename T>
ListaEnlazada<T>::~ListaEnlazada()
{
}

#endif