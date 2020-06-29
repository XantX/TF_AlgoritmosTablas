#ifndef __TABLAMOVE_HPP__
#define __TABLAMOVE_HPP__
#include "ClassManu.hpp"
class Tablamove
{
private:
    
public:
    void MenuTabla(DB*&, ClassMenu);
    Tablamove();
    ~Tablamove();
};
void Tablamove::MenuTabla(DB*& Tabla,ClassMenu MenuT){
bool Condi = true;
while (Condi)
{
    cout<<"\n";
    cout<<"Tabla: "<<Tabla->getNameTabla()<<"\n";
    int opc = MenuT.Tabla();
    switch (opc)
    {
        case 1:
        Tabla->FiltroView();
        break;
        case 2:
        //export
        Tabla->ExportarOn();
        break;
        case 3:
        Tabla->addFila();
        break;
        case 4:
        Condi = false;
        break;
    }
}
    
}
Tablamove::Tablamove()
{
}

Tablamove::~Tablamove()
{
}

#endif