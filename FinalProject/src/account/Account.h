#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include "IAccount.h"

class Account : public IAccount {
protected:
  std::string nomeCliente;
  int numConta;
  double saldo, limite;
public:
  Account(std::string name, int numC, double saldo);

  std::string getNome(void);
  int getMensal(void);
  int getConta(void);
  double getSaldo(void);
  double getLimite(void);

  void setNome(std::string n);
  void setConta(int c);
  void setSaldo(double s);
  virtual void definirLimite(double s);
  void sacar(double v) override;
  void depositar(double v) override;
};

Account::Account(std::string name, int numC, double s){
  nomeCliente = name;
  numConta = numC;
  saldo = s;
}
//GETs
std::string Account::getNome(void){
  return nomeCliente;
}
int Account::getConta(void){
  return numConta;
}
double Account::getSaldo(void){
  return saldo;
}
double Account::getLimite(void){
  return limite;
}
//SETs
void Account::definirLimite(double s){
  limite = s*2;
}
void Account::setNome(std::string n){
  nomeCliente = n;
}
void Account::setConta(int c){
  numConta = c;
}
void Account::setSaldo(double s){
  saldo = s;
}
//OTHER
void Account::depositar(double d){
  saldo += d;
  std::cout << "DEPOSITO EFETUADO COM SUCESSO!" << std::endl;
}
void Account::sacar(double s){
  if(s>saldo){
    std::cout << "SALDO INSUFICIENTE!" << std::endl;
  }
  else{
    saldo -= s;
    std::cout << "SAQUE EFETUADO COM SUCESSO!" << std::endl;
  }
}

#endif
