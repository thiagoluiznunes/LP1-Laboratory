#ifndef CASA_H
#define CASA_H

#include <string>
#include "Imovel.h"
using namespace std;

class Casa : public Imovel {
private:
  int numPavimentos, quantQuartos;
  double areaTerreno, areaConstruida;
public:
  Casa(int pav, int quart, double aTerr, double aConst, Endereco end);
  string getDescricao(void);
};

Casa::Casa(int pav, int quart, double aTerr, double aConst, Endereco end) : Imovel(end){
  numPavimentos = pav;
  quantQuartos = quart;
  areaTerreno = aTerr;
  areaConstruida = aConst;
}
string Casa::getDescricao(void){
  return "Casa!";
}
#endif
