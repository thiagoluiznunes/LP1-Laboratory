#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include "Endereco.h"
using namespace std;

class Imovel {
protected:
  Endereco endereco;
public:
  Imovel(const Endereco &end);

  const Endereco &getEndereco() const;
  virtual const string &getDescricao() const = 0;
};

Imovel::Imovel(const Endereco &end) : endereco(end){}

const Endereco &Imovel::getEndereco() const {
  return endereco;
}

#endif
