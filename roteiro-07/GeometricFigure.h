#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

#include <iostream>
#include <stdexcept>
using namespace std;

class GeometricFigure {

private:
  string name;

public:
  GeometricFigure(string name);

  string getName(void);
  void setName(string name);
  double caculatedArea(void);
};

GeometricFigure::GeometricFigure(string n){
  name = n;
}
string GeometricFigure::getName(void){
  return name;
}
void GeometricFigure::setName(string n){
  name = n;
}

#endif
