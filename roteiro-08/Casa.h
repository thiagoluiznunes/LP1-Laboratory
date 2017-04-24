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
  Casa(int pav, int quart, double aTerr, double aConst, const Endereco &end);
  const string &getDescricao() const override;
};

Casa::Casa(int pav, int quart, double aTerr, double aConst, const Endereco &end) : Imovel(end){
  numPavimentos = pav;
  quantQuartos = quart;
  areaTerreno = aTerr;
  areaConstruida = aConst;
}
const string &Casa::getDescricao() const {
  stringstream terrenoStream, constStream;
  terrenoStream << fixed << setprecision(2) << areaTerreno;
  constStream << fixed << setprecision(2) << areaConstruida;

  static string s = "";
  s = "Descrição da casa\n" + endereco.getEnderecoString();
  s += "\nNumero de pavimentos: " + to_string(numPavimentos) + "; Numero de quartos: " + to_string(quantQuartos)
          + "; Area do terreno: " + terrenoStream.str() + "; Area construida: " + constStream.str();

  return s;
}
#endif
