#include <iostream>
#include <stdexcept>
#include "DataClass.h"
using namespace std;

int main(int argc, char const *argv[]) throw(invalid_argument){

  DataClass *data1 = new DataClass(18,02,1993);
  DataClass *data2 = new DataClass(01,03,1991);

  cout << '\n' << "RG Thiago: " << data1->getDia() << "/";
  cout << data1->getMes() << "/" << data1->getAno() << '\n';

  cout << '\n' << "RG Matheus: " << data2->getDia() << "/";
  cout << data2->getMes() << "/" << data2->getAno() << '\n';

  cout << '\n';
  cout << "Método GET e SET" << '\n';
  data1->setAno(1997);
  cout << "Novo ano Thiago: " << data1->getAno() << '\n';

  cout << '\n';
  cout << "Método avançarDia" << '\n';
  data2->avancarDia();
  cout << "Novo dia Matheus: " << data2->getDia() << '\n';

  return 0;
}
