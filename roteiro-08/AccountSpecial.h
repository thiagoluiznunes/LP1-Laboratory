#ifndef ACCOUNT_SPECIAL_H
#define ACCOUNT_SPECIAL_H

class AccountSpecial : public Account{
private:
public:
  AccountSpecial(string name, int salary, int numC, double saldo);
  void definirLimite(void) override;
};
AccountSpecial::AccountSpecial(string n, int sa, int nu, double s) : Account(n,sa,nu,s){}

void AccountSpecial::definirLimite(void){
  limite = salarioMensal*3;
}

#endif
