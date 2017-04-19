#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "IAccount.h"
using namespace std;

class Account : public IAccount {
protected:
  string nomeCliente;
  int salarioMensal, numConta;
  double saldo, limite;
public:
  Account(string name, int salary, int numC, double saldo);

  string getNome(void);
  int getMensal(void);
  int getConta(void);
  double getSaldo(void);
  double getLimite(void);

  void setNome(string n);
  void setMensal(int s);
  void setConta(int c);
  void setSaldo(double s);
  virtual void definirLimite(void);
  void sacar(double v) override;
  void depositar(double v) override;
};

Account::Account(string name, int salary, int numC, double s){
  nomeCliente = name;
  salarioMensal = salary;
  numConta = numC;
  saldo = s;
}
//GETs
string Account::getNome(void){
  return nomeCliente;
}
int Account::getMensal(void){
  return salarioMensal;
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
void Account::definirLimite(void){
  limite = salarioMensal*2;
}
void Account::setNome(string n){
  nomeCliente = n;
}
void Account::setMensal(int s){
  salarioMensal = s;
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
  cout << "DEPOSITO EFETUADO COM SUCESSO!" << endl;
}
void Account::sacar(double s){
  if(s>saldo){
    cout << "SALDO INSUFICIENTE!" << endl;
  }
  else{
    saldo -= s;
    cout << "SAQUE EFETUADO COM SUCESSO!" << endl;
  }
}

#endif
