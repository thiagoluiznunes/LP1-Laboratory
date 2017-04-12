#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
using namespace std;

class Doctor {
protected:
  string name;
  float height;
  int weight;
public:
  Doctor(string name, float height, int weight);
  string getName(void);
  float getHeight(void);
  int getWeight(void);
  virtual string doSurgery(void);
  void setName(string n);
  void setHeight(float h);
  void setWeight(int w);

};
Doctor::Doctor(string n, float h, int w){
  name = n;
  height = h;
  weight = w;
}
string Doctor::getName(void){
  return name;
}
float Doctor::getHeight(void){
  return height;
}
int Doctor::getWeight(void){
  return weight;
}
void Doctor::setName(string n){
  name = n;
}
void Doctor::setHeight(float h){
  height = h;
}
void Doctor::setWeight(int w){
  weight = w;
}
string Doctor::doSurgery(void){
  return "Does surgery!";
}

#endif
