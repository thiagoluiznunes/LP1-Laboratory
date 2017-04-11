#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeometricFigure.h"

const static double PI = 3.14;

class Circle : public GeometricFigure {

private:
  double radius;
public:
  Circle(double radius, string name);

  double caculatedArea(void);
  double getRadius(void);
  void setRadius(double r);
};

Circle::Circle(double r, string name) : GeometricFigure(name){
  radius = r;
}
double Circle::caculatedArea(void){
  return PI*(radius*radius);
}
double Circle::getRadius(void){
  return radius;
}
void Circle::setRadius(double r){
  radius = r;
}

#endif
