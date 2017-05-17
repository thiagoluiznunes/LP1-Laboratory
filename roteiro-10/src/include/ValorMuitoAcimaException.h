#ifndef INCLUDE_VALOR_MUITO_ACIMA_H
#define INCLUDE_VALOR_MUITO_ACIMA_H

#include <stdexcept>

class ValorMuitoAcimaException : public std::runtime_error {

public:
    ValorMuitoAcimaException() : std::runtime_error("Valor muito acima!") {}
    ~ValorMuitoAcimaException();
};

#endif
