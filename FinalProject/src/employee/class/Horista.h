#ifndef HORISTA_H
#define HORISTA_H

#include "Account.h"
#include "Funcionario.h"
#include <iostream>

const static float HORAS = 40.0f;
const static float BONUS = 50.0f;

class Horista : public Funcionario {

private:
    double salarioPorHora;
    double horasTrabalhadas;

public:

    Horista(const string &nome, int mat, double salarioPorHora, double horasTrabalhadas);

    double calcularSalario() override;
};

Horista::Horista(const string &nome, int mat, double salarioH, double horasT, int numC, double saldo)
                : Funcionario(nome, mat),
                : Account(nome, numC, saldo), salarioPorHora(salarioH), horasTrabalhadas(horasT) {}

double Horista::calcularSalario() {
    double extra, horaExtra;
    double salario = salarioPorHora * HORAS;

    if (horasTrabalhadas <= HORAS) {
        return salario;
    }
    else {
        extra = horasTrabalhadas - HORAS;
        horaExtra = salarioPorHora * extra * BONUS / 100;

        return salario + horaExtra;
    }
}

#endif
