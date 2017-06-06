#ifndef ASSALARIADO_H
#define ASSALARIADO_H

#include "Account.h"
#include "Funcionario.h"

class Assalariado : public Funcionario, public Account  {

private:
    double salario;
public:
    Assalariado(const std::string &nome, int mat, double salario, int numC, double saldo);

    double calcularSalario() override;
};

Assalariado::Assalariado(const std::string &nome, int mat, double salario, int numC, double saldo) :
                         Funcionario(nome, mat), salario(salario),
                         Account(nome, numC, saldo){}

double Assalariado::calcularSalario() {return salario;}

#endif
