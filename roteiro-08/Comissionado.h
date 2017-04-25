#ifndef COMISSIONADO_H
#define COMISSIONADO_H


#include "Funcionario.h"

class Comissionado : public Funcionario {

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
                           double percentualComissao) : Funcionario(nome, mat),
                           salarioBase(salarioBase), vendaSemanal(vendaSemanal),
                           percentualComissao(percentualComissao) {}

double Comissionado::calcularSalario() {
    return salarioBase + vendaSemanal * percentualComissao / 100;
}

#endif
