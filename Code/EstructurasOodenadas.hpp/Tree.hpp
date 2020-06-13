#ifndef __TREE_HPP__
#define __TREE_HPP__
#include <iostream>
#include "Nodo.hpp"
#include <functional>
using namespace std;

template<typename T>
class Tree
{
private:
Nodo<T>* raiz;
long long NodosNum;
function<bool(T,T)> criterio;
function<void(T)> impresion;
string NameTree;

    void _add(T ,Nodo<T>*&);
    void _inorder(Nodo<T>*);

public:
    Tree(string);
    ~Tree();
    void setImpresion(function<void(T)>);
    void setCriterio(function<bool(T,T)>);
    string GetNameTrees();
    void InOrder();
    void Add(T);
};
//===============================================
template<typename T>
Tree<T>::Tree(string Name){
    raiz = nullptr;
    NodosNum = 0;
    NameTree = Name;
}
template<typename T>
void Tree<T>::Add(T data){
    if(criterio == nullptr){
        cout<<"ERROR:ADD:No se eligio un criterio"<<endl;
    }else{
        _add(data,raiz);
    }
}
template<typename T>
void Tree<T>::InOrder(){
    if(impresion == nullptr) {
        cout<<"ERROR:INORDER: no sea declarado un criterio de imprecion";
        return;
    }
    if(NodosNum == 0) cout<<"\nNo hay elementos para ver\n";
    else _inorder(raiz);
}
template<typename T>
string Tree<T>::GetNameTrees(){
    return NameTree;
}
template<typename T>
Tree<T>::~Tree(){
}
template<typename T>
void Tree<T>::setImpresion(function<void(T)> impresion){
    if(this->impresion == nullptr){
        this->impresion = impresion;
    }else{
        cout<<"\nYa se asigno un criterio de impresion\n";
    }
}
template<typename T>
void Tree<T>::setCriterio(function<bool(T,T)> criterio){
    if(this->criterio ==nullptr){
        this->criterio = criterio;
    }else{
        cout<<"Ya se agrego um criterio de indexacion";
    }
    
}

template<typename T>
void Tree<T>::_inorder(Nodo<T>* nodo){
    if(nodo == nullptr){
        return;
    }else{
        _inorder(nodo->Izq);
        impresion(nodo->data);
        _inorder(nodo->Der);
    }
}

template<typename T>
void Tree<T>::_add(T data, Nodo<T>*& nodo){
    Nodo<T>*nuevo =  new Nodo<T>(data);
    if(nodo == nullptr){
        nodo = nuevo;
        NodosNum++;
    }else{
        if(criterio(data,nodo->data))
        _add(data,nodo->Izq);
        else
        _add(data,nodo->Der);
    }
}

#endif