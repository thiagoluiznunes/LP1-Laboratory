#include <iostream>
#include "Employee.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Employee *emp1 = new Employee("Thiago", "Luiz", 800);
  Employee *emp2 = new Employee("Matheus", "Cesar", 3500);

  cout << '\n';
  cout << "Employee name: " << emp1->getName() << " " << emp1->getMidName() << '\n';
  cout << "Salary: " << emp1->getSalary() << '\n';
  emp1->giveIncrease();
  cout << "Increase 10% at salary: " << emp1->getSalary() << '\n';
  cout << "Yearly salary: " << emp1->getSalaryYearly() << '\n';

  cout << '\n';
  cout << "Employee name: " << emp2->getName() << " " << emp2->getMidName() << '\n';
  cout << "Salary: " << emp2->getSalary() << '\n';
  emp2->giveIncrease();
  cout << "Increase 10% at salary: " << emp2->getSalary() << '\n';
  cout << "Yearly salary: " << emp2->getSalaryYearly() << '\n';

  return 0;
}
