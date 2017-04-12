#ifndef OPHTHALMOLOGIST_H
#define OPHTHALMOLOGIST_H

#include <iostream>
#include <string>
#include "Doctor.h"
using namespace std;

class Ophthalmologist : public Doctor{
private:
  string course = "Ophthalmologist";
public:
  Ophthalmologist(string name, float height, int weight);

  string getCourse(void);
  void setCourse(string c);
  string doSurgery(void) override;
};

Ophthalmologist::Ophthalmologist(string n, float h, int w) : Doctor(n,h,w){}

string Ophthalmologist::getCourse(void){
  return course;
}
string Ophthalmologist::doSurgery(void){
  return "Does eye surgery!";
}
#endif
