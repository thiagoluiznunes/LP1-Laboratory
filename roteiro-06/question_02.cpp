#include <iostream>
#include "Television.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Television *tv1 = new Television(07, 20);
  Television *tv2 = new Television(12, 15);

  cout << endl;
  cout << "First channel test!" << endl;
  cout << "Channel: " << tv1->getChannel() << " Volume: " << tv1->getVolume() <<endl;
  tv1->setChannel(1);
  tv1->setVolume(1);
  cout << "Next channel: " << tv1->getChannel() << " Volume: " << tv1->getVolume() <<endl;

  cout << endl;
  cout << "Second channel test!" << endl;
  cout << "Channel: " << tv2->getChannel() << " Volume: " << tv2->getVolume() <<endl;
  tv2->setChannel(81);
  tv2->setVolume(1);
  cout << "Next channel: " << tv2->getChannel() << " Volume: " << tv2->getVolume() <<endl;
  cout << endl;

  return 0;
}
