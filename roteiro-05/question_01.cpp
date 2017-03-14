#include <iostream>
#include "DataClass.h"
using namespace std;

int main(int argc, char const *argv[]) {


  DataClass *data = new DataClass(18,02,1993);
  cout << "Ano: " << data->getAno() << '\n';
  return 0;
}
