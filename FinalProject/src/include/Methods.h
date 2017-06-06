#ifndef INCLUDE_METHODS_H
#define INCLUDE_METHODS_H

#include "Funcionario.h"

void printMenu(void) {
  std::cout << '\n' << "<<<<<<<<<<<<<<<<<<<< GERENCIA DE FUNCIONARIOS >>>>>>>>>>>>>>>>>>>" << '\n' << '\n';
  std::cout << '\t' << "Menu" << '\t' << '\n' << '\n';
  std::cout << "1 - Cadastrar" << '\n';
  std::cout << "2 - Consultar" << '\n';
  std::cout << "3 - Folha de Pagamento" << '\n';
  std::cout << "4 - Remover" << '\n';
  std::cout << "5 - Sair" << '\n';
}

/*Register Employee*/
void registerEmployee(std::vector<Funcionario>& vFun, int type){

  std::string name;
  int mat, numC;
  double salario, saldo = 0;

  switch (type) {
    /*Assalariado*/
    case '1':
      std::cout << "Nome: " << '\n';
      std::cin >> name;
      std::cout << "Matricula: " << '\n';
      std::cin >> mat;
      std::cout << "Salario: " << '\n';
      std::cin >> salario;
      std::cout << "Numero da Conta: " << '\n';
      std::cin >> numC;
      std::cout << "Saldo: " << '\n';
      std::cin >> saldo;

      Assalariado func(name, mat, salario, numC, saldo);
      vFun.push_back(func);
      std::cout << "Funcionario cadastrado com sucesso." << '\n';
      break;

    /*Comissionado*/
    case '2':
    break;

    /*Horista*/
    case '3':
    break;
  }
}
/*Search for all employees*/
void queryEmployees(std::vector<Funcionario>& vFun){

}
#endif
