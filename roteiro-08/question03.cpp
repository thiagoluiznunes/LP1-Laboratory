#include <iostream>
#include "GerenciaFolha.h"
#include "Assalariado.h"
#include "Horista.h"
#include "Comissionado.h"


int main() {

    GerenciaFolha painelGerencia;

    vector<Funcionario*> funcionarios(3);

    funcionarios[0] = new Assalariado("Thiago", 1, 1200);
    funcionarios[1] = new Horista("Luiz", 2, 30, 55);
    funcionarios[2] = new Comissionado("Pereira", 3, 800, 4500, 4);

    painelGerencia.setFuncionarios(funcionarios);

    cout << endl;
    cout << "Procurando empregados nao existentes. Aguarde." << endl;
    try {
        painelGerencia.checarSalario(4);
    }catch (FuncionarioException &e) {
        cout << "Exception: " << e.what() << endl << endl;
    }

    painelGerencia.setDinheiroCaixa(1000);
    cout << "Calculo da folha de pagamento sem saldo" << endl;
    try{
        cout << "Total valor da folha: " << painelGerencia.calcularFolha() << endl;
    }
    catch(OrcamentoException &e) {
        cout << "Exception: " << e.what() << endl << endl;
    }

    cout << "Adicionando dinheiro a folha de pagamento" << endl;
    painelGerencia.setDinheiroCaixa(10000);

    cout << "Funcionarios da Folha" << endl;
    cout << "Funcionario matricula 1: " << painelGerencia.checarSalario(1) << endl;
    cout << "Funcionario matricula 2: " << painelGerencia.checarSalario(2) << endl;
    cout << "Funcionario matricula 3: " << painelGerencia.checarSalario(3) << endl << endl;
    cout << "Valor total da folha de pagamento: " << painelGerencia.calcularFolha() << endl;
    cout << endl;

    for (auto &&item : funcionarios) {
        delete item;
    }
    funcionarios.clear();

    return 0;
}
