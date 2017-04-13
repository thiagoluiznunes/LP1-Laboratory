#include <iostream>
#include <string>
#include "Worker.h"
#include "HourlyWorker.h"
#include "WorkerSalaried.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Worker *teste = new Worker("Thiago", 1500);
  HourlyWorker *teste1 = new HourlyWorker("Luiz", 1500);
  WorkerSalaried *teste2 = new WorkerSalaried("Pereira", 2500);

  cout << endl;
  cout << "Worker " << teste->getName() << endl;
  cout << "Week´s payment: " << teste->calculatePayment(45) << endl;
  cout << endl;

  cout << "Hourly Worker " << teste1->getName() << endl;
  cout << "Week´s payment: " << teste1->calculatePayment(45) << endl;
  cout << endl;

  cout << "Worker Salaried " << teste2->getName() << endl;
  cout << "Week´s payment: " << teste2->calculatePayment(45) << endl;
  cout << endl;

  return 0;
}
