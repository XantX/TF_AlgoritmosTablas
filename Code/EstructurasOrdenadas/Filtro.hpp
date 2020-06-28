#ifndef __FILTRO_HPP__
#define __FILTRO_HPP__
#include<iostream>
#include <vector>
#include "Tree.hpp"

using namespace std;

typedef vector<Tree<LS>>& ArrTree;
class Filtro
{
private:

public:
    void mayor();
    void menor();
    void igual_a();
    void inicia_con();
    void Finaliza_con();
    void EstaContenidoEn();
    void NoEstaContenidoEn();
    Filtro();
    ~Filtro();
};

Filtro::Filtro()
{
}

Filtro::~Filtro()
{
}

#endif