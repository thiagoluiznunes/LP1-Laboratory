#ifndef OTORRINO_H
#define OTORRINO_H

#include <iostream>
#include <string>
#include "Doctor.h"
using namespace std;

class Otorrino : public Doctor{
private:
  string course = "Otorrino";
public:
  Otorrino(string name, float height, int weight);

  string getCourse(void);
  void setCourse(string c);
  string doSurgery(void) override;
};

Otorrino::Otorrino(string n, float h, int w) : Doctor(n,h,w){}

string Otorrino::getCourse(void){
  return course;
}
string Otorrino::doSurgery(void){
  return "Does nose surgery!";
}
#endif
