#include <iostream>
#include <string>
using namespace std;

class Order {
private:
  int number, amount;
  double price;
  string description;
public:
  Order(int n, int q, double p, string d);

  int getNumber(void);
  int getAmount(void);
  double getPrice(void);
  string getDescription(void);

  void setAmount(int x);
};

Order::Order(int n, int q, double p, string d){
  number = n;
  amount = q;
  price = p;
  description = d;
}

int Order::getNumber(void){
  return number;
}
int Order::getAmount(void){
  return amount;
}
double Order::getPrice(void){
  return price;
}
string Order::getDescription(void){
  return description;
}

void Order::setAmount(int x){
  amount = amount + x;
}
