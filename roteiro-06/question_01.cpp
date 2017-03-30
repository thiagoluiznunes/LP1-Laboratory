#include <iostream>
#include "Clock.h"
using namespace std;

int main(int argc, char const *argv[]) {

  cout << "First test!" << endl;

  Clock *firstTime = new Clock(23,59,59);

  cout << firstTime->getHour() << ':';
  cout << firstTime->getMinute() << ':';
  cout << firstTime->getSeconds() << endl;

  firstTime->advanceTime();

  cout << "New hour= " << firstTime->getHour() << ':';
  cout << firstTime->getMinute() << ':';
  cout << firstTime->getSeconds() << endl;

  cout << "Second test!" << endl;

  Clock *secondTime = new Clock(12,0,0);

  cout << secondTime->getHour() << ':';
  cout << secondTime->getMinute() << ':';
  cout << secondTime->getSeconds() << endl;

  secondTime->setTime(14,15,33);

  cout << "New hour= " << secondTime->getHour() << ':';
  cout << secondTime->getMinute() << ':';
  cout << secondTime->getSeconds() << endl;

  return 0;
}
