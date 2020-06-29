#ifndef __CRITERIOSB_HPP__
#define __CRITERIOSB_HPP__
#include "criterios.hpp"
#include "ListaEnlazada.hpp"
typedef ListaEnlazada<string> LS;
auto CriteriBMayor = [](LS& Lista1, string crite){
    long long Lis1 = stoll(Lista1[Column]);
    long long CriterioCom = stoll(crite);
    if(Lis1 == CriterioCom){
        Lista1.ShowAll(printString);
        cout<<"\n";
    }
    if(CriterioCom > Lis1){
        return true;
    }else{
        return false;
    }
};
auto CriteriBMenor = [](LS& Lista1, string crite){
    long long Lis1 = stoll(Lista1[Column]);
    long long CriterioCom = stoll(crite);
    if(Lis1 == CriterioCom){
        Lista1.ShowAll(printString);
        cout<<"\n";
    }
    if(CriterioCom < Lis1){
        return true;
    }else{
        return false;
    }
};
auto CriterioBAlphaIni = [](LS& Lista1, string crite){
    int Letra1 = Lista1[Column][0];
    int Letra2 = crite[0];
    if(Letra1 == Letra2){
        Lista1.ShowAll(printString);
    }
    if(Letra1 > Letra2){
        return true;
    }else{
        
        return false;
    }
};
auto CriterioBAlphaFIN = [](LS& Lista1, string crite){
    string L1 = Lista1[Column];
    int Letra1 = L1[L1.size()-1];
    int Letra2 = crite[0];
    if(Letra1 == Letra2){
        Lista1.ShowAll(printString);
    }
    if(Letra1 > Letra2){
        
        return true;
    }else{
        
        return false;
    }
};
#endif