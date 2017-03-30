#include <iostream>
#include <vector>
#include "RestaurantTable.h"
using namespace std;

class RestaurantHome {
private:
  vector<RestaurantTable> myTables;
public:
  RestaurantHome(void);

  void addOrderRest(int x, int position, int item);
  double calculationAllTables(void);
};

RestaurantHome::RestaurantHome(void){}

void RestaurantTable::addTable(vector<Order> v){
  myTables.push_back(v);
}

void RestaurantHome::addOrderRest(int x, int position, int item){

  vector<Order> v = myTables.at(position);

  for (size_t i = 0; i < v.size(); i++) {
    if(myTables.at(position).at(i).getNumber() == item){
      myTables.at(position).at(i).setAmount(x);
    }
  }

}
double RestaurantHome::calculationAllTables(void){
  double total = 0;



  return total;
}
