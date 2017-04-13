#include "Worker.h"
#include <iostream>
#include <string>

class WorkerSalaried : public Worker{
private:
public:
  WorkerSalaried(string name, float salary);

  float calculatePayment(int h) override;
};

WorkerSalaried::WorkerSalaried(string n, float s) : Worker(n,s){}

float WorkerSalaried::calculatePayment(int h){
  float valueWeek = salary/4;

  return valueWeek;
}
