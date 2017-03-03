#include <iostream>
using namespace std;

float percent(int votes, int allVotes){
  float v = votes;
  float all = allVotes;

  return (v/all)*100;
}

void printPlayers(int arr[], int size, int allVotes){
  float larger = 0;
  int player = 0;

  for (size_t i = 0; i < size; i++) {
    if(arr[i] != 0){

      float perc = percent(arr[i], allVotes);
      cout << "Jogador " << i+1 << ": " << arr[i] << " votos" << '\n';

      if(perc > larger){
        larger = perc;
        player = i+1;
      }
    }
  }
  cout << "O melhor jogador foi o número " << player;
  cout << ", com " << arr[player-1] << " votos, correspondendo a ";
  cout << larger << "% do total de votos." << '\n';
}

int main(int argc, char const *argv[]) {

  int choose;
  int allVotes;
  int arrayPlayers[23];
  int size = (sizeof(arrayPlayers)/sizeof(*arrayPlayers));

  for (size_t i = 0; i < size; i++) {
    arrayPlayers[i] = 0;
  }

  cout << "Informe um valor entre 1 e 23 ou 0 para sair: " << '\n';

  while (true) {
    cin >> choose;
    if(choose < 0 || choose > 23){
      cout << "Número não encontrado. Digite novamente." << '\n';
    }
    if(choose == 0){
      cout << "Votação encerrada!" << '\n';;
      break;
    }
    else{
      allVotes++;
      arrayPlayers[choose-1]++;
    }
  }
  cout << "Foram computados um total de: " << allVotes << '\n';
  printPlayers(arrayPlayers, size, allVotes);

  return 0;
}
