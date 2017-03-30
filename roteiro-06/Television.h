#include <iostream>
using namespace std;
const static int MAX_VOLUME = 30;

class Television {

private:
  int volume, channel;
public:
  Television(void);
  Television(int c, int v);

  int getVolume(void);
  int getChannel(void);

  void setChannel(int c);
  void setVolume(int v);
};

Television::Television(void){};
Television::Television(int c, int v){
  channel = c;
  volume = v;
}

int Television::getChannel(void){
  return channel;
}
int Television::getVolume(void){
  return volume;
}

void Television::setChannel(int c){
  if(c == 1){
    channel++;
  }
  else if(c == 0){
    channel--;
  }
  else{
    channel = c;
  }
}
void Television::setVolume(int v){
  if(v == 1){
    if(volume < MAX_VOLUME){
      volume++;
    }else{cout << "Volume at maximum!" << endl;}
  }
  if(v == 0){
    if(volume > 0){
      volume--;
    }else{cout << "Volume at least!" << endl;}
  }
}
