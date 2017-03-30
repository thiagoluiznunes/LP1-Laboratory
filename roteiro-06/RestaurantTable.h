#include <vector>
#include <iostream>
#include "Order.h"
using namespace std;

class RestaurantTable {
private:
  vector<Order> vOrder;

public:
  RestaurantTable(void);

  double calculationTable(void);

  void addOrder(Order o);
  void clearTable(void);

};

RestaurantTable::RestaurantTable(void){}

void RestaurantTable::addOrder(Order o){
  vOrder.push_back(o);
}
void RestaurantTable::clearTable(void){
  vOrder.clear();
}

double RestaurantTable::calculationTable(void){
  double total = 0;
  for (size_t i = 0; i < vOrder.size(); i++) {
    total = total + (vOrder.at(i).getPrice()*vOrder.at(i).getAmount());
  }
  return total;
}
