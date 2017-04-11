#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;
class Employee {
private:
  string registration;
  string name;
  float salary;
public:
  Employee(string r, string n, float s);

  string getResgist(void);
  string getName(void);
  float getSalary(void);
  void setResgist(string r);
  void setName(string n);
  void setSalary(float s);
};

Employee::Employee(string r, string n, float s){
  registration = r;
  name = n;
  salary = s;
}

string Employee::getResgist(void){
  return registration;
}
string Employee::getName(void){
  return name;
}
float Employee::getSalary(void){
  return salary;
}

void Employee::setResgist(string r){
  registration = r;
}
void Employee::setName(string n){
  name = n;
}
void Employee::setSalary(float s){
  salary = s;
}

#endif
