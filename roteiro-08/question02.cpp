#include <iostream>
#include <vector>
#include "Endereco.h"
#include "Imovel.h"
#include "Apartamento.h"
using namespace std;

int main(int argc, char const *argv[]) {


  Endereco teste2 = Endereco("Rua A", "Mangabeira", 101, "João Pessoa", "58000-000");
  Apartamento ap =  Apartamento("Sul", 200, 2, teste2);

  return 0;
}
