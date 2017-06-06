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
  int type = 0;
  std::vector<Funcionario> listEmployees;

  while (true) {
    std::cout << "Digite a opção desejada:" << '\n';
    std::cin >> chouce;
    switch (chouce) {
      case 1:
        while (true) {
          std::cout << "Digite o tipo de empregado: " << '\n';
          std::cin >> type;
          if(!(type < 0 || type > 3)){
            registerEmployee(&listEmployees, type);
          }
          else {
            int conf = 0;
            std::cout << "Tipo informado incorreto! Deseja continuar o registro? Se sim digite 1 se não digite 0." << '\n';
            std::cin >> conf;
            if(conf = 0){break;}
          }
        }
        break;

      case 2:
        //queryEmployees(&listEmployees);
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
