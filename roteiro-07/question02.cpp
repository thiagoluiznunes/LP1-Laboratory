#include <iostream>
#include "Consultant.h"
#include "Employee.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Consultant *teste1 = new Consultant("11414864", "Thiago", 800);

  cout << "Consultant" << endl;
  cout << "Registration: " << teste1->getRegist() << endl;
  cout << "Name: " << teste1->getName() << endl;
  cout << "Salary: " << teste1->getSalary() << endl;
  cout << endl;

  Employee *teste2 = new Employee("11414865", "Luiz", 800);

  cout << "Employee" << endl;
  cout << "Registration: " << teste2->getRegist() << endl;
  cout << "Name: " << teste2->getName() << endl;
  cout << "Salary: " << teste2->getSalary() << endl;
  cout << endl;

  return 0;
}
