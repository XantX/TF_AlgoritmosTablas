#ifndef __MENU_DB__
#define __MENU_DB__
#include <iostream>
using namespace std;
class ClassMenuDB
{
private:
    
public:
    void AddFilaM();
    ClassMenuDB();
    ~ClassMenuDB();
};

ClassMenuDB::ClassMenuDB()
{
}
void ClassMenuDB::AddFilaM(){
    cout<<"\t\t FIla:";
}
ClassMenuDB::~ClassMenuDB()
{
}

#endif