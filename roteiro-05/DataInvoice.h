#include <iostream>
#include <string>
using namespace std;

class DataInvoice {

private:
  int id, amount, price;
  string description;

public:
  DataInvoice(int id, string description, int amount, double price);

  void setID(int id);
  void setDescription(string description);
  void setAmount(int amount);
  void setPrice(double price);

  int getID(void);
  string getDescription(void);
  int getAmount(void);
  int getPrice(void);
  double getgetInvoiceAmount(void);

};

DataInvoice::DataInvoice(int id, string description, int amount, double price){

  DataInvoice::id = id;
  DataInvoice::description = description;
  DataInvoice::amount = amount;
  DataInvoice::price = price;

  cout << '\n' << "Object is being created." << '\n';
}

/*Methods Set and Void*/
void DataInvoice::setID(int newID){
  DataInvoice::id = newID;
}
void DataInvoice::setDescription(string newDesc){
  DataInvoice::description = newDesc;
}
void DataInvoice::setAmount(int newAmount){
  DataInvoice::amount = newAmount;
}
void DataInvoice::setPrice(double newPrice){
  DataInvoice::price = newPrice;
}

/*Methods Get*/
int DataInvoice::getID(void){
  return DataInvoice::id;
}
string DataInvoice::getDescription(void){
  return DataInvoice::description;
}
int DataInvoice::getAmount(void){
  return DataInvoice::amount;
}
int DataInvoice::getPrice(void){
  return DataInvoice::price;
}
double DataInvoice::getgetInvoiceAmount(void){
  if(price < 0){
    return 0.0;
  }
  else{
    return price*amount;
  }
}
