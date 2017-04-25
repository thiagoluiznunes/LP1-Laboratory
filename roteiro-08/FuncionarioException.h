#ifndef FUNCIONARIO_EXCEPTION_H
#define FUNCIONARIO_EXCEPTION_H

#include <stdexcept>

class FuncionarioException : public runtime_error {

public:
    FuncionarioException() : runtime_error("Funcionario não encontrado!") {}
};

#endif
