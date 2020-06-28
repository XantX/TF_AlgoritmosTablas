#ifndef __EXPORT_HPP__
#define __EXPORT_HPP__
#include <fstream>
#include <string>
#include "ListaEnlazada.hpp"
typedef ListaEnlazada<string> LS;
typedef ListaEnlazada<LS> LLS;
using namespace std;
template <class T>
class Export
{
private:
    string name;
    string ExtensionType;
    string spaces;

public:
Export(string name,LLS& DataB){
    
}
    _export(string name)
    {

        this->name = name;
        string extension;
        extension = ".csv";
        if (name.find(extension) != string::npos)
        {
            ExtensionType = ".csv";
        }
        else
        {
            ExtensionType = ".txt";
        }
    }
    void save(T x)
    {
        ofstream fichero(name, ios::app);

        fichero << x;
        saveSpaces();
    }

    void saveSpaces()
    {
        ofstream fichero(name, ios::app);
        if (ExtensionType == ".csv")
        {

            spaces = ";";
        }
        else
        {
            spaces = " ";
        }
        fichero << spaces;
    }

    bool getExtensionType()
    {
        if (ExtensionType == ".csv")
            return true;
        else
            return false;
    }

    void close()
    {
        ofstream fichero(name);
        fichero.close();
    }
    void clear()
    {
        ofstream fichero(name);
        fichero.clear();
    }
};
#endif // !__EXPORT_HPP__