#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
  string name;
  float salary;
public:
  Worker(string n, float s);

  string getName(void);
  float getSalary(void);
  void setName(string n);
  void setSalary(float s);
  virtual float calculatePayment(int h);
};
Worker::Worker(string n, float s){
  name = n;
  salary = s;
}

string Worker::getName(void){
  return name;
}
float Worker::getSalary(void){
  return salary;
}
void Worker::setName(string n){
  name = n;
}
void Worker::setSalary(float s){
  salary = s;
}
float Worker::calculatePayment(int h){
  return salary/4;
}

#endif
