#ifndef CONSULTANT_H
#define CONSULTANT_H

#include "Employee.h"
using namespace std;

class Consultant : public Employee{
private:
public:
  Consultant(string r, string n, string s);

  float getSalary(void);
  float getSalary(float percentage);
};

Consultant::Consultant(string r, string n, float s) : Employee(r,n,s){}

float Consultant::getSalary(void){
  return salary + (10*100)/100;
}
float Consultant::getSalary(float percent){
  return salary + (salary*percent)/100;
}

#endif
