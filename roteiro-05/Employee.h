#include <iostream>
#include <string>
using namespace std;

class Employee {

private:
  string name, midName;
  double salary;

public:
  Employee(string name, string midName, double salary);

  void setName(string name);
  void setMidName(string midName);
  void setSalary(double salary);
  void giveIncrease(void);

  string getName(void);
  string getMidName(void);
  double getSalary(void);
  double getSalaryYearly(void);
};

Employee::Employee(string name, string midName, double salary){

  Employee::name = name;
  Employee::midName = midName;
  Employee::salary = salary;

  cout << '\n' << "Object is being created." << '\n';
}

/*Methods Set and Void*/
void Employee::setName(string name){
  Employee::name = name;
}
void Employee::setMidName(string midName){
  Employee::midName = midName;
}
void Employee::setSalary(double salary){
  Employee::salary = salary;
}
void Employee::giveIncrease(void){
  Employee::salary += (Employee::salary*10)/100;
}

/*Methods Get*/
string Employee::getName(void){
  return Employee::name;
}
string Employee::getMidName(void){
  return Employee::midName;
}
double Employee::getSalary(void){
  return Employee::salary;
}
double Employee::getSalaryYearly(void){
  return Employee::salary*12;
}
