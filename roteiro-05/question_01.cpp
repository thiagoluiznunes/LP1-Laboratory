#include <iostream>
#include "DataClass.h"
using namespace std;

int main(int argc, char const *argv[]) {


  DataClass *data = new DataClass(30,02,1993);
  cout << "Ano: " << data->getAno() << '\n';

  data->avancarDia();
  cout << "MES: " << data->getMes() << '\n';
  cout << "DIA: " << data->getDia() << '\n';
  return 0;
}
