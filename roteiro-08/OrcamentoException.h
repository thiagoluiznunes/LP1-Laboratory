#ifndef ORCAMENTO_EXCEPTION_H
#define ORCAMENTO_EXCEPTION_H

#include <stdexcept>
using namespace std;

class OrcamentoException : public runtime_error {

public:
    OrcamentoException(double __arg) : runtime_error(
            "Dinheiro insuficiente para " + to_string(__arg)) {}
    OrcamentoException() : runtime_error("Estouro no orcamento. Não possui saldo suficiente!") {}
};

#endif
