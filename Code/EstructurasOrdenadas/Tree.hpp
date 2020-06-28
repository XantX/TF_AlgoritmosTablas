#ifndef __TREE_HPP__
#define __TREE_HPP__
#include <iostream>
#include "Nodo.hpp"
#include <functional>
#include <vector>
#include "criterios.hpp"
using namespace std;

template <typename T>
class Tree
{
private:
    Nodo<T> *raiz;
    long long NodosNum;
    function<bool(T &, T &)> criterio;
    function<bool(T &, string&)> criterio2;
    function<bool(T &, string)> criterioB;
    function<void(T)> impresion;
    string NameTree;
    long long NameTreeLL;
    string CriterioComparador;
    void _add(T, Nodo<T> *&);
    void _inorder(Nodo<T> *);
    void ReInorder(Nodo<T> *);
    vector<T> INor;
    void _findByData(Nodo<T> *, string s);
    bool Switcher(T, T);
    void rotarDer(Nodo<T> *&);
    void rotarIzq(Nodo<T> *&);
    int _AlturaIzq(Nodo<T>*);
    int _AlturaDer(Nodo<T>*);
    void _balanceo(Nodo<T>*&);
public:
    Tree(string, long long);
    ~Tree();
    void setImpresion(function<void(T)>);
    void setCriterio(function<bool(T&, T&)>);
    void setCriterio(function<bool(T &, string&)>);
    void setCriterioB(function<bool(T& , string)>);
    vector<T> RetornoInorder();
    string GetNameTrees();
    void InOrder();
    void Add(T);
    void Find(string);
};
//===============================================
template <typename T>
void Tree<T>::ReInorder(Nodo<T> *nodo)
{
    if (nodo == nullptr)
    {
        return;
    }
    else
    {
        ReInorder(nodo->Izq);
        INor.push_back(nodo->data);
        ReInorder(nodo->Der);
    }
}
template <typename T>
vector<T> Tree<T>::RetornoInorder()
{
    if (raiz != nullptr)
    {
        ReInorder(raiz);
    }
    else
    {
        cout << "Arbol vacio";
    }
    return INor;
}
template <typename T>
Tree<T>::Tree(string Name, long long NameLL)
{
    raiz = nullptr;
    NodosNum = 0;
    NameTree = Name;
    NameTreeLL = NameLL;
}
template <typename T>
void Tree<T>::Add(T data)
{
    if (criterio == nullptr && criterio2 == nullptr)
    { //cambiar
        cout << "ERROR:ADD:No se eligio un criterio" << endl;
    }
    else
    {
        _add(data, raiz);
    }
}
template <typename T>
void Tree<T>::InOrder()
{
    if (impresion == nullptr)
    {
        cout << "ERROR:INORDER: no sea declarado un criterio de imprecion";
        return;
    }
    if (NodosNum == 0)
        cout << "\nNo hay elementos para ver\n";
    else
        _inorder(raiz);
}
template <typename T>
string Tree<T>::GetNameTrees()
{
    return NameTree;
}
template <typename T>
Tree<T>::~Tree()
{
}
template <typename T>
void Tree<T>::setImpresion(function<void(T)> impresion)
{
    if (this->impresion == nullptr)
    {
        this->impresion = impresion;
    }
    else
    {
        cout << "\nYa se asigno un criterio de impresion\n";
    }
}
template <typename T>
void Tree<T>::setCriterio(function<bool(T&, T&)> criterioIN)
{
    //si el criterio de la clase esta vacio se iguala al pasado por parametro, caso contrario no, porque ya tendría un criterio
    if (this->criterio == nullptr && this->criterio2 == nullptr)
    {
        this->criterio = criterioIN;
    }
    else
    {
        cout << "Ya se agrego um criterio de indexacion";
    }
}
template <typename T>
void Tree<T>::setCriterio(function<bool(T &, string&)> criterioIN)
{
    //si el criterio de la clase esta vacio se iguala al pasado por parametro, caso contrario no, porque ya tendría un criterio
    if (this->criterio2 == nullptr && this->criterio == nullptr)
    {
        cout << "Dime con que criterio se comparar:\n";
        cin >> CriterioComparador;
        this->criterio2 = criterioIN;
    }
    else
    {
        cout << "Ya se agrego um criterio de indexacion";
    }
}
template <typename T>
void Tree<T>::_inorder(Nodo<T> *nodo)
{
    if (nodo == nullptr)
    {
        return;
    }
    else
    {
        _inorder(nodo->Izq);
        impresion(nodo->data);
        _inorder(nodo->Der);
    }
}
template <typename T>
bool Tree<T>::Switcher(T LADD, T LCOM)
{
    Setcolum(NameTreeLL);
    if (criterio != nullptr)
    {
        return criterio(LADD, LCOM);
    }
    else if (criterio2 != nullptr)
    {
        return criterio2(LADD, CriterioComparador);
    }
}
template <typename T>
void Tree<T>::_add(T data, Nodo<T> *&nodo)
{
    Nodo<T> *nuevo = new Nodo<T>(data);
    if (nodo == nullptr)
    {
        nodo = nuevo;
        NodosNum++;
        
    }
    else
    {
        if (Switcher(data, nodo->data)) //cambiar
            _add(data, nodo->Izq);
        else
            _add(data, nodo->Der);
    }
    _balanceo(nodo);
}
template<typename T>
void Tree<T>::rotarDer(Nodo<T>*& nodo){
    Nodo<T>*aux=nodo->Izq;
    nodo->Izq=aux->Der;
    aux->Der=nodo;
    nodo=aux;
}
template<typename T>
void Tree<T>::rotarIzq(Nodo<T>*& nodo){
    Nodo<T>*aux=nodo->Der;
    nodo->Der=aux->Izq;
    aux->Izq=nodo;
    nodo=aux;
}
template<typename T>
int Tree<T>::_AlturaDer(Nodo<T>* nodo){
    if(nodo == nullptr){
        return 0;
      }
      return _AlturaDer(nodo->Der)+1;
}
template<typename T>
int Tree<T>::_AlturaIzq(Nodo<T>* nodo){
    if(nodo == nullptr){
        return 0;
      }
      return _AlturaIzq(nodo->Izq)+1;
}
template<typename T>
void Tree<T>::_balanceo(Nodo<T>*&nodo){
    if(nodo==nullptr){
    return;
  }
       int alturader = _AlturaDer(nodo);
       int alturaizq = _AlturaIzq(nodo);
       int fb=alturader-alturaizq;
     if(fb>1){
         
       alturader = _AlturaDer(nodo->Der);
       alturaizq = _AlturaIzq(nodo->Der);
       if(alturaizq>alturader){
         rotarDer(nodo->Der);
       }
       rotarIzq(nodo);
     }
     if(fb<-1){
       
        alturader = _AlturaDer(nodo->Izq);
        alturaizq = _AlturaIzq(nodo->Izq);
       if(alturaizq<alturader){
         rotarIzq(nodo->Izq);
       }
       rotarDer(nodo);
     }
     _balanceo(nodo->Der);
     _balanceo(nodo->Izq);
     
}
template<typename T>
 void Tree<T>::setCriterioB(function<bool(T&,string)> criterioBu){
     if(this->criterioB == nullptr){
         this->criterioB = criterioBu;
     }else{
         cout<<"ERROR:TREE:Ya existe un criterio de busque";
     }
}
template<typename T>
void Tree<T>::Find(string criter){
    _findByData(raiz,criter);
}
template <typename T>
void Tree<T>::_findByData(Nodo<T> *nodo, string s)
{
    Setcolum(NameTreeLL);
    if(nodo == nullptr){
        cout<<"Se termino la busqueda";
        return;
    }
    
    if(criterioB(nodo->data,s)){
        _findByData(nodo->Izq,s);
    }else{
        _findByData(nodo->Der,s);
    }
}

#endif