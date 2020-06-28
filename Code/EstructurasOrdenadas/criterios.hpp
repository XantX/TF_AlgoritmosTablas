#ifndef __CRITERIOS_HPP__
#define __CRITERIOS_HPP__
#include <iostream>
#include <string>
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
using namespace std;
long long Column = 0;
auto Setcolum = [&](long long C){
  Column = C;
};
auto printNum = [](int x){
  cout<<x;
};
auto printString = [](string x){
  cout<<x<<" ";
};

auto CriterioMaS = [](string& Lista1, string& Lista2){
  long long l1 = stoi(Lista1);
  long long l2 = stoi(Lista2);
  if(l1 > l2){
    return true;
  }else{
    return false;
  }
};
auto CriterioMenS = [&](string Lista1, string Lista2){
  long long l1 = stoi(Lista1);
  long long l2 = stoi(Lista2);
  if(l1 < l2){
    return true;
  }else{
    return false;
  }
};
auto CriterioMen = [](LS& Lista1, LS& Lista2){
  long long l1 = stoi(Lista1[Column]);
  long long l2 = stoi(Lista2[Column]);
  if(l1 < l2){
    return true;
  }else{
    return false;
  }
};
auto AlphebeticoINI = [](LS& Lista1, LS& Lista2){
  int Letra1 = Lista1[Column][0];
  int Letra2 = Lista2[Column][0];
  if(Letra1 > Letra2){
    return true;
  }else{
    return false;
  }
};
auto AlphebeticoFIN = [](LS& Lista1, LS& Lista2){
  string L1 = Lista1[Column];
  string L2 = Lista2[Column];
  int Letra1 = L1[L1.size()- 1];
  int Letra2 = L2[L2.size()- 1];
  if(Letra1 < Letra2){
    return true;
  }else{
    return false;
  }
};

auto CriterioMa = [](LS& Lista1, LS& Lista2 ){
  long long l1 = stoll(Lista1[Column]);
  long long l2 = stoll(Lista2[Column]);
  if(l1 > l2){
    return true;
  }else{
    return false;
  }
};
auto IniciaCon = [](LS& Lista1, string Comparador){
  if(Lista1[Column].find(Comparador) == 0){
    return true;
  }else{
    return false;
  }
};
auto ImpriLS = [&](LS lista1){
  lista1.ShowAll(printString);
  cout<<"\n";
};
#endif