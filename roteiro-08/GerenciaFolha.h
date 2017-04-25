#ifndef GERENCIA_FILHA_H
#define GERENCIA_FILHA_H

#include <vector>
#include "Funcionario.h"
#include "FuncionarioException.h"
#include "OrcamentoException.h"
using namespace std;

class GerenciaFolha {

private:
    vector<Funcionario *> funcionarios;
    double dinheiro_Caixa;

public:
    GerenciaFolha();

    void setDinheiroCaixa(double dinheiro_Caixa);
    void setFuncionarios(const vector<Funcionario *> &funcionarios);
    double calcularFolha() throw(OrcamentoException);
    double checarSalario(int mat) throw(FuncionarioException);
};

GerenciaFolha::GerenciaFolha(){}

void GerenciaFolha::setFuncionarios(const vector<Funcionario *> &funcionarios) {
    GerenciaFolha::funcionarios = funcionarios;
}

void GerenciaFolha::setDinheiroCaixa(double dinheiro_Caixa) {
  GerenciaFolha::dinheiro_Caixa = dinheiro_Caixa;
}

double GerenciaFolha::checarSalario(int mat) throw (FuncionarioException) {
  for (auto item : funcionarios) {
    if(item->getMatricula() == mat) {
      return item->calcularSalario();
    }
  }
  throw FuncionarioException();
}
double GerenciaFolha::calcularFolha() throw (OrcamentoException) {
    if(funcionarios.size() == 0) {
        return 0;
    }

    double folhaTotal = 0;
    for (auto item : funcionarios) {
        folhaTotal += item->calcularSalario();
    }

    if(dinheiro_Caixa < folhaTotal) {
        throw OrcamentoException(folhaTotal);
    }
    return folhaTotal;
}

#endif
