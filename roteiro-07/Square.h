#ifndef SQUARE_H
#define SQUARE_H

#include "GeometricFigure.h"

class Square : public GeometricFigure {

private:
  double height;
  double width;
public:
  Square(double height, double widht, string name);

  double caculatedArea(void);
  double getHeight(void);
  double getWidht(void);
  void setHeigth(double h);
  void setWidth(double w);
};

Square::Square(double h, double w, string name) : GeometricFigure(name){
  height = h;
  width = w;
}
double Square::caculatedArea(void){
  return height*width;
}
double Square::getHeight(void){
  return height;
}
void Square::setHeigth(double h){
  height = h;
}
double Square::getWidht(void){
  return width;
}
void Square::setWidth(double w){
  width = w;
}

#endif
