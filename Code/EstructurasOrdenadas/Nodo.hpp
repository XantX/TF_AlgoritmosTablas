#ifndef __NODO_HPP__
#define __NODO_HPP__
template<typename T>
class Nodo
{
public:
    Nodo<T>* Der;
    Nodo<T>* Izq;
    T data;
    Nodo(T data){
        Der = Izq =  nullptr;
        this->data = data;
    }
    ~Nodo(){}
};   
#endif