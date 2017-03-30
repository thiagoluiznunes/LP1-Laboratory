#include <iostream>
using namespace std;

const static int MAX_SECONDS = 59;
const static int MAX_MINUTES = 59;
const static int MAX_HOURS = 23;

class Clock {

private:
  int hour, minute, seconds;

public:
  Clock(void);
  Clock(int h, int m, int s);

  int getHour(void);
  int getMinute(void);
  int getSeconds(void);

  void setTime(int h, int m, int s);
  void advanceTime(void);

};

Clock::Clock(void){cout << '\n' << "Object is being created." << '\n';}

Clock::Clock(int h, int m, int s){
  if(h>=0 && h<=23){
    hour = h;
    if(m>=0 && m <=59){
      minute = m;
      if(s>=0 && s <=59){
        seconds = s;
      }else {throw std::invalid_argument( "Second value it´s invalid!");}
    }else{throw std::invalid_argument( "Minute value it´s invalid!");}
  }else {throw std::invalid_argument( "Hour value it´s invalid!");}

  cout << '\n' << "Object is being created." << '\n';
}

int Clock::getHour(void){
  return hour;
}
int Clock::getMinute(void){
  return minute;
}
int Clock::getSeconds(void){
  return seconds;
}

void Clock::setTime(int h, int m, int s){
  if(h>=0 && h<=23){
    hour = h;
    if(m>=0 && m <=59){
      minute = m;
      if(s>=0 && s <=59){
        seconds = s;
      }else {throw std::invalid_argument( "Second value it´s invalid!");}
    }else{throw std::invalid_argument( "Minute value it´s invalid!");}
  }else {throw std::invalid_argument( "Hour value it´s invalid!");}
}

void Clock::advanceTime(void){
  if(seconds == MAX_SECONDS){
    if(minute == MAX_MINUTES){
      if(hour == MAX_HOURS){
        hour = 0;
        minute = 0;
        seconds = 0;
      }
      else{
        hour++;
        minute = 0;
        seconds = 0;
      }
    }
    else{
      minute++;
      seconds = 0;
    }
  }
  else{
    seconds++;
  }
}
