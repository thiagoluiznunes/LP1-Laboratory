#include "Account.h"
#include "Assalariado.h"
#include "Comissionado.h"
#include "Horista.h"
#include "Methods.h"

#include <string>
#include <iostream>

int main(int argc, char const *argv[]) {


  printMenu();

  int chouce = 0;
  std::vector<Funcionario> listEmployees;

  while (true) {
    std::cout << "Digite a opção desejada:" << '\n';
    std::cin >> chouce;
    switch (chouce) {
      case 1:
        registerEmployee(listEmployees);
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
      break;
    }
    if(chouce == 5){
      break;
    }
  }


  return 0;
}
