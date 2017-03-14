#include <iostream>
#include "DataInvoice.h"
using namespace std;

int main(int argc, char const *argv[]) {

  DataInvoice *invoice1 = new DataInvoice(01, "camera", 3, 399);
  DataInvoice *invoice2 = new DataInvoice(02, "notebook", 1, 2.000);

  cout << '\n';
  cout << "ID: " << invoice1->getID() << '\n';
  cout << "Description: " << invoice1->getDescription() << '\n';
  cout << "Amount: " << invoice1->getAmount() << '\n';
  cout << "Price: " << invoice1->getPrice() << '\n';
  cout << "Invoice Amount: " << invoice1->getgetInvoiceAmount() << '\n';

  cout << '\n';
  cout << "ID: " << invoice2->getID() << '\n';
  cout << "Description: " << invoice2->getDescription() << '\n';
  cout << "Amount: " << invoice2->getAmount() << '\n';
  cout << "Price: " << invoice2->getPrice() << '\n';
  cout << "Invoice Amount: " << invoice2->getgetInvoiceAmount() << '\n';

  cout << '\n';
  cout << "Method SET" << '\n';
  cout << "ID: " << invoice1->getID() << '\n';
  cout << "Amount: " << invoice1->getAmount() << '\n';
  invoice1->setAmount(15);
  cout << "New Amount: " << invoice1->getAmount() << '\n';
  cout << "New Invoice Amount: " << invoice1->getgetInvoiceAmount() << '\n';

  cout << '\n';
  cout << "ID: " << invoice2->getID() << '\n';
  cout << "Amount: " << invoice2->getAmount() << '\n';
  invoice2->setAmount(150);
  cout << "New Amount: " << invoice2->getAmount() << '\n';
  cout << "New Invoice Amount: " << invoice2->getgetInvoiceAmount() << '\n';

  return 0;
}
