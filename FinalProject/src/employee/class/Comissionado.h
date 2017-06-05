#ifndef COMISSIONADO_H
#define COMISSIONADO_H

#include "Account.h"
#include "Funcionario.h"

class Comissionado : public Funcionario, public Account {

private:
    double salarioBase;
    double vendaSemanal;
    double percentualComissao;

public:
    Comissionado(const string &nome, int mat, double salarioBase, double vendaSemanal,
                         double percentualComissao);

    double calcularSalario() override;
};

Comissionado::Comissionado(const string &nome, int mat, double salarioBase, double vendaSemanal,
                           double percentualComissao, int numC, double saldo)
                         : Funcionario(nome, mat),
                         : Account(nome, numC, saldo),
                         salarioBase(salarioBase), vendaSemanal(vendaSemanal),
                         percentualComissao(percentualComissao) {}

double Comissionado::calcularSalario() {
    return salarioBase + vendaSemanal * percentualComissao / 100;
}

#endif
