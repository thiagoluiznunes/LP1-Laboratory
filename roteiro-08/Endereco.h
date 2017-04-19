#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
using namespace std;

class Endereco {
private:
  string logradouro, bairro, cidade, cep;
  int numero;
public:
  Endereco(string log, string bairro, int num, string cidade, string cep);

  string getLogradouro(void);
  string getBairro(void);
  int getNumero(void);
  string getCidade(void);
  string getCep(void);
};

Endereco::Endereco(string l, string b, int n, string c, string cp){
  logradouro = l;
  bairro = b;
  numero = n;
  cidade = c;
  cep = cp;
}

string Endereco::getLogradouro(void){return logradouro;}
string Endereco::getBairro(void){return bairro;}
string Endereco::getCidade(void){return cidade;}
string Endereco::getCep(void){return cep;}
int Endereco::getNumero(void){return numero;}

#endif
