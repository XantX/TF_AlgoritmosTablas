#ifndef __MENUEXPORT_HPP__
#define __MENUEXPORT_HPP__
#include <iostream>
#include <string>
using namespace std;
class MenuExport
{
private:
    
public:
    string pedirExtencion();
    string pedirSeparadordecampos(string);
    string separador(int);
    MenuExport();
    ~MenuExport();
};

MenuExport::MenuExport()
{
}
string MenuExport::separador(int opc){
    switch (opc)
    {
    case 1:
        return ";";
        break;
    case 2:
        return " ";
        break;
    case 3:
        return ",";
        break;
    }
}
string MenuExport::pedirSeparadordecampos(string extenc){
    int opc;
    do
    {
       cout<<"Elige un separador de campos para la extencion\n";
       cout<<"--->"<<extenc<<"\n";
       cout<<"1) \";\" ";
       cout<<"2) \" \" ";
       cout<<"3) \",\"\n";
       cout<<"---->";
       cin>>opc; 
    } while (opc < 1 || opc > 3);
    return separador(opc);
}
string MenuExport::pedirExtencion(){
    string extencion;
    cin.ignore();
    cout<<"Dime la extencion con la que se quiere exportar sin el punto:\n";
    getline(cin,extencion);
    return extencion;
}
MenuExport::~MenuExport()
{
}

#endif