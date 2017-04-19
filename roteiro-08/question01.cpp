#include <iostream>
#include "Account.h"
#include "AccountSpecial.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Account *teste = new Account("Thiago", 800, 11414864, 500);
  AccountSpecial *teste2 = new AccountSpecial("Luiz", 800, 11414865, 500);

  //Metodos definir limite
  teste->definirLimite();
  teste2->definirLimite();

  cout << endl;
  cout << "Name: " << teste->getNome() << endl;
  cout << "Conta: " << teste->getConta() << endl;
  cout << "Salário: " << teste->getMensal() << endl;
  cout << "Saldo: " << teste->getSaldo() << endl;
  cout << "Limite: " << teste->getLimite() << endl;

  cout << endl;
  cout << "Name: " << teste2->getNome() << endl;
  cout << "Conta especial: " << teste2->getConta() << endl;
  cout << "Salário: " << teste2->getMensal() << endl;
  cout << "Saldo: " << teste2->getSaldo() << endl;
  cout << "Limite: " << teste2->getLimite() << endl;
  cout << endl;

  cout << "Nome: " << teste->getNome() << endl << "Conta: " << teste->getConta() << endl;
  cout << endl;
  teste->sacar(200);
  cout << "Saldo atual: " << teste->getSaldo() << endl;
  teste->depositar(150);
  cout << "Saldo atual: " << teste->getSaldo() << endl;

  cout << endl;

  return 0;
}
