#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include <iostream>
using namespace std;

class Endereco {
private:
  string logradouro, bairro, cidade, cep;
  int numero;
public:
  Endereco(const string &log, const string &bairro, int num, const string &cidade, const string &cep);

  const string &getLogradouro() const;
  const string &getBairro() const;
  int getNumero() const;
  const string &getCidade() const;
  const string &getCep() const;
  const string &getEnderecoString() const;
};

Endereco::Endereco(const string &l, const string &b, int n, const string &c, const string &cp)
         : logradouro(l), bairro(b),numero(n),cidade(c),cep(cp){}

 const string &Endereco::getLogradouro() const {
     return logradouro;
 }
 const string &Endereco::getBairro() const {
     return bairro;
 }
 const string &Endereco::getCidade() const {
     return cidade;
 }
 const string &Endereco::getCep() const {
     return cep;
 }
 int Endereco::getNumero() const {
   return numero;
 }
 const string &Endereco::getEnderecoString() const {
     static string s = "";
     s = "Rua: " + logradouro +"; Bairro: " + bairro + "; Número: " + to_string(numero)
     + "; Cidade: " + cidade + "; CEP: " + cep;
     return s;
 }
#endif
