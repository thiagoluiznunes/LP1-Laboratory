#include <iostream>
#include "Imovel.h"
#include "Casa.h"
#include "Terreno.h"
#include "Apartamento.h"
#include "Endereco.h"
using namespace std;

int main(int argc, char const *argv[]) {

  //Endereco(string log, string bairro, int num, string cidade, string cep);
  Endereco *first = new Endereco("Rua Paulo Roberto", "Bessa", 447, "JP", "58035110");
  //Imovel *imovel = new Imovel(first);
  return 0;
}
