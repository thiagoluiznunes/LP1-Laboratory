#include <iostream>
#include "Person.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Person *p1 = new Person("Thiago", "123-456", 24);
  Person *p2 = new Person("Matheus");

  cout << '\n';
  cout << "Thiago's phone: " << p1->getPhone() << '\n';
  cout << "Age: " << p1->getAge() << '\n';
  p1->setPhone("333-555");
  cout << "New Thiago's phone: " << p1->getPhone() << '\n';

  p2->setPhone("122-485");
  p2->setAge(26);
  cout << '\n';
  cout << "Matheus's phone: " << p2->getPhone() << '\n';
  cout << "Age: " << p2->getAge() << '\n';

  return 0;
}
