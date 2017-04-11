#include <iostream>
#include "Triangle.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Triangle *teste1 = new Triangle(2, 3, "triangulo");
  cout << teste1->getName() << endl;

  return 0;
}
