#ifndef SURGEON_H
#define SURGEON_H

#include <iostream>
#include <string>
#include "Doctor.h"
using namespace std;

class Surgeon : public Doctor{
private:
  string course = "Surgeon";
public:
  Surgeon(string name, float height, int weight);

  string getCourse(void);
  void setCourse(string c);
  string doSurgery(void) override;
};

Surgeon::Surgeon(string n, float h, int w) : Doctor(n,h,w){}

string Surgeon::getCourse(void){
  return course;
}
string Surgeon::doSurgery(void){
  return "Does heart surgery!";
}
#endif
