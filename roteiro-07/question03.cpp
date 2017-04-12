#include <iostream>
#include "Doctor.h"
#include "Surgeon.h"
#include "Ophthalmologist.h"
#include "Otorrino.h"
#include "Gynecologist.h"

int main(int argc, char const *argv[]) {

  Doctor *teste1 = new Doctor("Thiago", 1.75, 65);

  cout << "Doctor: " << teste1->getName() << endl;
  cout << "Height: " << teste1->getHeight() << endl;
  cout << "Weight: " << teste1->getWeight() << endl;
  cout << "Treatment: " << teste1->doSurgery() << endl;
  cout << endl;

  Surgeon *teste2 = new Surgeon("Luiz", 1.85, 72);

  cout << "Doctor: " << teste2->getName() << endl;
  cout << "Height: " << teste2->getHeight() << endl;
  cout << "Weight: " << teste2->getWeight() << endl;
  cout << "Specialty: " << teste2->getCourse() << endl;
  cout << "Treatment: " << teste2->doSurgery() << endl;
  cout << endl;

  Ophthalmologist *teste3 = new Ophthalmologist("Pereira", 1.95, 82);

  cout << "Doctor: " << teste3->getName() << endl;
  cout << "Height: " << teste3->getHeight() << endl;
  cout << "Weight: " << teste3->getWeight() << endl;
  cout << "Specialty: " << teste3->getCourse() << endl;
  cout << "Treatment: " << teste3->doSurgery() << endl;
  cout << endl;

  Otorrino *teste4 = new Otorrino("Nunes", 1.99, 95);

  cout << "Doctor: " << teste4->getName() << endl;
  cout << "Height: " << teste4->getHeight() << endl;
  cout << "Weight: " << teste4->getWeight() << endl;
  cout << "Specialty: " << teste4->getCourse() << endl;
  cout << "Treatment: " << teste4->doSurgery() << endl;
  cout << endl;

  Gynecologist *teste5 = new Gynecologist("Henrique", 1.55, 59);

  cout << "Doctor: " << teste5->getName() << endl;
  cout << "Height: " << teste5->getHeight() << endl;
  cout << "Weight: " << teste5->getWeight() << endl;
  cout << "Specialty: " << teste5->getCourse() << endl;
  cout << "Treatment: " << teste5->doSurgery() << endl;
  cout << endl;

  return 0;
}
