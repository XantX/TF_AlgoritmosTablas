#ifndef __CRITERIOS_HPP__
#define __CRITERIOS_HPP__
#include <iostream>
#include <string>
using namespace std;
auto printNum = [](int x){
  cout<<x;
};
auto printString = [](string x){
  cout<<x<<endl;
};
auto EnpiezaCon = [](int x, int y){
  return (x<y)?true:false;
};

auto CriterioMa = [](int x, int y){
  return (x>y)?true:false;
};

auto CriterioMen = [](int x, int y){
  return (x<y)?true:false;
};
#endif