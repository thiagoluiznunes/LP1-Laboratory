#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {

  int choose;
  int random;
  int array[5];
  int size = (sizeof(array)/sizeof(*array));

  for (size_t i = 0; i < size; i++) {
    array[i] = 0;
  }

  cout << "Digite o número de lançamentos: " << '\n';

  while (true) {
    cin >> choose;

    if(choose == 0){
      break;
    }
    else{
      srand(time(0));
      for (size_t i = 0; i < choose; i++) {
        random = rand() % 6 + 1;
        array[random-1]++;
      }
      for (size_t i = 0; i < size+1; i++) {
        float num = array[i];
        float ch = choose;
        float percent = (num/ch)*100;

        cout << "Número " << i+1 << " : " << percent << "%"<< '\n';
        array[i] = 0;
      }
      cout << '\n';
    }
  }

  return 0;
}
