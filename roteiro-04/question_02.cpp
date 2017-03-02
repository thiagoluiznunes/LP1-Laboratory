#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {

  srand(time(0));

  int choose;
  int random = rand() % 100 + 1;

  cout << "Advinhe o número entre 1 e 100." << '\n';

  while (true) {
    cin >> choose;
    if(choose == random){
      cout << "Parabéns. Você adivinhou o número." << '\n';
      break;
    }
    if(choose > random){
      cout << "Muito alto. Tente novamente." << '\n';
      continue;
    }
    if(choose < random){
      cout << "Muito baixo. Tente novamente." << '\n';
      continue;
    }
  }

  return 0;
}
