#include <iostream>
#include <stdexcept>
using namespace std;

#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_month 1
#define MAX_MONTH 12
#define MIN_year 1
#define MAX_YEAR 2017

class DataClass {

private:
  int day, month, year;

public:
  DataClass(int day, int month, int year);

  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);
  void nextDay(void);

  int getDay(void);
  int getMonth(void);
  int getYear(void);

};

DataClass::DataClass(int day, int month, int year) {
  if(day < MIN_DAY || day > MAX_DAY){
    throw invalid_argument("day invalido!");
  }
  if(month < MIN_month || month > MAX_MONTH){
    throw invalid_argument("Mês invalido!");
  }
  if(year < MIN_year || year > MAX_YEAR){
    throw invalid_argument("year invalido!");
  }

  DataClass::day = day;
  DataClass::month = month;
  DataClass::year = year;

  cout << '\n' << "Object is being created." << '\n';
}
/*Methods Set and Void*/
void DataClass::setDay(int newDay){
  DataClass::day = newDay;
}
void DataClass::setMonth(int newMonth){
  DataClass::month = newMonth;
}
void DataClass::setYear(int newYear){
  DataClass::year = newYear;
}
void DataClass::nextDay(void){
  if(day < MAX_DAY){
    day++;
  }
  else{
    DataClass::day = 1;
    if(DataClass::month < MAX_MONTH){
      DataClass::month++;
    }
    else{
      DataClass::month = 1;
      DataClass::year++;
    }
  }
}
/*Methods Get*/
int DataClass::getDay(void){
  return DataClass::day;
}
int DataClass::getMonth(void){
  return DataClass::month;
}
int DataClass::getYear(void){
  return DataClass::year;
}
