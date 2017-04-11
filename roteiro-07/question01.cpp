#include <iostream>
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Triangle *teste1 = new Triangle(2, 3, "Triangulo");
  Circle *teste2 = new Circle(5, "Circulo");
  Square *teste3 = new Square(4, 4, "Quadrado");

  cout << teste1->getName() << ": "<< teste1->caculatedArea()<< endl;
  cout << teste2->getName() << ": "<< teste2->caculatedArea()<< endl;
  cout << teste3->getName() << ": "<< teste3->caculatedArea()<< endl;

  return 0;
}
