#ifndef TERRENO_H
#define TERRENO_H

#include <string>
#include "Imovel.h"
using namespace std;

class Terreno : public Imovel {
private:
  double area;
public:
  Terreno(double area, Endereco end);
  string getDescricao(void);
};

Terreno::Terreno(double a, Endereco end) : Imovel(end){
  area = a;
}
string Terreno::getDescricao(void){
  return "Terreno!";
}
#endif
