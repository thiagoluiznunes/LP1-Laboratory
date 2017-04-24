#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <string>
#include <iomanip>
#include <sstream>
#include "Imovel.h"
#include "Apartamento.h"
using namespace std;

class Apartamento : public Imovel {
private:
  string posicao;
  double valorCondominio;
  int numVagas;
public:
  Apartamento(const string pos, double value, int vagas, const Endereco &end);
  const string &getDescricao() const override;
};

Apartamento::Apartamento(const string pos, double value, int vagas, const Endereco &end) : Imovel(end){
  posicao = pos;
  valorCondominio = value;
  numVagas = vagas;
}
const string &Apartamento::getDescricao() const {
   stringstream stream;
   stream << fixed << setprecision(2) << valorCondominio;

   static string s = "";
      s = "Descrição do apartamento\n" + endereco.getEnderecoString();
      s += "\nPosição: " + posicao + "; Valor do condominio: " + stream.str()
        + "; Vagas: " + to_string(numVagas);

  return s;
}
#endif
