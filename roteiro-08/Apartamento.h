#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <string>
#include "Imovel.h"
using namespace std;

class Apartamento : public Imovel {
private:
  string posicao;
  double valorCondominio;
  int numVagas;
public:
  Apartamento(string pos, double value, int vagas, Endereco end);
  string getDescricao(void);
};

Apartamento::Apartamento(string pos, double value, int vagas, Endereco end) : Imovel(end){
  posicao = pos;
  valorCondominio = value;
  numVagas = vagas;
}
string Apartamento::getDescricao(void){
  return "Apartamento!";
}
#endif
