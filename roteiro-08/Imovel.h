#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include "Endereco.h"
using namespace std;

class Imovel {
protected:
  Endereco *endereco;
public:
  Imovel(Endereco end);

  Endereco getEndereco(void);
  virtual string getDescricao(void) = 0;
};

Imovel::Imovel(const Endereco end){
  endereco = end;
}
Endereco Imovel::getEndereco(void){
  return endereco;
}
#endif
