#include "Worker.h"
#include <iostream>
#include <string>

class HourlyWorker : public Worker{
private:
public:
  HourlyWorker(string name, float salary);

  float calculatePayment(int h) override;
};

HourlyWorker::HourlyWorker(string n, float s) : Worker(n,s){}

float HourlyWorker::calculatePayment(int h){
  float valueHour = (salary/4)/40;
  float valueWeek = salary/4;
  if(h > 40){
    float extraHours = (h-40)*1.5;
    float extraPayment = extraHours*valueHour;
    return valueWeek+extraPayment;
  }
  else if(h>=0 && h<=40){
    return valueHour*h;
  }
}
