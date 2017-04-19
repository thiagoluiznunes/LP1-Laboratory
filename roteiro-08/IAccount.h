#ifndef IACCOUNT_H
#define IACCOUNT_H

class IAccount {
private:
public:
  IAccount();
  virtual void sacar(double v) = 0;
  virtual void depositar(double v) = 0;
};

IAccount::IAccount(){}

#endif
