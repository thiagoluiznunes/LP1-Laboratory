#ifndef ASSALARIADO_H
#define ASSALARIADO_H

#include "Funcionario.h"

class Assalariado : public Funcionario {

private:
    double salario;
public:
    Assalariado(const string &nome, int mat, double salario);

    double calcularSalario() override;
};

Assalariado::Assalariado(const string &nome, int mat, double salario) : Funcionario(nome, mat), salario(salario) {}

double Assalariado::calcularSalario() {return salario;}

#endif
