#include <iostream>
#include <stdexcept>
#include "DataClass.h"
using namespace std;

int main(int argc, char const *argv[]) throw(invalid_argument){

  DataClass *data1 = new DataClass(18,02,1993);
  DataClass *data2 = new DataClass(01,03,1991);

  cout << '\n' << "RG Thiago: " << data1->getDay() << "/";
  cout << data1->getMonth() << "/" << data1->getYear() << '\n';

  cout << '\n' << "RG Matheus: " << data2->getDay() << "/";
  cout << data2->getMonth() << "/" << data2->getYear() << '\n';

  cout << '\n';
  cout << "Methods GET e SET" << '\n';
  data1->setYear(1997);
  cout << "Thiago's new year: " << data1->getYear() << '\n';

  cout << '\n';
  cout << "Method nextDay" << '\n';
  data2->nextDay();
  cout << "Matheus's new day: " << data2->getDay() << '\n';

  return 0;
}
