#include <iostream>
#include <vector>
#include "Endereco.h"
#include "Imovel.h"
#include "Apartamento.h"
#include "Casa.h"
#include "Terreno.h"
using namespace std;

int main(int argc, char const *argv[]) {

  vector<Imovel*> imoveis(5);

  Endereco teste1 = Endereco("Rua Paulo", "Bessa", 447, "João Pessoa", "58035-110");
  Endereco teste2 = Endereco("Rua Roberto", "Bessa", 447, "João Pessoa", "58035-110");
  Endereco teste3 = Endereco("Rua De", "Bessa", 447, "João Pessoa", "58035-110");
  Endereco teste4 = Endereco("Rua Souza", "Bessa", 447, "João Pessoa", "58035-110");
  Endereco teste5 = Endereco("Rua Acioly", "Bessa", 447, "João Pessoa", "58035-110");

  imoveis[0] =  new Casa(1, 2, 300, 200, teste1);
  imoveis[1] =  new Casa(1, 2, 300, 200, teste2);
  imoveis[2] = new Terreno(120, teste3);
  imoveis[3] = new Terreno(100, teste4);
  imoveis[4] =  new Apartamento("Sul", 200, 2, teste5);

  for (size_t i = 0; i < imoveis.size(); i++) {
    cout << imoveis.at(i)->getDescricao() << endl << endl;
  }

  return 0;
}
