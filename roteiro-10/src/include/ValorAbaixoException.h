#ifndef INCLUDE_VALOR_ABAIXO_H
#define INCLUDE_VALOR_ABAIXO_H

#include <stdexcept>

class ValorAbaixoException : public std::runtime_error {

public:
    ValorAbaixoException() : std::runtime_error("Valor abaixo!") {}
    ~ValorAbaixoException();
};

#endif
