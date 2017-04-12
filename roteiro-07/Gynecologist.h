#ifndef GYNECOLOGIST_H
#define GYNECOLOGIST_H

#include <iostream>
#include <string>
#include "Doctor.h"
using namespace std;

class Gynecologist : public Doctor{
private:
  string course = "Gynecologist";
public:
  Gynecologist(string name, float height, int weight);

  string getCourse(void);
  void setCourse(string c);
  string doSurgery(void) override;
};

Gynecologist::Gynecologist(string n, float h, int w) : Doctor(n,h,w){}

string Gynecologist::getCourse(void){
  return course;
}
string Gynecologist::doSurgery(void){
  return "Does vagina surgery!";
}
#endif
