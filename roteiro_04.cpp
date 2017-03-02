#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {

  int input;
  int larger = 0;
  vector<int> myVector;

  cout << "Digite um conjunto de valores: " << '\n';

  while (true) {
    cin >> input;
    if(input != 0){
      myVector.push_back(input);
      continue;
    }
    else{
      myVector.push_back(input);
      break;
    }
  }

  for (size_t i = 0; i < myVector.size(); i++) {
    if(myVector.at(i) >= larger){
      larger = myVector.at(i);
    }
  }
  cout << "Maior valor inserido: " << larger << '\n';
  cout << endl;
  return 0;
}
