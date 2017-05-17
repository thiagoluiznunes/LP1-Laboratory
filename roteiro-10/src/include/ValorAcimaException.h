#ifndef INCLUDE_VALOR_ACIMA_H
#define INCLUDE_VALOR_ACIMA_H

#include <stdexcept>

class ValorAcimaException : public std::runtime_error {

public:
    ValorAcimaException() : std::runtime_error("Valor acima!") {}
    ~ValorAcimaException();
};

#endif
