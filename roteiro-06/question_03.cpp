#ifndef Order
#define Order

#include <iostream>
#include <vector>
#include "RestaurantTable.h"
#include "RestaurantHome.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Order *camarao = new Order(1,1,15,camarao);
  Order *salada = new Order(2,1,5,salada);
  Order *peixe = new Order(3,1,30,peixe);
  Order *cerveja = new Order(4,1,6,99, cerveja);

  RestaurantTable *thiagoMesa = new RestaurantTable();

  thiagoMesa->addOrder(camarao);
  thiagoMesa->addOrder(salada);
  thiagoMesa->addOrder(peixe);
  thiagoMesa->addOrder(cerveja);

  return 0;
}
 #endif
