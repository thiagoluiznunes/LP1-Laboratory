#include <iostream>
#include <string>
using namespace std;

class Person {

private:
  string name, phone;
  int age;

public:
  Person(string name, string phone, int age);
  Person(string name);

  void setName(string name);
  void setPhone(string phone);
  void setAge(int age);

  string getName(void);
  string getPhone(void);
  int getAge(void);
};

Person::Person(string name, string phone, int age){

  Person::name = name;
  Person::phone = phone;
  Person::age = age;

  cout << '\n' << "Object is being created." << '\n';
}
Person::Person(string name){
  Person::name = name;
}

/*Methods Set and Void*/
void Person::setName(string name){
  Person::name = name;
}
void Person::setPhone(string phone){
  Person::phone = phone;
}
void Person::setAge(int age){
  Person::age = age;
}

/*Methods Get*/
string Person::getName(void){
  return Person::name;
}
string Person::getPhone(void){
  return Person::phone;
}
int Person::getAge(void){
  return Person::age;
}
